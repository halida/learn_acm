
CFLAG=-std=c++98

run: s.bin
	cat input.txt | ./s.bin
s.bin: main.cpp
	c++ $(CFLAG) main.cpp -o s.bin
