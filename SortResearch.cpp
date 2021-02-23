#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <chrono>
#include <algorithm>
#include <thread>
#include <iterator>
using namespace std;


int main()
{
    //array<int, 4000> myarray;
    //for (int i = 0; i < 4000; i++)
    //    myarray[i] = rand();
    
    //vector<int> myvector(4000);
    //for (int i = 0; i < 4000; i++)
    //    myvector[i] = rand();

    //deque<int> mydeque(4000);
    //for (int i = 0; i < 4000; i++)
    //    mydeque[i] = rand();

    //list<int> mylist(4000);
    //for (auto it = mylist.begin(); it != mylist.end(); it++)
    //    *it = rand();

    //forward_list<int> myf_list(4000);
    //for (auto it = myf_list.begin(); it != myf_list.end(); it++)
    //    *it = rand();

    //sort func tests:
    auto start = std::chrono::high_resolution_clock::now();
    sort(myarray.begin(), myarray.end());
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}


//table (4000 elems):
/*
        array           vector          deque           list            f_list

N1      0.0141489s      0.0127239s      0.0656125s      0.0778439s      0.0772465s

N2      0.0144886s      0.0160681s      0.0611911s      0.0736374s      0.0696788s

N3      0.0134893s      0.0127211s      0.062743s       0.066873s       0.069315s

N4      0.0147467s      0.0157921s      0.063727s       0.0671769s      0.0724568s

N5      0.0147286s      0.0140324s      0.0602517s      0.0681055s      0.0725655s
------------------------------------------------------------------------------------
Mean s: 0.01432042s     0.01426752s     0.06270506s     0.07072734s     0.07225252s
------------------------------------------------------------------------------------
Mean ms:14.32042ms      14.26752ms      62.70506ms      70.72734ms      72.25252ms
====================================================================================
Top:    _-Top 2-_       _-Top 1-_       _-Top 3-_       disqualified    disqualified
*/
/*
Remarks:
1. Some of the Vector results was 0.028... s long. That's kind of strange. Perhaps my computer from 2009-2011 years is considered bad these days.

2. Some errors trying to time list and f_list. But after I clicked "ok" button programm continued to work. Strange.
It's like VS show no issues but right after starting the programm some build errors occur.
Unable to open file %path% error code = 0x80070002
*/
