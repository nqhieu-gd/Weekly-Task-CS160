#include <fstream>
#include <cstring>
#include "Course.h"
#include <iostream>
#include "Course.cpp"

int main() {
    std::cout << "Proceed to P423 problem.\n";
    int choice, k = 0;
    Course CL[50];
    while (choice != 0) {
        std::cout << "Enter a work number (1-14 to proceed or 0 to exit): ";
        std::cin >> choice;
        switch (choice) {
            case 0:
                std::cout << "Terminate the program.\n";
                break;
            case 1: {
                std::ifstream fin;
                fin.open("input.txt");
                if (!fin) {
                    std::cerr << "Error opening input file.\n";
                    break;
                }
                Course a = CoIn(fin);
                fin.close();
                CL[k++] = a;
                break;
            }
            case 2: {
                std::ofstream fout;
                fout.open("output.txt");
                if (!fout) {
                    std::cerr << "Error opening output file.\n";
                    return 1;
                }
                std::cout << "Enter the course number to ouput: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                CoOut(CL[num - 1], fout);
                fout.close();
                break;
            }
            case 3: {
                std::cout << "Enter the course number to proceed: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                CL[num - 1] = AddStu(CL[num - 1]);
                break;
            }
            case 4: {
                std::cout << "Enter the course number to proceed: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                CL[num - 1] = SubStu(CL[num - 1]);
                break;
            }
            case 5: {
                std::cout << "Enter the course number to proceed: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                dobMonCheck(CL[num - 1]);
                break;
            }
            case 6: {
                std::cout << "Enter the course number to proceed: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                dobCheck(CL[num - 1]);
                break;
            }
            case 7: {
                std::cout << "Enter the course number to proceed: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                DrivingReady(CL[num - 1]);
                break;
            }
            case 8: {
                std::ofstream fout;
                fout.open("K19.txt");
                if (!fout) {
                    std::cerr << "Error opening output file.\n";
                    return 1;
                }
                std::cout << "Enter the course number to check for K19 students: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                FindK19(fout, CL[num - 1]);
                fout.close();
                break;
            }
            case 9: {
                std::ofstream fout;
                fout.open("ID.txt");
                if (!fout) {
                    std::cerr << "Error opening output file.\n";
                    return 1;
                }
                std::cout << "Enter the course number to check for ID: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                FindID(fout, CL[num - 1]);
                fout.close();
                break;
            }
            case 10: {
                std::ofstream fout;
                fout.open("GN.txt");
                if (!fout) {
                    std::cerr << "Error opening output file.\n";
                    return 1;
                }
                std::cout << "Enter the course number to check for students with a given name: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                FindGN(fout, CL[num - 1]);
                fout.close();
                break;
            }
            case 11: {
                std::cout << "Proceed to sort students by ID.\n";
                std::cout << "Enter the course number to sort: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                std::ofstream fout;
                fout.open("SortID.txt");
                if (!fout) {
                    std::cerr << "Error opening output file.\n";
                    return 1;
                }
                SortID(fout, CL[num - 1]);
                fout.close();
                break;
            }
            case 12: {
                std::cout << "Proceed to sort students by first name.\n";
                std::cout << "Enter the course number to sort: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                std::ofstream fout;
                fout.open("SortFirstname.txt");
                if (!fout) {
                    std::cerr << "Error opening output file.\n";
                    return 1;
                }
                SortFirstname(fout, CL[num - 1]);
                fout.close();
                break;
            }
            case 13: {
                std::cout << "Proceed to sort students by GPA.\n";
                std::cout << "Enter the course number to sort: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                std::ofstream fout;
                fout.open("SortGPA.txt");
                if (!fout) {
                    std::cerr << "Error opening output file.\n";
                    return 1;
                }
                SortGPA(fout, CL[num - 1]);
                fout.close();
                break;
            }
            case 14: {
                std::cout << "Proceed to sort students by date of birth.\n";
                std::cout << "Enter the course number to sort: ";
                int num;
                std::cin >> num;
                if (num < 1 || num > k) {
                    std::cerr << "Invalid course number.\n";
                    break;
                }
                std::ofstream fout;
                fout.open("SortDOB.txt");
                if (!fout) {
                    std::cerr << "Error opening output file.\n";
                    return 1;
                }
                SortDOB(fout, CL[num - 1]);
                fout.close();
                break;
            }
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 14.\n";
                break;
        }
    }

    return 0;
}