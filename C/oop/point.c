// Include header of the "class"
#include "point.h"

#include <math.h>


// Public methods implementation down here

double length (point p){
  return sqrt(p.x*p.x + p.y*p.y);
}

// Add private methods down here if needed
