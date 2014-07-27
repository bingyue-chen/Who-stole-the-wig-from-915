#ifndef FIGHTING_H_INCLUDED
#define FIGHTING_H_INCLUDED

#include <character_basic>
#include <string>
#include <iostream>
#include <cstdio>
#include <ctime>

class fight
{
private:
    character boss;   /** boss info **/
    character cards[3]; /** cards info **/

    int boss_hp,challenger_hp; /** total hp **/
    int boss_mp,cards_mp[3]; /**  total mp **/
    int boss_current_hp,challenger_current_hp; /** current hp **/
    int num_of_attacking_card;
    clock_t startTime,endTime;

public:
    fight(character boss,character *card,int card_size);
    void setboss();
    void setchallenger();
    void set_attacking_card(int i);
    void set_fomula(int i);
    void set_answer(int i);

    void show_boss_info(); /** info : name  ,description , hp , mp , special_amount **/
    void show_challenger_info();

    void show_card_name(); /**  ex : ¥dµP¤@ : ¯äª¯ **/
    void show_card_info();
    void show_fomulas_of_card();

    void show_question();
    void show_answer();
    void show_boss_attack();
    void show_challenger_attack();
    void show_current_state();
    void show_looser(); /** show the losser's string **/

    bool IsTime_run_out();


    ~fight();
protected:

};


#endif // FIGHTING_H_INCLUDED
