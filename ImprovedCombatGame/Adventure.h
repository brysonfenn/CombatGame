//
// Created by Bryson Fenn on 4/15/21.
//

#ifndef IMPROVEDCOMBATGAME_ADVENTURE_H
#define IMPROVEDCOMBATGAME_ADVENTURE_H

#include <iostream>
#include "Enemy.h"
using namespace std;

class Adventure {
public:
    Adventure();

    vector<Weapon> inventory;
    double hp = 20.0;
    string userString;
    set<string> optionSet;
    string endingString = "Good Game";

    void printInventory();
    string getValidString(string request, string options);
    void adventure1();
    void leftpath1();
    void rightpath1();




    //Weapons
    Weapon nullWeapon = Weapon("", 0, false);
    Weapon stick = Weapon("stick", 1.5, false);
    Weapon stone = Weapon("stone", 3, true);
    Weapon shield = Weapon("shield", 1, false);
    Weapon healingPotion = Weapon("healing potion", 0, true);
    Weapon sword = Weapon("sword", 5, false);
    Weapon gun = Weapon("gun", 10, false);

    //Enemies
    Enemy rat = Enemy("Rat", 5.0, 1.0, {stone, healingPotion});
    Enemy wolf = Enemy("Wolf", 8.0, 2.5, {sword, healingPotion});
    Enemy monkey = Enemy("Monkey", 6.0, 1.5, {stone, stone, shield});
    Enemy goblin = Enemy("Goblin", 10, 3, {sword, healingPotion});
private:

};


#endif //IMPROVEDCOMBATGAME_ADVENTURE_H
