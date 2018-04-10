CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all: a.out
	./a.out

a.out: Member.o Member_test.o
	$(CXX) $(CXXFLAGS) Member.o Member_test.o

Member.o: Member.cpp Member.h
	$(CXX) $(CXXFLAGS) --compile Member.cpp -o Member.o

Member_test.o: Member_test.cpp Member.h doctest.h
	$(CXX) $(CXXFLAGS) --compile Member_test.cpp -o Member_test.o

clean: 
	rm *.o a.out