#include <iostream>
#include <fstream>
#include "func.cpp"

int main() {
    std::ifstream fin;
    std::ofstream fout;
    fin.open("seq.txt");
    if (!fin) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    Node* pHead = NULL;
    Node* pHead2 = NULL;
    Node* pHeadsort = NULL;
    genList(fin, pHead);
    fin.close();
    int choice;
    std::cout << "Successfully retrieved the first linked list via text file.\n";
    std::cout << "1. Remove all presences of x.\n" << "2. Remove all duplicates.\n";
    std::cout << "3. Reverse the list.\n" << "4. Insert even numbers.\n" << "5. Insert an integer into a sorted list.\n";
    std::cout << "6. Create a new list of sum.\n" << "7. Join 2 lists.\n" << "8. Joined 2 lists alternatingly.\n" << "0. Exit\n";
    std::cout << "Input your choice: ";
    std::cin >> choice;
    while (choice < 0 || choice > 8) {
        std::cerr << "Invalid choice, try again: ";
        std::cin >> choice;
    }
    while (choice != 0) {
        switch(choice) {
            case 1: {
                fout.open("removeVals.txt");
                if (!fout) {
                    std::cerr << "Error opening file.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                std::cout << "Proceed to problem 1.\n";
                int k;
                std::cout << "Which value do you want to find and remove? ";
                std::cin >> k;
                subList(pHead, k);
                outList(fout, pHead);
                std::cout << "Successfully remove all value " << k << " found.\n";
                std::cout << "What to do next? ";
                std::cin >> choice;
                fout.close();
                break;
            }
            case 2: {
                fout.open("removeDupes.txt");
                if (!fout) {
                    std::cerr << "Error opening file.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                std::cout << "Proceed to problem 2.\n";
                removeDupe(pHead);
                outList(fout, pHead);                
                std::cout << "Successfully remove all duplicates.\n";
                std::cout << "What to do next? ";
                std::cin >> choice;
                fout.close();
                break;
            }
            case 3: {
                fout.open("reverse.txt");
                if (!fout) {
                    std::cerr << "Error opening file.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                std::cout << "Proceed to problem 3.\n";
                revList(pHead);
                outList(fout, pHead);                
                std::cout << "Successfully reverse the list.\n";
                std::cout << "What to do next? ";
                std::cin >> choice;
                fout.close();
                break;
            }
            case 4: {
                fout.open("insertEven.txt");
                if (!fout) {
                    std::cerr << "Error opening file.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                std::cout << "Proceed to problem 4.\n";
                insertEven(pHead);
                outList(fout, pHead);                
                std::cout << "Successfully insert even numbers to the list.\n";
                std::cout << "What to do next? ";
                std::cin >> choice;
                fout.close();
                break;
            }
            case 5: {
                fout.open("insertSorted.txt");
                if (!fout) {
                    std::cerr << "Error opening file.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                std::cout << "Proceed to problem 5.\n";
                fin.open("sorted.txt");
                if (!fin) {
                    std::cerr << "Unexpected error.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                if (pHeadsort == NULL) genList(fin, pHeadsort);
                fin.close();
                insertSorted(pHeadsort);
                outList(fout, pHeadsort);                
                std::cout << "Successfully insert a number to the sorted list.\n";
                std::cout << "What to do next? ";
                std::cin >> choice;
                fout.close();
                break;
            }
            case 6: {
                fout.open("sum.txt");
                if (!fout) {
                    std::cerr << "Error opening file.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                std::cout << "Proceed to problem 6.\n";
                sumList(pHead);
                outList(fout, pHead);                
                std::cout << "Successfully create a list of sum of data in the original list up to the corresponding node.\n";
                std::cout << "What to do next? ";
                std::cin >> choice;
                fout.close();
                break;
            }
            case 7: {
                fout.open("mergeAlternatingly.txt");
                if (!fout) {
                    std::cerr << "Error opening file.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                std::cout << "Proceed to problem 7.\n";
                fin.open("seq2.txt");
                if (!fin) {
                    std::cerr << "Unexpected error.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                genList(fin, pHead2);
                fin.close();
                twoToOne(pHead, pHead2);
                outList(fout, pHead);                
                std::cout << "Successfully create a list made of 2 lists alternatingly.\n";
                std::cout << "What to do next? ";
                std::cin >> choice;
                fout.close();
                pHead2 = NULL;
                break;
            }
            case 8: {
                fout.open("joinedList.txt");
                if (!fout) {
                    std::cerr << "Error opening file.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                std::cout << "Proceed to problem 8.\n";
                fin.open("seq2.txt");
                if (!fin) {
                    std::cerr << "Unexpected error.\n";
                    std::cout << "What to do next? ";
                    std::cin >> choice;
                    break;
                }
                genList(fin, pHead2);
                fin.close();
                joinedList(pHead, pHead2);
                outList(fout, pHead);                
                std::cout << "Successfully create a list made of 2 lists back to back.\n";
                std::cout << "What to do next? ";
                std::cin >> choice;
                fout.close();
                pHead2 = NULL;
                break;
            }
            default: {
                std::cerr << "program terminated successfully.";
            }
        }
        while (choice < 0 || choice > 8) {
            std::cerr << "Invalid choice, try again: ";
            std::cin >> choice;
        }
    }
    if (pHead != NULL) clearList(pHead);
    if (pHead2 != NULL) clearList(pHead2);
    if (pHeadsort != NULL) clearList(pHeadsort);
    
    return 0;
}