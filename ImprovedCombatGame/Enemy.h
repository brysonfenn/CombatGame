//
// Created by Bryson Fenn on 4/15/20.
//
#include <string>
#include "Weapon.h"
#include <vector>
using namespace std;

#ifndef IMPROVEDCOMBATGAME_ENEMY_H
#define IMPROVEDCOMBATGAME_ENEMY_H


class Enemy {
public:
    Enemy(string name, double hp, double power, vector<Weapon>rewards);
    void UseWeapon(Weapon weapon, double& link_hp, vector<Weapon>& link_inventory, double tempHP);
    void GiveRewards(vector<Weapon>& link_inventory);
    void FightEnemy(double& link_hp, vector<Weapon>& link_inventory);
private:
    string name;
    double hp;
    double power;
    vector<Weapon> rewards;
    Weapon rew1 = Weapon("", 0, false);
    Weapon rew2 = Weapon("", 0, false);
    Weapon rew3 = Weapon("", 0, false);
    bool swordUsed = false;
};


#endif //IMPROVEDCOMBATGAME_ENEMY_H
