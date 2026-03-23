#pragma once

#include "Utils/clsInputValidate.h"
#include "clsPerson.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"


class clsBankClient : public clsPerson
{
private :
	enum enMode{ EmptyMode = 0, UpdateMode = 1, AddClientMode = 2, DeleteClientMode
	= 3, ListClientsMode = 4, TotalBalanceMode = 5};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TrasnferLogRecord;


		vector <string> TransferLogDataLine = clsString::Split(Line, Seperator);
		TrasnferLogRecord.DataTime = TransferLogDataLine[0];
		TrasnferLogRecord.AccountNumberSource = TransferLogDataLine[1];
		TrasnferLogRecord.AccountNumberDestination = TransferLogDataLine[2];
		TrasnferLogRecord.Amount = stod(TransferLogDataLine[3]);
		TrasnferLogRecord.BalanceSource = stod(TransferLogDataLine[4]);
		TrasnferLogRecord.BalanceDestination = stod(TransferLogDataLine[5]);
		TrasnferLogRecord.Username = TransferLogDataLine[6];
		return TrasnferLogRecord;

	}

	string _PrepareTransferRecord(double Amount, clsBankClient& DestinationClient, string Seperator = "#//#") {
		string TransferRecord = "";
		TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferRecord += _AccountNumber + Seperator;
		TransferRecord += DestinationClient.AccountNumber() + Seperator;
		TransferRecord += to_string(Amount) + Seperator;
		TransferRecord += to_string(_AccountBalance) + Seperator;
		TransferRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferRecord += CurrentUser.UserName;
		return TransferRecord;
	}

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

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

	clsBankClient()	 {
		_Mode = EmptyMode;
		_AccountNumber = "";
		_PinCode = "";
		_AccountBalance = 0;
	}

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber
		, string AccountNumber, string PinCode, float Balance)
		: clsPerson(FirstName, LastName, Email, PhoneNumber) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = Balance;
	}

	struct stTransferLogRecord {
		string DataTime;
		string AccountNumberSource, AccountNumberDestination;
		float Amount, BalanceSource, BalanceDestination;
		string Username;
	};

	bool IsEmpty() {
		if (_Mode == EmptyMode)
			return true;
		else
			return false;
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string NewPin) {
		_PinCode = NewPin;
	}

	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float NewAccountBalance) {
		_AccountBalance = NewAccountBalance;
	}

	float GetAccountBalance() const {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(AddClientMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances() {
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		double TotalBalance = 0;
		for (clsBankClient& C : vClients) {
			TotalBalance += C.AccountBalance;

		}
		return TotalBalance;
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;

	}


	enum enSaveResults{ svFailedEmptyObject = 0, svSucceeded = 1,
		svFaliedAccountNumberExists = 2};

	enSaveResults Save() {
		switch (_Mode) {

		case EmptyMode :

			if (IsEmpty())
			{
				return svFailedEmptyObject;
			}

		case UpdateMode :
			_Update();
			return svSucceeded;
		case AddClientMode :
			if (clsBankClient::IsClientExist(_AccountNumber)) {
				return svFaliedAccountNumberExists;
			}
			_AddClient();
			return svSucceeded;
		}
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)

			return false;

		else {
			_AccountBalance -= Amount;
			Save();
		}
		
	}

	bool Transfer(double Amount, clsBankClient &DestinationClient)
	{
		if (Amount > _AccountBalance)
			return false;

		else {
			Withdraw(Amount);
			DestinationClient.Deposit(Amount);
			RegisterTransfer(Amount, DestinationClient);
			return true;
		}

	}

	void RegisterTransfer(double Amount, clsBankClient& DestinationClient) {

		fstream MyFile;
		string Line = _PrepareTransferRecord(Amount, DestinationClient);
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << Line << endl;

			MyFile.close();
		}
	}

	static vector <stTransferLogRecord> GetTransferLogList() {
		return _LoadTransferLogDataFromFile();
	}
};


