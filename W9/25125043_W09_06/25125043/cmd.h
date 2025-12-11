#pragma once
#include <iostream>
#include <fstream>

struct cmd {
    struct src {
        std::string s;

        src(std::string path);
        ~src();

        int findLast(char a);

        std::string findFile();
    };

    struct des {
        std::string d;

        des(std::string dpath);
        ~des();
    };

    void MYCOPYFILE(std::string st);

    void copyf(std::string ptsource,std::string ptdes);

    void MYSPLITFILE(std::string ptsource,std::string ptdes);

    void MYMERGEFILE(std::string ptsource,std::string ptdes);
};