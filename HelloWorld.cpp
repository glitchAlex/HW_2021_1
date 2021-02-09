#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unistd.h>
using namespace std;

struct fighter{
    int hp = 0;
    int attack = 0;
    int agility = 0;
};

void attack(fighter &attacker, fighter &defender)
{
    cout << "-----" << endl;
    int chance = rand();
    chance = chance % 20;
    chance += 1;
    cout << "chance: " <<  chance <<  endl;
    if (chance >= defender.agility)
    {
        int hit = rand();
        hit = (hit % attacker.attack);
        hit += 1;
        cout << "HIT: " << hit <<  endl;
        defender.hp -= hit;
    }
    else
    {
        cout << "MISS" <<  endl;
    }
    cout << "-----" << endl << endl;
}

template <typename T>
T choice()
{
    T x;
    cin >> x;
    return x;
}

void fight(fighter &hero1, fighter &hero2)
{

}

void showHP(fighter &hero1, fighter &hero2)
{
    cout << "-----" << endl;
    cout << "Your hp: " << hero1.hp << endl << endl;
    cout << "Enemy's hp: " << hero2.hp << endl;
    cout << "-----" << endl << endl;
}

int main() 
{
    cout << "============ Launcher(?) started ============" << endl << endl;
    int sceCapacity = 1;
    cout << "Select scenario:" << endl << "avalible: " << sceCapacity << endl;
    cout << sceCapacity << ": Dungeon" <<  endl << endl;
    if (choice<int>() == 1)
    {
        cout << "============ Game Started ============" << endl <<  endl;
        fighter hero;
        hero.hp = 50;
        hero.attack = 12;
        hero.agility = 8;
        cout << "You are surrounded by dark. You see walls on your right and left. Looking behind gave you view of longtime rockfall. Lo-oks like you've been here for some time. The only way is to move forward." << endl;
        cout << "Avalible moves: " << endl << "1: forward" << endl;
        if (choice<int>() == 1)
        {
            cout << "you see an odd mouse. It looks hungry... and angry." << endl;
            fighter mouse;
            mouse.hp = 20;
            mouse.attack = 5;
            mouse.agility = 15;
            cout << "============ FIGHT ============" << endl;
            sleep(5);
            while (mouse.hp > 0 && hero.hp > 0)
            {
                cout << "Mouse attack:" << endl << endl;
                sleep(2);

                //attack
                attack(mouse, hero);

                if (hero.hp <= 0)
                {
                    cout << endl << "WASTED" << endl;
                    break;
                }
                
                cout << "You attack:" << endl << endl;
                sleep(2);

                //attack.h
                attack(hero, mouse);
                sleep(1);
                showHP(hero, mouse);
                sleep(2);
            }
            if (hero.hp > 0)
            {
                cout << "YOU WON" << endl;
            }
            else
            {
                cout << "GAME OVER" << endl;
            }
            cout << "Enter 'End' to end" << endl;
            choice<string>();
        }
    }
}

/*
//Идеи Васюкова (из задачки)
class Item {
public:
    // Так можно создать предмет, указав его название, вес, уровень и магичность
    Item(string title, int weight, int level, bool magical);
    // Получить вес предмета
    int getWeight();
    // Получить уровень предмета
    int getLevel();
    // Получить, является ли предмет магичным
    int isMagical();
};

class Player {
protected:
    // Сила и уровень героя
    int strength;
    int level;
public:
    // Создать героя, все подробности будут указаны позже
    Player() { }
    // Удалить героя, ничего умного эта процедура пока что не требует
    virtual ~Player() { }

    // Базовые методы, пока что очень простые.
    // На данном этапе можно считать, что для всех героев они ведут себя одинаково, 
    // так что пусть будут в базовом классе.

    // Задать силу
    void setStrength(int strength) {
        this->strength = strength;
    }
    // Задать уровень
    void setLevel(int level) {
        this->level = level;
    }

    // Получить силу
    int getStrength() {
        return this->strength;
    }
    // Получить уровень
    int getLevel() {
        return this->level;
    }

    // Проверка, может ли игрок использовать предмет
    virtual bool canUse(Item* item) = 0;
};

class Wizard: public Player {
public:
    //Wizard() {}
    //~Wizard() {}
    // Проверка, может ли игрок использовать предмет
    virtual bool canUse(Item* item)
    {
        if (strength >= item->getWeight() && level >= item->getLevel())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Knight: public Player {
public:
    //Knight() {}
    //~Knight() {}
    // Проверка, может ли игрок использовать предмет
    virtual bool canUse(Item* item)
    {
        if (!item->isMagical() && strength >= item->getWeight() && level >= item->getLevel())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    Item* items[3];
    items[0] = new Item("Small sword", 1, 1, false);
    items[1] = new Item("Big sword", 5, 3, false);
    items[2] = new Item("Ward", 1, 3, true);

    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Can use: " << players[i]->canUse(items[j]) << endl;
        }
    }
}*/
