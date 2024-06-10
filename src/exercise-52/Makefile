CC ?= gcc

CFLAGS	?= -std=c11 -Wall -Wextra -Wpedantic -Werror -D_GNU_SOURCE -g
LDFLAGS ?= -Wl,--as-needed -Wl,--no-undefined

OUTPUT_DIR ?= .

SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
TARGET	= $(OUTPUT_DIR)/exercise-52

all: $(TARGET)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
