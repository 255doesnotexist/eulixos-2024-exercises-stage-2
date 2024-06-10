CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Werror -D_GNU_SOURCE -g
LDFLAGS ?= -Wl,--as-needed -Wl,--no-undefined
OUTPUT_DIR ?= .

SRCS1 = main.c
OBJS1 = $(SRCS1:.c=.o)
SRCS2 = child_program.c
OBJS2 = $(SRCS2:.c=.o)
TARGET = $(OUTPUT_DIR)/exercise-55
CHILD_TARGET = $(OUTPUT_DIR)/child_program

.PHONY: all clean

all: $(TARGET) $(CHILD_TARGET)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(OBJS1) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(CHILD_TARGET): $(OBJS2) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(CHILD_TARGET) $(OBJS1) $(OBJS2)
