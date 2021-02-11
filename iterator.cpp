#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {10, 20, 30, 40, 50, 60};

    vector<int> *p = new vector<int>[a.size()];
    (*p) = a;

    //for (vector<int>::const_iterator i = (*p).begin(); i != (*p).end(); ++i) //checking that vector copied correctly
    //    cout << *i << ' ';

    vector<int>::iterator j = --b.end();
    for (vector<int>::iterator i = a.begin(); i != a.end(); ++i) //replace part 1
    {
        *i = *j;
        j = --j;//fix this later
    }
    ++j;//fix needed?
    for (vector<int>::const_iterator i = (*p).begin(); i != (*p).end(); ++i) //replace part 2
    {
        *j = *i;
        ++j;//fix needed?
    }
    //free v (and j?)
    delete[]p; //cleaning mess

    cout << "output:" << endl << endl; //output
    for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
        cout << *i << ' ';
    cout << endl;
    cout << endl;
    for (vector<int>::const_iterator i = b.begin(); i != b.end(); ++i)
        cout << *i << ' ';
}