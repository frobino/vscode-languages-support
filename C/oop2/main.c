#include <stdio.h>
#include <math.h>

#define Pointguts double x,y;
#define As_point(instruct) (*(point*)(&instruct))

typedef struct point {
  Pointguts
} point;

typedef struct {
  Pointguts
  double z;
} threepoint;

double length (point p){
  return sqrt(p.x*p.x + p.y*p.y);
}

double threelength (threepoint p){
  return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}

int main(){
  threepoint p = {.x=3, .y=0, .z=4};
  printf("p is %g units from the origin\n", threelength(p));
  double xylength = length(As_point(p));
  printf("Its projection onto the XY plane is %g units from the origin\n", xylength);
}
