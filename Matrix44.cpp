#include "Matrix44.h"

void addMatrix44(Matrix44* a, Matrix44* b, Matrix44* dest) {
	float m00 = a->m00 + b->m00;
	float m01 = a->m01 + b->m01;
	float m02 = a->m02 + b->m02;
	float m03 = a->m03 + b->m03;

	float m10 = a->m10 + b->m10;
	float m11 = a->m11 + b->m11;
	float m12 = a->m12 + b->m12;
	float m13 = a->m13 + b->m13;

	float m20 = a->m20 + b->m20;
	float m21 = a->m21 + b->m21;
	float m22 = a->m22 + b->m22;
	float m23 = a->m23 + b->m23;

	float m30 = a->m30 + b->m30;
	float m31 = a->m31 + b->m31;
	float m32 = a->m32 + b->m32;
	float m33 = a->m33 + b->m33;

	dest->m00 = m00;
	dest->m01 = m01;
	dest->m02 = m02;
	dest->m03 = m03;

	dest->m10 = m10;
	dest->m11 = m11;
	dest->m12 = m12;
	dest->m13 = m13;

	dest->m20 = m20;
	dest->m21 = m21;
	dest->m22 = m22;
	dest->m23 = m23;

	dest->m30 = m30;
	dest->m31 = m31;
	dest->m32 = m32;
	dest->m33 = m33;
}

void subtractMatrix44(Matrix44* a, Matrix44* b, Matrix44* dest) {
	float m00 = a->m00 - b->m00;
	float m01 = a->m01 - b->m01;
	float m02 = a->m02 - b->m02;
	float m03 = a->m03 - b->m03;

	float m10 = a->m10 - b->m10;
	float m11 = a->m11 - b->m11;
	float m12 = a->m12 - b->m12;
	float m13 = a->m13 - b->m13;

	float m20 = a->m20 - b->m20;
	float m21 = a->m21 - b->m21;
	float m22 = a->m22 - b->m22;
	float m23 = a->m23 - b->m23;

	float m30 = a->m30 - b->m30;
	float m31 = a->m31 - b->m31;
	float m32 = a->m32 - b->m32;
	float m33 = a->m33 - b->m33;

	dest->m00 = m00;
	dest->m01 = m01;
	dest->m02 = m02;
	dest->m03 = m03;

	dest->m10 = m10;
	dest->m11 = m11;
	dest->m12 = m12;
	dest->m13 = m13;

	dest->m20 = m20;
	dest->m21 = m21;
	dest->m22 = m22;
	dest->m23 = m23;

	dest->m30 = m30;
	dest->m31 = m31;
	dest->m32 = m32;
	dest->m33 = m33;
}

void scaleMatrix44(Matrix44* a, float scalar, Matrix44* dest) {
	float m00 = a->m00 * scalar;
	float m01 = a->m01 * scalar;
	float m02 = a->m02 * scalar;
	float m03 = a->m03 * scalar;

	float m10 = a->m10 * scalar;
	float m11 = a->m11 * scalar;
	float m12 = a->m12 * scalar;
	float m13 = a->m13 * scalar;

	float m20 = a->m20 * scalar;
	float m21 = a->m21 * scalar;
	float m22 = a->m22 * scalar;
	float m23 = a->m23 * scalar;

	float m30 = a->m30 * scalar;
	float m31 = a->m31 * scalar;
	float m32 = a->m32 * scalar;
	float m33 = a->m33 * scalar;

	dest->m00 = m00;
	dest->m01 = m01;
	dest->m02 = m02;
	dest->m03 = m03;

	dest->m10 = m10;
	dest->m11 = m11;
	dest->m12 = m12;
	dest->m13 = m13;

	dest->m20 = m20;
	dest->m21 = m21;
	dest->m22 = m22;
	dest->m23 = m23;

	dest->m30 = m30;
	dest->m31 = m31;
	dest->m32 = m32;
	dest->m33 = m33;
}

