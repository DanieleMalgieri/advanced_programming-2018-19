#include <iostream>
using namespace std;


bool is_it_leap(int y);


enum class Month {jenuary, february, march, april, may, june, july, august, september, october, november, december};

Month operator+(Month m, const int i){
	return Month((int(m)+i)%12);
}

int day_in_month(const Month _month, const int _year){
	switch(_month){
		case Month::november: case Month::april: case Month::june: case Month::september: return 30;
		break;
		case Month::february: {
			if(is_it_leap(_year)){
				return 29;
			}
			else 
			{
				return 28;
			}
		}
		break;
		case Month::jenuary: case Month::march: case Month::may: case Month::july: case Month::august:
		case Month::october: case Month::december: return 31;
		break;
	}
}

int day_in_month(const Month _month){
	switch(_month){
		case Month::november: case Month::april: case Month::june: case Month::september: return 30;
		break;
		case Month::february: return 28;
		break;
		case Month::jenuary: case Month::march: case Month::may: case Month::july: case Month::august:
		case Month::october: case Month::december: return 31;
		break;
	}
}


/* DATE CLASS IMPLEMENTATION */
class Date
{
	private:
	int date_day;
	Month date_month;
	int date_year;	
	
	public:
	Date(int _day, Month _month, int _year): date_day{_day}, date_month{_month}, date_year{_year} {}; //constructor
	
	int day() const;
	Month month() const;
	int year() const;

	void add_days(const int n);
	void add_months(const int n);
};


/* Helpers */
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
ostream& operator<<(ostream& os, const Date& d);

int main(){
	
	Date my_birthday{19, Month::april, 1989};
	cout << my_birthday;
	my_birthday.add_days(2500);
	cout << my_birthday;
}



/* Class Methods */
int Date::day() const{
	return date_day;
}

Month Date::month() const {
	return date_month;
}


int Date::year() const{
	return date_year;
}

void Date::add_days(const int n){
	int day_sum = date_day + n;
	date_day = 1;
	while(day_sum>day_in_month(date_month, date_year)){
		day_sum = day_sum - day_in_month(date_month, date_year);
		date_month = date_month +1;
		if(date_month == Month::jenuary) ++date_year;
	}
	date_day = day_sum;
}

void Date::add_months(const int _n){
	date_month = date_month + _n; //it requires to overlaod + operator.
}


/* HELPER FUNCTIONS */

bool operator==(const Date& lhs, const Date& rhs){
	if( lhs.day() == rhs.day() && lhs.month() == rhs.month() && lhs.year() == rhs.year())
		return true;
	else return false;
}

bool operator!=(const Date& lhs, const Date& rhs){
	if (lhs==rhs) return false;
	else return true;
}
bool is_it_leap(const int _y){
	if(_y%4==0 && _y%400!=0) return true;
	else return false;
}

ostream& operator<<(ostream& os, const Date& d)
{
	cout << d.day() << "/" << int(d.month()) << "/" << d.year() << "\n";
	return os;
}
	
