#include <stdlib.h>
#include "Adventure.h"
#include "Enemy.h"
using namespace std;

int main() {

    Weapon nullWeapon("", 0, false);
    Weapon stick("stick", 1, false);
    Weapon stone("stone", 2, true);
    Weapon shield("shield", 1, false);
    Weapon healingPotion("healing potion", 0, true);
    Weapon sword("sword", 3, false);
    Weapon gun("gun", 10, false);

    Enemy rat("Rat", 5.0, 1.0, {stone, stone, healingPotion});
    Enemy wolf("wolf", 8.0, 2.5, {sword, healingPotion});
    Enemy monkey("monkey", 6.0, 1.5, {stone, stone, shield});
//    Enemy zubeldia("daniel", 10, 3, healingPotion, healingPotion, gun);

    double link_hp = 20.0;
    vector<Weapon> link_inventory = {stick, stone, stone};

    Adventure adventure;

    vector<Enemy> enemyList = {rat, wolf, monkey};



//    while (link_hp > 0.0) {
//        srand(time(0));
//        int randInt = rand() % 3;
//        if (randInt >= 0 && randInt <= 3) {
//            Enemy randomEnemy = enemyList.at(randInt);
//            randomEnemy.FightEnemy(link_hp, link_inventory);
//        }
//    }

    return 0;
}
