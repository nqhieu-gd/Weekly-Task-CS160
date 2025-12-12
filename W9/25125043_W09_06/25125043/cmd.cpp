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

std::string cmd :: src :: findExt() {
    int k = -1;
    for (int i = findFile().size() - 1; i > 0; i--) {
        if (findFile()[i] == '.') {
            k = i;
            break;
        }
    }
    std::string sub = "";
    if (k != -1) for (int i = k; i < findFile().size(); i++) {
        sub += findFile()[i];
    }
    return sub;
}

std::string cmd :: src :: findPart() {
    int k = -1;
    for (int i = findFile().size() - findExt().size() - 1; i > 0; i--) {
        if (findFile()[i] == '.') {
            k = i;
            break;
        }
    }
    std::string sub = "";
    if (k != -1) for (int i = k; i < findFile().size() - findExt().size(); i++) {
        sub += findFile()[i];
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
    std::cout << "Successfully copy the file.\n";
};

void cmd :: MYSPLITFILE(std::string st) {
    std::string sub = "";
    for (int i = 0; i < 15; i++) {
        sub += st[i];
    }
    if (sub != "MYSPLITFILE -s ") {
        std::cerr << "Invalid command. Should be \"MYSPLITFILE -s source -d destination\"!";
        return;
    }
    int sid = 15, did = -1;
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
    if (esid > sid) while (st[esid] == ' ') esid--;
    if (did != -1) while (st[did] == ' ') did++;
    edid = st.size() - 1;
    while (st[edid] == ' ') edid--;
    int ex = edid;
    while (st[edid] >= 48 && st[edid] <= 57) edid--;
    if (st[edid] != ' ') {
        std::cerr << "Invalid command. Should be \"MYSPLITFILE -s source -d destination\"!";
        return;
    }
    int bx = edid + 1;
    while (st[edid] == ' ') edid--;
    int et = edid;
    while (st[edid] != '-') edid--;
    int bt = edid;
    edid--;
    while (st[edid] == ' ') edid--;
    if (did == -1 || esid == -1 || edid <= did) {
        std::cerr << "Invalid command. Should be \"MYSPLITFILE -s source -d destination\"!";
        return;
    }
    std::string sour = "", dest = "", types = "";
    int x = 0;
    for (int i = sid; i <= esid; i++) sour += st[i];
    for (int i = did; i <= edid; i++) dest += st[i];
    for (int i = bt; i <= et; i++) types += st[i];
    for (int i = bx; i <= ex; i++) x += x*9 + st[i] - 48;
    if(types == "-numpart" || types == "-sizeapart") splitf(sour, dest, types, x);
    else std::cerr << "Invalid command. Should be \"MYSPLITFILE -s source -d destination\"!";
}

void cmd :: splitf(std::string ptsource,std::string ptdes, std::string types, int x) {
    src source(ptsource);
    des des(ptdes);
    std::string no = "1";
    if (des.d[des.d.size() - 1] != '\\') des.d += "\\";
    std::ifstream fin;
    std::ofstream fout;
    fin.open(source.s, std::ios::binary);
    if (!fin) {
        std::cerr << "Error openning the source file!";
        return;
    }
    des.d += source.findFile();
    int dds = des.d.size() - source.findExt().size();
    des.d.erase(dds);
    des.d += ".part" + no;
    des.d += ".bin";
    DA<char> inp;
    inp.alloc();
    if (types == "-numpart") {
        int num = x, check = 0;
        fin.seekg(0, std::ios::end);
        long int sf = fin.tellg();
        fin.seekg(0, std::ios::beg);
        int pl = sf % x;
        sf = sf/x;
        inp.size = sf + ((pl > 0)? 1 : 0);
        while (fin) {
            fin.read(inp.p, inp.size);
            if (fin.gcount() == 0) break;
            fout.open(des.d, std::ios::binary);
            if (!fout) {
                break;
            }
            fout.write(inp.p, fin.gcount());
            num--;
            pl--;
            fout.close();
            if (num == 0) break;
            inp.size = sf + ((pl > 0)? 1 : 0);
            des.d.erase(dds);
            for (int i = no.size() - 1; i >= 0; i--) {
                if (no[i] == '9') {
                    no[i] = '0';
                    check = 1;
                    continue;
                }
                no[i]++;
                check = 0;
                break;
            }
            if (check == 1) {
                for (int i = 1; i < no.size(); i++) {
                    no[i] = '0';
                }
                no[0] = '1';
                no += "0";
            }
            des.d.erase(dds);
            des.d += ".part";
            des.d += no;
            des.d += ".bin";
        }
        inp.dealloc();
        fin.close();
        std::cout << "Successfully split the file into " << x - ((num > 0)? num : 0) << " files.";
        if (num > 0) std::cout << "\nAlthough it's not enough bytes!";
    }
    else {
        int check = 0;
        fin.seekg(0, std::ios::end);
        long int sf = fin.tellg();
        fin.seekg(0, std::ios::beg);
        int num = sf/x + ((sf % x > 0)? 1: 0);
        inp.size = x;
        while (fin) {
            fin.read(inp.p, inp.size);
            if (fin.gcount() == 0) break;
            fout.open(des.d, std::ios::binary);
            if (!fout) {
                break;
            }
            fout.write(inp.p, fin.gcount());
            fout.close();
            num--;
            if (num == 0 || !fin) break;
            inp.size = ((num == 1 && sf % x != 0)? sf % x : x);
            des.d.erase(dds);
            for (int i = no.size() - 1; i >= 0; i--) {
                if (no[i] == '9') {
                    no[i] = '0';
                    check = 1;
                    continue;
                }
                no[i]++;
                check = 0;
                break;
            }
            if (check == 1) {
                for (int i = 1; i < no.size(); i++) {
                    no[i] = '0';
                }
                no[0] = '1';
                no += "0";
            }
            des.d.erase(dds);
            des.d += ".part";
            des.d += no;
            des.d += ".bin";
        }
        inp.dealloc();
        fin.close();
        std::cout << "Successfully split the file into " << sf/x + 1 << " files.\n";
    }
}

void cmd :: MYMERGEFILE(std::string st) {
    std::string sub = "";
    for (int i = 0; i < 15; i++) {
        sub += st[i];
    }
    if (sub != "MYMERGEFILE -s ") {
        std::cerr << "Invalid command. Should be \"MYMERGEFILE -s source_of_part_1 -d destination\"!";
        return;
    }
    int sid = 15, did = -1;
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
        std::cerr << "Invalid command. Should be \"MYMERGEFILE -s source_of_part_1 -d destination\"!";
        return;
    }
    std::string sour = "", dest = "";
    for (int i = sid; i <= esid; i++) sour += st[i];
    for (int i = did; i <= edid; i++) dest += st[i];

    mergef(sour, dest);
}

