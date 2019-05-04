#!make -f

all: test
	./$<

demo:  Demo.o DummyChoosers.o DummyGuessers.o play.o calculate.o SmartGuesser.o
	g++ -std=c++1z $^ -o demo

test:  Test.o DummyChoosers.o DummyGuessers.o play.o calculate.o SmartGuesser.o 
	g++ -std=c++1z $^ -o test

%.o: %.cpp
	g++ -std=c++1z --compile $< -o $@

Demo.o: play.hpp calculate.hpp Chooser.hpp DummyChoosers.hpp Guesser.hpp DummyGuessers.hpp 
Test.o: play.hpp calculate.hpp Chooser.hpp DummyChoosers.hpp Guesser.hpp DummyGuessers.hpp badkan.hpp
play.o: play.hpp calculate.hpp Chooser.hpp Guesser.hpp
calculate.o: calculate.hpp Chooser.hpp Guesser.hpp 
DummyChoosers.o: Chooser.hpp
DummyGuessers.o: Guesser.hpp calculate.hpp
SmartGuesser.o:  SmartGuesser.hpp Guesser.hpp 

clean:
	rm -f *.o demo test
