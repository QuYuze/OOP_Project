#include <iostream>
#include "Character.h"
#include <windows.h>
using namespace std;
int game();

string battle(Player& player, Monster& monster, int attackfirst);


int main() {
    game();
    return 0;


}

int game(){
    cout << "Your name?" << endl;
    string name;
    cin >> name;
    Player p = Player(name);
    cout << "------------------------------------------------" << endl;
    cout << "|            Dragon Challenge Begin            |" << endl;

    Monster  m = Monster(p.getLevel());
    string input = "d";
    string result = "alive";
    int level = 1;
    while(input != "exit" && result != "dead" && level < 5) {
        Monster  m = Monster(p.getLevel());
        string runornot = "N";
        cout << "------------------------------------------------" << endl;
        cout << "               " << p.getName() << " meet " << m.getName() <<endl;
        p.appear();
        m.appear();
        cout << "Do you want to escape? (Enter 'Y' to escape)"<<endl;
        cin >> runornot;
        cout << endl;
        if(runornot == "Y") {
            if (p.flee()) {
                cout << "       You successfully run away" << endl;
                cout << "------------------------------------------------" << endl;
            } else{
                cout << "       Failed to run away, keeping fighting!" << endl;
                cout << "------------------------------------------------" << endl;
                result = battle(p,m,0);
            }
        } else{
            result = battle(p,m,1);
        }
        level = p.getLevel();
        if(result == "dead"){
            break;
        }else if(level >= 5){
            cout << "*******************************************" << endl;
            cout << "*                                         *" << endl;
            cout << "*  Congratulations! You WIN the monsters! *" << endl;
            cout << "*       You rescued the Princess!         *" << endl;
            cout << "*                                         *" << endl;
            cout << "*******************************************" << endl;
            break;
        }else{
            cout << "Do you want to continue? (Enter 'exit' to leave)" << endl;
            cin >> input;
            cout << endl;
        }
    }
    return 0;
}

string battle(Player& p, Monster& m, int attackfirst) {
    int isfinish = 1;
    string result = "alive";
    while (isfinish == 1) {
        if(attackfirst == 0) {
            m.attack(p);
            cout << p.getName() << " now have " << p.getHP() << " HP..." << endl;
            cout << endl;
            _sleep(1);
            if (p.getHP() <= 0) {
                cout << "------------------------------------------------" << endl;
                cout << "Your are defeated..." << endl;
                cout << "GAME OVER..." << endl;
                cout << "FAIL to rescue The Princess..." << endl;
                cout << "------------------------------------------------" << endl;
                result = "dead";
                break;
            }
            attackfirst++;
        }
        p.attack(m);
        cout << m.getName() << " now have " << m.getHP() << " HP!" << endl;
        cout << endl;
        _sleep(1);
        if (m.getHP() <= 0) {
            cout << "------------------------------------------------" << endl;
            cout << "       " << p.getName() << " killed the " << m.getName() << "!" << endl;
            cout << "           You are victorius!" << endl;
            cout << "------------------------------------------------" << endl;
            p.addExp(m.getBonus());
            isfinish = 0;
            result = "alive";
        } else {
            m.attack(p);
            cout << p.getName() << " now have " << p.getHP() << " HP..." << endl;
            cout << endl;
            if (p.getHP() <= 0) {
                cout << "------------------------------------------------" << endl;
                cout << "Your are defeated..." << endl;
                cout << "GAME OVER..." << endl;
                cout << "FAIL to rescue The Princess..." << endl;
                cout << "------------------------------------------------" << endl;
                isfinish = 2;
                result = "dead";
            }
        }
    }
    return result;
}
