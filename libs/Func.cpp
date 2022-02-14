#include "Func.hpp"

Vetor Func::produtoVetorial (Vetor &v1, Vetor &v2) {
	return Vetor { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
}