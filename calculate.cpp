#include "calculate.hpp"
#include <string>
#include <sstream>
using namespace std;
using std::string;
using std::to_string;


// calculateBullAndPgia
string bullpgia::calculateBullAndPgia(string str, string guess) {
	unsigned int length = str.size();
	int bull = 0;
	int pgia = 0;
	int help[length];
	for (int i = 0; i < length; i++) { help[i] = 0; }


	//initialize helper 
	for (int i = 0; i < length; i++) {		//"delete" current index in secret
		if (str[i] == guess[i]) {guess[i]=-9; str[i]=-9; help[i] = 1;  bull++;  }//fill the help arry with bull(bull=1)
		
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (((guess[i] == str[j])&&(str[j]!=-9)) && (help[i] == 0)) {guess[i]=-9; str[j]=-9; help[i] = 2; break; }
		}//end j
	}//end i

	for (int i = 0; i < length; i++) {
		if (help[i] == 2) { pgia++; }
		
	}

	string ans = to_string(bull) + "," + to_string(pgia);
	return ans;
}//end calculateBullAndPgia
