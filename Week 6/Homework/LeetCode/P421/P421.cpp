#include <iostream>

class Solution {
public:
    bool isNumber(std::string s) {
        int com = 0, mcom = 1, me = 0, id = 1;
        if ((s[0] < 48 || s[0] > 57) && s[0] != 69 && s[0] != 101 && s[0] != 43 && s[0] != 45 && s[0] != 46) return 0;
        if (s[0] == 46) com++;
        if (s[0] == 46 && (s.length() == 1 || s[1] == 69 || s[1] == 101)) return 0;
        if ((s[0] == 43 || s[0] == 45) && (s.length() == 1 || s[1] == 46 && s.length() == 2 || s[1] == 69 || s[1] == 101)) return 0;
        if (s[0] == 69 || s[0] == 101) return 0;
        while (s.length() > 0 && id < s.length()) {
            if ((s[id] < 48 || s[id] > 57) && s[id] != 69 && s[id] != 101 && s[id] != 43 && s[id] != 45 && s[id] != 46) return 0;
            if ((s[id] == 43 || s[id] == 45) && s[id -1] != 69 && s[id - 1] != 101) return 0;
            if (s[id] == 46) com++;
            if (s[id] == 46 && (s[id + 1] == 69 || s[id + 1] == 101) && (s[id - 1] == 43 || s[id - 1] == 45)) return 0;
            if ((s[id] == 43 || s[id] == 45 || s[id] == 69 || s[id] == 101) && (id == s.length() - 1)) return 0;
            if ((s[id] == 69 || s[id] == 101) && s[id + 1] == 46) return 0;
            else if ((s[id] == 69 || s[id] == 101) && com < mcom) mcom--;
            if (s[id] == 69 || s[id] == 101) me++;
            id++;
        }
        if (com > mcom || me > 1) return 0;

        return 1;
    }
};