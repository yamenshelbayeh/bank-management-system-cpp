#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"


class clsLoginScreen : protected clsScreen
{
private : 
    
    
    static bool _Login()
    {
        bool LoginFaild = false;
        short AttemptsCounter = 3;
        string Username, Password;
        do
        {
            
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n";
                cout << "You have " << AttemptsCounter << " Attempts left.\n\n";
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

            AttemptsCounter--;
            if (AttemptsCounter == 0) {
                cout << "\nYou are looked after 3 Attempts.";
                return false;
            }
        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenu();
        
    }

public :

    static bool ShowLoginScreen() {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();	
    }
};

