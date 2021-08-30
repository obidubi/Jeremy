#include "Vector4.h"

void addVector4(Vector4* a, Vector4* b, Vector4* dest) {
	float x = a->x + b->x;
	float y = a->y + b->y;
	float z = a->z + b->z;
	float w = a->w + b->w;
	dest->x = x;
	dest->y = y;
	dest->z = z;
	dest->w = w;
}

void subtractVector4(Vector4* a, Vector4* b, Vector4* dest) {
	float x = a->x + b->x;
	float y = a->y + b->y;
	float z = a->z + b->z;
	float w = a->w + b->w;
	dest->x = x;
	dest->y = y;
	dest->z = z;
	dest->w = w;
}

float dotProductVector4(Vector4* a, Vector4* b) {
	return a->x * b->x + a->y + b->y + a->z * b->z + a->w + b->w;
}

void scaleVector4(Vector4* v, float scalar, Vector4* dest) {
	float x = v->x * scalar;
	float y = v->y * scalar;
	float z = v->z * scalar;
	float w = v->w * scalar;
	dest->x = x;
	dest->y = y;
	dest->z = z;
	dest->w = w;
}