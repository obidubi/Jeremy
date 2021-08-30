#ifndef MATRIX33_H
#define MATRIX33_H

#include "Vector3.h"

struct Matrix33 {
	float m00, m01, m02;
	float m10, m11, m12;
	float m20, m21, m22;
};

typedef struct Matrix33 Matrix33;

void addMatrix33(Matrix33* a, Matrix33* b, Matrix33* dest);
void subtractMatrix33(Matrix33* a, Matrix33* b, Matrix33* dest);
void scaleMatrix33(Matrix33* m, float scalar, Matrix33* dest);
void multiplyMatrix33(Matrix33* a, Matrix33* b, Matrix33* dest);

void multiplyMat33Vec3(Matrix33* m, Vector3* v, Vector3* dest);

#endif
