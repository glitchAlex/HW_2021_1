#include <iostream>
#include <chrono>
#include <ctime>
#include <boost/circular_buffer.hpp>
using namespace std;

class login { //struct email-time
protected:
    string email = "no name"; //fix using only eng string
    time_t LastLogIn = chrono::system_clock::to_time_t(chrono::system_clock::now());
public:
    login(string mail) { email = mail; } //contructor
    void TimeMe() { LastLogIn = chrono::system_clock::to_time_t(chrono::system_clock::now()); } //time changing
    string GiveMeMail() { return email; } //mailgiving!
    time_t GiveMeTime() { return LastLogIn; } //return time
};

void log_in(login* user, boost::circular_buffer<login>* data) //push_back process and remebering log in time (req: &value)
{
    (*data).push_back(*user);
    (*user).TimeMe();
}

int main()
{
    boost::circular_buffer<login> data(3); //data buffer
    unique_ptr<login> fox(new login("wd2014@hack.com")); //beta tester
    data.push_back(*fox); //adding a tester to the data
    cout << data[0].GiveMeMail() << endl << endl; //check

    for (int i = 0; i < 5; i++) //3 tester more
    {
        string input;
        cout << "Enter email adress: ";
        cin >> input;
        login user(input);
        log_in(&user, &data); //timing user inside this func
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << data[i].GiveMeMail() << " " << ctime(&(data[i].GiveMeTime())) << endl;
        //hope this works
    }
}

/*int main() //copied code from https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
{
    auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
        << "elapsed time: " << elapsed_seconds.count() << "s\n";
}*/
