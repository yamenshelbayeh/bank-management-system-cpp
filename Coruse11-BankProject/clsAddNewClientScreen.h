#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsAddNewClientScreen :
    protected clsScreen
{
private :

	static void _ReadClientInfo(clsBankClient& Client) {

		cout << "\nRead First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nRead Last Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nRead Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nRead Phone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nRead PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nRead Balance : ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	
public :

    static void ShowAddNewClientScreen()
    {

        if (!CheckAccessRights(clsUser::PAdd)) {
            return;
       }

        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFailedEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaliedAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }

};

