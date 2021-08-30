#ifndef VECTOR4_H
#define VECTOR4_H

struct Vector4 {
	float x;
	float y;
	float z;
	float w;
};

typedef struct Vector4 Vector4;

void addVector4(Vector4* a, Vector4* b, Vector4* dest);
void subtractVector4(Vector4* a, Vector4* b, Vector4* dest);
float dotProductVector4(Vector4* a, Vector4* b);
//void crossProductVector4(Vector4* a, Vector4* b, Vector4* dest); //Would be useful for transformations with mat4, but not really sure how to handle it yet
void scaleVector4(Vector4* v, float scalar, Vector4* dest);

#endif