#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsTotalBalanceScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen :
    protected clsScreen
{

private :

	enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, 
		eTransfer = 4 , eTransferLog = 5, eShowMainMenu = 6 };

	static  void _GoBackToTransactionMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menu...\n";
		system("pause>0");
		ShowTransactionsMenu();
	}

	static enTransactionsMenuOptions _ReadTransactionsMenuChoice() {

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

		short Number = clsInputValidate::ReadIntNumberBetween(1, 6, "Wrong Input, Number should be between 1 and 6. Please Try Again : ");

		return enTransactionsMenuOptions(Number);

	}

	static void _PreformTransactionsMenuOption(enTransactionsMenuOptions Choice) {

		switch (Choice) {
		case eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenu();
			break;
		case eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenu();
			break;
		case eTotalBalance:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenu();
			break;
		case eTransfer :
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenu();
		case eTransferLog :
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenu();
		case eShowMainMenu:
			break;
		}

	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalanceScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen() {

		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() {

		clsTransferLogScreen::ShowTransferLogScreen();

	}

public :

    static void ShowTransactionsMenu() {

		if (!CheckAccessRights(clsUser::PTransactions)) {
			return;
		}

        system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

			

		_PreformTransactionsMenuOption(_ReadTransactionsMenuChoice());
    }
};

