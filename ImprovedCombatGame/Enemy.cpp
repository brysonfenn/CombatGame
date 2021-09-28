#include <iostream>
#include "Enemy.h"
using namespace std;

void DeleteExtraItems(vector<Weapon>& link_inventory);

void PrintLinkInventory(vector<Weapon> link_inventory) {
    cout << "Your inventory: ";
    for (long unsigned int i = 0; i < link_inventory.size(); i++) {
        cout << link_inventory.at(i).GetName();
        if (i < link_inventory.size() - 1) {cout << ", ";}
    }
    cout << endl;
}



Enemy::Enemy(string name, double hp, double power, vector<Weapon>rewards) {
    this->name = name;
    this->hp = hp;
    this->power = power;
    this->rewards=rewards;
    swordUsed = false;
}


void Enemy::UseWeapon(Weapon weapon, double &link_hp, vector<Weapon>& link_inventory,double tempHP) {
    this->hp -= weapon.GetPower();
    if (hp < 0) {
        this->hp = 0;
    }
    if (weapon.GetName() == "shield" || weapon.GetName() == "healing potion") {
        link_hp -= 1;
    }
    else {
        if (weapon.GetName() == "sword") {swordUsed = true;}
        link_hp -= power;
        if (link_hp < 0) {
            link_hp = 0;
        }
    }
    if (weapon.GetName() == "healing potion") {
        link_hp += 6;
        if (link_hp > 20.0) {
            link_hp = 20.0;
        }
    }
    cout << "Your HP: " << string(link_hp, '+') << string(20.0-link_hp,'_') << endl;
    cout << name << " HP: " << string(hp, '+') << string(tempHP-hp,'_') << endl;
    if (weapon.IsLimited()) {
        for (long unsigned int i = 0; i < link_inventory.size(); i++) {
            if (link_inventory.at(i).GetName() == weapon.GetName()) {
                link_inventory.erase(link_inventory.begin() + i);
                break;
            }
        }
    }
}


void Enemy::GiveRewards(vector<Weapon>& link_inventory) {
    cout << "Your rewards: ";
    for (size_t i = 0; i < rewards.size(); i++) {
        cout << rewards.at(i).GetName();
        if (i != rewards.size()-1) {cout << ", ";}
    }
    cout << endl;
    for (size_t i = 0; i < rewards.size(); i++) {
        link_inventory.push_back(rewards.at(i));
    }
    DeleteExtraItems(link_inventory);
    PrintLinkInventory(link_inventory);
}


void Enemy::FightEnemy(double& link_hp, vector<Weapon>& link_inventory) {
    double tempHP = hp;
    string userWeaponName;
    Weapon userWeapon("", -99.9, false);

    cout << endl << "You encounter a " << name << "." << endl << endl;
    cout << "Your HP: " << string(link_hp, '+') << string(20.0-link_hp,'_') << endl;
    cout << name << " HP: " << string(hp, '+') << string(tempHP-hp, '_') << endl << endl;

    while (hp > 0) {
        if (link_hp > 0) {
            PrintLinkInventory(link_inventory);
            cout << "Enter a weapon or tool to use: ";
            getline(cin, userWeaponName);
            if (userWeaponName == "sword" && swordUsed) {
                cout << "You already used the sword on this enemy." << endl; continue;}
            bool weaponFound = false;
            for (long unsigned int i = 0; i < link_inventory.size(); i++) {
                if (link_inventory.at(i).GetName() == userWeaponName) {
                    userWeapon = link_inventory.at(i);
                    weaponFound = true;
                    break;
                }
            }
            if (weaponFound) {
                UseWeapon(userWeapon, link_hp, link_inventory, tempHP);
            } else {
                cout << "Please enter a valid weapon or tool." << endl;
            }
        }
        else {
            cout << "YOU LOSE" << endl;
            break;
        }
    }

    if (hp <= 0 && link_hp > 0) {
        cout << "You killed the " << name << "." << endl;
        GiveRewards(link_inventory);
    } else if (hp <= 0 && link_hp <= 0){
        cout << "You and the " << name << " killed each other." << endl;
    }

    this->hp = tempHP;
}


void DeleteExtraItems(vector<Weapon>& link_inventory) {
    int swordCount = 0;
    int stickCount = 0;
    int shieldCount = 0;
    int stoneCount = 0;

    for (long unsigned int i = 0; i < link_inventory.size(); ++i) {
        if (link_inventory.at(i).GetName() == "sword") {
            swordCount++;
            if (swordCount > 1) {
                link_inventory.erase(link_inventory.begin() + i);
                i--;
            }
        }
        if (link_inventory.at(i).GetName() == "stick") {
            stickCount++;
            if (stickCount > 1) {
                link_inventory.erase(link_inventory.begin() + i);
                i--;
            }
        }
        if (link_inventory.at(i).GetName() == "shield") {
            shieldCount++;
            if (shieldCount > 1) {
                link_inventory.erase(link_inventory.begin() + i);
                i--;
            }
        }
        if (link_inventory.at(i).GetName() == "stone") {
            stoneCount++;
            if (stoneCount > 3) {
                link_inventory.erase(link_inventory.begin() + i);
                i--;
            }
        }
    }

}

