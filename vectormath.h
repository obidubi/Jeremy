#ifndef VECTOR_MATH
#define VECTOR_MATH

struct Vector3 {
	float x;
	float y;
	float z;
};

struct Matrix33 {
	float values[9];
};

typedef struct Vector3 Vector3;
typedef struct Matrix33 Matrix33;

void addVector3(Vector3* a, Vector3* b, Vector3* dest);
void subtractVector3(Vector3* a, Vector3* b, Vector3* dest);
void scaleVector3(Vector3* v, float scalar);
float dotProductVector3(Vector3* a, Vector3* b);
void crossProductVector3(Vector3* a, Vector3* b, Vector3* dest);
void normalizeVector3(Vector3* v);

void multiplyVector3Matrix33(Matrix33* m, Vector3* v, Vector3* dest);
void addMatrix33Matrix33(Matrix33*, Matrix33*, Matrix33*);
void subtractMatrix33Matrix33(Matrix33*, Matrix33*, Matrix33*);
void multiplyMatrix33Matrix33(Matrix33*, Matrix33*, Matrix33*);
void printMatrix33(Matrix33*);
#endif