void cmd :: mergef(std::string ptsource,std::string ptdes) {
    src source(ptsource);
    des des(ptdes);
    std::string no = "1";
    std::string extension = source.findExt();
    if (!(source.findPart() == ".part1")) {
        std::cerr << "Invalid command. Should be \"MYMERGEFILE -s source_of_part_1 -d destination\"!";
        return;
    }
    int sss = source.findExt().size() + source.findPart().size();
    if (des.d[des.d.size() - 1] != '\\') des.d += "\\";
    std::ifstream fin;
    std::ofstream fout;
    fin.open(source.s, std::ios::binary);
    if (!fin) {
        std::cerr << "Error openning the source file!";
        return;
    }
    des.d += source.findFile();
    des.d.erase(des.d.size() - sss);
    sss = source.s.size() - sss + 5;
    des.d += source.findExt();
    fout.open(des.d, std::ios::binary);
    if (!fout) {
        std::cerr << "Error openning the destination file!";
        return;
    }
    DA<char> inp;
    inp.alloc();
    int check = 0;
    while (fin) {
        while(fin) {
            fin.read(inp.p, inp.size);
            fout.write(inp.p, fin.gcount());
        }
        for (int i = no.size() - 1; i >= 0; i--) {
            if (no[i] == '9') {
                no[i] = '0';
                check = 1;
                continue;
            }
            no[i]++;
            check = 0;
            break;
        }
        if (check == 1) {
            for (int i = 1; i < no.size(); i++) {
                no[i] = '0';
            }
            no[0] = '1';
            no += "0";
        }
        fin.close();
        source.s.erase(sss);
        source.s += no + extension;
        fin.open(source.s, std::ios::binary);
    }
    fout.close();
    std::cout << "Successfully merge the files into one file.\n";
}