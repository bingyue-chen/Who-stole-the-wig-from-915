/******************************
***  Update: 2014/08/06     ***
***  By: bohunchen          ***
******************************/

#ifndef FIGHTING_H_INCLUDED
#define FIGHTING_H_INCLUDED
#include "QuizModule.h"
#include "character_basic.h"
#include "function.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <thread>
#include <conio.h>
#include <chrono>

static bool flag;

class fight
{
private:

    character* boss;   /** boss info **/
    character* cards[3]; /** cards info **/
    Quiz* quiz;

    int boss_hp,challenger_hp; /** total hp **/
    int boss_mp_cnt,cards_mp_cnt[3]; /**  current mp **/
    int boss_hp_cnt,challenger_hp_cnt; /** current hp **/

    int num_of_attacking_card;
    int num_of_fomula;
    int num_of_challenger_answer;

    int boss_special_cnt,cards_special_cnt[3];



public:

    fight(character* boss,character* card[3],int card_size);
    void setboss();
    void setchallenger();
    void setquiz();

    void set_attacking_card(int i);
    void set_fomula(int i); /**  pass range 1 ~ formula.size()**/

    void show_boss_info(); /** info : name  ,description , hp , mp , special_amount **/
    void show_challenger_info();

    void show_card_name();
    bool show_card_info(int num_of_cards);
    bool show_formulas_of_card(int num_of_cards);

    void show_question();
    void show_answer();
    void show_boss_attack();
    bool show_challenger_attack();  /**  False means mp not enough ,and you have to choose formula again.**/

    void show_current_state();

    void show_loser(); /** show the loser's string **/
    void show_reward();

    int getboss_num_of_formulas();

    void next_problem();


    bool IsBossGG();
    bool IsChallengerGG();
    bool IsBossFull();
    bool IsCardsFull(int i);


    ~fight();
protected:

};

void counting_func(int n);
char waiting_answer();

#endif // FIGHTING_H_INCLUDED
