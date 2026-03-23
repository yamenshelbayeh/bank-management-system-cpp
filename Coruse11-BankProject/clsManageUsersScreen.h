#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsListUsersScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen :
    protected clsScreen
{

private :

    enum enManageUsersChoices { eListUsers = 1, eAddUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenuFromManage = 6 };

	static  void _GoBackToManageUsersMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menu...\n";
		system("pause>0");
		ShowManageUsersMenu();
	}

	static enManageUsersChoices _ReadManageUsersMenuChoice() {

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

		short Number = clsInputValidate::ReadIntNumberBetween(1, 6, "Wrong Input, Number snhould be between 1 and 6. Please Try Again : ");

		return enManageUsersChoices(Number);

	}

	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowListUsersScreen();

	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();

	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();

	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PreformManageUsersMenuOption(enManageUsersChoices Choice) {

		switch (Choice) {
		case eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		case eAddUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case eFindUser :
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case eMainMenuFromManage :
			break;
		}

	}
public :

    static void ShowManageUsersMenu() {

		if (!CheckAccessRights(clsUser::PManageUsers)) {
			return;
		}
        system("cls");
        _DrawScreenHeader("\t  Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

		_PreformManageUsersMenuOption(_ReadManageUsersMenuChoice());

    }
};

