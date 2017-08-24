COMPILER_FLAGS = -Wall -g -c -std=c++11
# LINKER_FLAGS not needed

Encrypt: Encrypt.o IOManager.o Cipher.o
	g++ Encrypt.o IOManager.o Cipher.o -o Encrypt

IOManager.o: IOManager.cpp IOManager.h
	g++ $(COMPILER_FLAGS) IOManager.cpp

Cipher.o: Cipher.cpp Cipher.h
	g++ $(COMPILER_FLAGS) Cipher.cpp

clean:
	rm -f Encrypt *.o

.PHONY: clean
