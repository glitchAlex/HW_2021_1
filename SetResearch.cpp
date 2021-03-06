#include <iostream>
#include <chrono>
#include <ctime>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//unsigned int N = 0;
	//cout << "Enter N number: ";
	//cin >> N;
	int number[4000];
	for (int i = 0; i < 4000; i++)
		number[i] = rand();

	//part 1 timing set
	auto start = chrono::high_resolution_clock::now();
	set<int> myset(number, number + 4000);
	auto finish = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed = finish - start;
	cout << "Elapsed time for set<int>: " << elapsed.count() << " s\n";

	//part 2 timing vector
	//declaring start1, finish1 and elapsed1 because of the declaration time in the first part.
	auto start1 = chrono::high_resolution_clock::now();
	vector<int> myvector(number, number + 4000);
	sort(myvector.begin(), myvector.end());
	auto finish1 = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed1 = finish1 - start1;
	cout << "Elapsed time for vetor<int>: " << elapsed1.count() << " s\n";
}

//table (4000 elems)
/*
*		set				vector

N1		0.0280523s		0.0142608s

N2		0.0420869s		0.0131368s

N3		0.0265094s		0.0153918s

N4		0.0421841s		0.0140506s

N5		0.0279104s		0.0149156s
-----------------------------------
Mean s:	0.03334862s		0.01435112s
-----------------------------------
Mean ms:33.34862ms		14.35112ms
===================================
Top:	_-Top 2-_		_-Top 1-_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
results from https://www.onlinegdb.com/online_c++_compiler:
set: 0.00362517s
vector: 0.00151344s
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Let: Mean ms(set) = Const * Mean ms(vector)
Then: Const ~= 2.324

Let: N2(set) = Const * N2(vector)
Then: Const ~= 3.204

Let: N3(set) = Const * N3(vector)
Then: Const ~= 1.722
*/
