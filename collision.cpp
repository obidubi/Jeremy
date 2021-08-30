#include <stdlib.h>
#include <math.h>
#include "collision.h"

void createBoxCollider(Vector3 position, Vector3 rotation, Vector3 scale) {
	BoxCollider* collider = (BoxCollider*) malloc(sizeof(BoxCollider));
	Vector3 baseVerts[] = {{1, 1, 1},
						   {1, 1, -1}, 
						   {-1, 1, -1}, 
						   {-1, 1, 1}, 
						   {1, -1, 1}, 
						   {1, -1, -1}, 
						   {-1, -1, -1}, 
						   {-1, -1, 1}};

	double xRadians = rotation.x / 180.0 * PI;
	double yRadians = rotation.y / 180.0 * PI;
	double zRadians = rotation.z / 180.0 * PI;
}

void transform(BoxCollider* collider) {
	Vector3 baseVerts[] = { {1, 1, 1},
						   {1, 1, -1},
						   {-1, 1, -1},
						   {-1, 1, 1},
						   {1, -1, 1},
						   {1, -1, -1},
						   {-1, -1, -1},
						   {-1, -1, 1} };
	Vector3 rotation = collider->rotation;
	double xRadians = rotation.x / 180.0 * PI;
	double yRadians = rotation.y / 180.0 * PI;
	double zRadians = rotation.z / 180.0 * PI;
	Matrix33 xRot = {1, 0, 0, 0, cos(xRadians), -sin(xRadians), 0, sin(xRadians), cos(xRadians)};
	Matrix33 yRot = {cos(yRadians), 0, sin(yRadians), 0, 1, 0, -sin(yRadians), 0, cos(yRadians)};
	Matrix33 zRot = {cos(zRadians), -sin(zRadians), 0, sin(zRadians), cos(zRadians), 0, 0, 0, 1};
	Matrix33 dest;
	multiplyMatrix33(&yRot, &xRot, &dest);
	multiplyMatrix33(&zRot, &dest, &dest);
	for (int i = 0; i < 8; i++) {
		multiplyMat33Vec3(&dest, &baseVerts[i], &collider->next[i]);
	}
}

void applyTransform(BoxCollider* collider) {
	for (int i = 0; i < 8; i++) {
		collider->prev[i] = collider->next[i];
	}
}

int edgeToEdgeCollision(Vector3* ei1, Vector3* ei2, Vector3* ef1, Vector3* ef2, Vector3* pe1, Vector3* pe2) {
	Vector3 vel, D1, n1;
	subtractVector3(ef1, ei1, &vel);
	subtractVector3(ei2, ei1, &D1);
	crossProduct(&vel, &D1, &n1);
	normalizeVector3(&n1, &n1);

	Vector3 Pd;
	subtractVector3(pe1, pe2, &Pd);

	float denominator1 = dotProductVector3(&D1, &n1);
	if (denominator1 == 0) return 0;
	float numerator1 = dotProductVector3(&Pd, &n1);

	float t1 = numerator1 / denominator1;
	Vector3 p1 = {ei1->x + t1 * D1.x, ei1->y + t1 * D1.y, ei1->z + t1 * D1.z};
	if (!betweenPoints(pe1, pe2, &p1)) return 0;

	Vector3 D2, n2;
	subtractVector3(ef2, ef1, &D2);
	crossProduct(&vel, &D2, &n2);
	float denominator2 = dotProductVector3(&D2, &n2);
	if (denominator2 == 0) return 0;
	float numerator2 = dotProductVector3(&Pd, &n2);

	float t2 = numerator2 / denominator2;
	Vector3 p2 = {ef1->x + t2 * D2.x, ef1->y + t2 * D2.y, ef1->z + t2 * D2.z};

	if (!betweenPoints(pe1, pe2, &p2)) return 0;


}

int betweenPoints(Vector3* p1, Vector3* p2, Vector3* v) {
	float xMin = p1->x, xMax = p2->x, yMin = p1->y, yMax = p2->y, zMin = p1->z, zMax = p2->z;
	if (xMin > xMax) {
		xMin = xMax;
		xMax = p1->x;
	}
	if (yMin > yMax) {
		yMin = yMax;
		yMax = p1->y;
	}
	if (zMin > zMax) {
		zMin = zMax;
		zMax = p1->z;
	}
	if (v->x < xMin || v->x > xMax || v->y < yMin || v->y > xMax || v->z < zMin || v->z > zMax) return 0;
	return 1;
}