#include <iostream>
#include <vector>
#include <boost/multi_array.hpp>
using namespace std;

const int N = 3; //change to use new N

/*template <typename T>
boost::multi_array<T, N> fill_multi_array_Nd(vector<vector<vector<T>>> vector)
{
    boost::multi_array<T, N> multi_arr(boost::extents[]);

    return multi_arr;
}*/

template<size_t dimcount, typename T> //copied from stackoverflow
struct multidimensional_vector
{
    typedef std::vector< typename multidimensional_vector<dimcount - 1, T>::type > type;
};

template<typename T>
struct multidimensional_vector<0, T>
{
    typedef T type;
};

multidimensional_vector<1, int>::type v;
multidimensional_vector<2, int>::type v2;
multidimensional_vector<3, int>::type v3;
multidimensional_vector<4, int>::type v4;

//

int main()
{
    v.push_back(15);
    cout << v[0] << endl;
    v2.push_back(v);
    cout << v2[0][0] << endl;
    v3.push_back(v2);
    cout << v3[0][0][0] << endl;
    v4.push_back(v3);
    cout << v4[0][0][0][0] << endl;

    multidimensional_vector<N, int>::type vectN;
    cout << "Resize process: " << endl
        << "Enter sizes:\nExamples: 2 2; 3 5 2;\n(According to const N)\n" << endl;
    vector<int> size;
    int count = N;
    while (count > 0)
    {
        int input = 0;
        cin >> input;
        size.push_back(input);
        count--;
    }
    
    cout << "input proc (rand func is being used)\n";
    while (count < size.size())
    {
        cout << "???" << endl;
        count++;
    }
}
