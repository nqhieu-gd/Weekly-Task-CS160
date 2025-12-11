#include <fstream>
#include <iostream>
#include "cmd.h"
#include "DynamicArray.h"

cmd :: src :: src(std::string path)
: s(path)
{}

cmd :: src :: ~src()
{}

cmd :: des :: des(std::string dpath)
: d(dpath)
{}

cmd :: des :: ~des()
{}

int cmd :: src :: findLast(char a) {
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == a) return i;
    }
    return -1;
}

std::string cmd :: src :: findFile() {
    int k = findLast('\\');
    if (k == -1) return s;
    else while (k == s.size() - 1) {
        s.erase(s.size() - 1);
        k = findLast('\\');
    }
    if (k == -1) return s;
    std::string sub;
    for (int i = k + 1; i < s.size(); i ++) {
        sub += s[i];
    }
    return sub;
}

void cmd :: MYCOPYFILE(std::string st) {
    std::string sub = "";
    for (int i = 0; i < 14; i++) {
        sub += st[i];
    }
    if (sub != "MYCOPYFILE -s ") {
        std::cerr << "Invalid command. Should be \"MYCOPYFILE -s source -d destination\"!";
        return;
    }
    int sid = 14, did = -1;
    while (st[sid] == ' ') sid++;
    int esid = -1, edid = -1;
    for (int i = sid; i < st.size(); i++) {
        if (st[i] == ' ' && i < st.size() - 4) {
            if (st[i + 1] == '-' && st[i + 2] == 'd' && st[i + 3] == ' ') {
                did = i + 4;
                esid = i - 1;
            }
        }
    }
    while (esid > sid && st[esid] == ' ') esid--;
    while (did != -1 && st[did] == ' ') did++;
    edid = st.size() - 1;
    while (st[edid] == ' ') edid--;
    if (did == -1 || esid == -1 || edid <= did) {
        std::cerr << "Invalid command. Should be \"MYCOPYFILE -s source -d destination\"!";
        return;
    }
    std::string sour = "", dest = "";
    for (int i = sid; i <= esid; i++) sour += st[i];
    for (int i = did; i <= edid; i++) dest += st[i];

    copyf(sour, dest);
}

void cmd :: copyf(std::string ptsource,std::string ptdes) {
    src source(ptsource);
    des des(ptdes);
    if (des.d[des.d.size() - 1] != '\\') des.d += "\\";
    std::ifstream fin;
    std::ofstream fout;
    fin.open(source.s, std::ios::binary);
    if (!fin) {
        std::cerr << "Error openning the source file!";
        return;
    }
    des.d += source.findFile();
    fout.open(des.d, std::ios::binary);
    if (!fout) {
        std::cerr << "Error openning the destination file!";
        return;
    }
    DA<char> inp;
    inp.alloc();
    inp.size = 4096;
    while (fin) {
        fin.read(inp.p, inp.size);
        if (fin.gcount() < 4096) {
            inp.size = fin.gcount();
            fout.write(inp.p, inp.size);
            break;
        }
        if (fin.gcount() == 4096) {
            fout.write(inp.p, inp.size);
            inp.dealloc();
            inp.size = 4096;
            inp.alloc();
        }
    }
    inp.dealloc();
    fin.close();
    fout.close();
    std::cout << "Successfully copy the file.";
};

void cmd :: MYSPLITFILE(std::string ptsource,std::string ptdes) {};

void cmd :: MYMERGEFILE(std::string ptsource,std::string ptdes) {};