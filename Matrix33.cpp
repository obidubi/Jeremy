#include "Matrix33.h"

void addMatrix33(Matrix33* a, Matrix33* b, Matrix33* dest) {
	float m00 = a->m00 + b->m00;
	float m01 = a->m01 + b->m01;
	float m02 = a->m02 + b->m02;

	float m10 = a->m10 + b->m10;
	float m11 = a->m11 + b->m11;
	float m12 = a->m12 + b->m12;

	float m20 = a->m20 + b->m20;
	float m21 = a->m21 + b->m21;
	float m22 = a->m22 + b->m22;

	dest->m00 = m00;
	dest->m01 = m01;
	dest->m02 = m02;

	dest->m10 = m10;
	dest->m11 = m11;
	dest->m12 = m12;

	dest->m20 = m20;
	dest->m21 = m21;
	dest->m22 = m22;
}

void subtractMatrix33(Matrix33* a, Matrix33* b, Matrix33* dest) {
	float m00 = a->m00 - b->m00;
	float m01 = a->m01 - b->m01;
	float m02 = a->m02 - b->m02;

	float m10 = a->m10 - b->m10;
	float m11 = a->m11 - b->m11;
	float m12 = a->m12 - b->m12;

	float m20 = a->m20 - b->m20;
	float m21 = a->m21 - b->m21;
	float m22 = a->m22 - b->m22;

	dest->m00 = m00;
	dest->m01 = m01;
	dest->m02 = m02;

	dest->m10 = m10;
	dest->m11 = m11;
	dest->m12 = m12;

	dest->m20 = m20;
	dest->m21 = m21;
	dest->m22 = m22;
}

void scaleMatrix33(Matrix33* m, float scalar, Matrix33* dest) {
	float m00 = m->m00 * scalar;
	float m01 = m->m01 * scalar;
	float m02 = m->m02 * scalar;

	float m10 = m->m10 * scalar;
	float m11 = m->m11 * scalar;
	float m12 = m->m12 * scalar;

	float m20 = m->m20 * scalar;
	float m21 = m->m21 * scalar;
	float m22 = m->m22 * scalar;

	dest->m00 = m00;
	dest->m01 = m01;
	dest->m02 = m02;

	dest->m10 = m10;
	dest->m11 = m11;
	dest->m12 = m12;

	dest->m20 = m20;
	dest->m21 = m21;
	dest->m22 = m22;
}

void multiplyMatrix33(Matrix33* a, Matrix33* b, Matrix33* dest) {
	float m00 = a->m00 * b->m00 + a->m01 * b->m10 + a->m02 * b->m20;
	float m01 = a->m00 * b->m01 + a->m01 * b->m11 + a->m02 * b->m21;
	float m02 = a->m00 * b->m02 + a->m01 * b->m12 + a->m02 * b->m22;

	float m10 = a->m10 * b->m00 + a->m11 * b->m10 + a->m12 * b->m20;
	float m11 = a->m10 * b->m01 + a->m11 * b->m11 + a->m12 * b->m21;
	float m12 = a->m10 * b->m02 + a->m11 * b->m12 + a->m12 * b->m22;

	float m20 = a->m20 * b->m00 + a->m21 * b->m10 + a->m22 * b->m20;
	float m21 = a->m20 * b->m01 + a->m21 * b->m11 + a->m22 * b->m21;
	float m22 = a->m20 * b->m02 + a->m21 * b->m12 + a->m22 * b->m22;

	dest->m00 = m00;
	dest->m01 = m01;
	dest->m02 = m02;

	dest->m10 = m10;
	dest->m11 = m11;
	dest->m12 = m12;

	dest->m20 = m20;
	dest->m21 = m21;
	dest->m22 = m22;
}

void multiplyMat33Vec3(Matrix33* m, Vector3* v, Vector3* dest) {
	float x = v->x * m->m00 + v->y * m->m01 + v->z * m->m02;
	float y = v->x * m->m10 + v->y * m->m11 + v->z * m->m12;
	float z = v->x * m->m20 + v->y * m->m21 + v->z * m->m22;

	dest->x = x;
	dest->y = y;
	dest->z = z;
}

void setIdentityMatrix33(Matrix33* m) {
	m->m00 = 1;
	m->m01 = 0;
	m->m02 = 0;

	m->m10 = 0;
	m->m11 = 1;
	m->m12 = 0;

	m->m20 = 0;
	m->m21 = 0;
	m->m22 = 1;
}