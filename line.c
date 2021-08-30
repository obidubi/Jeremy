#include "vectormath.h"

struct Line {
	Vector3 p0;
	Vector3 p1;
};

typedef struct Line Line;

Line* createLine(float x1, float y1, float z1, float x2, float y2, float z2) {
	Line* line = malloc(sizeof(Line));

	line->p0.x = x1;
	line->p0.y = y1;
	line->p0.z = z1;

	line->p1.x = x2;
	line->p1.y = y2;
	line->p1.z = z2;

	return line;
}

destroyLine(Line* line) {
	free(line);
}
