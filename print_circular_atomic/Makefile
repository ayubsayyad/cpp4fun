SOURCE= print_circular_atomic.cpp
TARGET=print_circular_atomic
CC=g++

#------------------------------------------------------------------------------



all: $(TARGET)

$(TARGET): $(SOURCE)

	$(CC) $(SOURCE) -o$(TARGET) -lstdc++ -pthread -std=c++11

clean:

	rm -f $(TARGET)
