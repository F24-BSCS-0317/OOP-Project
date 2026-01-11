#include<iostream>
#include<string>
#include"SmartHome.h"
using namespace std;

int main()
{
    cout << "=====================================================" << endl;
    cout << "      Smart Home Simulator – C++ OOP Project         " << endl;
    cout << "=====================================================" << endl;

    SmartHome myHome;

    myHome.addDevice(new Light("Living Room Light"));
    myHome.addDevice(new AC("Bedroom AC"));
    myHome.addDevice(new TV("Hall TV"));
    myHome.addDevice(new Door("Main Door"));

    cout << "\nWelcome to Smart Home Simulator!" << endl;

    string userName;
    cout << "Enter your Name: ";
    getline(cin, userName);
    User user(userName);
    user.controlHome(myHome);

    return 0;
}
