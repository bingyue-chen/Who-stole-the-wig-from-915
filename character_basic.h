/******************************
***  Update: 2014/07/24     ***
***  By: snowcookie         ***
******************************/

#ifndef __CHARACTER_BASIC_H__
#define __CHARACTER_BASIC_H__

#define init_int 0
#define init_string ""

#include <vector>
#include <string>

using namespace std;

class formulas{

private:

    string name,description;
    int attack_amount,mp_amount;

public:

    formulas();
    formulas( string name );
    formulas( string name , int attack_amount , int mp_amount );

    void setname( string name );
    void setdescription( string description );
    void setattack_amount( int attack_amount );
    void setmp_amount( int mp_amount );

    string getname();
    string getdescription();
    int getattack_amount();
    int getmp_amount();

    string get_formulas_info();

};

class character{

private:

    string name,description;
    int hp,mp;
    vector<formulas> vformulas;
    bool check_hp();
    bool check_mp( int use_mp_amount );

public:

    character();
    character( string name );
    character( string name , int hp , int , int mp );

    void setname( string name );
    void setdescription( string description );
    void sethp( int hp );
    void setmp( int mp );
    void setformulas( vector<formulas> vformulas );

    string getname();
    string getdescription();
    int gethp();
    int getmp();
    vector<formulas> getformulas();

    int attack( int select_formulas_number );
    int attacked( int attacked_amount );

};

#endif // __CHARACTER_BASIC_H__
