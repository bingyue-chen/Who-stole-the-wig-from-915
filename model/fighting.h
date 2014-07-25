#ifndef FIGHTING_H_INCLUDED
#define FIGHTING_H_INCLUDED

#include <character_basic>
#include <string>

class fight
{
private:
    character boss;   /** boss info **/
    character cards[3]; /** cards info **/
    int boss_hp,cards_hp; /** cards_hp mean the total hp of three cards **/
public:
    fight(character boss,character *card,int card_size);
    void setboss();
    void setcards();
    void sethp_boss();
    void sethp_cards();
    ~fight();
protected:

};


#endif // FIGHTING_H_INCLUDED
