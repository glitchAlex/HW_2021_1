#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> a = { 1, 2, 3, 4, 5, 6 };
    cout << "1: " << a.capacity() << "\n"; //capacity of 6 element

    a.push_back(12); //pushing 1 more element
    cout << "2: " << a.capacity() << "\n"; //now capacity is 9 elements

    vector<int> b = {}; //empty vector
    cout << "3: " << b.capacity() << endl; //capacity of an empty vector = 0

    b.push_back(12); //pushing 1 element to the empty vector
    cout << "4: " << b.capacity() << endl; //capacity now is 1

    b.push_back(13); //lets repeat it 4 times
    cout << "5: " << b.capacity() << endl; //capacity now is 2

    b.push_back(14); 
    cout << "6: " << b.capacity() << endl; //capacity now is 3

    b.push_back(14);
    cout << "7: " << b.capacity() << endl; //capacity now is 4

    b.push_back(14);
    cout << "8: " << b.capacity() << endl; //capacity now is 6

    //so I have a prediction that by pushing vector we increase by 1.5
    //let's check using 10 and 100 elem long vectors
    vector<int> c(10, 42);
    vector<int> d(100, 42);
    c.push_back(43);
    d.push_back(43);
    cout << "9: " << c.capacity() << " and " << d.capacity() << endl; //as expected we have vectors 15 and 150 elems long

    //to complete the second part of the task lets take vector b and reserve 4 elems
    b.reserve(4);
    cout << "10: " << b.capacity() << endl; //nothing happend

    //lets reserve 10 elems now
    b.reserve(10);
    cout << "10: " << b.capacity() << endl; //capacity is 10 now

    //Honestly, I don't know how to complete 3d part of the task. Do you really want me to do that? Well, I'll try.
    //idk lets have 1000 elems reserved for a start
    b.reserve(1000);
    cout << "11: " << b.capacity() << endl; //ok

    //btw, lets check size of vector b
    cout << "12: " << b.size() << endl; //as expeted size is 5. It means there are 5 elements. 
    //cout << "13: " << b[5] << endl; //I have tried to see what value of the 6th element. There was an error

    //now lets reserve 10000 elems
    b.reserve(10000);
    cout << "14: " << b.capacity() << endl; //ok

    //100000 elems
    b.reserve(100000);
    cout << "15: " << b.capacity() << endl; //ok

    //1000000 elems 0_o
    b.reserve(1000000);
    cout << "16: " << b.capacity() << endl; //ok

    //10000000
    b.reserve(10000000);
    cout << "17: " << b.capacity() << endl; //ok

    //100000000
    b.reserve(100000000);
    cout << "18: " << b.capacity() << endl; //you can see a "freeze" for a split second there

    //lets double it
    //b.reserve(200000000);
    //cout << "19: " << b.capacity() << endl; //now we have an exception
    //programm stops working and waiting me to handle this exception
    //strange fact: cout N19 still work in VS Code

    //lets try 100000001 (1 elem more than was before)
    b.reserve(100000001);
    cout << "20: " << b.capacity() << endl;//still freeze but it's ok

    //lets try 100000001 (1 elem more than was before)
    //b.reserve(150000000);
    //cout << "21: " << b.capacity() << endl;//another exception.

    //as you may see, if we try to reserve more than 100000001-150000000 elemnts everything go down
}
