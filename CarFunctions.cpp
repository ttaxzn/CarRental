#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "CarRental.h"
using namespace std;

void MainMenu()
{
cout << "-----------------------------------" << endl;
cout << setw(26) << "Welcome to Cars Inc" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << setw(24) << "Admin login (A)" << endl;
cout << endl;
cout << setw(24) << "User login (U)" << endl;
cout << endl;
cout << setw(31) << "Press a key to continue: " << endl;
cout << endl;
}

void UserLogin()
{
cout << "-----------------------------------" << endl;
cout << setw(24) << "Welcome User!" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << setw(30) << "Create new user login (N)" << endl;
cout << endl;
cout << setw(29) << "Existing user login (E)" << endl;
cout << endl;
cout << setw(20) << "Exit (Q)" << endl;
cout << endl;
}

// ADMIN FUNCTIONS 
void AdminLogin()
{
cout << "-----------------------------------" << endl;
cout << setw(24) << "Welcome Admin!" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << setw(30) << "Create new admin login (N)" << endl;
cout << endl;
cout << setw(29) << "Existing admin login (E)" << endl;
cout << endl;
cout << setw(20) << "Exit (Q)" << endl;
cout << endl;
}

void AdminMenu()
{
cout << "-----------------------------------" << endl;
cout << setw(22) << "Admin Menu" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << setw(27) << "Add new vehicle (N)" << endl;
cout << endl;
cout << setw(26) << "Remove vehicle (R)" << endl;
cout << endl;
cout << setw(32) << "View current vehicle list (C)" << endl;
cout << endl;
cout << setw(23) << "Log out (Q)" << endl;
}


void Admin::setUser()
{
string ADMINUSER;
string ADMINPASS;
cout << "-----------------------------------" << endl;
cout << setw(25) << "New Admin Login" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << "Enter username: " << endl;
cin >> ADMINUSER;
username=ADMINUSER;
cout << "Enter password: " << endl;
cin >> ADMINPASS;
password=ADMINPASS;
cout << "Admin successfully created!" << endl;
cout << endl;
}

bool isAdmin(vector <Admin> admin1)
{
int i;
bool isadmin=false;
string username1;
string password1;
cout << "-----------------------------------" << endl;
cout << setw(27) << "Existing Admin Login" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << "Enter username:" << endl;
cin >> username1;
cout << "Enter password:" << endl;
cin >> password1;
for(i=0; i<admin1.size(); i++)
{
    if(admin1.at(i).getUsername()==username1 && admin1.at(i).getPass()==password1)
    {
        isadmin=true;
    }

}
return isadmin;
}


// USER FUNCTIONS 
void User::setUser()
{
string ADMINUSER;
string ADMINPASS;
cout << "-----------------------------------" << endl;
cout << setw(24) << "New User Login" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << "Enter username: " << endl;
cin >> ADMINUSER;
username=ADMINUSER;
cout << "Enter password: " << endl;
cin >> ADMINPASS;
password=ADMINPASS;
cout << "User successfully created!" << endl;
}

string User::getUsername()
{
return username;
}

string User::getPass()
{
return password;
}


bool isUser(vector <User> user1)
{
int i;
bool isuser=false;
string username1;
string password1;
cout << "-----------------------------------" << endl;
cout << setw(27) << "Existing User Login" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << "Enter username:" << endl;
cin >> username1;
cout << "Enter password:" << endl;
cin >> password1;
for(i=0; i<user1.size(); i++)
{
    if(user1.at(i).getUsername()==username1 && user1.at(i).getPass()==password1)
    {
        isuser=true;
    }
}
return isuser;
cout << endl;
}

void UserMenu() 
{
cout << "-----------------------------------" << endl;
cout << setw(22) << "User Menu" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << setw(27) << "Rent new vehicle (N)" << endl;
cout << endl;
cout << setw(26) << "Return vehicle (R)" << endl;
cout << endl;
cout << setw(30) << "View your vehicle list (C)" << endl;
cout << endl;
cout << setw(23) << "Log out (Q)" << endl;

}

