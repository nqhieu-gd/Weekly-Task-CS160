#include <iostream>
#include <cstring>
#include <fstream>
#include "Course.h"

Course CoIn(std::ifstream &fin) {
	Course a;
	Student s;
	fin.get(a.id, 16);
	fin.ignore();
	std::cout << "Proceed to inputting a course.\n" << "The course's id: " << a.id << '\n';
	fin.get(a.name, 81);
	fin.ignore();
	std::cout << "The course's name: " << a.name << '\n';
	fin >> a.li.size;
	std::cout << "Student number: " << a.li.size << '\n';
	a.li.con();
	std::cout << "Student list: \n";
	for (int i = 1; a.li.size >= i; i++) {
		fin.ignore();
		fin.get(s.name, 51);
		fin.ignore();
		fin.get(s.id, 9);
		fin.ignore();
		for (int j = 0; j < 3; j++) {
			fin >> s.dob[j];
		}
		fin >> s.gpa;
		a.li.inst(s, i-1);
		std::cout << i << ". " << a.li.p[i-1].name << '\n';
	}
	fin >> a.li.ma;
	std::cout << "Maximum required number of students: " << a.li.ma << '\n';
	fin >> a.li.mi;
	std::cout << "Minimum required number of students: " << a.li.mi << '\n';
	a.li.update();
    std::cout << (a.li.isopen ? "Course can be opened.\n" : "Course can not be opened.\n");

	return a;
}

void CoOut(Course a, std::ofstream &fout){
	fout << a.id << '\n';
	fout << a.name << '\n';
	int s = a.li.size;
	fout << s << '\n';
	for (int i = 0; i < s; i++) {
		fout << a.li.p[i].name << '\n';
		fout << a.li.p[i].id << '\n';
		for (int j = 0; j < 3; j++) {
			if (a.li.p[i].dob[j] < 10) fout << 0;
			fout << a.li.p[i].dob[j] << ' ';
		}
		fout << '\n';
		fout << a.li.p[i].gpa << '\n';
	}
	std::cout << "Successfully output " << a.id << " course to external file.\n";
}

Course AddStu(Course a) {
	int cont = 1, b, mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	Student s;
	while (cont == 1) {
		std::cout << "Adding a student to " << a.id << " course.\n";
		std::cout << "Enter the student's id: ";
		std::cin.ignore();
		std::cin.get(s.id, 16);
		std::cin.ignore();
		std::cout << "Enter the student's name: ";
		std::cin.get(s.name, 81);
		std::cin.ignore();
		std::cout << "Enter the student's date of birth: ";
		for (int i = 0; i < 3; i++) {
			std::cin >> s.dob[i];
		}
		if (s.dob[2] % 4 != 0 || (s.dob[2] % 100 == 0 && s.dob[2] % 400 != 0)) mon[1] = 28;
		else mon[1] = 29;
		if (mon[s.dob[1]] < s.dob[0]) {
			std::cerr << "Invalid date of birth";
			continue;
		}
		std::cout << "Enter the student's gpa: ";
		std::cin >> s.gpa;
		a.li.add(s);
		std::cout << "Successfully added student with id " << s.id << " to " << a.id << " course.\n";
		std::cout << "Enter 1 to continue, terminate otherwise.\n";
		std::cin >> cont;
	}
	a.li.update();
	if (!a.li.isopen) std::cout << "Exceeding maximum student number allowed.\n";
	else std::cout << "Student number not exceeding maximum number allowed.\n";
	
	return a;
}

Course SubStu(Course a) {
	std::cout << "Removing a student from " << a.id << " course.\n";
	int s;
	std::cout << "Enter student's order number to remove: ";
	std::cin >> s;
	if (s < 1 || s > a.li.size) {
		std::cerr << "Invalid student number.\n";
		return a;
	}
	a.li.Sub(s);
	std::cout << "Successfully removed a student from " << a.id << " course.\n";
	a.li.update();
	if (!a.li.isopen) std::cout << "Not enough student to open course.\n";
	else std::cout << "Student number suffices.\n";

	return a;
}

