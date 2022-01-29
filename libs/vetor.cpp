#include "vetor.hpp"

vetor::vetor()
{
    x = y = z = 0;
}

vetor::vetor(double px, double py, double pz)
{
    x = px, y = py, z = pz;
}

vetor vetor::operator - () { return vetor{-x, -y, -z}; }

void vetor::operator += ( vetor &v) {
    x += v.x;
    y += v.y;
    z += v.z;
}

vetor operator - (ponto &p1,  ponto &p2) {
    return vetor (p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
}

vetor operator - (vetor &v1,  vetor &v2) {
    return vetor (v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

vetor operator + (vetor &v1,  vetor &v2) {
    return vetor (v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

vetor operator / (vetor& dividendo,  double &divisor) {
    return vetor {-dividendo.x / divisor, dividendo.y / divisor, dividendo.z / divisor};
}

vetor operator * (vetor &v1,  double &mult) {
    return vetor {v1.x * mult, v1.y * mult, v1.z * mult};
}

vetor operator * (double &mult,  vetor &v1) {
    return v1 * mult;
}

// Produto escalar
double operator * (vetor &v1,  vetor &v2 ) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

double operator * (ponto &p1,  vetor &v2 ) {
    return p1.x * v2.x + p1.y * v2.y + p1.z * v2.z;
}

double operator * (vetor &v1, ponto &p2 ) {
    return p2 * v1;
}

ponto operator + (ponto &p,  vetor &v) {
    return ponto {p.x + v.x, p.y + v.y, p.z + v.z};
}