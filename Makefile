AUX_DIR     := aux
BUILD_DIR   := build
SRC_DIR     := src
RESULT_DIR  := result
TEST_DIR    := test

CC ?= gcc

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror -g
LDFLAGS = -Wl,--as-needed -Wl,--no-undefined

EXERCISES := $(shell find $(SRC_DIR) -type d -name 'exercise-*' -exec basename {} \;)

all: $(EXERCISES)

$(EXERCISES):
	@mkdir -p $(abspath $(BUILD_DIR))/$(notdir $@)
	$(MAKE) -C $(SRC_DIR)/$@ OUTPUT_DIR=$(abspath $(BUILD_DIR))/$(notdir $@) || true

test: $(RESULT_DIR) $(EXERCISES:%=test-%) report generate_json_report

test-%: $(BUILD_DIR)/%
	@mkdir -p $(RESULT_DIR)/$*
	@echo "Running tests for $*"
	@$(TEST_DIR)/$*/test.sh $(BUILD_DIR)/$*/$* && touch $(RESULT_DIR)/$*/$*.pass || touch $(RESULT_DIR)/$*/$*.fail

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(RESULT_DIR):
	@mkdir -p $(RESULT_DIR)

report:
	@echo "Generating test report..."
	@total=$$(find $(RESULT_DIR) -type f -name '*.pass' -o -name '*.fail' | wc -l); \
	success=$$(find $(RESULT_DIR) -type f -name '*.pass' | wc -l); \
	failed=$$(find $(RESULT_DIR) -type f -name '*.fail' | wc -l); \
	echo "Total tests: $$total"; \
	echo "Success: $$success"; \
	echo "Failed: $$failed"; \
	echo "Success tests:"; \
	find $(RESULT_DIR) -type f -name '*.pass' -exec basename {} .pass \; | sed 's/^/  /'; \
	echo "Failed tests:"; \
	find $(RESULT_DIR) -type f -name '*.fail' -exec basename {} .fail \; | sed 's/^/  /'

generate_json_report:
	@echo "Generating JSON report..."
	@success=$$(find $(RESULT_DIR) -type f -name '*.pass' | wc -l); \
	score=$$((success * 5)); \
	total_score=100; \
	channel="gitee"; \
	course_id=1547; \
	ext="aaa"; \
	name=""; \
	echo '{' > $(RESULT_DIR)/report.json; \
	echo '  "channel": "'$$channel'"'',' >> $(RESULT_DIR)/report.json; \
	echo '  "courseId": ' $$course_id',' >> $(RESULT_DIR)/report.json; \
	echo '  "ext": "'$$ext'"'',' >> $(RESULT_DIR)/report.json; \
	echo '  "name": "'$$name'"'',' >> $(RESULT_DIR)/report.json; \
	echo '  "score": ' $$score',' >> $(RESULT_DIR)/report.json; \
	echo '  "totalScore": ' $$total_score >> $(RESULT_DIR)/report.json; \
	echo '}' >> $(RESULT_DIR)/report.json;

clean:
	for dir in $(EXERCISES); do \
		$(MAKE) -C $(SRC_DIR)/$$dir clean; \
	done
	rm -rf $(BUILD_DIR) $(RESULT_DIR)

.PHONY: all clean $(EXERCISES) report generate_json_report
