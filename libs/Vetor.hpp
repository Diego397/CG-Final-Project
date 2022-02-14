#include <cmath>

struct Ponto { double x, y, z; };

class Vetor {

public:
	Vetor();

	Vetor(double pX, double pY, double pZ);

	double x, y, z;

	Vetor operator - ();

	void operator += (Vetor &v);
};

Ponto operator + (Ponto &p,  Vetor &v);

Ponto operator - (Ponto &p,  Vetor &v);

Vetor operator - (Ponto &p1,  Ponto &p2);

Vetor operator - (Vetor &v1,  Vetor &v2);

Vetor operator + (Vetor &v1,  Vetor &v2);

Vetor operator / (Vetor& dividendo,  double &divisor);

Vetor operator * (Vetor &v1,  double &mult);

Vetor operator * (double &mult,  Vetor &v1);

double operator * (Vetor &v1,  Vetor &v2 );

double operator * (Ponto &p1,  Vetor &v2 );

double operator * (Vetor &v1, Ponto &p2 );

Vetor produtoVetorial (Vetor &v1,  Vetor &v2);

double norma (Vetor &v);

Vetor normalizar (Vetor &v);