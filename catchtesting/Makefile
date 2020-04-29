all : main_factorial.x

main_factorial.x : main_factorial.o factorial.o
	g++ $^ -o $@

%.o : %.cpp  #% es una abrevia los """.cpp
	g++ -c $< #creando los objetos, "$<" porque la 1era y única dependencia

clean :
	rm -f *.x *.o

