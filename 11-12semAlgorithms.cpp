#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
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
	Sleep(20); //to prevent same rand number
	return ret;
}

void remove(vector<int>& v)
{
	auto end = v.end();
	for (auto it = v.begin(); it != end; ++it) {
		end = remove(it + 1, end, *it);
	}

	v.erase(end, v.end());
}

void swap(vector<int>& vec, int i)
{
	int t = vec[i];
	vec[i] = vec[i + 1];
	vec[i + 1] = t;
}

void printV(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
}

int main()
{
	int N = 10;
	vector<int> v1;
	for (int i = 0; i < N; i++)
		v1.push_back(rand() % 9 * 1 + 1); //N1
	for (int i = 0; i < N; i++)
		cout << v1[i] << endl;

	cout << "Enter 5 values:" << endl; //N2
	for (int i = 0; i < 5; i++)
	{
		int value = 0;
		cin >> value;
		v1.push_back(value);
	}
	cout << "Enter completed" << endl << endl;

	for (int i = 0; i < v1.size()-1; i++)//N3
	{
		if (rand() % 2 == 0)
		{
			swap(v1, i);
		}
	}
	cout << endl;
	printV(v1);
	//n4
	remove(v1);
	cout << endl;
	printV(v1);

	//n5
	{
		int counter = 0;
		for (auto it = v1.begin(); it != v1.end(); it++)
		{
			if ((*it) % 2 == 1)
				counter += 1;
		}
		cout << endl << "counter n5: " << counter << endl;
	}

	//n6
	{
		vector<int>::const_iterator it;
		it = min_element(v1.begin(), v1.end());
		cout << "min el: " << *it << endl;
		it = max_element(v1.begin(), v1.end());
		cout << "max el: " << *it << endl;
		cout << endl;
	}

	//n7
	{

	}

	//n8
	for (auto it = v1.begin(); it != v1.end(); it++)
		*it *= *it;
	printV(v1);
	cout << endl;

	//n9
	vector<int> v2;
	for (int i = 0; i < v1.size(); i++)
	{
		v2.push_back(rand());
	}
	printV(v2);
	cout << endl;

	//n10
	{
		int sum = 0;
		for (auto it = v2.begin(); it != v2.end(); it++)
		{
			sum += *it;
		}
		cout << "summ is: " << sum << endl;
	}
	cout << endl;

	//n11
	for (int i = 0; i < (myRand() % v1.size())/2; i++)
	{
		v2[i] = 1;
	}
	printV(v2);
	cout << endl;

	//n12
	vector<int> v3;
	//for (auto it = v3.begin(); it != it + vec.size(); it++)
	for (int i = 0; i < v1.size(); i++)
	{
		v3.push_back(v1[i] - v2[i]);
	}
	printV(v3);
	cout << endl;

	//n13
	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		if (*it < 0)
			*it = 0;
	}
	printV(v3);
	cout << endl;

	//n14
	int value = 0;
	v3.erase(remove(v3.begin(), v3.end(), value), v3.end());
	printV(v3);
	cout << endl;

	//n15
	reverse(v3.begin(), v3.end());
	printV(v3);
	cout << endl;

	//n16
	if (v3.size() == 0)//0size scenario
	{
		cout << "TOP1: " << "none" << endl;
		cout << "TOP2: " << "none" << endl;
		cout << "TOP3: " << "none" << endl;
	}
	else if (v3.size() == 1)//1 size scenario
	{
		cout << "TOP1: " << v3[0] << endl;
		cout << "TOP2: " << "none" << endl;
		cout << "TOP3: " << "none" << endl;
	}
	else if (v3.size() == 2)// 2 size scenario
	{
		int max = 0, min = 0;
		if (v3[0] > v3[1])
		{
			max = v3[0];
			min = v3[1];
		}
		else
		{
			max = v3[1];
			min = v3[0];
		}
		cout << "TOP1: " << max << endl;
		cout << "TOP2: " << min << endl;
		cout << "TOP3: " << "none" << endl;
	}
	else//>3 scenario
	{
		int first = -1, second = -1, third = -1;
		for (int i = 0; i < v3.size(); i++)
		{
			if (v3.at(i) > first)
			{
				third = second;
				second = first;
				first = v3.at(i);
			}
			else if (v3.at(i) > second)
			{
				third = second;
				second = v3.at(i);
			}
			else if (v3.at(i) > third)
			{
				third = v3.at(i);
			}
		}
		cout << "TOP1: " << first << endl;
		cout << "TOP2: " << second << endl;
		cout << "TOP3: " << third << endl;
	}
	cout << endl;

	//17
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	//n18
	vector<int> v4;
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));
	cout << endl;

	//n19
	{
		int start = 0, end = 0;
		bool flag1 = 0;
		for (int i = 0; i < v4.size(); i++)
		{
			cout << i <<endl;
			if (!flag1 and v4[i] == 1)
			{
				start = i;
				flag1 = 1;
			}
			else if (!flag1 and v4[i] > 1)
			{
				start = i - 1;
				end = i - 1;
				break;
			}
			if (v4[i] > 1)
			{
				end = i;
				break;
			}
		}
		cout << "start (index): " << start << endl
			<< "end (index): " << end << endl;
	}
	//printV(v4);
	cout << endl;

	//n20
	cout << "v1:" << endl;
	printV(v1);
	cout << endl;

	cout << "v2:" << endl;
	printV(v2);
	cout << endl;

	cout << "v3:" << endl;
	printV(v3);
	cout << endl;

	cout << "v4:" << endl;
	printV(v4);
	cout << endl;
}
