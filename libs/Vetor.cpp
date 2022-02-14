#include "Vetor.hpp"
#include <cmath>

Ponto operator + (Ponto &p,  Vetor &v) {
	return Ponto {p.x + v.x, p.y + v.y, p.z + v.z};
}

Ponto operator - (Ponto &p,  Vetor &v) {
	return Ponto {p.x - v.x, p.y - v.y, p.z - v.z};
}

Vetor::Vetor()
{
	x = y = z = 0;
}

Vetor::Vetor(double px, double py, double pz)
{
	x = px, y = py, z = pz;
}

Vetor Vetor::operator - () { return Vetor{-x, -y, -z}; }

void Vetor::operator += ( Vetor &v) {
	x += v.x;
	y += v.y;
	z += v.z;
}

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
	return Vetor {dividendo.x / divisor, dividendo.y / divisor, dividendo.z / divisor};
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

Vetor produtoVetorial (Vetor &v1,  Vetor &v2)
{
	return { 
		v1.y*v2.z - v1.z*v2.y, 
		v1.z*v2.x - v1.x*v2.z, 
		v1.x*v2.y - v1.y*v2.x 
	};
}

double norma (Vetor &v)
{
	return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

Vetor normalizar (Vetor &v)
{
	double norm = norma(v);
	return v / norm;
}