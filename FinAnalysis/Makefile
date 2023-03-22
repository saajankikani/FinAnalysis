CC = g++
BIN = analyze
SRCS = $(shell find . -name "*.cpp")

all: $(BIN)

clean:
	rm -f $(BIN)

$(BIN): $(SRCS)
	$(CC) -std=c++11 -o analyze $(SRCS)