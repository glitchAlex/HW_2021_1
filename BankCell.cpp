#include <iostream>
using namespace std;

class BankCell
{
protected:
	int test = 500;
	float insideCash = 0;
public:
	int ret()
	{
		return test;
	}
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
	shared_ptr<BankCell> ptr;
public:
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
		if (exist == false)
		{
			this->~Human();
		}
	}
	Human(const shared_ptr<BankCell> out) : ptr(out) { cout << "Human created" << endl; }
	~Human() { ptr.reset(); cout << "Human deleted" << endl; }
};

int main()
{
	/*{//without input arguments in Human. TestRun.
		unique_ptr<BankCell> testRun(new BankCell);
		cout << (*testRun).ret(); cout << endl;
		shared_ptr<Human> testHum(new Human);
		cout << (*testHum).check(); cout << endl;
	} cout << endl << endl;*/


	cout << "Here goes the main part:" << endl << endl;
	shared_ptr<BankCell> BC(new BankCell); //frst working code
	unique_ptr<Human> H1(new Human(BC));
	unique_ptr<Human> H2(new Human(BC));
	unique_ptr<Human> H3(new Human(BC));
	(*H1).changeValuePtr(500);
	(*H2).changeValuePtr(-300);
	(*H3).changeValuePtr(-1000);
	cout<<"BC: "<<(*BC).account()<<endl;
	H1.reset();
	H2.reset();
	H3.reset();
	BC.reset();
	cout << "Hold up" << endl;
	int wait = 0;
	cin >> wait;

	cout << "turle was here";
}
