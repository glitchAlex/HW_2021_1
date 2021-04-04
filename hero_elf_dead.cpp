#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

int myRand() //my random int generator
{
	srand(static_cast<unsigned int>(time(0)));
	int ret = rand();
	for (int i = 0; i < rand() % 100; i++)
	{
		if (ret % 2 == 0)
		{
			ret /= 2;
			ret += 1;
		}
		else
		{
			ret *= 3;
			ret -= 1;
		}
	}
	return ret;
}

class Hero {
protected:
	string name = "NO NAME";
	int health;
	int strength;
	//int agility; //This attribute is not required
public:
	Hero(string Name, int Health, int Strength)
	{
		name = Name;
		health = Health;
		strength = Strength;
	}
	~Hero()
	{
		cout << "Hero " << name << " dead" << endl;
	}
	void coutStats() //to know current stats
	{
		cout << name << "'s stats:" << endl;
		cout << "Health: " << health << endl
			<< "Strength: " << strength << endl << endl;
	}
	void changeHealth(int change) //to change hero health
	{
		health += change;
		if (health < 0)
			health = 0;
	}
	int showHealth() //to known hero health
	{
		return health;
	}
	string showName() //to show hero name
	{
		return name;
	}
	void strike(Hero& otherHero) //strike strategy: you hit if your 'chance' is higher than opponet's strength.
//Hit points measured by how far your chance to 20. If it's around your strength you'll hit 1x time harder.
//If it's nearing 20 then you'll hit 2x harder. if your chance >= 20 (what if) then you'll hit 3x harder.
	{
		cout << this->showName() << " strikes!" << endl;
		int chance = myRand()%20;
		if (chance >= otherHero.strength)
		{
			if (chance >= 20)
			{
				cout << "CRITICAL HIT!" << endl;
				otherHero.changeHealth(-3 * strength);
			}
			else
			{
				cout << "HIT!" << endl;
				otherHero.changeHealth(-1 * strength * ( ( (chance - strength) /(20 - strength) ) + 1)); //( ( chance - strength) /(20 - strength) )
			}
		}
		else
			cout << "MISS!" << endl;

		cout << chance;
	}
};

void status(Hero& hero1, Hero& hero2) //to view hero's status during the fight
{
	cout << endl <<  "-----STATUS-----" << endl << endl;
	cout << hero1.showName() << "'s Health: " << hero1.showHealth() << endl;
	cout << hero2.showName() << "'s Health: " << hero2.showHealth() << endl;
	cout << "----------------" << endl << endl;
}

void fight(Hero& hero1, Hero& hero2) //fight loop
{
	Sleep(1500);
	cout << "Fight started. Initiated by " << hero1.showName() << endl << endl;
	while (hero1.showHealth() > 0 && hero2.showHealth())
	{
		hero1.strike(hero2);
		status(hero1, hero2);
		Sleep(3500);
		if (hero2.showHealth() > 0) //if hero2 survived
		{
			hero2.strike(hero1);
			status(hero1, hero2);
			Sleep(3500);
		}
	}
	if (hero1.showHealth() == 0) //hero2 victory
	{
		delete& hero1;
		cout << endl << hero2.showName() << " won." << endl;
	}
	if (hero2.showHealth() == 0) //hero1 victory
	{
		delete& hero2;
		cout << endl << hero1.showName() << " won." << endl;
	}
}

int main()
{
	Hero* main(new Hero("Randal The Vandal", 20, 0));
	Hero* enemy(new Hero("Riven of Thousand Voices, The last known Ahamkara", 50, 10));
	main->coutStats();
	enemy->coutStats();
	fight(*main, *enemy);
}
