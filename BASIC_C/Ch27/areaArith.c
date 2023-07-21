#include "basicArith.h" // Actually including "basicArith.c"
// It serves as index of functions of areaArith.c
double TriangleArea(double base, double height){ return Div(Mul(base, height), 2); }
double CircleArea(double rad){ return Mul(Mul(rad, rad), PI); }