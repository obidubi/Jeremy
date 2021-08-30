#ifndef MATRIX44_H
#define MATRIX44_H

#include "Vector4.h"

struct Matrix44 {
	float m00, m01, m02, m03;
	float m10, m11, m12, m13;
	float m20, m21, m22, m23;
	float m30, m31, m32, m33;
};

typedef struct Matrix44 Matrix44;

void addMatrix44(Matrix44* a, Matrix44* b, Matrix44* dest);
void subtractMatrix44(Matrix44* a, Matrix44* b, Matrix44* dest);
void scaleMatrix44(Matrix44* m, float scalar, Matrix44* dest);
void multiplyMatrix44(Matrix44* a, Matrix44* b, Matrix44* dest);
void setIdentityMatrix44(Matrix44* m);

void multiplyMat44Vec4(Matrix44* m, Vector4* v, Vector4* dest);

#endif
