#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Date.h"
#include "Student.h"
#include "ReverseInt.cpp"
#include "3Sum.cpp"
#include "SqRt.cpp"

int main() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    if (choice < 1 || choice > 5) {
        std::cout << "Invalid choice!" << std::endl;
        return 1;
    }
    if (choice == 1) {
        std::cout << "Proceed to problem P401." << std::endl;
        date d, d1;
        int n;
        std::cout << "Enter a day first: ";
        d = day_in(d);
        std::cout << "Choose one sub-problem (1-14) (Or click something not in 1-14 to exit): ";
        std::cin >> choice;
        while (choice >= 1 && choice <= 14) {
            if (choice == 1) {
                std::cout << "Proceed to problem P401.1." << std::endl;
                d = day_in(d);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 2) {
                std::cout << "Proceed to problem P401.2." << std::endl;
                day_out(d);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 3) {
                std::cout << "Proceed to problem P401.3." << std::endl;
                std::ifstream fin;
                fin.open("date.txt");
                d = input_date(fin);
                fin.close();
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 5) {
                std::cout << "Proceed to problem P401.5." << std::endl;
                std::ofstream fout;
                fout.open("date.txt");
                std::cout << "Choose format (1 for \"yyyy-MM-dd\" or 2 for \"MMM-dd-yy\"): ";
                std::cin >> choice;
                if (choice == 1 || choice == 2) {
                    outputDateWihFormat(fout, d, choice);
                }
                else std::cout << "Invalid choice!" << std::endl;
                fout.close();
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 4) {
                std::cout << "Proceed to problem P401.4." << std::endl;
                std::ofstream fout;
                fout.open("date.txt");
                outputDateWihFormat(fout, d, 1);
                fout.close();
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 6) {
                std::cout << "Proceed to problem P401.6." << std::endl;
                std::cout << "Enter another date to compare: " << std::endl;
                d1 = day_in(d1);
                std::cout << "The later date is: ";
                d = later_date(d, d1);
                day_out(d);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 7) {
                std::cout << "Proceed to problem P401.7." << std::endl;
                std::cout << "The day after is: ";
                d = tomorrow(d);
                day_out(d);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 8) {
                std::cout << "Proceed to problem P401.8." << std::endl;
                std::cout << "The day before is: ";
                d = yesterday(d);
                day_out(d);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 9) {
                std::cout << "Proceed to problem P401.9." << std::endl;
                std::cout << "Enter number of days to increase: ";
                std::cin >> n;
                d = increase_day(d, n);
                std::cout << "The new date is: ";
                day_out(d);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 10) {
                std::cout << "Proceed to problem P401.10." << std::endl;
                std::cout << "Enter number of days to decrease: ";
                std::cin >> n;
                d = decrease_day(d, n);
                std::cout << "The new date is: ";
                day_out(d);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 11) {
                std::cout << "Proceed to problem P401.11." << std::endl;
                std::cout << "Since 1/1 this year, the number of days is: " << compute(d) << std::endl;
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 12) {
                std::cout << "Proceed to problem P401.12." << std::endl;
                std::cout << "Since 1/1/1970, the number of days is: " << compute_70(d) << std::endl;
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else if (choice == 13) {
                std::cout << "Proceed to problem P401.13." << std::endl;
                std::cout << "Enter another date to compute days difference: " << std::endl;
                d1 = day_in(d1);
                std::cout << "The number of days between the two dates is: " << compute_day(d, d1) << std::endl;
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            } else {
                std::cout << "Proceed to problem P401.14." << std::endl;
                std::cout << "The day of the week is: " << checkWeekday(d) << std::endl;
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-14 to exit): ";
                std::cin >> choice;
            }
        }
    } else if (choice == 2) {
        std::cout << "Proceed to problem P402." << std::endl;
        student s, s1;
        std::cout << "Enter a student's information first: " << std::endl;
        s = input_student(s);
        std::cout << "Choose one sub-problem (1-12) (Or click something not in 1-12 to exit): ";
        std::cin >> choice;
        while (choice >= 1 && choice <= 12) {
            if (choice == 1) {
                std::cout << "Proceed to problem P402.1." << std::endl;
                s = input_student(s);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 2) {
                std::cout << "Proceed to problem P402.2." << std::endl;
                output_student(s);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 3) {
                std::cout << "Proceed to problem P402.3." << std::endl;
                std::ifstream fin;
                fin.open("student.txt");
                s = fin_student(s, fin);
                fin.close();
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 4) {
                std::cout << "Proceed to problem P402.4." << std::endl;
                std::ofstream fout;
                fout.open("student.txt");
                fout_student(s, fout);
                fout.close();
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 5) {
                std::cout << "Proceed to problem P402.5." << std::endl;
                std::ofstream fout;
                fout.open("student.txt");
                fout_student_remake(s, fout);
                fout.close();
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 6) {
                std::cout << "Proceed to problem P402.6." << std::endl;
                std::ofstream fout;
                fout.open("student.txt");
                class_check(s, fout);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 7) {
                std::cout << "Proceed to problem P402.7." << std::endl;
                std::cout << "Enter another student's information to compare ID: " << std::endl;
                s1 = input_student(s1);
                std::cout << "The student with higher ID is: " << std::endl;
                s = later_id(s, s1);
                output_student(s);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 8) {
                std::cout << "Proceed to problem P402.8." << std::endl;
                std::cout << "Enter another student's information to compare GPA: " << std::endl;
                s1 = input_student(s1);
                std::cout << "The student with higher GPA is: " << std::endl;
                s = higher_gpa(s, s1);
                output_student(s);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 10) {
                std::cout << "Proceed to problem P402.10." << std::endl;
                std::cout << "Enter another student's information to compare first name: " << std::endl;
                s1 = input_student(s1);
                std::cout << "The student with later first name is: " << std::endl;
                s = later_first_name(s, s1);
                output_student(s);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 11) {
                std::cout << "Proceed to problem P402.11." << std::endl;
                std::cout << "Enter another student's information to compare last name: " << std::endl;
                s1 = input_student(s1);
                std::cout << "The student with later last name is: " << std::endl;
                s = later_last_name(s, s1);
                output_student(s);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 12) {
                std::cout << "Proceed to problem P402.12." << std::endl;
                std::cout << "Enter another student's information to compare date of birth: " << std::endl;
                s1 = input_student(s1);
                std::cout << "The older student is: " << std::endl;
                s = older_dob(s, s1);
                output_student(s);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            } else if (choice == 9) {
                std::cout << "Proceed to problem P402.9." << std::endl;
                std::cout << "Enter another student's information to compare name: " << std::endl;
                s1 = input_student(s1);
                std::cout << "The student with later last name is: " << std::endl;
                s = later_name(s, s1);
                output_student(s);
                std::cout << '\n' << "Choose one sub-problem (Or click something not in 1-12 to exit): ";
                std::cin >> choice;
            }
        }
    } else if (choice == 3) {
        std::cout << "Proceed to problem P403." << std::endl;
        std::cout << "Enter a number to be reversed: ";
        int x;
        std::cin >> x;
        std::cout << "The revesed number is: " << reverse(x);
    } else if (choice == 4) {
        std::cout << "Proceed to problem P404." << std::endl;
        int n, x;
        std::cout << "How many elements in the array? ";
        std::cin >> n;
        std::vector<int> vt;
        std::cout << "Enter array's elements one by one: ";
        for (int i = 0; i< n; i++) {
            std::cin >> x;
            vt.push_back(x);
        }
        std::vector<std::vector<int>> res = threeSum(vt);
        std::cout << "Triplets with total sum is 0: " << '\n';
        std::cout << '[';
        for (std::vector<int> i : res) {
            std::cout << '[';
            for (int j : i) {
                std::cout << j << ' ';
            }
            std::cout << ']' << ' ';
        }
        std::cout << ']';
    } else {
        std::cout << "Proceed to problem P405." << std::endl;
        std::cout << "Enter a number to find integer square root: ";
        int x;
        std::cin >> x;
        std::cout << "The integer closest to its square root is " << mySqrt(x);
    }

    return 0;
}