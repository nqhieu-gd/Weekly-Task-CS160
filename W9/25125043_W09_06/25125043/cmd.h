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

        std::string findExt();
    };

    struct des {
        std::string d;

        des(std::string dpath);
        ~des();
    };

    void MYCOPYFILE(std::string st);

    void copyf(std::string ptsource,std::string ptdes);

    void MYSPLITFILE(std::string st);

    void splitf(std::string ptsource,std::string ptdes, std::string types, int x);

    void MYMERGEFILE(std::string st);
};