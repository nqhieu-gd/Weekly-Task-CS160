#pragma once
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Student.h"

student input_student(student s) {
	std::cout << "Enter student's id: ";
	std::cin >> s.id;
	std::cout << "Enter student's full name: ";
	std::cin >> s.fullname;
	std::cout << "Enter student's gpa: ";
	std::cin >> s.gpa;
	std::cout << "Enter student's address: ";
	std::cin >> s.address;
	std::cout << "Enter student's date of birth: ";
	std::cin >> s.dob.day >> s.dob.month >> s.dob.year;
	
	return s;
}

void output_student(student s) {
	std::cout << "Student's id: " << s.id << '\n';
	std::cout << "Student's full name: " << s.fullname << '\n';
	std::cout << "Student's gpa: " << s.gpa << '\n';
	std::cout << "Student's address: " << s.address << '\n';
	std::cout << "Student's date of birth: " << s.dob.day << ' ' << s.dob.month << ' ' << s.dob.year << '\n';
}

student fin_student(student s, std::ifstream file) {
	if (file) {
		file >> s.id;
		file.ignore();
		std::getline(file, s.fullname);
		file >> s.gpa;
		file.ignore();
		std::getline(file, s.address);
		file >> s.dob.year >> s.dob.month >> s.dob.day;
	}
}

void fout_student(student s, std::ofstream &file) {
	if (file) {
		file << s.id << '\n' << s.fullname << '\n' << s.gpa << '\n' << s.address << '\n' << s.dob.year << ' ' << s.dob.month << ' ' << s.dob.day;
	}
}

void fout_student_remake(student s, std::ofstream &file) {
	int x;
	if (file) {
		file << s.id << '\n';
		for (int i = 0; i < s.fullname.size(); i++) {
			if (s.fullname[i] == ' ') break;
			file << s.fullname[i];
			x = i;
		}
		file << '\n';
		if (x < s.fullname.size()) {
			for (int i = x + 2; i < s.fullname.size(); i++) {
				file << s.fullname[i];
			}
		}
		file << '\n' << s.gpa << '\n' << s.address << '\n' << s.dob.year << ' ' << "year" << ' ' << s.dob.month << ' ' << "month" << ' ' << s.dob.day << ' ' << "day";
	}
}

void class_check(student s, std::ofstream &file) {
	while (s.id >= 100) s.id = s.id/10;
	if (file) {
		file << "Student's class: K" << s.id;
	}
}

student later_id(student a, student b) {
	return (a.id > b.id)? a : b;
}

student higher_gpa(student a, student b) {
	return (a.gpa > b.gpa)? a : b;
}

student later_first_name(student a, student b) {
	int check1, check2;
	for (int i = a.fullname.size() - 1; a.fullname[i] != ' '; i--) {
		check1 = i;
	}
	for (int i = b.fullname.size() - 1; b.fullname[i] != ' '; i--) {
		check2 = i;
	}
	int x = ((a.fullname.size() - check1 > b.fullname.size() - check2)? b.fullname.size() - check2 : a.fullname.size() - check1);
	for (int i = 0; i < x; i++) {
		if (a.fullname[check1 + i] != b.fullname[check2 + i]) return (a.fullname[check1 + i] > b.fullname[check2 + i])? a : b;
	}
	
	if (a.fullname.size() - check1 != b.fullname.size() - check2) return (a.fullname.size() - check1 > b.fullname.size() - check2)? a : b;
	
	else return later_id(a, b);
}

student later_last_name(student a, student b) {
	int check1, check2;
	for (int i = a.fullname.size() - 1; a.fullname[i] != ' '; i--) {
		check1 = i;
	}
	for (int i = b.fullname.size() - 1; b.fullname[i] != ' '; i--) {
		check2 = i;
	}
	int x = ((check1 > check2)? check2 : check1);
	for (int i = 0; i < x - 1; i++) {
		if (a.fullname[i] != b.fullname[i]) return (a.fullname[i] > b.fullname[i])? a : b;
	}
	
	if (check1 != check2) return (check1 > check2)? a : b;
	
	else return later_id(a, b);
}

student older_dob(student a, student b) {
	if (a.dob.year != b.dob.year) return (a.dob.year > b.dob.year)? a : b;
    if (a.dob.month != b.dob.month) return (a.dob.month > b.dob.month)? a : b;
    if (a.dob.day != b.dob.day) return (a.dob.day > b.dob.day)? a : b;

	else return later_id(a, b);
}

student later_name(student a, student b) {
    int check1 = a.fullname.size() - 1, check2 = b.fullname.size() - 1;
	int x = ((check1 > check2)? check2 : check1);
	for (int i = 0; i < x - 1; i++) {
		if (a.fullname[i] != b.fullname[i]) return (a.fullname[i] > b.fullname[i])? a : b;
	}
	
	if (check1 != check2) return (check1 > check2)? a : b;
	
	else return later_id(a, b);
}