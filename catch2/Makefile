all : main_factorial.x

main_factorial.x : main_factorial.o factorial.o
	g++ $^ -o $@

test : test_factorial.x
test_factorial.x : test_factorial.o factorial.o
	g++ $^ -o $@   #enlazando	

%.o : %.cpp  #% es una abrevia los """.cpp
	g++ -c $< #creando los objetos, "$<" porque la 1era y única dependencia

clean :
	rm -f *.x *.o

