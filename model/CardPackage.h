/*********************************
*     Last modified:2014/8/3     *
*********************************/
#ifndef CARDPACKAGE_H_INCLUDED
#define CARDPACKAGE_H_INCLUDED

#include "character_basic.h"
#include "formulas.h"
#include "function.h"
#include <iostream>
#include <vector>

class FightingTeam{
    private:
        character* card_1;
        character* card_2;
        character* card_3;
    public:
        FightingTeam();
        ~FightingTeam();
        void setCard_1(character* card);
        void setCard_2(character* card);
        void setCard_3(character* card);
        character* getCard_1();
        character* getCard_2();
        character* getCard_3();
        void showCardInfo(int i);
        void showFightingCardsName();

};

class CardPackage{
    private:
        class FightingTeam fighting_team;
        vector<character*> card_group;
    public:
        /*
            --Main tool--
            void seeOneCardInfo()       : see the card info, the card will be selected in this function.
            void changeCard()           : two way to change cards in fighting team.
                                            1) Change all cards in fighting team
                                            2) Only change one card in fighting team
            void addNewCard()           : add new card into card_group.
        */
        CardPackage();
        ~CardPackage();
        void addNewCard(character* new_card);
        void changeCard();
        void setFightingTeam();
        void setOneFightingCard();
        void showCardsInPackage();
        void seeOneCardInfo();
        void showSelectedCardInfo(int i);
        void showCardsNotInFighting();
        void showTeam();
        bool IsInTeam(character* card);
};

#endif // CARDPACKAGE_H_INCLUDED
