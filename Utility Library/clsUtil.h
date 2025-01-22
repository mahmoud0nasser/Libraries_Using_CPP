#pragma once

#include <iostream>
#include "clsDate.h"

using namespace std;

class clsUtil
{
public:
	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}

		return Text;
	}

	static int SRand()
	{
		srand((unsigned)time(NULL));

		return rand();
	}

	static int RandomNumber(int From, int To)
	{
		int RandNumber = rand() % (To - From + 1) + From;

		return RandNumber;
	}

	enum enCharType
	{
		SamallLetter = 1,
		CapitalLetter = 2,
		SpecialCharacter = 3,
		Digit = 4,
		MixChars = 5
	};

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SamallLetter:
			return (char)RandomNumber(97, 122);
		case enCharType::CapitalLetter:
			return (char)RandomNumber(65, 90);
		case enCharType::SpecialCharacter:
			return (char)RandomNumber(33, 47);
		case enCharType::Digit:
			return (char)RandomNumber(48, 57);
		case enCharType::MixChars:
			return (char)GetRandomCharacter((enCharType)RandomNumber(1, 4));
		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word = "";

		for (short i = 0; i < Length; i++)
		{
			Word += GetRandomCharacter(CharType);
		}

		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";

		for (short i = 0; i < 4; i++)
		{
			Key += GenerateWord(CharType, 5);

			if (i != 3)
				Key += "-";
		}

		return Key;
	}

	static void GenerateKeys(short LengthOfKeys, enCharType CharType)
	{
		for (int i = 0; i < LengthOfKeys; i++)
		{
			cout << "Key [ " << i + 1 << "]: " << GenerateKey(CharType) << endl;
		}
	}

	static int ReadPositiveNumber(string Message)
	{
		int Number = 0;

		do {
			cout << Message << endl;
			cin >> Number;
		} while (Number <= 0);

		return Number;
	}

	static void ReadArray(int arr[], int& arrLength)
	{
		cout << "\nEnter number of elements:\n";

		for (int i = 0; i < arrLength; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
		}
		cout << "\n";
	}

	void PrintStringArray(string arr[], int arrLength)
	{
		cout << "\nArray elements:\n\n";

		for (int i = 0; i < arrLength; i++)
		{
			cout << "Array[" << i << "] : ";
			cout << arr[i] << "\n";
		}

		cout << "\n";
	}

	static int TimesRepeated(int arr[], int arrLength, int Number)
	{
		int Counter = 0;

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				Counter++;
		}

		return Counter;
	}

	static void PrintArray(int arr[], int Length)
	{
		cout << "Array Elements: ";
		for (int i = 0; i < Length; i++)
		{
			cout << arr[i] << " ";
		}
	}

	static void FillArrayWithRandomNumbers(int arr[], int& arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To);
	}

	static void FillArrayWithRandomNumbers(string arr[], int& arrLength, enCharType CharType, short LengthOfWords)
	{
		for (int i = 0; i < arrLength; i++) {
			string Word = "";
			for (int j = 0; j < LengthOfWords; j++)
			{
				Word += GetRandomCharacter(CharType);
			}
			arr[i] = Word;
		}
	}

	static int MaxNumberInArray(int arr[], int arrLength)
	{
		int Max = 0;

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > Max)
			{
				Max = arr[i];
			}
		}

		return Max;
	}

	static int MinNumberInArray(int arr[], int arrLength)
	{
		int Min = 0;
		Min = arr[0];

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}

		return Min;
	}

	static int SumArray(int arr[], int arrLength)
	{
		int Sum = 0;

		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}

		return Sum;
	}

	static float ArrayAverage(int arr[], int arrLength)
	{
		return  (float)SumArray(arr, arrLength) / arrLength;
	}

	static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}

	enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

	static enPrimNotPrime CheckPrime(int Number)
	{
		int M = round(Number / 2);

		for (int Counter = 2; Counter <= M; Counter++) {
			if (Number % Counter == 0)
				return enPrimNotPrime::NotPrime;
		}

		return enPrimNotPrime::Prime;
	}

	static void CopyOnlyPrimeNumbers(int arrSource[], int arrDestination[], int arrLength, int& arr2Lenght)
	{
		int Counter = 0;

		for (int i = 0; i < arrLength; i++) {
			if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime) {
				arrDestination[Counter] = arrSource[i];
				Counter++;
			}
		}

		arr2Lenght = --Counter;
	}

	static void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrSum[i] = arr1[i] + arr2[i];
		}
	}

	static void Swap(int& Number_1, int& Number_2)
	{
		int Temp = 0;

		Temp = Number_1;
		Number_1 = Number_2;
		Number_2 = Temp;
	}

	static void Swap(float& Number_1, float& Number_2)
	{
		float Temp = 0.0;

		Temp = Number_1;
		Number_1 = Number_2;
		Number_2 = Temp;
	}

	static void Swap(string& Word_1, string& Word_2)
	{
		string Temp = "";

		Temp = Word_1;
		Word_1 = Word_2;
		Word_2 = Temp;
	}

	static void Swap(clsDate& Date_1, clsDate& Date_2)
	{
		clsDate Temp;

		Temp = Date_1;
		Date_1 = Date_2;
		Date_2 = Temp;
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++) {
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void CopyArrayInReverseOrder(int arrSource[], int arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[arrLength - 1 - i];
	}

	static void FillArrayWithRandomKeys(string arr[], int& arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++) {
			arr[i] = GenerateKey(CharType);
		}
	}

	static short FindNumberPositionInArray(int Number, int arr[], int arrLength)
	{
		/*
		This function will search for a number in array and return its index,
		or return -1 if it does not exists
		*/

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				return i; // and return the index    
		}

		//if you reached here, this means the number is not found	
		return -1;
	}

	static bool IsNumberInArray(int Number, int arr[], int arrLength)
	{
		return FindNumberPositionInArray(Number, arr, arrLength) != -1;
	}

	static int ReadNumber()
	{
		int Number;
		cout << "\nPlease enter a number? ";
		cin >> Number; return Number;
	}

	static void AddArrayElement(int Number, int arr[], int& arrLength)
	{
		//its a new element so we need to add the length by 1
		arrLength++;
		arr[arrLength - 1] = Number;
	}

	static void InputUserNumbersInArray(int arr[], int& arrLength)
	{
		bool AddMore = true;
		do
		{
			AddArrayElement(ReadNumber(), arr, arrLength);
			cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
			cin >> AddMore;
		} while (AddMore);
	}

	static void CopyArrayUsingAddArrayElement(int arrSource[], int arrDestination[], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
	}

	static void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++) {
			if (arrSource[i] % 2 != 0)
			{
				AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
			}
		}
	}

	static void CopyPrimeNumbers(int arrSource[], int arrDestination[], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
			if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
			{
				AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
			}
	}

	static void CopyDistinctNumbersToArray(int arrSource[], int arrDestination[], int SourceLength, int& DestinationLength)
	{
		for (int i = 0; i < SourceLength; i++)
		{
			if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
			{
				AddArrayElement(arrSource[i], arrDestination, DestinationLength);
			}
		};
	}

	static bool IsPalindromeArray(int arr[], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			if (arr[i] != arr[Length - i - 1])
			{
				return false;
			}
		};
		return true;
	}

	static int OddCount(int arr[100], int arrLength)
	{
		int Counter = 0;

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 != 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	static int EvenCount(int arr[], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 == 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	static int PositiveCount(int arr[], int arrLength)
	{
		int Counter = 0;

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] >= 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	static int NegativeCount(int arr[], int arrLength)
	{
		int Counter = 0;

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	static float MyABS(float Number)
	{
		if (Number > 0)
			return Number;
		else
			return Number * -1;
	}

	static float GetFractionPart(float Number)
	{
		return Number - int(Number);
	}

	static int MyRound(float Number)
	{
		int IntPart;
		IntPart = int(Number);

		float FractionsPart = GetFractionPart(Number);

		if (abs(FractionsPart) >= .5)
		{
			if (Number > 0)
				return ++IntPart;
			else
				return --IntPart;
		}
		else
		{
			return IntPart;
		}
	}

	static int MyFloor(float Number)
	{
		if (Number > 0)
			return int(Number);
		else
			return int(Number) - 1;
	}

	static int MyCeil(float Number)
	{
		if (abs(GetFractionPart(Number)) > 0)
			if (Number > 0)
				return int(Number) + 1;
			else
				return int(Number);
		else
			return Number;
	}

	static int MySqrt(float Number)
	{
		return pow(Number, 0.5);
	}
};