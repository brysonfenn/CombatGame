//
// Created by Bryson Fenn on 4/15/20.
//

#include "Weapon.h"


Weapon::Weapon(string name, double power, bool limited) {
    this->name = name;
    this->power = power;
    this->limited = limited;
}

string Weapon::GetName() {
    return name;
}

double Weapon::GetPower() {
    return power;
}

bool Weapon::IsLimited() {
    return limited;
}

