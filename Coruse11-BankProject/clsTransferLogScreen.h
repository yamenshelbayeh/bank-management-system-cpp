#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen :
    protected clsScreen
{

private : 

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DataTime;
        cout << "| " << setw(8) << left << TransferLogRecord.AccountNumberSource;
        cout << "| " << setw(8) << left << TransferLogRecord.AccountNumberDestination;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.BalanceSource;
        cout << "| " << setw(10) << left << TransferLogRecord.BalanceDestination;
        cout << "| " << setw(8) << left << TransferLogRecord.Username;


    }

public :

    static void ShowTransferLogScreen() {

        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\t  Transfer Log List Screen";
        string SubTitle = "\t  (" + to_string(vTransferLogRecord.size()) + ") Client(s)";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

