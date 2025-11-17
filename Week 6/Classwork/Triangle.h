#pragma once
struct Point {
    float x;
    float y;
};

struct Triangle {
    Point A;
    Point B;
    Point C;
};

Point PoiIn(Point a);

Triangle TriIn();

void TriOut(Triangle h);

float Peri(Triangle h);

Point Centroid(Triangle h);

void LiIn();

void LiOut(Triangle li[]);

Triangle BestPeri(Triangle li[]);