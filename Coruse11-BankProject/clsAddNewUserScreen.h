#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsAddNewUserScreen : protected clsScreen
{
private : 

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

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t  Add User Screen");

        string Username = "";

        cout << "\nPlease Enter Username : ";
        Username = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(Username)) 
        {
            cout << "\nUsername Is Already Used, Choose another one : ";
            Username = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(Username);


        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded :
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject :
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists :
        {
            cout << "\nError User was not saved because Username is used!\n";
            break;

        }
        }
    }
};

