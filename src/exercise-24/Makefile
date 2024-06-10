CC ?= gcc

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror -g
LDFLAGS = -Wl,--as-needed -Wl,--no-undefined

OUTPUT_DIR ?= .

SRCS = main.c matrix_trans.c
OBJS = $(SRCS:.c=.o)
TARGET = $(OUTPUT_DIR)/exercise-24

all: $(TARGET)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(OBJS) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
