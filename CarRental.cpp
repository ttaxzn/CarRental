#include <iostream>
#include <string>
#include <vector>
#include "CarFunctions.cpp"
using namespace std;

int main()
{
MainMenu();
Admin Admin1;
User User1;
Car Car1;
vector <Admin> adminlist;
vector <User> userlist;
vector <Car> carslist;
vector <Car> userCar;
char choice;
char choice1;
char choice2;
char choice3;
char choice4;
cin >> choice;
while(choice!='E' || choice!='e')
{
    // ADMIN CHOICES
    if(choice=='A' || choice=='a')
    {
        AdminLogin();
        cin >> choice1;
        if(choice1=='N' || choice1=='n')
        {
            Admin1.setUser();
            adminlist.push_back(Admin1);
            continue;
        }
        if(choice1=='E' || choice1=='e')
        {
            if(isAdmin(adminlist)==true)
            {
                cout << "Successfully logged in!" << endl;
                cout << endl;
                AdminMenu();
                cin >> choice3;
                if(choice3=='N' || choice3=='n')
                {
                    Car1.setCar();
                    carslist.push_back(Car1);
                    AdminMenu();
                    cin >> choice3;
                }
                if(choice3=='R' || choice3=='R')
                {
                    removeCar(carslist);
                    AdminMenu();
                    cin >> choice3;
                }
                if(choice3=='C' || choice3=='c')
                {
                    displayCars(carslist);
                    AdminMenu();
                    cin >> choice3;
                }
                if(choice3=='Q' || choice3=='q')
                {
                    MainMenu();
                }
            }
            else
            {
                cout << "Invalid credentials, please try again" << endl;
                cout << endl;
                continue;
            }

        }
        if(choice1=='Q' || choice1=='q')
        {
            MainMenu();
        }
    }

    // USER CHOICES
    if(choice=='U' || choice=='u')
    {
        UserLogin();
        cin >> choice2;
        if(choice2=='N' || choice2=='n')
        {
            User1.setUser();
            userlist.push_back(User1);
            continue;
        }
        if(choice2=='E' || choice2=='e')
        {
            if(isUser(userlist)==true)
            {
                cout << "Successfully logged in!" << endl;
                cout << endl;
                UserMenu();
                cin >> choice4;
                if(choice4=='N' || choice4=='n')
                {
                    if(!carslist.empty())
                    {
                    displayCars(carslist);
                    }
                    rentCar(carslist, userCar);
                    UserMenu();
                    cin >> choice3;
                }
                if(choice3=='R' || choice3=='R')
                {
                    displayUserCars(userCar);
                    UserMenu();
                    cin >> choice3;
                }
                if(choice3=='C' || choice3=='c')
                {
                    displayCars(userCar);
                    UserMenu();
                    cin >> choice3;
                }
                if(choice3=='Q' || choice3=='q')
                {
                    MainMenu();
                }
            }
            else
            {
                cout << "Invalid credentials, please try again" << endl;
            }
            continue;
        }
        if(choice2=='Q' || choice2=='q')
        {
            MainMenu();
        }
    }
cin >> choice;
}


    return 0;
}