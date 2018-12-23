#include "threepoint.h"
#include <stdio.h>

int main(){
  threepoint p = {.x=3, .y=0, .z=4};
  printf("p is %g units from the origin\n", threelength(p));
  double xylength = length(p.p2);
  printf("Its projection onto the XY plane is %g units from the origin\n", xylength);
}
