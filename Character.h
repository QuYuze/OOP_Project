#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

using namespace std;

class Character
{
    private:

        string name;
        int hitpoint;
        int damage;
        int MaxHP;

    public:
	    Character();
        Character(string n, int max, int a);
        virtual void attack(Character & c);
        virtual void appear() = 0;
        virtual void action() = 0;

        virtual int getDamage() const;
        virtual string getName() const;
        virtual int getHP() const;
        virtual int getMaxHP() const;

        virtual void setDamage(int d);
        virtual void setName(string s);
        virtual void setMaxHP(int mhp);
        virtual void setHP(int hp);

};

std::ostream& operator<<(std::ostream& stream, const Character& obj);

class Monster;

class Player : public Character{
	private:
		int defence;
		int exp;
		int level;
	public:
		Player(string s);
		void setDefence(int df);
		int getDefence();
		int getLevel();

		void attack(Monster & m);
		void levelUp(int currLevel);
		void addExp(int bonus);
		void appear();
		void action();
		bool flee();
};

class Monster : public Character{
    private:
        int MaxHpList [4] = {0, 100, 200, 600};
        int damageList[4] = {0, 20, 50, 70};
        int bonusList[4] = {0, 25, 50, 99};
        string nameList[4] = {"", "Goblin", "Vampire", "Dragon"};

        int bonus;

    public:
	    Monster(int type);
	    int getType(int playerLevel);
        int getRandom();
        void setType(int playerLevel);
        void appear();
        void action();
	    void attack(Player & p);
	    int getBonus();

};


