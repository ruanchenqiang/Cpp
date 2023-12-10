TARGET= main
OX= -O3
SRCS= $(wildcard *.cpp)
OBJS= $(patsubst %.cpp, %.o, $(SRCS))
LIBS= -pthread
CPPFLAGS= -std=c++17 -Wall -g

all: $(TARGET)

%.o: %.cpp
	g++ -o $@ -c $^ $(INCS) $(LIBS) $(CPPFLAGS) $(OX)

main: $(OBJS)
	g++ -o $@ $(INCS) $(OBJS) $(LIBS) $(CPPFLAGS) $(OX)

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(TARGET)


