#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsFindUserScreen :
    protected clsScreen
{
private :

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }

public :

    static void ShowFindUserScreen() {
        
        _DrawScreenHeader("\t  Find User Screen");

		cout << "\nPlease Enter Username : ";
		string Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUsername Doesn't Exists, Choose another one : ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);

        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User);
    }
};

