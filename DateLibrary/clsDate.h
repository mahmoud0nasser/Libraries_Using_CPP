#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

class clsDate
{
private:
	int _Day;
	int _Month;
	int _Year;

	vector<string> Split(string Date, string Delim = "/")
	{
		int pos;
		vector<string> vWords;

		while ((pos = Date.find(Delim)) != string::npos)
		{
			string Word = Date.substr(0, pos);

			if (Word != "")
			{
				vWords.push_back(Word);
			}
			Date.erase(0, pos + Delim.length());
		}

		if (Date != "")
			vWords.push_back(Date);

		return vWords;
	}

	void ConvertStringToDate(string Date)
	{
		vector<string> vDate = Split(Date);

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	void GetDateFromDayOrderInYearInSameClass(short DateOrderInYear, short Year) {
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		_Year = Year;
		_Month = 1;
		while (true) {
			MonthDays = NumberOfDaysInAMonth(_Month, Year);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				_Month++;
			}
			else {
				_Day = RemainingDays;
				break;
			}
		}
	}

public:

	clsDate()
	{
		time_t now = time(0);
		tm* t = localtime(&now);
		_Day = (short)t->tm_mday;
		_Month = (short)t->tm_mon + 1;
		_Year = t->tm_year + 1900;
	}

	clsDate(string Date)
	{
		ConvertStringToDate(Date);
	}

