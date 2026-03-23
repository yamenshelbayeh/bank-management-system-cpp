#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsDepositScreen :
    protected clsScreen
{

private :

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

    static void ShowDepositScreen() {

		_DrawScreenHeader("\t   Deposit Screen");

		cout << "\nPlease Enter client Accout Number : ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount number is not found, please try again : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		char Answer;
		clsBankClient Client = clsBankClient::Find(AccountNumber);

			_PrintClient(Client);

			cout << "\nEnter Deposit Amount : ";

			double DepositeAmount = clsInputValidate::ReadDblNumber();

			cout << "\nAre you sure you want to preform this transaction? y/n? ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Client.Deposit(DepositeAmount);
				cout << "\nAmount Deposited Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;

			}

			else
			{
				cout << "\nOperation Cancelled." << endl;
			}
    }
};

