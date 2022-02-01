#include "func.hpp"

vetor func::produtoVetorial (vetor &v1, vetor &v2) {
	return vetor { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
}