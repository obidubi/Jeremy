#include <math.h>

#include "Matrix33.h"
#include "Matrix44.h"
#include "Vector3.h"
#include "Vector4.h"

#define PI 3.1415926535;

//Testing some stuff
void testStuff() {
	Matrix33 m31 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
	Matrix33 m32 = {1, 1, 1, 2, 2, 2, 3, 3, 3};
	Matrix33 m3sum1;
	addMatrix33(&m31, &m32, &m3sum1);
	Matrix33 m3sum2;
	subtractMatrix33(&m31, &m32, &m3sum2);
	Matrix33 m3product;
	multiplyMatrix33(&m31, &m32, &m3product);

	Vector3 v31 = {1, 0, 0};
	Vector3 v32 = {0, 0, 1};
	Vector3 v3sum1;
	addVector3(&v31, &v32, &v3sum1);
	Vector3 v3sum2;
	subtractVector3(&v31, &v32, &v3sum2);
	float v3prod1 = dotProductVector3(&v31, &v32);
	Vector3 v3prod2;
	crossProduct(&v31, &v32, &v3prod2);

	Vector3 m3v3prod;
	multiplyMat33Vec3(&m31, &v31, &m3v3prod);
}

//Translation stuff
void rotateX(Matrix44* m, float degrees, Matrix44* dest) {
	float radians = degrees / 180.0f * PI;
	Matrix44 rotX = {1, 0,            0,             0, 
					 0, cos(radians), -sin(radians), 0, 
					 0, sin(radians), cos(radians),  0, 
					 0, 0,            0,             1};
	multiplyMatrix44(m, &rotX, dest);
}

void rotateY(Matrix44* m, float degrees, Matrix44* dest) {
	float radians = degrees / 180.0f * PI;
	Matrix44 rotY = {cos(radians),  0, sin(radians), 0, 
					 0,             1, 0,            0, 
					 -sin(radians), 0, cos(radians), 0, 
					 0,             0, 0,            1};
	multiplyMatrix44(m, &rotY, dest);
}

void rotateZ(Matrix44* m, float degrees, Matrix44* dest) {
	float radians = degrees / 180.0f * PI;
	Matrix44 rotZ = {cos(radians), -sin(radians), 0, 0, 
					 sin(radians), cos(radians),  0, 0, 
					 0,            0,             1, 0, 
					 0,            0,             0, 1};
	multiplyMatrix44(m, &rotZ, dest);
}

void translate(float x, float y, float z, Matrix44* m, Matrix44* dest) {
	Matrix44 tran = {0, 0, 0, x, 
					 0, 0, 0, y, 
					 0, 0, 0, z, 
					 0, 0, 0, 0};
	addMatrix44(m, &tran, dest);
}

void transpose(Matrix44* m, Matrix44* dest) {
	float m00 = m->m00;
	float m01 = m->m10;
	float m02 = m->m20;
	float m03 = m->m30;

	float m10 = m->m01;
	float m11 = m->m11;
	float m12 = m->m21;
	float m13 = m->m31;

	float m20 = m->m02;
	float m21 = m->m12;
	float m22 = m->m22;
	float m23 = m->m32;

	float m30 = m->m03;
	float m31 = m->m13;
	float m32 = m->m23;
	float m33 = m->m33;

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

//Assumes you're copying to a 16 float buffer because that's what OpenGL wants
void copyToBuffer(Matrix44* m, float dest[]) {
	dest[0]  = m->m00;
	dest[1]  = m->m01;
	dest[2]  = m->m02;
	dest[3]  = m->m03;

	dest[4]  = m->m10;
	dest[5]  = m->m11;
	dest[6]  = m->m12;
	dest[7]  = m->m13;

	dest[8]  = m->m20;
	dest[9]  = m->m21;
	dest[10] = m->m22;
	dest[11] = m->m23;

	dest[12] = m->m30;
	dest[13] = m->m31;
	dest[14] = m->m32;
	dest[15] = m->m33;
}

//Turns out OpenGL matrices are column major or whatever it's called
void copyToBufferTransposed(Matrix44* m, float dest[]) {
	dest[0]  = m->m00;
	dest[1]  = m->m10;
	dest[2]  = m->m20;
	dest[3]  = m->m30;

	dest[4]  = m->m01;
	dest[5]  = m->m11;
	dest[6]  = m->m21;
	dest[7]  = m->m31;

	dest[8]  = m->m02;
	dest[9]  = m->m12;
	dest[10] = m->m22;
	dest[11] = m->m32;

	dest[12] = m->m03;
	dest[13] = m->m13;
	dest[14] = m->m23;
	dest[15] = m->m33;
}

void scaleMatrixXYZ(float x, float y, float z, Matrix44* dest) {
	Matrix44 scale = {x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1};
	multiplyMatrix44(&scale, dest, dest);
}

//Matrix stuff
void createTransformationMatrix(Vector3* position, Vector3* rotation, Vector3* scale, Matrix44* dest) {
	setIdentityMatrix44(dest);
	scaleMatrixXYZ(scale->x, scale->y, scale->z, dest);
	rotateZ(dest, rotation->z, dest);
	rotateY(dest, rotation->y, dest);
	rotateX(dest, rotation->x, dest);
	translate(position->x, position->y, position->z, dest, dest);
}

void createViewMatrix(Vector3* position, Vector3* rotation, Matrix44* m) {
	
}