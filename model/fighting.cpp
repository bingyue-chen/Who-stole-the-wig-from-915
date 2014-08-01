/******************************
***  Update: 2014/08/01     ***
***  By: bohunchen          ***
******************************/

#include "character_basic.h"
#include "function.h"
#include "fighting.h"

fight::fight(character* boss,character** card,int card_size){
    this->boss=boss;

    this->cards[0]=card[0];
    this->cards[1]=card[1];
    this->cards[2]=card[2];
}

void fight::setboss(){
    this->boss_hp=boss->gethp(); /** total hp **/
    this->boss_mp_cnt=boss->getmp(); /** mp **/
    this->boss_hp_cnt=boss_hp; /** hp_cnt **/
    this->boss_special_cnt=0; /** init the special to 0 **/
}

void fight::setchallenger(){
    this->challenger_hp=cards[0]->gethp()+cards[1]->gethp()+cards[2]->gethp();/** total hp **/
    this->challenger_hp_cnt=challenger_hp; /** hp_cnt **/

    this->cards_mp_cnt[0]=cards[0]->getmp(); /** mp of cards **/
    this->cards_mp_cnt[1]=cards[1]->getmp();
    this->cards_mp_cnt[2]=cards[2]->getmp();

    this->cards_special_cnt[0]=0; /** init the special to 0 **/
    this->cards_special_cnt[1]=0;
    this->cards_special_cnt[2]=0;
}

void fight::set_attacking_card(int i){
    if(i>=1&&i<=3)
        this->num_of_attacking_card=i;
    else
        cout<<"num_of_attacking error"<<endl;
}

void fight::set_fomula(int i){
    this->num_of_fomula=i;
}

void fight::set_answer(int i){
    this->num_of_challenger_answer=i;
}

void fight::set_question(int i){
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
}

void fight::show_boss_info(){
    cout<<boss->get_character_info()<<endl;
}

void fight::show_card_name(){
    for(int i=0;i<3;i++)
        cout<<"[Card "<<i+1<<"] : "<<cards[i]->getname()<<endl;
}

void fight::show_card_info(){
    cout<<cards[num_of_attacking_card]->get_character_info()<<endl;
}

void fight::show_formulas_of_card(){
    cout<<cards[num_of_attacking_card]->get_formulas_info()<<endl;
}

void fight::show_question(){
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
}

void fight::show_answer(){
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
}

int fight::getboss_num_of_fomula(){
    if( boss_hp_cnt>(0.5*boss_hp) )
        return 0;
    else return 1;
}

void fight::show_boss_attack(){
      /*[Boss] 對 [玩家] 使用 [攻擊招式]
               [玩家]受到____點傷害！*/
    string s = "";
    vector<formulas*> vformulas;
    class formulas *f = NULL;
    vformulas=boss->getformulas();

    f = vformulas[getboss_num_of_fomula()];

    boss_mp_cnt-= f->getmp_amount(); /** mp cost **/

    s = boss->getname() + " using " + f->getname() + " to attack you "+ "\n";  /** show attack info**/
    if( boss->getattack_str() != "" )
        s += boss->getattack_str() + "\n";
    s += "\n";

    s += "You were under attack by" + turn_int_to_string( f->getattack_amount() ) + " damage ! \n";

    challenger_hp_cnt-=f->getattack_amount() ;  /** the attacked hp of challenger**/
    if(challenger_hp_cnt<=0)
        challenger_hp_cnt=0;

    for(int i=0;i<3;i++){  /** cards_special_cnt +1 **/
        cards_special_cnt[i]++;
    }
}

void fight::show_challenger_attack(){
    string s = "";
    vector<formulas*> vformulas;
    class formulas *f = NULL;
    vformulas=cards[num_of_attacking_card-1]->getformulas();

    f = vformulas[num_of_fomula-1];

    cards_mp_cnt[num_of_attacking_card-1]-= f->getmp_amount();

    s = cards[num_of_attacking_card-1]->getname() + " using " + f->getname() + " to attack "+boss->getname()+ "\n";
    if( cards[num_of_attacking_card-1]->getattack_str() != "" )
        s += cards[num_of_attacking_card-1]->getattack_str() + "\n";
    s += "\n";

    s += boss->getname()+" were under attack by" + turn_int_to_string( f->getattack_amount() ) + " damage ! \n";

    boss_hp_cnt-= f->getattack_amount();  /** the attacked hp of boss **/
    if(boss_hp_cnt<=0)
        boss_hp_cnt=0;

    boss_special_cnt++; /** boss_special_cnt++ **/
}

void fight::show_looser(){
    if(boss_hp_cnt<=0)
        cout<<boss->getattack_str()<<endl;
    else if(challenger_hp_cnt<=0)
        cout<<"Challenger GG..."<<endl;
}

void fight::show_reward(){
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
}

void fight::show_current_state(){
    cout<<"[" << boss->getname() << "]  HP : "<< boss_hp_cnt<<+ "  MP :　"<<boss_mp_cnt<<" Special amount : "<<boss_special_cnt<<"\n";
    cout<<"[challenger]  HP : "<<challenger_hp_cnt<<"\n";
    if(IsBossGG()||IsChallengerGG())
        show_looser();
}

bool fight::IsBossGG(){
    return (boss_hp_cnt<=0);
}

bool fight::IsChallengerGG(){
    return (challenger_hp_cnt<=0);
}
bool fight::IsBossFull(){
    return (boss_special_cnt==boss->getspecial_amount());
}
bool fight::IsCardsFull(int i){
    if(cards_special_cnt[i]==cards[i]->getspecial_amount())
        return true;
    return false;
}
bool fight::IsTime_run_out(){
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
}
bool fight::IsAC(){
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
    /** waiting to complete **/
}
