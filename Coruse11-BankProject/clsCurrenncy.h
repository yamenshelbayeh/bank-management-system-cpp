#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsCurrenncy :
    private clsScreen
{
private :
    enum enMode{EmptyMode = 0, UpdateMode = 1};
    enMode _Mode;

    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

	static clsCurrenncy _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> Currencies;
		Currencies = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, Currencies[0], Currencies[1], Currencies[2],
			Currencies[3]);

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				if (C._MarkedForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

	}

	void _AddDataLineToFile(string Line) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << Line << endl;

			MyFile.close();
		}

	}

	void _AddClient() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	static vector <stTransferLogRecord> _LoadTransferLogDataFromFile() {

		vector <stTransferLogRecord> TransferLogList;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				stTransferLogRecord TransferLog = _ConvertTransferLogLineToRecord(Line);

				TransferLogList.push_back(TransferLog);
			}

			MyFile.close();

		}

		return TransferLogList;
	}

	public :

		clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
			 {
			_Mode = Mode;
			_Country = Country;
			_CurrencyName = CurrencyName;
			_CurrencyCode = CurrencyCode;
		}
};

