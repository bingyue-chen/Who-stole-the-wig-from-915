/*********************************
*     Last modified:2014/8/3     *
*********************************/

#include "CardPackage.h"

FightingTeam::FightingTeam(){}
FightingTeam::~FightingTeam(){}

void FightingTeam::setCard_1(character* card){
    this->card_1 = card;
}

void FightingTeam::setCard_2(character* card){
    this->card_2 = card;
}

void FightingTeam::setCard_3(character* card){
    this->card_3 = card;
}

character* FightingTeam::getCard_1(){
    return this->card_1;
}

character* FightingTeam::getCard_2(){
    return this->card_2;
}

character* FightingTeam::getCard_3(){
    return this->card_3;
}

void FightingTeam::showCardInfo(int i){
    character* c;

    if(i == 1)
        c = this->card_1;
    else if(i == 2)
        c = this->card_2;
    else if(i == 3)
        c = this->card_3;
    else{
        cout << "Sorry... Input number error!" << endl;
        cout << "Please enter 1, 2 or 3 next time." << endl;
        return;
    }

    cout << c->get_character_info() << endl;
}

void FightingTeam::showFightingCardsName(){
    cout << "Current fighting cards:" << endl;
    cout << "\t1." << this->card_1->getname() << endl;
    cout << "\t2." << this->card_2->getname() << endl;
    cout << "\t3." << this->card_3->getname() << endl;
    cout << endl;
}

CardPackage::CardPackage(){}
CardPackage::~CardPackage(){}

void CardPackage::addNewCard(character* new_card){
    this->card_group.push_back(new_card);
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

    this->showCardsInPackage();
    cout << "Select 3 cards you want, and input their number." << endl;
    cout << "Fighting Card 1:";
    cin >> c1;
    cout << "Fighting Card 2:";
    cin >> c2;
    cout << "Fighting Card 3:";
    cin >> c3;
    cout << endl;

    this->fighting_team.setCard_1(this->card_group.at(c1));
    this->fighting_team.setCard_2(this->card_group.at(c2));
    this->fighting_team.setCard_3(this->card_group.at(c3));
}

void CardPackage::setOneFightingCard(){
    int card_number, replace_number;
    character* card;

    this->fighting_team.showFightingCardsName();
    cout << "Which card to be replaced:";
    cin >> replace_number;

    this->showCardsNotInFighting();
    cout << "Which card to go fighting:";
    cin >> card_number;
    card = this->card_group.at(card_number);

    if(replace_number == 1)
        this->fighting_team.setCard_1(card);
    else if(replace_number == 2)
        this->fighting_team.setCard_2(card);
    else if(replace_number == 3)
        this->fighting_team.setCard_3(card);
    else
        cout << "Error! Please input correct number." << endl;
}

void CardPackage::showCardsInPackage(){
    cout << "Cards in Package:" << endl;

    for(int i=0; i < this->card_group.size(); i++)
        cout << i << ". " << this->card_group.at(i)->getname() << endl;
}

void CardPackage::showCardsNotInFighting(){
    cout << "Cards in Package(without cards in fighting team):" << endl;

    for(int i=0; i < this->card_group.size(); i++){
        if(this->IsInTeam(this->card_group.at(i)))
            continue;
        else
            cout << "\t" << i << ". " << this->card_group.at(i)->getname() << endl;
    }
}

bool CardPackage::IsInTeam(character* card){
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

    if((0 <= number) && (number < this->card_group.size()))
        this->showSelectedCardInfo(number);
    else
        cout << "Error! Please input correct number." << endl;
}

void CardPackage::showSelectedCardInfo(int i){
    cout << this->card_group.at(i)->get_character_info() << endl;
}

void CardPackage::showTeam(){
    this->fighting_team.showFightingCardsName();
}
