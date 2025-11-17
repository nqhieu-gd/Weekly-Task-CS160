#include <iostream>
#include <cmath>
#include "Triangle.h"

Point PoiIn(Point a) {
    std::cout << "Enter the point's location on x axis: ";
    std::cin >> a.x;
    std::cout << "Enter the point's location on y axis: ";
    std::cin >> a.y;
};

Triangle TriIn() {
    Triangle h;
    std::cout << "Enter a Triangle: \n";
    std::cout << " Enter the first point: \n";
    PoiIn(h.A);
    std::cout << " Enter the second point: \n";
    PoiIn(h.B);
    std::cout << " Enter the last point: \n";
    PoiIn(h.C);
}

void TriOut(Triangle h) {
    std::cout << "The first point locates at: ()" << h.A.x << ',' << h.A.y << ')' << '\n';
    std::cout << "The second point locates at: ()" << h.B.x << ',' << h.B.y << ')' << '\n';
    std::cout << "The last point locates at: ()" << h.C.x << ',' << h.C.y << ')' << '\n';
}

float Peri(Triangle h){
    float p = 0;
    p += sqrt(pow(h.A.x - h.B.x, 2) + pow(h.A.y - h.B.y, 2));
    p += sqrt(pow(h.A.x - h.C.x, 2) + pow(h.A.y - h.C.y, 2));
    p += sqrt(pow(h.C.x - h.B.x, 2) + pow(h.C.y - h.B.y, 2));

    return p;
}

Point Centroid(Triangle h) {
    Point g;
    g.x = (float) (h.A.x + h.B.x + h.C.x)/3;
    g.y = (float) (h.A.y + h.B.y + h.C.y)/3;

    return g;
}

void LiIn() {
    int n = 0;
    std::cout << "How many Triangle to list: ";
    std::cin >> n;
    int m = -n;
    Triangle li[n];
    while (m < 0) {
        li[n + m] = TriIn();
        m++;
    }
}

void LiOut(Triangle li[]) {
    int n = sizeof(li)/sizeof(li[0]);
    for (int i = 0; i < n; i++) {
        std::cout << "The numer " << i + 1 << "triangle: \n";
        TriOut(li[i]);
    }
}

Triangle BestPeri(Triangle li[]) {
    float p = Peri(li[0]);
    int n = sizeof(li)/sizeof(li[0]), cnt = 0;
    for (int i = 1; i < n; i++) {
        if (Peri(li[i]) > p) p = Peri(li[i]);
        cnt = i;
    }

    return li[cnt];
}