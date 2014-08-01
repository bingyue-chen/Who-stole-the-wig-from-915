/******************************
***  Update: 2014/07/29     ***
***  By: snowcookie         ***
******************************/

#include "character_database.h"

/***** init *****/
character_database::character_database(){
    this->charater_size = 0;
}

/***** des *****/
character_database::~character_database(){
    for( unsigned int i = 0 ; i < this->vcharacter.size() ; i++ )
        delete this->vcharacter[i];
}

/***** get *****/

int character_database::get_charater_size(){
    return this->charater_size;
}

/***** functional *****/

int character_database::read_character_data(){

    if( !read_whole_file_to_stringstream( this->ss , "../data/character.txt" ) )
        return -1;

    while( ss.good() ){
        this->vcharacter.push_back( this->read_character() );
    }

    this->charater_size = this->vcharacter.size();

    return 1;
}

character* character_database::read_character( ){

    class character *c;
    class formulas *f;
    string name,description,attack_str,attacked_str,dead_str;
    int number,hp,mp,normal_attack_amount,status,attack_amount,mp_amount;
    char cc;

    ss >> number;
    ss.get( cc );
    getline( ss , name );
    getline( ss , description );
    ss >> hp >> mp >> normal_attack_amount;
    ss.get( cc );
    getline( ss , attack_str );
    getline( ss , attacked_str );
    getline( ss , dead_str );

    c = new character( number , name , description , hp , mp , normal_attack_amount );
    c->setattack_str( attack_str );
    c->setattacked_str( attacked_str );
    c->setdead_str( dead_str );

    while( ss.good() && getline( ss , name ) && name.compare("") != 0 ){

        getline( ss , description );
        ss >> status >> attack_amount >> mp_amount;
        ss.get( cc );

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
