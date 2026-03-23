#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsUpdateUserScreen :
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

    static void _SetPremissions(clsUser& User) {

        User.Permissions = 0;
        char Answer;
        cout << "\n\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            User.Permissions = -1;
            return;
        }
        cout << "\nDo you want to give access to : \n";
        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            User.Permissions += clsUser::enPermissions::PShow;

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            User.Permissions += clsUser::enPermissions::PAdd;

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            User.Permissions += clsUser::enPermissions::PDelete;

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            User.Permissions += clsUser::enPermissions::PUpdate;

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            User.Permissions += clsUser::enPermissions::PFind;

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            User.Permissions += clsUser::enPermissions::PTransactions;

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            User.Permissions += clsUser::enPermissions::PManageUsers;

        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            User.Permissions += clsUser::enPermissions::PLoginRegister;

        cout << "\nCurrency Exchange? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            User.Permissions += clsUser::enPermissions::PCurrencyExchange;
    }

    static void _ReadUserInfo(clsUser& User) {

        cout << "\nRead First Name : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nRead Last Name : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nRead Email : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nRead Phone : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password? ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        _SetPremissions(User);

    }
public :

    static void ShowUpdateUserScreen() {

        
		_DrawScreenHeader("\t  Update User Screen");

		cout << "\nPlease Enter Username : ";
		string Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUsername Doesn't Exists, Choose another one : ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);
		_PrintUser(User);

		cout << "\nUpdate User Info : ";
		cout << "\n____________________\n";

        _ReadUserInfo(User);

        clsUser::enSaveResults SaveResult;
        SaveResult = User.Save();
        
		switch (SaveResult) {
		case clsUser::enSaveResults::svSucceeded:
			cout << "\nAccount Updated Successfully.\n";
            _PrintUser(User);
			break;
		case clsUser::enSaveResults::svFaildEmptyObject:
			cout << "\nError Account was not saved because its Empty.\n";
			break;
		}
	}
   
};

