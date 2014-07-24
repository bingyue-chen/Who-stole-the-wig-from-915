/******************************
***  Update: 2014/07/24     ***
***  By: snowcookie         ***
******************************/

#ifndef __CHARACTER_BASIC_H__
#define __CHARACTER_BASIC_H__

#include <vector>
#include <string>

class character{

private:

    string name,description;
    int hp,mp;
    vector<formulas> vformulas;
    bool check_hp();
    bool check_mp( int use_mp_amount );

public:

    void character();
    void character( string name );
    void character( string name , int hp , int , mp );

    void setname( string name );
    void setdescription( string description );
    void sethp( int hp );
    void setmp( int mp );
    void setformulas( vector<formulas> vformulas );

    string getname();
    string getname();
    int gethp();
    int getmp();
    vector<formulas> getformulas();

    int attack( int select_formulas_number );
    int attacked( int attacked_amount );
}

class formulas{

private:

    string name,description;
    int attack_amount,mp_amount;

public:

    void formulas();
    void formulas( string name );
    void formulas( string name , int attack_amount , int mp_amount );

    void setname( string name );
    void setdescription( string description );
    void setattack_amount( int attack_amount );
    void setmp_amount( int mp_amount );

    string name

};

#endif
