#ifndef COLLISION_H
#define COLLISION_H

#include "Vector3.h"
#include "Matrix33.h"

#define PI 3.14159265358979323846;

struct BoxCollider {
	Vector3 prev[8];
	Vector3 next[8];
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
};

typedef struct BoxCollider BoxCollider;

void createBoxCollider(Vector3 position, Vector3 rotation, Vector3 scale);

void transform(BoxCollider* collider);
void applyTransform(BoxCollider* collider);
int edgeToEdgeCollision(Vector3* ei1, Vector3* ei2, Vector3* ef1, Vector3* ef2, Vector3* pe1, Vector3* pe2);
int betweenPoints(Vector3* p1, Vector3* p2, Vector3* v);

#endif