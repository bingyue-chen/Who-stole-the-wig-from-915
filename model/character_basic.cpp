/******************************
***  Update: 2014/08/06     ***
***  By: snowcookie         ***
******************************/

#include "character_basic.h"

/***** init *****/
character::character( int number , string name , string description , int hp , int mp , int normal_attack_amount ){
    this->setnumber( number );
    this->setname( name );
    this->setdescription( description );
    this->setattack_str( "" );
    this->setattacked_str( "" );
    this->setdead_str( "" );
    this->sethp( hp );
    this->setmp( mp );
    this->setnormal_attack_amount( normal_attack_amount );
    this->setspecial_amount( 0 );
    this->normal_attack = new formulas ( "normal attack" , "normal" , 0 , normal_attack_amount , 0 );
    this->addformulas( normal_attack );
}

/***** des *****/
character::~character( ){
    for( unsigned int i = 0 ; i < this->vformulas.size() ; i++ )
        delete this->vformulas[i];
}

/***** set *****/
void character::setname( string name ){
    this->name = name;
}

void character::setdescription( string description ){
    this->description = description;
}

void character::setattack_str( string attack_str ){
    this->attack_str = attack_str;
}
void character::setattacked_str( string attacked_str ){
    this->attacked_str = attacked_str;
}

void character::setdead_str( string dead_str ){
    this->dead_str = dead_str;
}

void character::setnumber( int number ){
     this->number = number;
}

void character::sethp( int hp ){
    this->hp = hp;
}

void character::setmp( int mp ){
    this->mp = mp;
}

void character::setnormal_attack_amount( int normal_attack_amount ){
    this->normal_attack_amount = normal_attack_amount;
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

string character::getattack_str(){
    return this->attack_str;
}

string character::getattacked_str(){
    return this->attacked_str;
}
string character::getdead_str(){
    return this->dead_str;
}

int character::getnumber(){
    return this->number;
}

int character::gethp(){
    return this->hp;
}

int character::getmp(){
    return this->mp;
}

int character::getnormal_attack_amount(){
    return this->normal_attack_amount;
}

int character::getspecial_amount(){
    return this->special_amount;
}

vector<formulas*> character::getformulas(){
    return this->vformulas;
}

/***** functional *****/

void character::addformulas( formulas* f){
    this->vformulas.push_back( f );
}

string character::get_character_info(){

    string s = "";

    s = this->getname() + " : " + this->getdescription();
    s += " , hp : " + turn_int_to_string( this->hp );
    s += " , mp : " + turn_int_to_string( this->mp );
    s += " , special amount : " + turn_int_to_string( this->special_amount );

    return s;
}

string character::get_formulas_info(){

    string s = "";

    for( unsigned int i = 0 ; i < this->vformulas.size() ; i++ ){
        s += turn_int_to_string( i + 1 ) + " : " + this->vformulas[i]->get_formulas_info() + "\n";
    }

    return s;
}
