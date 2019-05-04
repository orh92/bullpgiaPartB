#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector>
using bullpgia::Guesser;

namespace bullpgia{

class SmartGuesser:public Guesser{


private:
unsigned int length;//the length
unsigned int flag=0;
unsigned int tryesNumber=0;
int sizeofPermuArray=0;
int premuIndexArray=0;
int premuInit=0;
string myGuess="";
bool permu=true;
	                  //0,1,2,3,4,5,6,7,8,9 frequency 	
int helpArray[10]={0,0,0,0,0,0,0,0,0,0};
std::vector<string> permuArray;


public:
void permutation(string s,int i,int n);
int findPermuSize();
void swap(char& a, char& b);

string guess()override;//function to guess 
void startNewGame(uint length)override;//start new game by int length
void learn(string answers)override;//learn data

};//end SmartGuesser

};//end bullpgia
