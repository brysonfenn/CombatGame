

#ifndef IMPROVEDCOMBATGAME_WEAPON_H
#define IMPROVEDCOMBATGAME_WEAPON_H
#include <set>
#include <list>
#include <string>
#include <ctime>
using namespace std;

class Weapon {
public:
    Weapon(string name, double power, bool limited);
    string GetName();
    double GetPower();
    bool IsLimited();

private:
    string name;
    double power;
    bool limited;
};


#endif //IMPROVEDCOMBATGAME_WEAPON_H
