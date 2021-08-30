#ifndef MATHUTILS_H
#define MATHUTILS_H

#include "Matrix44.h"
#include "Vector4.h"
#include "Vector3.h"

void testStuff();

void rotateX(Matrix44* m, float degrees, Matrix44* dest);
void rotateY(Matrix44* m, float degrees, Matrix44* dest);
void rotateZ(Matrix44* m, float degrees, Matrix44* dest);
void translate(float x, float y, float z, Matrix44* m, Matrix44* dest);
void transpose(Matrix44* m, Matrix44* dest);
void copyToBuffer(Matrix44* m, float dest[]);
void copyToBufferTransposed(Matrix44* m, float dest[]);
void createTransformationMatrix(Vector3* position, Vector3* rotation, Vector3* scale, Matrix44* dest);
#endif
