/******************************
***  Update: 2014/07/27     ***
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
