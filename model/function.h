/******************************
***  Update: 2014/08/06     ***
***  By: snowcookie         ***
******************************/

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <sstream>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;

string turn_int_to_string( int n );
int turn_int_to_string( string s );
bool read_whole_file_to_stringstream( stringstream &ss , const char* filepath );
bool check_string_is_number( const string& s );

#endif // __FUNCTION_H__
