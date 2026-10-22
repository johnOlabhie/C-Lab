#include <iostream>

using namespace std;

class Date {
	int d, m, y;

public:
	// A fully specified date
	Date(int dd, int mm, int yy) : d(dd), m(mm), y (yy) {}

	// The day of the month (1-31)
	int day() const { return d; }

	// The month of the year (1-12)
	int month() const { return m; }

	// The year number
	int year() const { return y; }
};

// 1. The Output Operator function
//We take our output stream (s) and feed the date pieces into it one by one, separated by forward slashes ("/").
//It calls the public getter methods day  month , year  to fetch the numbers safely from the Date object.
ostream& operator<<(ostream& s, const Date& dt) {
    s << dt.day() << "/" << dt.month() << "/" << dt.year();
    return s;
}

//

// 2.testing 
int main() {
    Date myDate(25, 10, 2026);
    
    cout << "My test date is: " << myDate << endl;
    
    return 0;
}