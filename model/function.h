/******************************
***  Update: 2014/07/29     ***
***  By: snowcookie         ***
******************************/

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <sstream>
#include <string>
#include <fstream>

using namespace std;

string turn_int_to_string( int n );
int turn_int_to_string( string s );
bool read_whole_file_to_stringstream( stringstream &ss , const char* filepath );

#endif // __FUNCTION_H__
