/******************************
***  Update: 2014/07/25     ***
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

	c->check_can_attack( 1 );
	c->check_can_attack( 2 );
	cout << c->attack( 1 , c2 ) << endl;

	cout << c->get_character_info() << endl;
	cout << c2->get_character_info() << endl;

	cout << endl;

	c2->check_can_attack( 2 );
	c2->check_can_attack( 1 );
	cout << c2->attack( 1 , c ) << endl;

	cout << c->get_character_info() << endl;
    cout << c2->get_character_info() << endl;

	delete c ;
	delete c2;

	return 0;
}
