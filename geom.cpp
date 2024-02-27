#include "geom.h"


double Lengh(Point &a, Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double DotProd(Vector &l, Vector &r) {
    return l.x * r.x + l.y * r.y;
}

double CrossProd(Vector &l, Vector &r) {
    return l.x * r.y - l.y * r.x;
}

Vector Norm(Vector &v) {
    return Vector(v.x / v.len, v.y / v.len);
}

Vector MultVec(Vector &v, double k) {
    return Vector(v.x * k, v.y * k);
}

bool InTriangle(Triangle &t, Point &p) {
    Vector ab = Vector(t.a, t.b);
    Vector ac = Vector(t.a, t.c);
    Vector ap = Vector(t.a, p);

    double dotab = CrossProd(ab, ap);
    double dotac = CrossProd(ac, ap);

    Vector ba = MultVec(ab, -1);
    Vector bc = Vector(t.b, t.c);
    Vector bp = Vector(t.b, p);

    double dotba = CrossProd(ba, bp);
    double dotbc = CrossProd(bc, bp);

    if ((dotab > 0 && dotac < 0 || dotab < 0 && dotac > 0) && (dotba > 0 && dotbc < 0 || dotba < 0 && dotbc > 0)) {
        return true;
    }
    return false;
}
