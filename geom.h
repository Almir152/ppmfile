#include <cmath>

using namespace std;


class Point {
public:
    double x;
    double y;

    Point() = default;

    Point(double x, double y) : x(x), y(y) {}

};

double Lengh(Point &a, Point &b);


class Vector {
public:
    double x;
    double y;
    double len;


    Vector() {}

    Vector(double x, double y) : x(x), y(y), len(sqrt(x * x + y * y)) {}

    Vector(Point beg, Point end) {
        x = end.x - beg.x;
        y = end.y - beg.y;
        len = sqrt(x * x + y * y);
    }
};

double DotProd(Vector &l, Vector &r);

double CrossProd(Vector &l, Vector &r);

Vector Norm(Vector &v);

Vector MultVec(Vector &a, double k);


class Triangle {
public:
    Point a;
    Point b;
    Point c;

    Triangle(){}

    Triangle(Point a, Point b, Point c): a(a), b(b), c(c){}
};

bool InTriangle(Triangle &t, Point &p);