void dobMonCheck(Course a) {
	std::cout << "Checking month of birth for students in " << a.id << " course.\n";
	std::cout << "Which month is it now? ";
	int m, cnt = 1;
	std::cin >> m;
	std::cout << "Students born in this month:\n";
	for (int i = 0; i < a.li.size; i++) {
		if (a.li.p[i].dob[1] == m) {
			std::cout << cnt << ". " << a.li.p[i].name << '\n';
			cnt++;
		}
	}
}

void dobCheck(Course a) {
	std::cout << "Checking date of birth for students in " << a.id << " course.\n";
	std::cout << "What date is today? \n";
	int d, m, cnt = 1;
	std::cout << "Day: ";
	std::cin >> d;
	std::cout << "Month: ";
	std::cin >> m;
	std::cout << "Students born in this date:\n";
	for (int i = 0; i < a.li.size; i++) {
		if (a.li.p[i].dob[0] == d && a.li.p[i].dob[1] == m) {
			std::cout << cnt << ". " << a.li.p[i].name << '\n';
			cnt++;
		}
	}
	if (cnt == 1) std::cout << "No students were born in this date.\n";
}

void DrivingReady(Course a) {
	std::cout << "Checking if students are ready to get a drive license for students in " << a.id << " course.\n";
	std::cout << "What date is today? \n";
	int d, m, y, cnt = 1;
	std::cout << "Day: ";
	std::cin >> d;
	std::cout << "Month: ";
	std::cin >> m;
	std::cout << "Year: ";
	std::cin >> y;
	std::cout << "Students that are ready to get a driver license:\n";
	for (int i = 0; i < a.li.size; i++) {
		if (y - a.li.p[i].dob[2] > 18 || y - a.li.p[i].dob[2] == 18 && m > a.li.p[i].dob[1] || y - a.li.p[i].dob[2] == 18 && m == a.li.p[i].dob[1] && d >= a.li.p[i].dob[0]) {
			std::cout << cnt << ". " << a.li.p[i].name << '\n';
			cnt++;
		}
	}
	if (cnt == 1) std::cout << "No students are ready to get a driver license.\n";
}

void FindK19(std::ofstream &fout, Course a) {
	fout << "All students in K19 class: \n";
	int cnt = 1;
	for (int i = 0; i < a.li.size; i++) {
		if (a.li.p[i].id[0] == '1' && a.li.p[i].id[1] == '9') {
			fout << cnt++ << ". " << a.li.p[i].name << '\n';
		}
	}
}

void FindID(std::ofstream &fout, Course a) {
	std::cout << "Searching for student with a certain ID in " << a.id << " course.\n";
	char i[9];
	std::cout << "Enter that student's ID: ";
	std::cin.ignore();
	std::cin.get(i, 9);
	std::cin.ignore();
	fout << "Student with id " << i << " : ";
	for (int k = 0; k < a.li.size; k++) {
		for (int j = 0; j < 9; j++) {
			if (a.li.p[k].id[j] != i[j]) break;
			if (j == 8) {
				fout << a.li.p[k].name;
				break;
			}
		}
	}
}

void FindGN(std::ofstream &fout, Course a) {
	std::cout << "Searching for student with a given name in " << a.id << " course.\n";
	char i[26];
	int cnt = 1;
	std::cout << "Enter the given name: ";
	std::cin.ignore();
	std::cin.get(i, 26);
	std::cin.ignore();
	fout << "Students with that given name: \n";
	for (int k = 0; k < a.li.size; k++) {
		for (int j = strlen(a.li.p[k].name) - 1; j >= 0; j--) {
			if (a.li.p[k].name[j] == ' ') {
			if (strlen(a.li.p[k].name) - j - 1 == strlen(i)) {
				for (int l = j + 1; l <= strlen(a.li.p[k].name); l++) {
					if (a.li.p[k].name[l] != i[l - j - 1]) break;
					if (l == strlen(a.li.p[k].name) - 1) fout << cnt++ << ". " << a.li.p[k].name << '\n';
				}
			}
				break;
			}
		}
	}
}

