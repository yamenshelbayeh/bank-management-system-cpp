#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsUpdateClientScreen :
    protected clsScreen
{
private : 

	static void ReadClientInfo(clsBankClient& Client) {

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

	static void ShowUpdateClientScreen() {

		if (!CheckAccessRights(clsUser::PUpdate)) {
			return;
		}

		_DrawScreenHeader("\tUpdate Client Screen");

		cout << "\nPlease Enter client Accout Number : ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount number is not found, please try again : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nUpdate Client Info : ";
		cout << "\n____________________\n";

		ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult = Client.Save();

		switch (SaveResult) {
		case clsBankClient::svSucceeded:
			cout << "\nAccount Updated Successfully.\n";
			_PrintClient(Client);
			break;
		case clsBankClient::svFailedEmptyObject:
			cout << "\nError Account was not saved because its Empty.\n";
			break;
		}
	}


};

