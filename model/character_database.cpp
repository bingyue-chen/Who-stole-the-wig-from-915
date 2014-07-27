/******************************
***  Update: 2014/07/27     ***
***  By: snowcookie         ***
******************************/

#include "character_database.h"

/***** init *****/
character_database::character_database(){
    ifs.open( "../data/character.txt" , ifstream::in );
    this->charater_size = 0;
}

/***** des *****/
character_database::~character_database(){
    ifs.close();
    for( unsigned int i = 0 ; i < this->vcharacter.size() ; i++ )
        delete this->vcharacter[i];
}

/***** get *****/

int character_database::get_charater_size(){
    return this->charater_size;
}

/***** functional *****/

int character_database::read_character_data(){

    if( !this->check_file_open() )
        return -1;

    while( ifs.good() ){
        this->vcharacter.push_back( this->read_character() );
    }

    this->charater_size = this->vcharacter.size();

    return 1;
}

bool character_database::check_file_open(){
    return this->ifs.is_open();
}

character* character_database::read_character( ){

    class character *c;
    class formulas *f;
    string name,description,attack_str,attacked_str,dead_str;
    int number,hp,mp,normal_attack_amount,status,attack_amount,mp_amount;
    char cc;

    ifs >> number;
    ifs.get( cc );
    getline( ifs , name );
    getline( ifs , description );
    ifs >> hp >> mp >> normal_attack_amount;
    ifs.get( cc );
    getline( ifs , attack_str );
    getline( ifs , attacked_str );
    getline( ifs , dead_str );

    c = new character( number , name , description , hp , mp , normal_attack_amount );
    c->setattack_str( attack_str );
    c->setattacked_str( attacked_str );
    c->setdead_str( dead_str );

    while( ifs.good() && getline( ifs , name ) && name.compare("") != 0 ){

        getline( ifs , description );
        ifs >> status >> attack_amount >> mp_amount;
        ifs.get( cc );

        f = new class formulas( name , description , status , attack_amount , mp_amount );
        c->addformulas( f );
    }

    return c;
}

character* character_database::get_character( int number ){
    if( number > 0 && (unsigned int)number <= this->vcharacter.size() )
        return this->vcharacter[number-1];
    else
        return NULL;
}
