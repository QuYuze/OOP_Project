#include <iostream>
#include <string>
#include "Character.h"
#include <cstdlib>
#include <time.h>

///////////////////////////////Character///////////////////////////////
Character::Character(){}

Character::Character(string n, int max, int a){
	Character::name = n;
    Character::hitpoint = max;
    Character::damage = a;
    Character::MaxHP = max;  
}

void Character::appear() {}
void Character::action() {}

int Character::getDamage() const{
	return damage;
}

int Character::getHP() const {
	return hitpoint;
}

string Character::getName() const{
	return name;
}

int Character::getMaxHP() const{
	return MaxHP;
}

void Character::setDamage(int d){
    this->damage = d;
}
void  Character::setName(string s){
    this->name = s;
}
void Character::setMaxHP(int mhp){
    this->MaxHP = mhp;
}
void Character::setHP(int hp) {
    this->hitpoint = hp;
}
void Character::attack(Character & c){
}

///////////////////////////////Player///////////////////////////////
Player::Player(string s):Character(){
   setName(s);
   setHP(220);
   setMaxHP(220);
   setDamage(40);
   setDefence(10);
   level = 1;
   exp = 0;
}

void Player::appear() {
    cout << "Your current status: " << endl;
    cout << "MaxHP / Current HP: " << getMaxHP() << " / " << getHP() << endl;
    cout << "Power: " << getDamage() << endl;
    cout << "Defence: " << getDefence() << endl;
    cout << "Experience: " << exp << endl;
    cout << "Your now need " << 100 - exp << " to get to next level!" << endl;
    cout << "Your level " << level << " right now!" << endl;
    cout << "And ready for a new challange!" << endl;
    cout << endl;
}

void Player::action() {
    cout << getName() << " dealt " << getDamage() << " to the monster!" << endl;
}

void Player::setDefence(int df){
    this->defence = df;
}

int Player::getDefence(){
    return  defence;
}

int Player::getLevel() {
    return level;
}

void Player::attack(Monster & m){
    m.setHP(m.getHP()-getDamage());
    if(m.getHP() < 0){
        m.setHP(0);
    }
    action();
}
//level up, renew the attributes of the player depending on the current level
void Player::levelUp(int curLevel){
    cout << "Congratulations! You have leveled up!" << endl;
    level = curLevel + 1;
    setMaxHP(getMaxHP()+100);
    setHP(getMaxHP());
    setDamage(getDamage()+10);
    setDefence(getDefence()+10);
    exp -= 100;
    appear();
}
//add some exp to the character, level up if current exp exceeds 100
//call this function immediatly if the player successfully defeat the opponent
void Player::addExp(int bonus){
    exp += bonus;
    if(exp >= 100){
        levelUp(level);
    }
}

bool Player::flee() {
    srand((unsigned)time(NULL));
    return (rand()%100) > 50;
}

///////////////////////////////Monster///////////////////////////////
//set the attributes of the monster based on player's current level
Monster::Monster(int playerLevel) : Character(){
	int type = getType(playerLevel);
	/*
    setHP(20);
    setDamage(1);
    setMaxHP(20);
    setName("test dummy");
    bonus = 100;
    */
	setType(type);
}

void Monster::setType(int type) {
    setHP(MaxHpList[type]);
    setDamage(damageList[type]);
    setMaxHP(MaxHpList[type]);
    setName(nameList[type]);
    bonus = bonusList[type];
}

//return the monster type number:(1, 2, 3)
int Monster::getType(int playerLevel){
	int type = 0;
	int flag = getRandom();
	//cout << playerLevel << endl;
    if(playerLevel == 1){
        if(flag >= 1 && flag <= 9){
            type = 1;
        }else{
            type = 2;
        }
    }else if(playerLevel == 2){
        if(flag >= 1 && flag <= 2){
            type = 1;
        }else if(flag >= 3 && flag <= 9){
            type = 2;
        }else{
            type = 3;
        }
    }else if(playerLevel == 3) {
        if(flag == 1 ){
            type = 1;
        }else if(flag >= 2 && flag <= 4){
            type = 2;
        }else{
            type = 3;
        }
    }else if(playerLevel == 4){
        if(flag >= 1 && flag <= 3){
            type = 2;
        }else{
            type = 3;
        }
    }
	return type;	
}
void Monster::appear() {
    cout << getName() << " has appeared!" << endl;
    cout << "HP: " << getHP() << endl;
    cout << "Power: " << getDamage() << endl;
    cout << "Bonus experience: " << getBonus() << endl;
    cout << endl;
}

//the monster attack the player
void Monster::attack(Player & p){
	p.setHP(p.getHP()-(getDamage()-p.getDefence()));
    if(p.getHP() < 0){
        p.setHP(0);
    }
	action();
}

//a random generator
int Monster::getRandom(){
	srand((unsigned)time(NULL));
	return (rand()%10+1);
}

void Monster::action() {
    cout << getName() << " attack the Challenger with power of " << getDamage() << "!" << endl;
}

int Monster::getBonus() {
    return bonus;
}