void multiplyMatrix44(Matrix44* a, Matrix44* b, Matrix44* dest) {
	float m00 = a->m00 * b->m00 + a->m01 * b->m10 + a->m02 * b->m20 + a->m03 * b->m30;
	float m01 = a->m00 * b->m01 + a->m01 * b->m11 + a->m02 * b->m21 + a->m03 * b->m31;
	float m02 = a->m00 * b->m02 + a->m01 * b->m12 + a->m02 * b->m22 + a->m03 * b->m32;
	float m03 = a->m00 * b->m03 + a->m01 * b->m13 + a->m02 * b->m23 + a->m03 * b->m33;

	float m10 = a->m10 * b->m00 + a->m11 * b->m10 + a->m12 * b->m20 + a->m13 * b->m30;
	float m11 = a->m10 * b->m01 + a->m11 * b->m11 + a->m12 * b->m21 + a->m13 * b->m31;
	float m12 = a->m10 * b->m02 + a->m11 * b->m12 + a->m12 * b->m22 + a->m13 * b->m32;
	float m13 = a->m10 * b->m03 + a->m11 * b->m13 + a->m12 * b->m23 + a->m13 * b->m33;

	float m20 = a->m20 * b->m00 + a->m21 * b->m10 + a->m22 * b->m20 + a->m23 * b->m30;
	float m21 = a->m20 * b->m01 + a->m21 * b->m11 + a->m22 * b->m21 + a->m23 * b->m31;
	float m22 = a->m20 * b->m02 + a->m21 * b->m12 + a->m22 * b->m22 + a->m23 * b->m32;
	float m23 = a->m20 * b->m03 + a->m21 * b->m13 + a->m22 * b->m23 + a->m23 * b->m33;

	float m30 = a->m30 * b->m00 + a->m31 * b->m10 + a->m32 * b->m20 + a->m33 * b->m30;
	float m31 = a->m30 * b->m01 + a->m31 * b->m11 + a->m32 * b->m21 + a->m33 * b->m31;
	float m32 = a->m30 * b->m02 + a->m31 * b->m12 + a->m32 * b->m22 + a->m33 * b->m32;
	float m33 = a->m30 * b->m03 + a->m31 * b->m13 + a->m32 * b->m23 + a->m33 * b->m33;

	dest->m00 = m00;
	dest->m01 = m01;
	dest->m02 = m02;
	dest->m03 = m03;

	dest->m10 = m10;
	dest->m11 = m11;
	dest->m12 = m12;
	dest->m13 = m13;

	dest->m20 = m20;
	dest->m21 = m21;
	dest->m22 = m22;
	dest->m23 = m23;

	dest->m30 = m30;
	dest->m31 = m31;
	dest->m32 = m32;
	dest->m33 = m33;
}

void multiplyMat44Vec4(Matrix44* m, Vector4* v, Vector4* dest) {
	float x = m->m00 * v->x + m->m01 * v->y + m->m02 * v->z + m->m03 * v->w;
	float y = m->m10 * v->x + m->m11 * v->y + m->m12 * v->z + m->m13 * v->w;
	float z = m->m20 * v->x + m->m21 * v->y + m->m22 * v->z + m->m23 * v->w;
	float w = m->m30 * v->x + m->m31 * v->y + m->m32 * v->z + m->m33 * v->w;

	dest->x = x;
	dest->y = y;
	dest->z = z;
	dest->w = w;
}

void setIdentityMatrix44(Matrix44* m) {
	m->m00 = 1;
	m->m01 = 0;
	m->m02 = 0;
	m->m03 = 0;

	m->m10 = 0;
	m->m11 = 1;
	m->m12 = 0;
	m->m13 = 0;

	m->m20 = 0;
	m->m21 = 0;
	m->m22 = 1;
	m->m23 = 0;

	m->m30 = 0;
	m->m31 = 0;
	m->m32 = 0;
	m->m33 = 1;
}