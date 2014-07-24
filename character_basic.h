/******************************
***  Update: 2014/07/24     ***
***  By: snowcookie         ***
******************************/

#ifndef __CHARACTER_BASIC_H__
#define __CHARACTER_BASIC_H__

#include "formulas.h"
#include <vector>
#include <string>

using namespace std;

class character{

private:

    string name,description;
    int hp,mp,normal_attack,special_amount;
    vector<formulas> vformulas;
    bool check_hp();
    bool check_mp( int use_mp_amount );
    bool check_special_amount();

public:

    character( string name , string description , int hp , int mp , int normal_attack );

    void setname( string name );
    void setdescription( string description );
    void sethp( int hp );
    void setmp( int mp );
    void setnormal_attack( int normal_attack );
    void setspecial_amount( int special_amount );

    string getname();
    string getdescription();
    int gethp();
    int getmp();
    int getnormal_attack();
    int getspecial_amount();
    vector<formulas> getformulas();

    void addformulas( formulas f );
    int attack( int select_formulas_number );
    int attacked( int attacked_amount );

    string print_formulas();
    string print_attack();
    string print_attacked();
    string print_formulas_info();

};

#endif // __CHARACTER_BASIC_H__
