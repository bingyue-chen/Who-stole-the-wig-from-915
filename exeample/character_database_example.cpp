#include <iostream>
#include "character_database.h"

using namespace std;

int main(){

    class character_database cd;
    class character *c;

    cd.read_character_data();

    cout << cd.get_charater_size() << " card(s)." << endl << endl;

    for( int i = 1 ; i <= cd.get_charater_size() ; i++ ){
        c = cd.get_character( i );
        cout << c->get_character_info() << endl;
        cout << c->get_formulas_info() << endl;
    }

    return 0;
}
