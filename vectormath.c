#include "vectormath.h"

void addVector3(Vector3* a, Vector3* b, Vector3* dest) {
	dest->x = a->x + b->x;
	dest->y = a->y + b->y;
	dest->z = a->z + b->z;
}

void subtractVector3(Vector3* a, Vector3* b, Vector3* dest) {
	dest->x = a->x - b->x;
	dest->y = a->y + b->y;
	dest->z = a->z + b->z;
}

void scaleVector3(Vector3* a, float scalar) {
	a->x *= scalar;
	a->y *= scalar;
	a->z *= scalar;
}

float dotProductVector3(Vector3* a, Vector3* b) {
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

void crossProductVector3(Vector3* a, Vector3* b, Vector3* dest) {
	dest->x = a->y * b->z - a->z * b->y;
	dest->y = a->z * b->x - a->x * b->z;
	dest->z = a->x * b->y - a->y * b->x;
}

void normalizeVector3(Vector3* v) {
	float length = v->x * v->x + v->y * v->y + v->z * v->z;
	if (length != 0) {
		v->x /= length;
		v->y /= length;
		v->z /= length;
	}
}

void multiplyVector3Matrix33(Matrix33* m, Vector3* v, Vector3* dest) {
	dest->x = m->values[0] * v->x + m->values[1] * v->y + m->values[2] * v->z;
	dest->x = m->values[3] * v->x + m->values[4] * v->y + m->values[5] * v->z;
	dest->x = m->values[6] * v->x + m->values[7] * v->y + m->values[8] * v->z;
}

void addMatrix33Matrix33(Matrix33* a, Matrix33* b, Matrix33* dest) {
	dest->values[0] = a->values[0] + b->values[0];
	dest->values[1] = a->values[1] + b->values[1];
	dest->values[2] = a->values[2] + b->values[2];

	dest->values[3] = a->values[3] + b->values[3];
	dest->values[4] = a->values[4] + b->values[4];
	dest->values[5] = a->values[5] + b->values[5];

	dest->values[6] = a->values[6] + b->values[6];
	dest->values[7] = a->values[7] + b->values[7];
	dest->values[8] = a->values[8] + b->values[8];
}

void subtractMatrix33Matrix33(Matrix33* a, Matrix33* b, Matrix33* dest) {
	dest->values[0] = a->values[0] - b->values[0];
	dest->values[1] = a->values[1] - b->values[1];
	dest->values[2] = a->values[2] - b->values[2];

	dest->values[3] = a->values[3] - b->values[3];
	dest->values[4] = a->values[4] - b->values[4];
	dest->values[5] = a->values[5] - b->values[5];

	dest->values[6] = a->values[6] - b->values[6];
	dest->values[7] = a->values[7] - b->values[7];
	dest->values[8] = a->values[8] - b->values[8];
}

void multiplyMatrix33Matrix33(Matrix33* a, Matrix33* b, Matrix33* dest) {
	dest->values[0] = a->values[0] * b->values[0] + a->values[1] * b->values[3] + a->values[2] * b->values[6];
	dest->values[1] = a->values[0] * b->values[1] + a->values[1] * b->values[4] + a->values[2] * b->values[7];
	dest->values[2] = a->values[0] * b->values[2] + a->values[1] * b->values[5] + a->values[2] * b->values[8];

	dest->values[3] = a->values[3] * b->values[0] + a->values[4] * b->values[3] + a->values[5] * b->values[6];
	dest->values[4] = a->values[3] * b->values[1] + a->values[4] * b->values[4] + a->values[5] * b->values[7];
	dest->values[5] = a->values[3] * b->values[2] + a->values[4] * b->values[5] + a->values[5] * b->values[8];

	dest->values[6] = a->values[6] * b->values[0] + a->values[7] * b->values[3] + a->values[8] * b->values[6];
	dest->values[7] = a->values[6] * b->values[1] + a->values[7] * b->values[4] + a->values[8] * b->values[7];
	dest->values[8] = a->values[6] * b->values[2] + a->values[7] * b->values[5] + a->values[8] * b->values[8];
}

int calculateInverseMatrix33(Matrix33* m) {
	Matrix33 aug = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
	
	return 0;
}

/*
void printVector3(Vector3* v) {
	std::cout << "[" << v->x << ", " << v->y << ", " << v->z << "]" << std::endl;
}

void printMatrix33(Matrix33* m) {
	std::cout << "[" << m->values[0] << " " << m->values[1] << " " << m->values[2] << "]" << std::endl;
	std::cout << "[" << m->values[3] << " " << m->values[4] << " " << m->values[5] << "]" << std::endl;
	std::cout << "[" << m->values[6] << " " << m->values[7] << " " << m->values[8] << "]" << std::endl;
}
*/