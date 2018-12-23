#include "threepoint.h"
#include <math.h>

double threelength (threepoint p){
  return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}
