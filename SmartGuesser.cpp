#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using namespace std;
using bullpgia::SmartGuesser;
using bullpgia::calculateBullAndPgia;


//function to find the permutation size of the length
int bullpgia::SmartGuesser::findPermuSize() {
	int start = this->length;
	int ans = this->length;;
	while (start > 2) {
		start = start - 1;
		ans = ans * start;
	}
	return ans;
}

//help functoin that used in ::bullpgia:SmartGuesser::permutation
void bullpgia::SmartGuesser::swap(char& a, char& b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}

//filling vector with all the permutations
void bullpgia::SmartGuesser::permutation(string s, int i, int n)
{
	int j;
	if (i == n) {
		if (premuInit < sizeofPermuArray) {
			permuArray.push_back(s);
			premuInit++;
		}
	}
	else
	{
		for (j = i; j < s.size(); j++)
		{
			swap(s[i], s[j]);
			permutation(s, i + 1, n);
			swap(s[i], s[j]);
		}
	}
}//end permutation




//   return the guess string, and turns++
string bullpgia::SmartGuesser::guess() {
	this->tryesNumber++;
	return myGuess;
}// end guess



// startNewGame
void bullpgia::SmartGuesser::startNewGame(uint length) {
	this->length = length;
	this->tryesNumber = 0;
	this->premuIndexArray = 0;
	this->premuInit = 0;
	this->flag = 0;
	this->myGuess = "";
	this->permu = true;
	for (int i = 0; i < 10; i++) { helpArray[i] = 0; }
	permuArray.clear();
	this->sizeofPermuArray = findPermuSize();
	for (int i = 0; i < length; i++) {
		this->myGuess += to_string(0);
	}//end for of the length
	this->tryesNumber++;  //increase the tryes when you initialize game. because the length zero's

}//end startNewGame


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ LEARNNN

//   learn
void bullpgia::SmartGuesser::learn(string bullpgia) {
	int currentBull = bullpgia[0] - 48;
	if (flag < 9) {//this situation is to check how maney bulls in the each digit 0-9 (init situation)
		if (currentBull != 0) {
			this->helpArray[flag] = currentBull;
		}
		this->flag++;
		this->myGuess = "";
		for (int j = 0; j < length; j++) {//length times +"num"
			this->myGuess += to_string(flag);
		}//end for of the length
	}//end if flag<9   @@ when thats end. i have help array filled with the frequency of the numbers @end init situation@
	else if (flag == 9) {
		if (currentBull != 0) {
			this->helpArray[flag] = currentBull;
		}
		flag = 10;
	}//end flag==9
	else {// start the guesses by permutations

			//if permu(flag) is true so need to fill the vector with all the permutations that can be from the founded numbers
			//that in helpArray
		if (permu) {
			this->myGuess = "";
			permu = false;
			for (int i = 0; i <= 9; i++) {
				while (helpArray[i] > 0) {
					myGuess += to_string(i);
					helpArray[i]--;
				}//end while
			}//end if permu(if its my first permutation befor i send to func to creat array with all permutations)
			permutation(myGuess, 0, this->length-1);
		}//end if permu

		else {//is all the permutation tryes each iteration
			if (premuIndexArray < sizeofPermuArray) {
				myGuess = permuArray[premuIndexArray];
				premuIndexArray++;
				this->tryesNumber++;
			}
		}//end current iteration...

	}//end else "start the guesses by permutations
}//end learn
