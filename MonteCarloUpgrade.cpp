#include <iostream>
#include <vector>
#include <chrono>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;

double ConsistentMonteCarlo()
{
	double N = 100000.00; //100k points
	int counter = 0; //to count points that is inside 1 radius circle
	for (int i = 0; i < N; i++)
	{
		double x = (rand() % 10000) / 10000.00;
		double y = (rand() % 10000) / 10000.00;
		//cout << "x: " << x << "; y: " << y << ";\n";
		//cout << "x*x + y*y = " << x * x + y * y << ";\n\n";
		if (x * x + y * y < 1)
			counter += 1;
	}
	//multiply by 4 because without it equals to pi/4
	return (4 * double(counter) / N); //pi number
	//why 3.26-3.27? idk
}

void threadFunc(int *counter)
{
	int N = 100000 / thread::hardware_concurrency(); //100k/thread::hardware_concurrency() points to count
	//cout << "Thread id: " << this_thread::get_id() << "; counting " << N << " points\n"; //to get how many points 1 thread is counting
	for (int i = 0; i < N; i++)
	{
		double x = (rand() % 10000) / 10000.00;
		double y = (rand() % 10000) / 10000.00;
		if (x * x + y * y < 1)
		{
			const lock_guard<mutex> lock(mtx);
			*counter += 1;
		}
	}
}

double ParallelMonteCarlo()
{
	//100k points and thread::hardware_concurrency() threads
	int counter = 0;
	vector<thread> th(thread::hardware_concurrency()); //vector to contain threads

	for (unsigned int i = 0; i < thread::hardware_concurrency(); i++)
		th.push_back(thread(&threadFunc, &counter));

	for (auto& thr : th) //join all threads
		if (thr.joinable())
			thr.join();

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

	start = std::chrono::high_resolution_clock::now();
	cout << ParallelMonteCarlo() << endl;
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	cout << "Parallel Monte Carlo time: " << elapsed.count() << "s;\n";
	//cout << typeid(thread::hardware_concurrency()).name() << endl;
}
