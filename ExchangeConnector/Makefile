SOURCE= AGExchangeSession.cpp AGSortedList.cpp  AGEpollEventLoop.cpp  main.cpp
TARGET=ExchangeConnector
CC=g++

#------------------------------------------------------------------------------



all: $(TARGET)

$(TARGET): $(SOURCE)

	$(CC) $(SOURCE) -o$(TARGET) -lstdc++ -pthread -std=c++11

clean:

	rm -f $(TARGET)
