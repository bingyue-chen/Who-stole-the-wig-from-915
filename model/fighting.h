/******************************
***  Update: 2014/07/28     ***
***  By: bohunchen          ***
******************************/

#ifndef FIGHTING_H_INCLUDED
#define FIGHTING_H_INCLUDED

#include <character_basic.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <ctime>

class fight
{
private:
    character* boss;   /** boss info **/
    character* cards[3]; /** cards info **/

    int boss_hp,challenger_hp; /** total hp **/
    int boss_mp_cnt,cards_mp_cnt[3]; /**  current mp **/
    int boss_hp_cnt,challenger_hp_cnt; /** current hp **/

    int num_of_attacking_card;
    int num_of_fomula;
    int num_of_challenger_answer;

    int boss_special_cnt,cards_special_cnt[3];

    clock_t startTime,endTime;

public:
    fight(character* boss,character* card[3],int card_size);
    void setboss();
    void setchallenger();

    void set_attacking_card(int i);
    void set_fomula(int i);

    /**  Unfinished part **/
    void set_question(int i);
    /**********************/

    void set_answer(int i);

    void show_boss_info(); /** info : name  ,description , hp , mp , special_amount **/
    void show_challenger_info();

    void show_card_name(); /**  ex : ¥dµP¤@ : ¯äª¯ **/
    void show_card_info();
    void show_formulas_of_card();

    void show_question();
    void show_answer();
    void show_boss_attack();
    void show_challenger_attack();
    void show_current_state();
    void show_special_power();
    void show_looser(); /** show the losser's string **/
    void show_reward();

    int getboss_num_of_fomula();


    bool IsTime_run_out();
    bool IsAC();
    bool IsBossGG();
    bool IsChallengerGG();
    bool IsBossFull();
    bool IsCardsFull(int i);

    ~fight();
protected:

};


#endif // FIGHTING_H_INCLUDED