	clsDate(short Day, short Month, int Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(int Days, int Year)
	{
		GetDateFromDayOrderInYearInSameClass(Days, Year);
	}

	static bool isLeapYear(int Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0;
	}

	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	static int DaysInLeapYear(int Year)
	{
		return (isLeapYear(Year) ? 366 : 365);
	}

	int DaysInLeapYear()
	{
		return DaysInLeapYear(_Year);
	}

	static int HoursInLeapYear(int Year)
	{
		return DaysInLeapYear(Year) * 24;
	}

	int HoursInLeapYear()
	{
		return HoursInLeapYear(_Year);
	}

	static int MinutesInLeapYear(int Year)
	{
		return HoursInLeapYear(Year) * 60;
	}

	int MinutesInLeapYear()
	{
		return MinutesInLeapYear(_Year);
	}

	static int SecondsInLeapYear(int Year)
	{
		return MinutesInLeapYear(Year) * 60;
	}

	int SecondsInLeapYear()
	{
		return SecondsInLeapYear(_Year);
	}

	static short NumberOfDaysInAMonth(int Month, int Year) {
		if (Month < 1 || Month > 12)
			return 0;

		int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	static short DayOfWeekOrder(clsDate Date) {
		short a, y, m;
		a = (14 - Date._Month) / 12;
		y = Date._Year - a;
		m = Date._Month + (12 * a) - 2;
		// Gregorian: 0: Sun, 1: Mon, 2: Tue ... etc.
		return (Date._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	static short DayOfWeekOrder(int Day, int Month, int Year) {
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian: 0: Sun, 1: Mon, 2: Tue ... etc.
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(*this);
	}

	static string DayShortName(short DayOfWeekOrder) {
		string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder());
	}

	static string MonthShortName(int MonthNumber) {
		string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return (Months[MonthNumber - 1]);
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year) {
		int NumberOfDays;
		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, Month, Year);
		NumberOfDays = NumberOfDaysInAMonth(Month, Year);
		// Print the current month name
		printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");
		for (int j = 1; j <= NumberOfDays; j++) {
			printf("%5d", j);
			if (++i == 7) {
				i = 0;
				printf("\n");
			}
		}
		printf("\n  _________________________________\n");
	}

	void PrintMonthCalendar()
	{
		return PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(int Year) {
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");
		for (int i = 1; i <= 12; i++) {
			PrintMonthCalendar(i, Year);
		}
		return;
	}

	void PrintYearCalendar()
	{
		return PrintYearCalendar(_Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
		short TotalDays = 0;
		for (int i = 1; i <= Month - 1; i++) {
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(clsDate Date) {
		short TotalDays = 0;
		for (int i = 1; i <= Date._Day - 1; i++) {
			TotalDays += NumberOfDaysInAMonth(i, Date._Year);
		}
		TotalDays += Date._Day;
		return TotalDays;
	}

	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(*this);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date._Year = Year;
		Date._Month = 1;
		while (true) {
			MonthDays = NumberOfDaysInAMonth(Date._Month, Year);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else {
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	clsDate GetDateFromDayOrderInYear(int Days)
	{
		return GetDateFromDayOrderInYear(Days, _Year);
	}

	static clsDate DateAddDays(short Days, clsDate Date) {
		short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date);
		short MonthDays = 0;
		Date._Month = 1;
		while (true) {
			MonthDays = NumberOfDaysInAMonth(Date._Month, Date._Year);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date._Month++;
				if (Date._Month > 12) {
					Date._Month = 1;
					Date._Year++;
				}
			}
			else {
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	clsDate DateAddDays(int Days)
	{
		return DateAddDays(Days, *this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {
		return (Date1._Year < Date2._Year) ? true :
			((Date1._Year == Date2._Year) ?
				(Date1._Month < Date2._Month ? true :
					(Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false))
				: false);
	}

	bool IsDate1BeforeDate2(clsDate Date)
	{
		return IsDate1BeforeDate2(*this, Date);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
		return (Date1._Year == Date2._Year) ?
			((Date1._Month == Date2._Month) ?
				((Date1._Day == Date2._Day) ? true : false)
				: false)
			: false;
	}

	bool IsDate1EqualDate2(clsDate Date)
	{
		return IsDate1EqualDate2(*this, Date);
	}

	static bool IsLastDayInMonth(clsDate Date) {
		return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	// Function to check if a month is the last month in the year
	static bool IsLastMonthInYear(short Month) {
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static clsDate IncreaseDateByOneDay(clsDate Date) {
		if (IsLastDayInMonth(Date)) {
			if (IsLastMonthInYear(Date._Month)) {
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else {
				Date._Day = 1;
				Date._Month++;
			}
		}
		else {
			Date._Day++;
		}
		return Date;
	}

	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2)) {
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}

	int GetDifferenceInDays(clsDate Date, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date, IncludeEndDay);
	}

	static clsDate GetSystemDate() {
		clsDate Date;
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);
		Date._Year = now.tm_year + 1900;
		Date._Month = now.tm_mon + 1;
		Date._Day = now.tm_mday;
		return Date;
	}

	static int CalculateYourAgeInDays(clsDate BirthDate, bool IncludeEndDay = false) {
		int Days = 0;
		clsDate SystemDate = GetSystemDate();
		while (IsDate1BeforeDate2(BirthDate, SystemDate)) {
			Days++;
			BirthDate = IncreaseDateByOneDay(BirthDate);
		}
		return IncludeEndDay ? ++Days : Days;
	}

	int CaculateYourAgeInDays(clsDate Date, bool IncludeEndDay = false)
	{
		return CaculateYourAgeInDays(*this, IncludeEndDay);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2) {
		clsDate TempDate;
		TempDate._Year = Date1._Year;
		TempDate._Month = Date1._Month;
		TempDate._Day = Date1._Day;
		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;
		Date2._Year = TempDate._Year;
		Date2._Month = TempDate._Month;
		Date2._Day = TempDate._Day;
	}

	void SwapDates(clsDate& Date)
	{
		SwapDates(*this, Date);
	}

	static int GetDifferenceInDaysNegative(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
		int Days = 0;
		short SwapFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2)) {
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2)) {
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	int GetDifferenceInDaysNegative(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDaysNegative(*this, Date2, IncludeEndDay);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date) {
		for (int i = 1; i <= 7; i++) {
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date) {
		for (short i = 1; i <= Weeks; i++) {
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Weeks)
	{
		*this = IncreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date) {
		if (Date._Month == 12) {
			Date._Month = 1;
			Date._Year++;
		}
		else {
			Date._Month++;
		}

		// Check if the day exceeds the maximum days in the current month
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth) {
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate Date) {
		for (short i = 1; i <= Days; i++) {
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(short Days)
	{
		*this = IncreaseDateByXDays(Days, *this);
	}

	static clsDate IncreaseDateByXMonths(short Months, clsDate Date) {
		for (short i = 1; i <= Months; i++) {
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short Months)
	{
		*this = IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date) {
		Date._Year++;
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate Date) {
		for (short i = 1; i <= Years; i++) {
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	void IncreaseDateByXYears(short Years)
	{
		*this = IncreaseDateByXYears(Years, *this);
	}

	static clsDate IncreaseDateByXYearsFaster(short Years, clsDate Date) {
		Date._Year += Years;
		return Date;
	}

	void IncreaseDateByXYearsFaster(short Years)
	{
		*this = IncreaseDateByXYearsFaster(Years, *this);
	}

	static clsDate IncreaseDateByOneDecade(clsDate Date) {
		Date._Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short Decade, clsDate Date) {
		for (short i = 1; i <= Decade * 10; i++) {
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	void IncreaseDateByXDecades(short Decade)
	{
		*this = IncreaseDateByXDecades(Decade, *this);
	}

	static clsDate IncreaseDateByXDecadesFaster(short Decade, clsDate Date) {
		Date._Year += Decade * 10;
		return Date;
	}

	void IncreaseDateByXDecadesFaster(short Decade)
	{
		*this = IncreaseDateByXDecadesFaster(Decade, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date) {
		Date._Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate Date) {
		Date._Year += 1000;
		return Date;
	}

	void IncreaseDateByOneMillennium()
	{
		*this = IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate Date) {
		if (Date._Day == 1) {
			if (Date._Month == 1) {
				Date._Month = 12;
				Date._Day = 31;
				Date._Year--;
			}
			else {
				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
			}
		}
		else {
			Date._Day--;
		}
		return Date;
	}

	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date) {
		for (int i = 1; i <= 7; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date) {
		for (short i = 1; i <= Weeks; i++) {
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short Weeks)
	{
		*this = DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date) {
		if (Date._Month == 1) {
			Date._Month = 12;
			Date._Year--;
		}
		else {
			Date._Month--;
		}
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth) {
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate Date) {
		for (short i = 1; i <= Days; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short Days)
	{
		*this = DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate Date) {
		for (short i = 1; i <= Months; i++) {
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months)
	{
		*this = DecreaseDateByXMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date) {
		Date._Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate Date) {
		for (short i = 1; i <= Years; i++) {
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	void DecreaseDateByXYears(short Years)
	{
		*this = DecreaseDateByXYears(Years, *this);
	}

	static clsDate DecreaseDateByXYearsFaster(short Years, clsDate Date) {
		Date._Year -= Years;
		return Date;
	}

	void DecreaseDateByXYearsFaster(short Years)
	{
		*this = DecreaseDateByXYearsFaster(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate Date) {
		Date._Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decade, clsDate Date) {
		for (short i = 1; i <= Decade * 10; i++) {
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	void DecreaseDateByXDecades(short Decade)
	{
		*this = DecreaseDateByXDecades(Decade, *this);
	}

	static clsDate DecreaseDateByXDecadesFaster(short Decade, clsDate Date) {
		Date._Year -= Decade * 10;
		return Date;
	}

	void DecreaseDateByXDecadesFaster(short Decade)
	{
		*this = DecreaseDateByXDecadesFaster(Decade, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate Date) {
		Date._Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate Date) {
		Date._Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(clsDate Date) {
		return DayOfWeekOrder(Date) == 6;
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date) {
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date) {
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date) {
		return 6 - DayOfWeekOrder(Date);
	}

	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date1) {
		clsDate EndOfMonthDate;
		EndOfMonthDate._Day = NumberOfDaysInAMonth(Date1._Month, Date1._Year);
		EndOfMonthDate._Month = Date1._Month;
		EndOfMonthDate._Year = Date1._Year;
		return GetDifferenceInDays(Date1, EndOfMonthDate, true);
	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date1) {
		clsDate EndOfYearDate;
		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date1._Year;
		return GetDifferenceInDays(Date1, EndOfYearDate, true);
	}

	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo) {
		short DaysCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo)) {
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DaysCount;
	}

	short CalculateVacationDays(clsDate DateTo)
	{
		return CalculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
		//we get rid of all weekends before the first business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}

	clsDate CalculateVacationReturnDate(short VacationDays)
	{
		return CalculateVacationReturnDate(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
		return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
	}

	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare {
		Before = -1,
		Equal = 0,
		After = 1
	};

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2) {
		if (IsDate1BeforeDate2(Date1, Date2)) return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2)) return enDateCompare::Equal;
		return enDateCompare::After; // No need for explicit check; this is faster
	}

	enDateCompare CompareDates(clsDate Date)
	{
		return CompareDates(*this, Date);
	}
};