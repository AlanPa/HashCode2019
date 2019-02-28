# Windows command : mingw32-make au lieu de make

CC = g++
CFLAGS = -Wall -std=c++11
LDFLAGS =

DEPS = slide.h photos.h
OBJ = slide.o photos.o main.o

default: slide.exe 

slide.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	rm -f *.o core
	rm -f *.exe
	rm -f *.txt
