/******************************
***  Update: 2014/07/24     ***
***  By: snowcookie         ***
******************************/

#include "character_basic.h"
#include "function.h"

/***** init *****/
formulas::formulas(){
    this->setname( init_string );
    this->setdescription( init_string );
    this->setattack_amount( init_int );
    this->setmp_amount( init_int );
}

formulas::formulas( string name ){
    this->setname( name );
    this->setdescription( init_string );
    this->setattack_amount( init_int );
    this->setmp_amount( init_int );
}

formulas::formulas( string name , int attack_amount , int mp_amount ){
    this->setname( name );
    this->setdescription( init_string );
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

/***** functional *****/

string formulas::get_formulas_info(){

    string s = "";

    s = this->getname() + " : " + this->getdescription();
    s += " , 攻擊力 : " + turn_int_to_string( this->getattack_amount() );
    s += " , 耗魔量 : " + turn_int_to_string( this->getmp_amount() );

    return s;
}
