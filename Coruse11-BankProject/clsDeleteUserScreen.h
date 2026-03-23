#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsDeleteUserScreen :
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

    static void ShowDeleteUserScreen() {

        _DrawScreenHeader("\t  Delete User Screen");

		cout << "\nPlease Enter Username : ";
		string Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUsername Doesn't Exists, Choose another one : ";
			Username = clsInputValidate::ReadString();
		}


		clsUser User = clsUser::Find(Username);
		char Answer;
		bool Exists = clsUser::IsUserExist(Username);
		
		if (Exists && Username == "Admin") {
			cout << "\n\nYou can't delete this user.\n";
		}
		else if (Exists)
		{
			_PrintUser(User);
			cout << "\nAre you sure you want to delete this User? y/n? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				if (User.Delete()) {
					cout << "\nUser Deleted Successfully.\n";
					_PrintUser(User);
				}
				else
					cout << "\nError Client was not Deleted";
			}

			else
			{
				cout << "\nOperation Cancelled." << endl;
			}

		}
		else
		{
			cout << "\nUser with Username (" << Username << ") is not Found...\n";
		}
    }
};

