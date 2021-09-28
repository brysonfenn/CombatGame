
#include "Adventure.h"

Adventure::Adventure() {
//    Enemy zubeldia("daniel", 10, 3, healingPotion, healingPotion, gun);
    try {
        adventure1();
    }
    catch(string endString) {cout << endString << endl;}
    cout << "The End" << endl;
}

void Adventure::adventure1() {
    cout << "Welcome to my Universe" << endl << "Here you will battle monsters and learn to survive, if you can." << endl;
    cout << "You suddenly find yourself in a dark room full of objects. A couple of them catch your eye. ";
    optionSet.clear(); optionSet.insert("a"); optionSet.insert("b");
    userString = getValidString("Do you grab:", "a) Stick b) Stones");

    if (userString == "a") {inventory.push_back(stick);}
    else if (userString == "b") {inventory.push_back(stone);inventory.push_back(stone);inventory.push_back(stone);}
    printInventory();
    rat.FightEnemy(hp,inventory);
    cout << endl << "Great Job. You have now learned how to fight. Each enemy will give you rewards. " << endl <<
            "You will meet deadlier enemies and you will acquire more powerful weapons as time goes on." << endl;
    if (inventory[0].GetName() != "stick") {
        cout << "After fighting that rat, you realize you can still pick up the stick." << endl;
        inventory.push_back(stick);
    }
    printInventory();
    userString = getValidString("Did you have fun?","a) Yes b) No");

    if (userString == "a") {cout << "Great!";}
    else if (userString == "b") {cout << "That's too bad!";} cout << endl;
    cout << endl << "Suddenly, something big and loud jumps in through a window!" << endl;
    cout << "Hit any key and press enter to continue." << endl; cin >> userString;
    monkey.FightEnemy(hp,inventory);
    cout << endl << "Your shield will neutralize all enemy attacks so that both you and your enemy lose 1 HP." << endl;
    cout << endl << "Walking outside, you find yourself with an option of two roads. ";
    userString = getValidString("Do you choose:","a) The Left Path, b) The Right Path");

    if (userString == "a") {leftpath1();}
    else if (userString == "b") {rightpath1();}
}

void Adventure::leftpath1() {
    cout << endl << "You decide you should take the left path, which leads you for about a mile, " << endl
        << "when you begin hearing voices growing louder and louder, but you see no one." << endl;
    cout << "Suddenly, something big and green jumps in front of you!" << endl;
    cout << "Hit any key and press enter to continue." << endl; cin >> userString;
    goblin.FightEnemy(hp,inventory);
    if (hp <= 0) {throw endingString;}
    cout << endl << "Wow. That was frightening, but great job!" << endl;
    cout << "You now have a sword. This is a powerful weapon that can defeat enemies quickly, but " << endl
        << "it can only be used once per round" << endl;
    cout << "Wait... There's another one!" << endl;
    cout << "Hit any key and press enter to continue." << endl; cin >> userString;
    goblin.FightEnemy(hp,inventory);
    if (hp <= 0) {throw endingString;}
}

void Adventure::rightpath1() {
    cout << endl << "You begin walking but after about five hours, you realize this path will lead you nowhere " << endl
        << "exciting, and you decide to turn back." << endl;
    cout << "Hit any key and press enter to continue." << endl; cin >> userString;
    leftpath1();
}


void Adventure::printInventory() {
    cout << "Your Inventory: ";
    for (size_t i = 0; i < inventory.size(); i++) {
        cout << inventory.at(i).GetName();
        if (i != inventory.size()-1) {cout << ", ";}
    }
    cout << endl;
}

string Adventure::getValidString(string request, string options) {
    do {
        cout << request << endl << options << endl;
        getline(cin, userString);
        if (optionSet.find(userString) == optionSet.end()) {
            cout << "Please enter a valid string." << endl;
        }
    } while (optionSet.find(userString) == optionSet.end());
    return userString;
}

