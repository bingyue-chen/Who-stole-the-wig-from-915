/******************************
***  Update: 2014/07/29     ***
***  By: snowcookie         ***
******************************/

#include "function.h"

/***** By snowcookie *****/
string turn_int_to_string( int n ){
    stringstream ss;
    string s = "";
    ss << n;
    ss >> s;
    return s;
}

int turn_string_to_int( string s ){
    stringstream ss;
    int n = 0;
    ss << s;
    ss >> n;
    return n;
}

bool read_whole_file_to_stringstream( stringstream &ss , const char* filepath ){

    ifstream in( filepath );

    if( in.fail() )
            return false;

    ss << in.rdbuf();

    in.close();

    return true;
}
