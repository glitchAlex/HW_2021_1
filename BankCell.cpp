#include <iostream>
using namespace std;

class BankCell
{
protected:
	float insideCash = 0;
public:
	void changeValue(float change)
	{
		insideCash += change;
	}
	float account()
	{
		return insideCash;
	}
	BankCell() { cout << "BankCell created" << endl; }
	~BankCell() { cout << "BankCell deleted" << endl; }
};

class Human
{
protected:
	bool exist = true; //should we delete dead humans?
	shared_ptr<BankCell> ptr = NULL;
public:
	shared_ptr<BankCell> WhichCell()
	{
		return ptr;
	}
	void createBC()
	{
		if (ptr == NULL)
		{
			shared_ptr<BankCell> BC(new BankCell);
			ptr = BC;
		}
		else
			cout << "ok..." << endl;
	}
	void assign(shared_ptr<BankCell> out)
	{
		ptr = out;
	}
	bool check()
	{
		return exist;
	}
	void changeValuePtr(float change)
	{
		(*ptr).changeValue(change);
	}
	void died()
	{
		exist = false;
		if (exist == false) //perfect logic, I know (no)
		{
			this->~Human();
		}
	}
	Human() { cout << "Human created" << endl; }
	~Human() { ptr.reset(); cout << "Human deleted" << endl; }
};

int main()
{
	cout << "Here goes the main part:" << endl << endl;
	//shared_ptr<BankCell> BC(new BankCell); //frst working code
	unique_ptr<Human> H1(new Human());
	unique_ptr<Human> H2(new Human());
	unique_ptr<Human> H3(new Human());
	(*H1).createBC();
	(*H2).assign((*H1).WhichCell());
	(*H3).assign((*H1).WhichCell());
	(*H1).changeValuePtr(500);
	(*H2).changeValuePtr(-300);
	(*H3).changeValuePtr(-1000);
	cout<<"BC: "<< (*(*H1).WhichCell()).account()<<endl;
	H1.reset();
	H2.reset();
	//cout << "shared still live" << endl;
	H3.reset();
	//cout << "shared died" << endl;
	cout << "Hold up" << endl;
	int wait = 0;
	cin >> wait;

	cout << "turle was here" << endl;
}
