/******************************
***  Update: 2014/08/06     ***
***  By: snowcookie         ***
******************************/

#include "character_basic.h"
#include <iostream>

using namespace std;

int main(){

	class character *c = new character( 1 , "test" , "XDD" , 250 , 200 , 50 );
	class formulas *f = new formulas( "fire" ,"very hot" , 0 , 100 , 10 );
	class formulas *f2 = new formulas( "light" , "very light" , 1 ,120 , 50 );

	class character *c2 = new character( 2 , "test2" , "HI" , 300 , 150 , 55 );
	class formulas *f3 = new formulas( "forzen" , "very cool" , 0 , 100 , 10 );

	cout << c->get_character_info() << endl;

	c->addformulas( f );
	c->addformulas( f2 );

	cout << c->get_formulas_info() << endl;

	cout << c2->get_character_info() << endl;
	c2->addformulas( f3 );
	cout << c2->get_formulas_info() << endl;

	delete c ;
	delete c2;

	return 0;
}
