CROSS_COMPILE ?=
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -O0
TARGET = writer
SRCS = writer.c
OBJS = writer.o

#if [ $1 -eq "CROSS_COMPILE" ]; then
#  echo "Cross compilation"	
#else
#  echo "Native compilation"
#fi

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)