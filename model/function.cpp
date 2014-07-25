/******************************
***  Update: 2014/07/24     ***
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
