#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsWithdrawScreen :
    protected clsScreen
{
private:

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


public:

	static void ShowWithdrawScreen() {

		_DrawScreenHeader("\t   Withdraw Screen");

		cout << "\nPlease Enter client Accout Number : ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount number is not found, please try again : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		char Answer;
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		cout << "\nEnter Withdraw Amount : ";

		double WithdrawAmount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to preform this transaction? y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.Withdraw(WithdrawAmount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << WithdrawAmount;
				cout << "\nYour Balance is: " << Client.AccountBalance;

			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}
};

