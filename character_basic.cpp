/******************************
***  Update: 2014/07/24     ***
***  By: snowcookie         ***
******************************/

#include "character_basic.h"
#include "function.h"

/***** init *****/
character::character( string name , string description , int hp , int mp , int normal_attack ){
    this->setname( name );
    this->setdescription( description );
    this->sethp( hp );
    this->setmp( mp );
    this->setnormal_attack( normal_attack );
    this->setspecial_amount( 0 );
}

/***** set *****/
void character::setname( string name ){
    this->name = name;
}

void character::setdescription( string description ){
    this->description = description;
}

void character::sethp( int hp ){
    this->hp = hp;
}

void character::setmp( int mp ){
    this->mp = mp;
}

void character::setnormal_attack( int normal_attack ){
    this->normal_attack = normal_attack;
}
void character::setspecial_amount( int special_amount ){
    this->special_amount = special_amount;
}

/***** get *****/
string character::getname(){
    return this->name;
}

string character::getdescription(){
    return this->description;
}

int character::gethp(){
    return this->hp;
}

int character::getmp(){
    return this->mp;
}

int character::getnormal_attack(){
    return this->normal_attack;
}

int character::getspecial_amount(){
    return this->special_amount;
}

vector<formulas> character::getformulas(){
    return this->vformulas;
}

/***** functional *****/

void character::addformulas( formulas f){
    this->vformulas.push_back( f );
}

int character::attack( int select_formulas_number ){
    return 0;
}

int character::attacked( int attacked_amount ){
    return 0;
}