void rentCar(vector <Car> car1, vector <Car> userCar)
{
string make1;
string model1;
int year1;
int i;
Car car2;
if(!car1.empty())
{
cout << "Make:" << endl;
cin >> make1;
cout << "Model:" << endl;
cin >> model1;
cout << "Year" << endl;
cin >> year1;
for(i=0; i<car1.size(); i++)
{
    if(car1.at(i).getMake()==make1 && car1.at(i).getModel()==model1 && car1.at(i).getYear()==year1)
    {
        car1.at(i).setUnavailable();
        car2.setRental(make1, model1, year1);
        userCar.push_back(car2);
        cout << "Car successfully rented! Enjoy your ride!" << endl;
        cout << endl;
    }
}
}
else
{
cout << "No cars in inventory. Try again later" << endl;
}

}

void displayUserCars(vector <Car> userCar)
{
int i;
if(!userCar.empty())
{
    for(i=0; i<userCar.size(); i++)
    {
        cout << userCar.at(i).getMake() << " " << userCar.at(i).getModel() << " " << userCar.at(i).getYear() << endl;
    }
}
else
{
    cout << "You do not currently have any cars." << endl;
}
}


// CAR FUNCTIONS

void Car::setCar()
{
string make1;
string model1;
int year1;
char isavailable1;
cout << "-----------------------------------" << endl;
cout << setw(23) << "Add New Car" << endl;
cout << "-----------------------------------" << endl;
cout << endl;
cout << "Make: " << endl;
cout << endl;
cin >> make1;
cout << endl;
make=make1;
cout << "Model: " << endl;
cout << endl;
cin >> model1;
cout << endl;
model=model1;
cout << "Year: " << endl;
cout << endl;
cin >> year1;
cout << endl;
year=year1;
cout << "Is it available? (Y/N)" << endl;
cout << endl;
cin >> isavailable1;
cout << endl;
if(isavailable1=='Y' || isavailable1=='y')
{
isAvailable=true;
}
else
{
isAvailable=false;
}
cout << "Car successfully added to inventory!" << endl;
cout << endl;
}

void Car::setUnavailable()
{
isAvailable=false;  
}

void Car::setAvailable()
{
isAvailable=true;
}

void Car::setRental(string make1, string model1, int year1)
{
make=make1;
model=model1;
year=year1;
}

string Car::getMake()
{
    return make;
}

string Car::getModel()
{
    return model;
}

int Car::getYear()
{
    return year;
}

string Car::getAvailability()
{
    if(isAvailable==false)
    {
        return "UNAVAILABLE";
    }
    else
    {
        return "AVAILABLE";
    }
}


void displayCars(vector <Car> car1)
{
int i;
cout << "-----------------------------------" << endl;
cout << setw(23) << "Current Cars" << endl;
cout << "-----------------------------------" << endl;
if(!car1.empty())
{
for(i=0; i<car1.size(); i++)
{
    cout << car1.at(i).getMake() << " " << car1.at(i).getModel() << " " << car1.at(i).getYear() << " " << car1.at(i).getAvailability() << endl;
}
}
else
{
cout << "No cars in inventory." << endl;
}
cout << endl;
}

void removeCar(vector <Car> car1)
{
int i;
string make1;
string model1;
int year1;
cout << "-----------------------------------" << endl;
cout << setw(23) << "Remove A Car" << endl;
cout << "-----------------------------------" << endl;
if(!car1.empty())
{
for(i=0; i<car1.size(); i++)
{
    if(car1.at(i).getMake()==make1 && car1.at(i).getModel()==model1 && car1.at(i).getYear()==year1)
    {
        car1.erase(car1.begin()+i);
    }
}
}
else
{
cout << endl;
cout << setw(28) << "No cars in inventory." << endl;
}
}