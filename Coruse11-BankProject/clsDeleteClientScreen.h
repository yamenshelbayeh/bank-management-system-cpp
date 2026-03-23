#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
class clsDeleteClientScreen :
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

	static void ShowDeleteClientScreen() {

		if (!CheckAccessRights(clsUser::PDelete)) {
			return;
		}
		clsScreen::_DrawScreenHeader("\t  Delete Client Screen");

		

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount number is not found, please try again : ";
			AccountNumber = clsInputValidate::ReadString();
		}


		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char Answer;
		cout << "\nAre u sure u want to delete this card? y/n ";
		cin >> Answer;

		if (toupper(Answer) == 'Y') {
			if (Client.Delete()) {
				cout << "\nClient Deleted Successfully.\n";
				_PrintClient(Client);
			}
			else
				cout << "\nError Client was not Deleted";
		}



	}
};

