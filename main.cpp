#include <bits/stdc++.h>
#include "geom.h"
#include "out.h"

using namespace std;


int const W = 1024;
int const H = 1024;

int main() {
    vector<vector<Pixel>> photo(W, vector<Pixel>(H));

    // градиент
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            photo[i][j] = {i / 1024.0, j / 1024.0, i * j / 1024.0};
        }
    }

    // круг
    int x0 = 511, y0 = 511;
    int r = 100;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if ((i - x0) * (i - x0) + (j - y0) * (j - y0) <= r * r) {
                photo[i][j] = {0.5, 0.5, 0.2};
            }
        }
    }

    // треугольник
    int x1 = 634, y1 = 456;
    int x2 = 434, y2 = 967;
    int x3 = 899, y3 = 632;
    Triangle t = Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            Point p = Point(i, j);
            if (InTriangle(t, p)) {
                photo[i][j] = {0.76, 0.3, 0};
            }
        }
    }

    // четырехугольник
    x1 = 34, y1 = 56;
    x2 = 234, y2 = 667;
    x3 = 299, y3 = 232;
    int x4 = 374, y4 = 838;
    Triangle t1 = Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
    Triangle t2 = Triangle(Point(x4, y4), Point(x2, y2), Point(x3, y3));
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            Point p = Point(i, j);
            if (InTriangle(t1, p) || InTriangle(t2, p)) {
                photo[i][j] = {0, 0.9, 0.3};
            }
        }
    }


    PrintPhoto(photo);
}