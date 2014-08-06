/******************************
***  Update: 2014/08/06     ***
***  By: bohunchen          ***
******************************/

#include "fighting.h"


fight::fight(character* boss,character** card,int card_size){
    this->boss=boss;

    this->cards[0]=card[0];
    this->cards[1]=card[1];
    this->cards[2]=card[2];

    flag=true;
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

void fight::setquiz(){
    quiz= new class Quiz(boss->getname(),3);
}

void fight::set_attacking_card(int i){
    if(i>=1&&i<=3)
        this->num_of_attacking_card=i-1;
    else
        cout<<"num_of_attacking : error ! "<<endl;
}

void fight::set_fomula(int i){  /**  pass range 1 ~ formula.size()**/
    if( i>=1 && (unsigned int)i<cards[num_of_attacking_card]->getformulas().size() )
        this->num_of_fomula=i-1;
    else
        cout<<"set_formula error"<<endl;
}

void fight::show_boss_info(){
    cout<<boss->get_character_info()<<endl;
}

void fight::show_card_name(){
    for(int i=0;i<3;i++)
        cout<<"[Card "<<i+1<<"] : "<<cards[i]->getname()<<endl;
}

bool fight::show_card_info(int num_of_cards){
    if(num_of_cards>=1&&num_of_cards<=3){
        cout<<cards[num_of_cards-1]->get_character_info()<<endl;
        return true;
    }
    else{
        cout<<"show_card_info : error !"<<endl;
        return false;
    }
}

bool fight::show_formulas_of_card(int num_of_cards){
    if(num_of_cards>=1&&num_of_cards<=3){
        cout<<cards[num_of_cards-1]->get_formulas_info()<<endl;
        return true;
    }
    else{
        cout<<"show_formulas_of_card : error !"<<endl;
        return false;
    }
}

void fight::show_question(){
    quiz->showQuestionMessage();
}

int fight::getboss_num_of_formulas(){
    if(IsBossFull())
        return 2;
    else if( boss_hp_cnt>(0.5*boss_hp) )
        return 0;
    else return 1;
}

void fight::show_boss_attack(){

    string s = "";
    /*vector<formulas*> vformulas;
    vformulas=boss->getformulas();
    f = vformulas[getboss_num_of_formulas()];*/
    class formulas *f = NULL;

    f = ( boss->getformulas() )[getboss_num_of_formulas()];

    if( boss_mp_cnt < f->getmp_amount() ){  /** checking mp **/
        /*f=vformulas[0];*/
        f=( boss->getformulas() )[0];
    }
    if(getboss_num_of_formulas()==2){
        cout<<"[" << boss->getname() << "]  is out of control !!! "<<endl;
        boss_special_cnt=0;
    }

    boss_mp_cnt-= f->getmp_amount(); /** mp cost **/

    s = boss->getname() + " using " + f->getname() + " to attack you "+ "\n";  /** show attack info**/
    if( boss->getattack_str() != "" )
        s += boss->getattack_str() + "\n";
    s += "\n";

    s += "You were under attack by" + turn_int_to_string( f->getattack_amount() ) + " damage ! \n";

    cout<<s;

    challenger_hp_cnt-=f->getattack_amount() ;  /** the attacked hp of challenger**/
    if(challenger_hp_cnt<=0)
        challenger_hp_cnt=0;

    for(int i=0;i<3;i++){  /** cards_special_cnt +1 **/
        if(!IsCardsFull(i))
            cards_special_cnt[i]++;
    }

}

bool fight::show_challenger_attack(){   /**  False means mp not enough ,and you have to choose formula again.**/
    string s = "";
    /*vector<formulas*> vformulas;
    vformulas=cards[num_of_attacking_card-1]->getformulas();
    f = vformulas[num_of_fomula-1];*/
    class formulas *f = NULL;
    f=( cards[num_of_attacking_card-1]->getformulas() )[num_of_fomula-1];

    if(f->getstatus()==1){
        if(!IsCardsFull(num_of_attacking_card-1) ){   /**checking special**/
            cout<<"The special amount of cards isn't enough !";
            return false;
        }
        else{ /** Eruption ,and set special_cnt =0 **/
            cout<<"[" << cards[num_of_attacking_card]->getname() << "]  is angry now !!! "<<endl;
            cards_special_cnt[num_of_attacking_card]=0;
        }
    }
    else{
        if(f->getmp_amount()>cards_mp_cnt[num_of_attacking_card-1]){  /**checking mp**/
            cout<<"The mp of cards isn't enough !";
            return false;
        }
        cards_mp_cnt[num_of_attacking_card-1]-= f->getmp_amount(); /** mp cost **/
    }

    s = cards[num_of_attacking_card-1]->getname() + " using " + f->getname() + " to attack "+boss->getname()+ "\n"; /** attack info**/
    if( cards[num_of_attacking_card-1]->getattack_str() != "" )
        s += cards[num_of_attacking_card-1]->getattack_str() + "\n";
    s += "\n";

    s += boss->getname()+" were under attack by" + turn_int_to_string( f->getattack_amount() ) + " damage ! \n";

    cout<<s;

    boss_hp_cnt-= f->getattack_amount();  /**  hp of boss cost **/
    if(boss_hp_cnt<=0)
        boss_hp_cnt=0;
    if(!IsBossFull())
        boss_special_cnt++; /** boss_special_cnt++ **/
    return true;
}

void fight::show_loser(){
    if(boss_hp_cnt<=0)
        cout<<boss->getdead_str()<<endl;
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
    cout<<"[" << boss->getname() << "]  HP : "<< boss_hp_cnt<<+ "  MP :¡@"<<boss_mp_cnt<<" Special amount : "<<boss_special_cnt<<"\n";
    cout<<"[challenger]  HP : "<<challenger_hp_cnt<<"\n";
    for(int i=0;i<3;i++){
        cout<<"[" << cards[i]->getname() << "]  mp : "<<cards_mp_cnt[i]<<" Special amount : "<<cards_special_cnt[i]<<"\n";
    }
    if(IsBossGG()||IsChallengerGG())
        show_loser();
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
    if(cards_special_cnt[i]==cards[i]->getspecial_amount()){
        return true;
    }
    return false;
}

void counting_func(int n){
     while( flag && n-- ){
        cout << "now remain " << n << " secound(s)" << endl;
        this_thread::sleep_for (std::chrono::seconds(1));
    }
    flag = false;
}

char waiting_answer(){
    flag=true;
    char s='x';
    std::thread t(counting_func,10);
    while( flag ){
        if ( kbhit() != 0 ) {
            s = getch();
            cout<< s <<endl;
            flag = false;
        }
    }
    t.join();
    return s;
}

void fight::show_answer(){
   char c;
   c=waiting_answer();
   if(c=='x')  /** challenger didn't answer **/
        quiz->showAnswerResult(false);
   else
        quiz->showAnswerResult(c);
}

void fight::next_problem(){
    quiz->nextQuestion();
}
