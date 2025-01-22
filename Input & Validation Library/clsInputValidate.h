#pragma once

#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsInputValidate
{

public:
	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (From > To)
			clsUtil::Swap(From, To);

		if (Number < From || Number > To)
			return false;
		return true;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (From > To)
			clsUtil::Swap(From, To);

		if (Number < From || Number > To)
			return false;
		return true;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (From > To)
			clsUtil::Swap(From, To);

		if (Number < From || Number > To)
			return false;
		return true;
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (!clsDate::IsDate1BeforeDate2(DateFrom, DateTo))
		{
			clsUtil::Swap(DateFrom, DateTo);
		}

		if (clsDate::IsDate1AfterDate2(Date, DateFrom) && clsDate::IsDate1BeforeDate2(Date, DateTo))
			return true;

		return false;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again? \n")
	{
		int Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage)
	{
		int Number = ReadIntNumber("Invalid Number, Enter again: \n");

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber("Invalid Number, Enter again: \n");
		}

		return Number;
	}

	static float ReadFltNumberBetween(float From, float To, string Message)
	{
		float Number = 0;

		cin >> Number;

		Number = ReadFltNumber("Invalid Number, Enter again: \n");

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message;
			cin >> Number;
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string Message)
	{
		double Number = 0;

		cin >> Number;

		Number = ReadDblNumber("Invalid Number, Enter again: \n");

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message;
			cin >> Number;
		}

		return Number;
	}

	static float ReadFltNumber(string Message)
	{
		float Number = 0;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
			cin >> Number;
		}

		return Number;
	}

	static double ReadDblNumber(string Message)
	{
		double Number = 0;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
			cin >> Number;
		}

		return Number;
	}

	static bool isValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
};

