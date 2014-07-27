/******************************
***  Update: 2014/07/27     ***
***  By: snowcookie         ***
******************************/

#ifndef __CHARACTER_DATABASE_H__
#define __CHARACTER_DATABASE_H__

#include "character_basic.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class character_database{

private:

    vector<character*> vcharacter;
    ifstream ifs;
    character* read_character( );
    bool check_file_open();
    int charater_size;

public:

    character_database();
    ~character_database();

    int read_character_data();
    character* get_character( int number );
    int get_charater_size();

};

#endif // __CHARACTER_DATABASE_H__

