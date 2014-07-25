/******************************
***  Update: 2014/07/25     ***
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
    int hp,mp,normal_attack_amount,special_amount;
    vector<formulas*> vformulas;
    class formulas* normal_attack;
    bool check_hp();
    bool check_mp( int use_mp_amount );
    bool check_special_amount();
    void attacked( int attacked_amount );

public:

    character( string name , string description , int hp , int mp , int normal_attack_amount );

    void setname( string name );
    void setdescription( string description );
    void sethp( int hp );
    void setmp( int mp );
    void setnormal_attack_amount( int normal_attack_amount );
    void setspecial_amount( int special_amount );

    string getname();
    string getdescription();
    int gethp();
    int getmp();
    int getnormal_attack_amount();
    int getspecial_amount();
    vector<formulas*> getformulas();

    void addformulas( formulas* f );
    int check_can_attack( int select_formulas_number );
    string attack( int select_formulas_number , class character *attacked_character );

    string get_character_info();
    string get_formulas_info();
    string attack_info( int status );
    string attacked_info( );
};

#endif // __CHARACTER_BASIC_H__
