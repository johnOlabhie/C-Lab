#include <cassert>
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

// Julian day numbers, representing the number of days since 1 Jan 4713BC,
// are used to avoid the various quirks of calendars, and to simplify
// various calculations with dates.

// The time function returns the number of seconds from the start of
// 1 Jan 1970 to now, from which we can compute today's Julian day number.


const long seconds_per_day = 24*60*60L;

// Day number when time() == 0 at start of day (1 Jan 1970)
const long time_epoch = 2440588L;

// Julian day number for today
long julian_today() {
	return time(0) / seconds_per_day + time_epoch;
}

// Up to 2 Sep 1752, Britain and colonies used the Julian calendar.
// From the next day, they used the Gregorian calendar, in which that
// day was 14 Sep 1752 (i.e. 11 days were dropped).

// Day number of first day of Gregorian calendar in Britain (14 Sep 1752)
const long gregorian_epoch = 2361222L;

// Convert a date to a Julian day number
long date_to_julian(int d, int m, int y) {
	// there was no year 0
	if (y < 0)
		y++;
	// consider Jan and Feb as belonging to previous year
	if (m <= 2) {
		y--;
		m += 12;
	}
	m++;
	long start_of_year = 1720995L + (long)floor(365.25 * y);
	int day_of_year = (long)floor(30.6001 * m) + d;
	long jd = start_of_year + day_of_year;
	// Gregorian correction
	if (jd >= gregorian_epoch)
		jd += 2 + y/400 - y/100;
	return jd;
}

// Convert a Julian day number to a date
void julian_to_date(const long jd, int &d, int &m, int &y) {
	// determine year from 29 Feb 1BC
	if (jd >= gregorian_epoch) {
		// JD 1721119 = 29 Feb 1BC (Gregorian calendar)
		long days = jd - 1721119L;
		y = ((int)ceil(days / 36524.25) - 1)*100;
		// days in the century
		days -= (long)floor(y*365.2425);
		y += (int)ceil(days / 365.25) - 1;
	} else
		// JD 1721117 = 29 Feb 1BC (Julian calendar)
		y = (int)ceil((jd - 1721117L) / 365.25) - 1;

	long start_of_year = 1720995L + (long)floor(365.25 * y);
	// Gregorian correction
	if (jd >= gregorian_epoch)
		start_of_year += 2 + y/400 - y/100;
	int day_of_year = jd - start_of_year;
	m = (int)floor(day_of_year / 30.6001);
	d = day_of_year - (long)floor(30.6001 * m);
	// consider Jan and Feb as belonging to previous year
	m--;
	if (m > 12)
		m -= 12;
	if (m <= 2)
		y++;
	// there was no year 0
	if (y <= 0)
		y--;
	assert(date_to_julian(d, m, y) == jd);
}

class Date {
	// The date as a Julian day number
	long julian_day;

	public:
	// Member operator function for subtraction -task 3
long operator-(const Date& b) const {
    return julian_day - b.julian_day;
}
//I added const at the end because subtracting dates doesn't change either date 
//object, it just reads them.

	// Today's date
	Date() : julian_day(julian_today()) {}

	// A date in the current year
	Date(int d, int m) : julian_day(date_to_julian(d, m, Date().year())) {}

	// A fully specified date
	Date(int d, int m, int y) : julian_day(date_to_julian(d, m, y)) {}

	// The date of a Julian day number
	Date(long jd) : julian_day(jd) {}

	// The day of the month (1-31)
	int day() const;

	// The month of the year (1-12)
	int month() const;

	// The year number
	int year() const;

	// The day of the week (Sun=0, ..., Sat=6)
	int day_of_week() const { return (julian_day + 1)%7; }

	// The date as a Julian day number
	long day_number() const { return julian_day; }
};

int Date::day() const {
	int d, m, y;
	julian_to_date(julian_day, d, m, y);
	return d;
}

int Date::month() const {
	int d, m, y;
	julian_to_date(julian_day, d, m, y);
	return m;
}

int Date::year() const {
	int d, m, y;
	julian_to_date(julian_day, d, m, y);
	return y;
}



// 1. my Output Operator (carried over from Part 1)
ostream& operator<<(ostream& s, const Date& dt) {
    s << dt.day() << "/" << dt.month() << "/" << dt.year();
    return s;
}

// 2. Main method to test the new constructors
int main() {
    // Test 1: Default constructor (today's date)
    Date today;
    cout << "Today's date is: " << today << endl;

    // Test 2: Two-argument constructor (day and month in current year)
    Date summer(25, 6);
    cout << "Summer date is: " << summer << endl;

    // Test 3: Fully specified constructor
    Date specificDate(25, 10, 2026);
    cout << "Specific date is: " << specificDate << endl;



 //3

    // 2. Christmas date for the current year 
    Date christmas(25, 12); //(Day 25, Month 12)
    
    // 3.a. Subtract today from Christmas to find days remaining.
    long daysToChristmas = christmas - today;
    cout << "Days until Christmas: " << daysToChristmas << endl;

    // 3.b. Calculate your age in days
    Date birthday(25, 4, 2002); 
    long ageInDays = today - birthday;
    cout << "My age in days: " << ageInDays << " days old!" << endl;

    return 0;
}