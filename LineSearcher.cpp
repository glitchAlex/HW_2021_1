#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
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

int main()
{
	string line;
	string path = "text.txt";
	fstream file(path);
	if (file.is_open())
	{
		for (int i = 0; i < 100/*myRand() % 100*/; i++) //myRand() actually bad for this task,
		{
			if (i < 10)
				file << "Hello. This line number is 0" << i << endl;
			else
				file << "Hello. This line number is " << i << endl;
		}
		file.seekg(0, ios::beg);
		getline(file, line);
		int N = 0;
		cout << "Please Eneter the line number you wish to get:\nNote that 0 is line too.\nAvailable line numbers from 0 to 99 including." << endl;
		cin >> N;
		if (N < 0 || N >= 100)
		{
			cout << endl << "INCORRECT INPUT" << endl;
			file.close();
			return 1;
		}
		file.seekg(N*(line.size()+2), ios::beg); //think '\n' considerated as 2 symbols. There is gotta be a better way to do it. Works only with same line size.
		getline(file, line);
		cout << line;
	}
	else
		cout << endl << endl << "No file opened." << endl;
	file.close();
	return 0;
}
