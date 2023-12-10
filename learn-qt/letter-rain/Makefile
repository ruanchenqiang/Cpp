TARGET= letter-rain
CXX= g++
OX= -O3
SRCS= $(wildcard *.cpp)
OBJS= $(patsubst %.cpp, %.o, $(SRCS))
INCS= -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtWidgets
LIBS= -pthread -lQt5Core -lQt5Gui -lQt5Widgets
CPPFLAGS= -std=c++17 -Wall -g

all: $(TARGET)

letter-rain: $(OBJS)
	$(CXX) -o $@ $(INCS) $(OBJS) $(LIBS) $(CPPFLAGS) $(OX)

%.o: %.cpp
	$(CXX) -o $@ -c $^ $(INCS) $(LIBS) $(CPPFLAGS) $(OX)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
