/*********************************
*     Last modified:2014/8/5     *
*********************************/
#ifndef CARDPACKAGE_H_INCLUDED
#define CARDPACKAGE_H_INCLUDED

#include "character_basic.h"
#include "character_database.h"
#include "formulas.h"
#include "function.h"
#include <iostream>
#include <vector>
#include <sstream>

class FightingTeam{
    private:
        character* card[3];
    public:
        FightingTeam();
        ~FightingTeam();
        void setCard_1(character* card);
        void setCard_2(character* card);
        void setCard_3(character* card);
        character* getCard_1();
        character* getCard_2();
        character* getCard_3();
        void showFightingCardsName();

};

class CardPackage{
    private:
        class FightingTeam fighting_team;
        vector<int> card_group;//store the card's number
        class character_database* card_db;
    public:
        /*
            --Main tool--
            void seeOneCardInfo()       : see the card info, the card will be selected in this function.
            void changeCard()           : two way to change cards in fighting team.
                                            1) Change all cards in fighting team
                                            2) Only change one card in fighting team
            void addNewCard()           : add new card into card_group.

            [Remenber]
                Before using changeCard() to change ONE card, player should already set up fighting team.
                Use setFightingTeam() can set all cards in the team.
                The initial number of cards to set fighting team up must >= 3.
        */
        CardPackage(class character_database* db);
        ~CardPackage();
        void addNewCard(int card_number);//add card's number
        void changeCard();
        void setFightingTeam();
        void setOneFightingCard();
        void showCardsInPackage();
        void seeOneCardInfo();
        void showSelectedCardInfo(int i);//use card_db to find the selected card info
        void showCardsNotInFighting();
        void showTeam();
        bool IsInTeam(int i);
        bool IsRemainNumberInCardGroup(int i);
        character* getCardInDB(int number_in_card_group);
};

bool IsTwoNumberTheSame(int n1,int n2, int n3);

#endif // CARDPACKAGE_H_INCLUDED
