#include "point.h"

typedef struct {
  union {
    struct point;
    point p2;
  };
  double z;
} threepoint;

double threelength (threepoint p);
