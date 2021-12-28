#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
public: 
void setUser();
string getUsername();
string getPass();
protected:
string username;
string password;
};

class Admin : public User
{
public:
void setUser();
};

class Car
{
public:
void setCar();
void setRental(string make1, string model1, int year1);
string getMake();
string getModel();
int getYear();
string getAvailability();
void setAvailable();
void setUnavailable();
private:
string make;
string model;
int year;
bool isAvailable;
};




void MainMenu();
void AdminLogin();
void AdminMenu();
void UserLogin();
void UserMenu();
bool isAdmin(vector <Admin> admin1);
bool isUser(vector <User> user1);
void displayCars(vector <Car> car1);
void displayUserCars(vector <Car> userCar);
void removeCar(vector <Car> car1);
void rentCar(vector <Car> car1, vector <Car> userCar);