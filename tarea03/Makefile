CXX=g++
CXXFLAGS=-O3 -std=c++11 -fsanitize=undefined -fsanitize=signed-integer-overflow -fsanitize=address -g

all : 1.x run1
%.x : %.cpp
	$(CXX)  $(CXXFLAGS) $< -o $@

run1 : 1.x
	./1.x
test1 : 1.x
	./1.x | tail -n 1 | awk '{print $$2}'
clean:
	rm -rf 1.x*
