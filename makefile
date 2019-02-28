# Windows command : mingw32-make au lieu de make

CC = g++
CFLAGS = -Wall -Werror -std=c++11
LDFLAGS =

DEPS = slide.h # TODO change
OBJ = slide.o main.o # TODO change

default: slide.exe 

slide.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	rm -f *.o core
	rm -f *.exe
	rm -f *.txt
