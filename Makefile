#definiendo variables
CXX = g++
CXXFLAGS = -fsanitize=address -fsanitize=undefined -O2

all : 1.x datos.txt sumas.pdf

1.x : 1.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

datos.txt : 1.x
	./1.x > datos.txt

sumas.pdf : datos.txt plotfigure.gp 
	gnuplot plotfigure.gp

clean :
	rm -f datos.txt 1.x 1.pdf
