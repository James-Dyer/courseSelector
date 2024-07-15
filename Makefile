CC = g++
CFLAGS = -Wall -std=c++17

SRCS = Logic.cpp GlobalVariables.cpp main.cpp Course.cpp Req.cpp FileIO.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = courseSelector

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
