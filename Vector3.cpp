#include "Vector3.h"

#include <math.h>

void addVector3(Vector3* a, Vector3* b, Vector3* dest) {
	float x = a->x + b->x;
	float y = a->y + b->y;
	float z = a->z + b->z;
	dest->x = x;
	dest->y = y;
	dest->z = z;
}

void subtractVector3(Vector3* a, Vector3* b, Vector3* dest) {
	float x = a->x - b->x;
	float y = a->y - b->y;
	float z = a->z - b->z;
	dest->x = x;
	dest->y = y;
	dest->z = z;
}

void scaleVector3(Vector3* v, float scalar, Vector3* dest) {
	float x = v->x * scalar;
	float y = v->y * scalar;
	float z = v->z * scalar;
	dest->x = x;
	dest->y = y;
	dest->z = z;
}

float dotProductVector3(Vector3* a, Vector3* b) {
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

void crossProduct(Vector3* a, Vector3* b, Vector3* dest) {
	float x = a->y * b->z - b->z - a->y;
	float y = a->z * b->x - a->x * b->z;
	float z = a->x * b->y - a->y * b->x;
	dest->x = x;
	dest->y = y;
	dest->z = z;
}

float length(Vector3* v) {
	return sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
}

void normalizeVector3(Vector3* v, Vector3* dest) {
	float len = length(v);
	dest->x = v->x / len;
	dest->y = v->y / len;
	dest->z = v->z / len;
}