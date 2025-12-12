#include "cmd.cpp"

int main() {
    cmd c;

    std::string st;
    std::getline(std::cin, st);
    c.MYSPLITFILE(st);

    return 0;
}