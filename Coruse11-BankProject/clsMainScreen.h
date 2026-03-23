#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrency.h"
#include "clsCurrencyExchangeMenu.h"

using namespace std;


class clsMainScreen : protected clsScreen
{
private :

	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
	};

	
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();

	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();

	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();

	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();

	}

	static void _ShowTransactionsMenu()
	{
		clsTransactionsScreen::ShowTransactionsMenu();

	}

	static void _ShowManageUsersMenu()
	{
		clsManageUsersScreen::ShowManageUsersMenu();

	}

	static void _ShowLoginRegisterMenu() {
		clsLoginRegisterScreen::ShowLoginRegisterFile();
	}

	static void _ShowCurrencyExchangeMenu() {
		clsCurrencyExchangeMenu::ShowCurrencyExchangeMenu();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("","");
	}

	static enMainMenueOptions _ReadMainMenuChoice() {

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		
		short Number = clsInputValidate::ReadIntNumberBetween(1, 10, "Wrong Input, Number should be between 1 and 10. Please Try Again : ");
		
		return enMainMenueOptions(Number);

	}

	static void _PreformMainMenuOption(enMainMenueOptions Choice) {

		switch (Choice) {
		case eListClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		case eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		case eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case eShowTransactionsMenu:
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenue();
			break;
		case eManageUsers:
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenue();
		case eLoginRegister :
			system("cls");
			_ShowLoginRegisterMenu();
			_GoBackToMainMenue();
		case eCurrencyExchange :
			system("cls");
			_ShowCurrencyExchangeMenu();
			_GoBackToMainMenue();
		case eExit:
			system("cls");
			_Logout();
			break;
		}

	}

public :

	static void ShowMainMenu() {

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		_PreformMainMenuOption(_ReadMainMenuChoice());
	}


};

