CXX=g++
CFLAGS=-std=c++11 -O2 -Wall -g
CXXFLAGS=-std=c++11 -O2 -Wall -g

TARGET:=test
SOURCE:=$(wildcard ../*.cc)
OBJS=./bubbleSort.cc ./countSort.cc ./heapSort.cc ./insertionSort.cc \
	 ./mergeSort.cc ./quickSort.cc ./selectionSort.cc ./shellSort.cc ./main.cc

$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS)	$(OBJS) -o ./$(TARGET) 

clean:
	rm ./test