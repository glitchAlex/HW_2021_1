#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <cmath>
#include <vector>
#include <chrono>
#include <future>
using namespace std;

double ConsistentMonteCarlo()
{
	double N = 100000.00; //100k points
	int counter = 0; //to count points that is inside 1 radius circle
	for (int i = 0; i < N; i++)
	{
		double x = ( rand() % 10000 ) / 10000.00;
		double y = ( rand() % 10000 ) / 10000.00;
		//cout << "x: " << x << "; y: " << y << ";\n";
		//cout << "x*x + y*y = " << x * x + y * y << ";\n\n";
		if (x * x + y * y < 1)
			counter += 1;
	}
	//double ret = 4 * double(counter) / N; //multiply by 4 because without it equals to pi/4
	return (4 * double(counter) / N); //pi number
	//why 3.26-3.27? idk
}

void threadFunc(promise<int> && promise)
{
	int N = 100000 / 4; //100k/4 points to count
	int counter = 0; //to count points that is inside 1 radius circle
	for (int i = 0; i < N; i++)
	{
		double x = (rand() % 10000) / 10000.00;
		double y = (rand() % 10000) / 10000.00;
		if (x * x + y * y < 1)
			counter += 1;
	}
	promise.set_value(counter); //to get counter
}

double ParallelMonteCarlo()
{
	//100k points and 4 threads
	promise<int> prms1;
	promise<int> prms2;
	promise<int> prms3;
	promise<int> prms4;

	auto ret1 = prms1.get_future();
	auto ret2 = prms2.get_future();
	auto ret3 = prms3.get_future();
	auto ret4 = prms4.get_future();

	thread th1(&threadFunc, move(prms1));
	thread th2(&threadFunc, move(prms2));
	thread th3(&threadFunc, move(prms3));
	thread th4(&threadFunc, move(prms4));

	th1.join();
	th2.join();
	th3.join();
	th4.join();

	int counter = ret1.get() + ret2.get() + ret3.get() + ret4.get(); //summing all counters
	//double ret = 4 * double(counter) / 100000.00;
	return (4 * double(counter) / 100000.00);
}

int main()
{
	//100k points
	srand(static_cast<unsigned int>(time(0))); //to change seed
	
	auto start = std::chrono::high_resolution_clock::now();
	cout << ConsistentMonteCarlo() << endl;
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Consistent Monte Carlo time: " << elapsed.count() << "s;\n\n";

	auto start1 = std::chrono::high_resolution_clock::now();
	cout << ParallelMonteCarlo() << endl;
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;
	cout << "Parallel Monte Carlo time: " << elapsed1.count() << "s;\n";
}
