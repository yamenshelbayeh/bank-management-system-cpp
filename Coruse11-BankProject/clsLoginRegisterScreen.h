#pragma once
#include "clsScreen.h"
class clsLoginRegisterScreen :
    protected clsScreen
{
private :
	static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord) {

		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
	}
public :

    static void ShowLoginRegisterFile() {

		if (!CheckAccessRights(clsUser::PLoginRegister)) {
			return;
		}

		vector <clsUser::stLoginRegisterRecord> Logins = clsUser::GetLoginRegisterList();
		
		string Title = "\t  Login Register List Screen";
		string SubTitle = "\t  (" + to_string(Logins.size()) + ") Client(s)";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (Logins.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsUser::stLoginRegisterRecord Login : Logins)
			{

				PrintLoginRegisterRecordLine(Login);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

    }
};

