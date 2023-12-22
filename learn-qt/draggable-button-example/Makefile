TARGET= example
CXX= g++
MOC= moc-qt5
OX= -O3
MOC_DIR= moc
MOC_HDR= dragbutton.h widget.h
MOC_SRCS= $(MOC_HDR:%.h=$(MOC_DIR)/moc_%.cpp)
MOC_OBJS= $(patsubst %.cpp, %.o, $(MOC_SRCS))
SRCS= $(wildcard *.cpp)
OBJS= $(patsubst %.cpp, %.o, $(SRCS))
INCS= -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtWidgets
LIBS= -pthread -lQt5Core -lQt5Gui -lQt5Widgets
CPPFLAGS= -std=c++17 -Wall -g

all: $(MOC_DIR) $(TARGET)

$(MOC_DIR): 
	mkdir -p $(MOC_DIR)

$(MOC_DIR)/moc_dragbutton.cpp: dragbutton.h
	$(MOC) -o $(MOC_DIR)/moc_dragbutton.cpp dragbutton.h $(INCS)

$(MOC_DIR)/moc_widget.cpp: widget.h
	$(MOC) -o $(MOC_DIR)/moc_widget.cpp widget.h $(INCS)

example: $(OBJS) $(MOC_OBJS)
	$(CXX) -o $@ $(INCS) $(OBJS) $(MOC_OBJS) $(LIBS) $(CPPFLAGS) $(OX)

%.o: %.cpp
	$(CXX) -o $@ -c $^ $(INCS) $(LIBS) $(CPPFLAGS) $(OX)

clean:
	rm -rf $(MOC_DIR)
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
