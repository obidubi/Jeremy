#ifndef VECTOR3_H
#define VECTOR3_H

struct Vector3 {
	float x;
	float y;
	float z;
};

typedef struct Vector3 Vector3;

void addVector3(Vector3* a, Vector3* b, Vector3* dest);
void subtractVector3(Vector3* a, Vector3* b, Vector3* dest);
void scaleVector3(Vector3* v, float scalar, Vector3* dest);
float dotProductVector3(Vector3* a, Vector3* b);
void crossProduct(Vector3* a, Vector3* b, Vector3* dest);
float length(Vector3* v);
void normalizeVector3(Vector3* v, Vector3* dest);

#endif