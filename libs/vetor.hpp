struct ponto { double x, y, z; };

class vetor {

public:
	vetor();

	vetor(double pX, double pY, double pZ);

	double x, y, z;

	vetor operator - ();

	void operator += (vetor &v);
};

ponto operator + (ponto &p,  vetor &v);

ponto operator - (ponto &p,  vetor &v);

vetor operator - (ponto &p1,  ponto &p2);

vetor operator - (vetor &v1,  vetor &v2);

vetor operator + (vetor &v1,  vetor &v2);

vetor operator / (vetor& dividendo,  double &divisor);

vetor operator * (vetor &v1,  double &mult);

vetor operator * (double &mult,  vetor &v1);

double operator * (vetor &v1,  vetor &v2 );

double operator * (ponto &p1,  vetor &v2 );

double operator * (vetor &v1, ponto &p2 );