/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "calculate.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};


		//my test@@@@@@@@@@@@@@@@@@@
		ConstantChooser chooser1234{"1234"}, chooser4321{"4321"}, chooser1111{"1111"};
		ConstantGuesser guesser1234{"1234"}, guesser4321{"4321"}, guesser1111{"1111"};
		//end my test@@@@@@@@@@@@@@@


		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).

		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).


		//my test@@@@@@@@@@@@@@@@@@@
		
.CHECK_EQUAL(play(chooser1234, guesser1234, 4, 100), 1)    //win in 1 turn  ~ chooser,guesser,length,max turns
.CHECK_OUTPUT(calculateBullAndPgia("1111","4321"),"1,0")
.CHECK_OUTPUT(calculateBullAndPgia("1111","1234"),"1,0")
.CHECK_OUTPUT(calculateBullAndPgia("1100","2211"),"0,2")    
.CHECK_OUTPUT(calculateBullAndPgia("1100","0011"),"0,4")    
.CHECK_OUTPUT(calculateBullAndPgia("1010","1100"),"2,2")
.CHECK_OUTPUT(calculateBullAndPgia("1231","1113"),"1,2")     
.CHECK_OUTPUT(calculateBullAndPgia("1231","1111"),"2,0")   
.CHECK_OUTPUT(calculateBullAndPgia("1111","0231"),"1,0")  
.CHECK_OUTPUT(calculateBullAndPgia("3210","1032"),"0,4")  
.CHECK_OUTPUT(calculateBullAndPgia("7593","1239"),"0,2") 
.CHECK_OUTPUT(calculateBullAndPgia("5432","4377"),"0,2") 
.CHECK_OUTPUT(calculateBullAndPgia("8153","9899"),"0,1") 
.CHECK_OUTPUT(calculateBullAndPgia("7353","7353"),"4,0") 
.CHECK_OUTPUT(calculateBullAndPgia("1128","8754"),"0,1") 
.CHECK_OUTPUT(calculateBullAndPgia("7543","3344"),"1,1") 
.CHECK_OUTPUT(calculateBullAndPgia("7321","7312"),"2,2") 
.CHECK_OUTPUT(calculateBullAndPgia("6754","7654"),"2,2") 
.CHECK_OUTPUT(calculateBullAndPgia("0110","1010"),"2,2") 
.CHECK_OUTPUT(calculateBullAndPgia("0369","4425"),"0,0") 

.CHECK_OUTPUT(calculateBullAndPgia("0132","0321"),"1,3") 
.CHECK_OUTPUT(calculateBullAndPgia("1244","1234"),"3,0") 



		//end my test@@@@@@@@@@@@@@@


		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 100 turns!
		
					}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
