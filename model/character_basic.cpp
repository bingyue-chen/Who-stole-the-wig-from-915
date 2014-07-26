/******************************
***  Update: 2014/07/25     ***
***  By: snowcookie         ***
******************************/

#include "character_basic.h"
#include "function.h"

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

int character::check_can_attack( int select_formulas_number ){

    class formulas *f = NULL;

    if( this->hp <= 0 )
        return 0;

    if( select_formulas_number <= 0 || ( unsigned int )select_formulas_number > this->vformulas.size() )
        return -1;

    f = this->vformulas[select_formulas_number-1];

    if( !this->check_mp( f->getmp_amount() ) )
        return -2;

    if( f->getstatus() == 1 && !this->check_special_amount() )
        return -3;

    return 1;

}

string character::attack( int select_formulas_number , class character *attacked_character ){

    string s = "";

    class formulas *f = NULL;

    f = this->vformulas[select_formulas_number-1];

    this->mp -= f->getmp_amount();
    if( f->getstatus() == 1 )
        this->special_amount -= 6;
    attacked_character->attacked( f->getattack_amount() );
    attacked_character->setspecial_amount( attacked_character->getspecial_amount() + 1 );

    s = this->getname() + " using " + f->getname() + " to attack " + attacked_character->getname() + "\n";
    if( this->attack_str != "" )
        s += this->attack_str + "\n";
    s += "\n";

    s += attacked_character->getname() + " was " + turn_int_to_string( f->getattack_amount() ) + " damage\n";
    if( attacked_character->getattacked_str() != "" )
        s += attacked_character->getattacked_str() + "\n";
    if( attacked_character->gethp() <= 0 && attacked_character->getdead_str() != "" )
        s += attacked_character->getdead_str() + "\n";

    return s;

}

void character::attacked( int attacked_amount ){

    this->hp -= attacked_amount;
    this->hp = this->hp < 0 ? 0 : this->hp;
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

string character::attack_info( int status ){

    if( status == -1 )
        return "select error number";
    else if( status == -2 )
        return "";
    return "";
}

string character::attacked_info( ){
    return "";
}

bool character::check_hp(){
    return hp > 0;
}

bool character::check_mp( int use_mp_amount ){
    return this->mp >= use_mp_amount;
}

bool character::check_special_amount(){
    return this->special_amount >= 6;
}


