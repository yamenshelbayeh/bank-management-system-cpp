#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include "clsFindCurrencyScreen.h"

class clsCurrencyExchangeMenu :
    protected clsScreen
{
private :

	enum enCurrenciesMainMenueOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};

    static void _GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menu...";
        system("pause>0");
        ShowCurrencyExchangeMenu();
    }

    static void _ShowCurrenciesListScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();

    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();

    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

	static enCurrenciesMainMenueOptions _ReadCurrencyMenuChoice() {

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";

		short Number = clsInputValidate::ReadIntNumberBetween(1, 5, "Wrong Input, Number should be between 1 and 5. Please Try Again : ");

		return enCurrenciesMainMenueOptions(Number);

	}

	static void _PreformMainMenuOption(enCurrenciesMainMenueOptions Choice) {

		switch (Choice) {
		case eListCurrencies:
			system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenue();
			break;
		case eFindCurrency:
			system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenue();
			break;
		case eUpdateCurrencyRate:
			system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenue();
			break;
		case eCurrencyCalculator:
			system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenue();
			break;
		case eMainMenue:
			break;
		}

	}
public :

    static void ShowCurrencyExchangeMenu() {

        if (!CheckAccessRights(clsUser::PCurrencyExchange)) {
            return;
        }
        system("cls");
        _DrawScreenHeader("    Currancy Exhange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PreformMainMenuOption(_ReadCurrencyMenuChoice());
    }
};

