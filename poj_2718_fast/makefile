
CFLAG=-std=c++0x

run: s.bin
	cat input.txt | ./s.bin
s.bin: main.cpp
	c++ $(CFLAG) main.cpp -o s.bin
