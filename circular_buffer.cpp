#include <iostream>
#include <chrono>
#include <ctime>
#include <boost/circular_buffer.hpp>
using namespace std;

struct login { //struct email-time
    string email = "no name"; //fix using only eng string
};

void log_in(login* user, boost::circular_buffer<login>* data)
{
    //push_back process and remebering log in time
}

int main()
{
    boost::circular_buffer<login> data(10); //data buffer
    login fox; //beta tester
    fox.email = "wd2014@hack.com"; //giving some personality
    data.push_back(fox); //adding the beta tester
    cout << data[0].email << endl;
    cout << endl;
    auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << ctime(&givemetime) << endl;
}
