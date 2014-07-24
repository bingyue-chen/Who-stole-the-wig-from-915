/******************************
***  Update: 2014/07/24     ***
***  By: snowcookie         ***
******************************/

#ifndef __FORMULAS_H__
#define __FORMULAS_H__

#define init_int 0
#define init_string ""

#include <vector>
#include <string>

using namespace std;

class formulas{

private:

    string name,description;
    int status,attack_amount,mp_amount;

    /*****
        status:
                0 : normal formulas
                1 : special formulas
    *****/

public:

    formulas();
    formulas( string name );
    formulas( string name , int attack_amount , int mp_amount );

    void setname( string name );
    void setdescription( string description );
    void setattack_amount( int attack_amount );
    void setmp_amount( int mp_amount );
    void setstatus( int status );

    string getname();
    string getdescription();
    int getattack_amount();
    int getmp_amount();
    int getstatus();

    string get_formulas_info();

};

#endif // __FORMULAS_H__