void outfs(Student &a) {
	std::ofstream fout;
	fout.open("temp.txt");
	if (fout) {
		fout << a.name << '\n';
		fout << a.id << '\n';
		fout << a.dob[0] << ' ' << a.dob[1] << ' ' << a.dob[2] << '\n';
		fout << a.gpa;
	}
	fout.close();
}

void infs(Student &a) {
	std::ifstream fin;
	fin.open("temp.txt");
	if (fin) {
		fin.get(a.name, 51);
		fin.ignore();
		fin.get(a.id, 9);
		fin.ignore();
		fin >> a.dob[0] >> a.dob[1] >> a.dob[2];
		fin >> a.gpa;
	}
	fin.close();
}

void sw(Student &a, Student &b) {
	Student temp;
	outfs(b);
	infs(temp);
	outfs(a);
	infs(b);
	outfs(temp);
	infs(a);
}

void SortID(std::ofstream &fout, Course &a) {
	int k = a.li.size, x[k] = {0}, y[k], temp = 0, t = 0;
	for (int i = 0; i < k; i++) {
		y[i] = i;
		for (int j = 0; j < 8; j++) {
			x[i] = x[i]*10 + (int) a.li.p[i].id[j] - 48;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if(x[j] > x[j+1]) {
				temp = x[j];
				t = y[j];
				x[j] = x[j+1];
				y[j] = y[j+1];
				x[j+1] = temp;
				y[j+1] = t;
				sw(a.li.p[j], a.li.p[j+1]);
			}
		}
	}
	fout << "Students sorted by ID:\n";
    for (int i = 0; i < a.li.size; i++) {
        fout << (i + 1) << ". " << a.li.p[i].name << '\n';
    }
}

void SortFirstname(std::ofstream &fout, Course &a) {
    std::cout << "Sorting students by first name in " << a.id << " course.\n";
    for (int i = 0; i < a.li.size - 1; i++) {
        for (int j = 0; j < a.li.size - i - 1; j++) {
            char firstName1[51] = "";
            char firstName2[51] = "";
            int k = strlen(a.li.p[j].name) - 1, x = 0;
			while (a.li.p[j].name[k] != ' ' && k >= 0) {
                k--;
            }
			k++;
            while (k < strlen(a.li.p[j].name)) {
                firstName1[x] = a.li.p[j].name[k];
                k++;
				x++;
            }
            firstName1[x] = '\0';
            k = strlen(a.li.p[j+1].name) - 1;
			x = 0;
			while (a.li.p[j+1].name[k] != ' ' && k >= 0) {
                k--;
            }
			k++;
            while (k < strlen(a.li.p[j+1].name)) {
                firstName2[x] = a.li.p[j+1].name[k];
                k++;
				x++;
            }
            firstName2[x] = '\0';
            if (strcmp(firstName1, firstName2) > 0) {
                sw(a.li.p[j], a.li.p[j+1]);
            }
        }
    }
    fout << "Students sorted by first name:\n";
    for (int i = 0; i < a.li.size; i++) {
        fout << (i + 1) << ". " << a.li.p[i].name << '\n';
    }
}

void SortGPA(std::ofstream &fout, Course &a) {
	int k = a.li.size;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if(a.li.p[j].gpa > a.li.p[j+1].gpa) {
				sw(a.li.p[j], a.li.p[j+1]);
			}
		}
	}
	fout << "Students sorted by GPA:\n";
    for (int i = 0; i < a.li.size; i++) {
        fout << (i + 1) << ". " << a.li.p[i].name << '\n';
    }
}

void SortDOB(std::ofstream &fout, Course &a) {
	int k = a.li.size, x[k] = {0}, temp = 0;
	for (int i = 0; i < k; i++) {
		x[i] = a.li.p[i].dob[2]*10000 + a.li.p[i].dob[1]*100 + a.li.p[i].dob[0];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if(x[j] > x[j+1]) {
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
				sw(a.li.p[j], a.li.p[j+1]);
			}
		}
	}
	fout << "Students sorted by date of birth:\n";
    for (int i = 0; i < a.li.size; i++) {
        fout << (i + 1) << ". " << a.li.p[i].name << '\n';
    }
}