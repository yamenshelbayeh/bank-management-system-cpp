#pragma once
#include "clsBankClient.h"

class clsCurrency 
{
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> Currencies;
		Currencies = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, Currencies[0], Currencies[1], Currencies[2],
			stod(Currencies[3]));

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static  vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{

		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrencies.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrencies;

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string CurrencyRecord = "";
		CurrencyRecord += Currency._Country + Seperator;
		CurrencyRecord += Currency._CurrencyCode + Seperator;
		CurrencyRecord += Currency._CurrencyName + Seperator;
		CurrencyRecord += to_string(Currency._Rate);

		return CurrencyRecord;

	}

	static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencies)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : vCurrencies)
			{
				
					DataLine = _ConvertCurrencyObjectToLine(C);
					MyFile << DataLine << endl;
			

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}
		_SaveCurrenciesDataToFile(_vCurrencys);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyName = CurrencyName;
		_CurrencyCode = CurrencyCode;
		_Rate = Rate;
	}

	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrenciesDataFromFile();

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());

	}

};

