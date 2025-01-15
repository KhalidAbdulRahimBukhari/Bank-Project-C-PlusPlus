#pragma once
#include<iostream>
#include<iomanip>
#include"clsCurrency.h"
#include"clsScreen.h"
class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << left << setw(8) << "" << "| " << setw(25) << Currency.Country();
		cout << "| " << setw(10) << Currency.CurrencyCode();
		cout << "| " << setw(30) << Currency.CurrencyName();
		cout << left << setw(8) << "| " << setw(12) << Currency.Rate();
	}


public:


	static void ShowListCurrenciesScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t Currencies List Screen";
		string SubTitle = "\t  (" + to_string (vCurrencies.size())  + ") Currency.";

		_DrawScreenHeader(Title,SubTitle);

		cout  << setw(8) << left << "" << "\n\t__________________________________________________";
		cout << "______________________________________________________________________\n" << endl;
		cout << left << setw(8) << "" << "| " << setw(25) << "Country";
		cout << "| " << setw(10) << "Code";
		cout << "| " << setw(30) << "Name";
		cout << left << setw(8) << "| " << setw(12) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t__________________________________________________";
		cout << "______________________________________________________________________\n" <<endl;

		if (vCurrencies.size() == 0)
		{
			cout << "\nNo Currencies available in the system\n";
		}
		else

			for (clsCurrency Currency : vCurrencies)
			{
				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}

		cout << left << setw(8) << "" << "\t\n__________________________________________________";
		cout << "______________________________________________________________________\n";

	}

};

