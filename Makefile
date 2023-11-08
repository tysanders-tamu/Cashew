TARGET = out
CC=g++
LD=g++

FLAGS = -O3
SOURCES = main.cpp Buffer.cpp Boid.cpp Flock.cpp

all: $(TARGET)

clean:
	rm *.o
	rm $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(FLAGS) $^ -o $@
