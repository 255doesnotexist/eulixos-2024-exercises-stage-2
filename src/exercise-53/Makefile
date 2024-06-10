CC ?= gcc

CFLAGS	= -std=c11 -Wall -Wextra -Wpedantic -Werror -g -fpic
LDFLAGS = -Wl,--as-needed -Wl,--no-undefined

OUTPUT_DIR ?= .

SRCS		= main.c 
OBJS		= $(SRCS:.c=.o)
TARGET		= $(OUTPUT_DIR)/exercise-53

LIB_NAME	= libv2p.so
LIB_TARGET	= $(OUTPUT_DIR)/$(LIB_NAME)
LIB_SRC		= v2p.c
LIB_OBJ		= $(LIB_SRC:.c=.o)
RPATH		=  -Wl,-rpath,'$$ORIGIN'

all: $(TARGET)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB_TARGET): $(LIB_OBJ)
	$(CC) -shared -o $@ $^

$(TARGET): $(OBJS) $(LIB_TARGET)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(OUTPUT_DIR) -lv2p $(RPATH)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(LIB_TARGET) $(TARGET) $(OBJS) $(LIB_OBJ)
