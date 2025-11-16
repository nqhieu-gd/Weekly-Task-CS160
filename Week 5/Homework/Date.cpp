#include <iostream>
#include <fstream>
#include "Date.h"

date tomorrow(date d) {
    if (d.day == 31 && (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10)) {
        d.day = 1;
        d.month += 1;
    } else if (d.day == 30 && (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)) {
        d.day = 1;
        d.month += 1;
    } else if (d.day == 28 && d.month == 2 && (d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0))) {
        d.day = 1;
        d.month += 1;
    } else if (d.day == 29 && d.month == 2) {
        d.day = 1;
        d.month += 1;
    } else if (d.day == 31 && d.month == 12) {
        d.day = 1;
        d.month = 1;
        d.year += 1;
    } else {
        d.day += 1;
    }

    return d;
}

date yesterday(date d){
    if (d.day == 1 && (d.month == 2 || d.month == 4 || d.month == 6 || d.month == 8 || d.month == 9 || d.month == 11)) {
        d.day = 31;
        d.month -= 1;
    } else if (d.day == 1 && (d.month == 5 || d.month == 7 || d.month == 10 || d.month == 12)) {
        d.day = 30;
        d.month -= 1;
    } else if (d.day == 1 && d.month == 3 && (d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0))) {
        d.day = 28;
        d.month -= 1;
    } else if (d.day == 1 && d.month == 3) {
        d.day = 29;
        d.month -= 1;
    } else if (d.day == 1 && d.month == 1) {
        d.day = 31;
        d.month = 12;
        d.year -= 1;
    } else {
        d.day -= 1;
    }

    return d;
}

date increase_day(date d, int n) {
    int a;
	while (n >= 365) {
		if (d.month == 2 && d.day == 29) {
			d.year ++;
			d.day --;
			n -= 364;
		}
		else if (d.month <= 2 && (d.year % 4 != 0 || d.year % 100 == 0 && d.year % 400 != 0) || d.month >= 3 && ((d.year + 1) % 4 != 0 || (d.year + 1) % 100 == 0 && (d.year + 1) % 400 != 0)) {
			d.year ++;
			n -= 365;
		}
		else if (d.month <= 2 && (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0) || d.month >= 3 && ((d.year + 1) % 4 == 0 && (d.year + 1) % 100 != 0 || (d.year + 1) % 400 == 0)) {
			d.year ++;
			n -= 366;
		}
	}
	if (d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0)) a = 28;
	else a = 29;
	int mon[12] = {31, a, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// cm = "current month"
	int cm = d.month;
// cml = "current month length"
    int cml = mon[cm - 1] - d.day;
	if (cml < n) {
		d.day += n;
		n = 0;
		return d;
	}
	d.day = 1;
	while (cml < n){
		n -= cml;
		if (cm != 12) cm++;
		else {
			cm = 1;
			d.year ++;
			if (d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0)) mon[1] = 28;
			else mon[1] = 29;
		}
		cml = mon[cm - 1];
		d.month ++;
	}
	d.day += n;

    return d;
}

date decrease_day(date d, int n) {
    int a;
	while (n >= 365) {
		if (d.month == 2 && d.day == 29) {
			d.year --;
			d.day --;
			n -= 366;
		}
		else if (d.month <= 2 && ((d.year - 1) % 4 != 0 || (d.year - 1) % 100 == 0 && (d.year - 1) % 400 != 0) || d.month >= 3 && (d.year % 4 != 0 || d.year % 100 == 0 && d.year % 400 != 0)) {
			d.year --;
			n -= 365;
		}
		else if (d.month <= 2 && ((d.year - 1) % 4 == 0 && (d.year - 1) % 100 != 0 || (d.year - 1) % 400 == 0) || d.month >= 3 && (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0)) {
			d.year --;
			n -= 366;
		}
	}
	if (d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0)) a = 28;
	else a = 29;
	int mon[12] = {31, a, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// cm = "current month"
	int cm = d.month;
// cml = "current month length"
    int cml = d.day;
	if (n < d.day) {
		d.day -= n;
		n = 0;
		return d;
	}
	while (d.day < n){
		n -= d.day;
		if (cm != 1) cm--;
		else {
			cm = 12;
			d.year --;
			if (d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0)) mon[1] = 28;
			else mon[1] = 29;
		}
		d.day = mon[cm - 1];
		d.month --;
	}
	d.day -= n;

    return d;
}

int compute(date d) {
	int dif = 0, a;
	if (d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0)) a = 28;
	else a = 29;
	int mon[12] = {31, a, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 0; i < d.month - 1; i++) {
		dif += mon[i];
	}
	dif += d.day - 1;
	
	return dif;
}
		

int compute_70(date d) {
	int dif = 0, gap = d.year - 1970, mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, check = ((gap - 30)/100) - ((gap - 30)/100)/4;
// gap is used to work on year length and check is used to determine how many non-leap year that is dividable by 100 but not 400
	if (gap > 3) {
		dif += 1096;
		gap -= 3;
	}
//1461 is length of 4 consecutive year (temporarily exclude the fact that it may include a non-leap year that is dividable by 100 but not 400)
	if (gap >= 4) dif += (gap/4 - 1)*1461;
	if (gap%4 > 0) {
		dif += (gap%4 - 1)*365 + 1461;
	}
//1095 is length of 3 consecutive non-leap year
	else {
		dif += 1095;
		mon[1] = 29;
	}
	for (int i = 0; i < d.month - 1; i++) {
		dif += mon[i];
	}
	dif += d.day - 1;
	if (gap >= 127) {
		dif -= check;
		if ((d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0)) && d.month <= 2) dif ++;
	}
	
	return dif;
}

int compute_day(date a, date b) {
	int x = compute_70(a) - compute_70(b);
	if (x < 0) x = -x;
	return x;
}

std::string checkWeekday(date d) {
	int a = compute_70(d)%7;
	if (a > 3) return week[a + 3 - 6];
	return week[a + 3];
}
	

date later_date(date a, date b){
	if (a.year != b.year) return  (a.year > b.year)? a : b;
	if (a.month != b.month) return  (a.month > b.month)? a : b;
	if (a.day != b.day) return  (a.day > b.day)? a : b;
}

date input_date(std::ifstream &file) {
	date df;
	if (file) {
		file >> df.day >> df.month >> df.year;
	}
	
	return df;
}

void outputDateWihFormat(std::ofstream &file, date d, int choice) {
    if (choice == 1) {
        if (file) {
            file << d.year << ' - ';
            if (d.month < 10) file << 0;
            file << d.month << ' - ';
            if (d.day < 10) file << 0 << d.day << '\n';
        }
    }
}

void outputDateWihFormat(std::ofstream &file, date d, int choice) {
    if (choice == 2) {
        if (file) {
            file << month[d.month] << ' ';
            if (d.day < 10) file << 0;
            file << d.day << ' ';
            if (d.year%100 == 0) file << 00 << '\n'; 
            else if (d.year < 10) file << 0 << d.year%100 << '\n';
            else file << d.year%100 << '\n';
        }
    }
}

date day_in(date d) {
	std::cout << "Enter a day: ";
	std::cin >> d.day;
	std::cout << "Enter a month: ";
	std::cin >> d.month;
	std::cout << "Enter a year: ";
	std::cin >> d.year;

	return d;
}

void day_out(date d) {
	std::cout << "The date is: " << d.day << ' ' << d.month << ' ' << d.year << std::endl;
}