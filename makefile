CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = main
SOURCES = main.cpp HashTable.cpp FileManager.cpp VigenereCipher.cpp
HEADERS = HashTable.hpp FileManager.hpp VigenereCipher.hpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run