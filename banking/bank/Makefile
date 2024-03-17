CC=g++
CFLAGS = -c -Wall -Werror
LDFLAGS =
SOURCES = $(wildcard *.cpp)
DEPENDENCIES = $(SOURCES:.cpp=.d)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = banking

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(DEPENDENCIES)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.d: %.cpp
	$(CC) -MM -MT '$*.o' $< > $@

%.o: %.cpp %.d
	$(CC) $(CFLAGS) $< -o $@

-include $(wildcard *.d)

clean:
	rm *.o *.d $(EXECUTABLE)

.PHONY: all clean

.DEFAULT_GOAL := all
