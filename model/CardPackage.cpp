/*********************************
*     Last modified:2014/8/5     *
*********************************/

#include "CardPackage.h"

FightingTeam::FightingTeam(){}
FightingTeam::~FightingTeam(){}

void FightingTeam::setCard_1(character* card){
    this->card[0] = card;
}

void FightingTeam::setCard_2(character* card){
    this->card[1] = card;
}

void FightingTeam::setCard_3(character* card){
    this->card[2] = card;
}

character* FightingTeam::getCard_1(){
    return this->card[0];
}

character* FightingTeam::getCard_2(){
    return this->card[1];
}

character* FightingTeam::getCard_3(){
    return this->card[2];
}

void FightingTeam::showFightingCardsName(){
    cout << "Current fighting cards:" << endl;
    cout << "\t1." << this->card[0]->getname() << endl;
    cout << "\t2." << this->card[1]->getname() << endl;
    cout << "\t3." << this->card[2]->getname() << endl;
    cout << endl;
}

CardPackage::CardPackage(class character_database* db){
    this->card_db = db;
}

CardPackage::~CardPackage(){}

void CardPackage::addNewCard(int card_number){
    this->card_group.push_back(card_number);
}

void CardPackage::changeCard(){
    int mode;

    cout << "Please select how to set your fighting team:" << endl;
    cout << "\t" << "1.Replace all" << "\t" << "2.Change only one" << endl;
    cout << "Mode:";
    cin >> mode;
    cout <<endl;

    if(mode == 1)
        this->setFightingTeam();
    else if(mode == 2)
        this->setOneFightingCard();
    else{
        cout << "Sorry... Input mode error!" << endl;
        cout << "Please enter 1 or 2." << endl;
        return;
    }
    this->showTeam();
}

void CardPackage::setFightingTeam(){
    int c1, c2, c3;
    character* card;

    this->showCardsInPackage();
    cout << "Select 3 cards you want, and input their number." << endl;
    cout << "Fighting Card 1:";
    cin >> c1;
    cout << "Fighting Card 2:";
    cin >> c2;
    cout << "Fighting Card 3:";
    cin >> c3;
    cout << endl;

    if(!IsTwoNumberTheSame(c1, c2, c3)){
        cout << "Sorry! At least two of the number you input are the same..." << endl;
        cout << "Please input three numbers which are different from each other." << endl;
    }
    else{
        //Set card[0] in fighting team
        card = this->getCardInDB(c1-1);
        this->fighting_team.setCard_1(card);

        //Set card[1] in fighting team
        card = this->getCardInDB(c2-1);
        this->fighting_team.setCard_2(card);

        //Set card[2] in fighting team
        card = this->getCardInDB(c3-1);
        this->fighting_team.setCard_3(card);
    }
}

void CardPackage::setOneFightingCard(){
    int number_in_card_group, replace_number;
    character* card;

    this->fighting_team.showFightingCardsName();
    cout << "Which card to be replaced:";
    cin >> replace_number;

    this->showCardsNotInFighting();
    cout << "Which card to go fighting:";
    cin >> number_in_card_group;

    if(this->IsRemainNumberInCardGroup(number_in_card_group))
        card = this->getCardInDB(number_in_card_group-1);
    else{
        //player doesn't input at the correct range, print error message and return directly.
        cout << "Error! Please input the remain card's number which is not in fighting team." << endl;
        return;
    }

    if(replace_number == 1)
        this->fighting_team.setCard_1(card);
    else if(replace_number == 2)
        this->fighting_team.setCard_2(card);
    else if(replace_number == 3)
        this->fighting_team.setCard_3(card);
    else
        cout << "Error! Please input correct number 1, 2 or 3." << endl;
}

void CardPackage::showCardsInPackage(){
    character* card;

    cout << "Cards in Package:" << endl;
    for(unsigned int i=1; i <= this->card_group.size(); i++){
        card = this->getCardInDB(i-1);
        cout << i << ". " << card->getname() << endl;
    }
}

void CardPackage::showCardsNotInFighting(){
    character* card;

    cout << "Cards in Package(without cards in fighting team):" << endl;
    for(unsigned int i=1; i <= this->card_group.size(); i++){
        if(this->IsInTeam(i-1))
            continue;
        else{
            card = this->getCardInDB(i-1);
            cout << "\t" << i << ". " << card->getname() << endl;
        }
    }
}

bool CardPackage::IsInTeam(int i){
    character* card = this->getCardInDB(i);

    if(card == this->fighting_team.getCard_1())
        return true;
    else if(card == this->fighting_team.getCard_2())
        return true;
    else if(card == this->fighting_team.getCard_3())
        return true;
    else
        return false;
}

void CardPackage::seeOneCardInfo(){
    int number;

    this->showCardsInPackage();
    cout << "Which card's information you want to see?" << endl;
    cout << "Card number:";
    cin >> number;

    if((1 <= number) && ((unsigned int)number <= this->card_group.size()))
        this->showSelectedCardInfo(number-1);
    else
        cout << "Error! Please input correct number." << endl;
}

void CardPackage::showSelectedCardInfo(int i){
    character* card = this->getCardInDB(i);

    cout << card->get_character_info() << endl;
    cout << card->get_formulas_info() << endl;
}

void CardPackage::showTeam(){
    this->fighting_team.showFightingCardsName();
}

character* CardPackage::getCardInDB(int number_in_card_group){
    int card_number = this->card_group.at(number_in_card_group);//get card's number
    character* card = this->card_db->get_character(card_number);//get selected card

    return card;
}

bool CardPackage::IsRemainNumberInCardGroup(int i){
    //test if i is in the range of the card_group's size
    if(! ((0 <= i) && ((unsigned int)i < this->card_group.size()) ))
        return false;

    if(i == this->fighting_team.getCard_1()->getnumber())
        return false;
    else if(i == this->fighting_team.getCard_2()->getnumber())
        return false;
    else if(i == this->fighting_team.getCard_3()->getnumber())
        return false;
    else
        return true;
}

bool IsTwoNumberTheSame(int n1, int n2, int n3){
    if(n1 == n2)
        return false;
    else if(n1 == n3)
        return false;
    else if(n2 == n3)
        return false;
    else
        return true;
}
