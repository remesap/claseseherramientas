
all : 1.x datos.txt sumas.pdf

1.x : 1.cpp
	g++ $^ -o $@

datos.txt : 1.x
	./1.x > datos.txt

sumas.pdf : datos.txt plotfigure.gp 
	gnuplot plotfigure.gp

clean :
	rm -f datos.txt 1.x 1.pdf
