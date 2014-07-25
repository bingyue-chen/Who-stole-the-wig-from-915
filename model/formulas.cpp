/******************************
***  Update: 2014/07/25     ***
***  By: snowcookie         ***
******************************/

#include "formulas.h"
#include "function.h"

/***** init *****/
formulas::formulas( string name , string description , int status , int attack_amount , int mp_amount ){
    this->setname( name );
    this->setdescription( description );
    this->setstatus( status );
    this->setattack_amount( attack_amount );
    this->setmp_amount( mp_amount );
}

/***** set *****/
void formulas::setname( string name ){
    this->name = name;
}

void formulas::setdescription( string description ){
    this->description = description;
}

void formulas::setattack_amount( int attack_amount ){
    this->attack_amount = attack_amount;
}

void formulas::setmp_amount( int mp_amount ){
    this->mp_amount = mp_amount;
}

void formulas::setstatus( int status ){
    this->status = status;
}

/***** get *****/
string formulas::getname(){
    return this->name;
}

string formulas::getdescription(){
    return this->description;
}

int formulas::getattack_amount(){
    return this->attack_amount;
}

int formulas::getmp_amount(){
    return this->mp_amount;
}

int formulas::getstatus(){
    return this->status;
}

/***** functional *****/

string formulas::get_formulas_info(){

    string s = "";

    s = this->getname() + " : " + this->getdescription();
    s += " , attack : " + turn_int_to_string( this->getattack_amount() );
    s += " , mp : " + turn_int_to_string( this->getmp_amount() );

    if( this->getstatus() == 1 )
        s += "( specail amount full can use )";

    return s;
}
