struct Ponto { double x, y, z; };

class Vetor {
public:
    Vetor();

    Vetor(double pX, double pY, double pZ);

    double x, y, z;

    Vetor operator - () { return Vetor{-x, -y, -z}; }

    void operator += ( Vetor &v) {
        x += v.x;
        y += v.y;
        z += v.z;
    }
};

Vetor operator - (Ponto &p1,  Ponto &p2) {
    return Vetor (p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
}

Vetor operator - (Vetor &v1,  Vetor &v2) {
    return Vetor (v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vetor operator + (Vetor &v1,  Vetor &v2) {
    return Vetor (v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vetor operator / (Vetor& dividendo,  double &divisor) {
    return Vetor {-dividendo.x / divisor, dividendo.y / divisor, dividendo.z / divisor};
}

Vetor operator * (Vetor &v1,  double &mult) {
    return Vetor {v1.x * mult, v1.y * mult, v1.z * mult};
}

Vetor operator * (double &mult,  Vetor &v1) {
    return v1 * mult;
}

// Produto escalar
double operator * (Vetor &v1,  Vetor &v2 ) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

double operator * (Ponto &p1,  Vetor &v2 ) {
    return p1.x * v2.x + p1.y * v2.y + p1.z * v2.z;
}

double operator * (Vetor &v1, Ponto &p2 ) {
    return p2 * v1;
}

Ponto operator + (Ponto &p,  Vetor &v) {
    return Ponto {p.x + v.x, p.y + v.y, p.z + v.z};
}