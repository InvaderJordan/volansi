#include <stdio.h>
#include <stdlib.h>

#include "kdtree.h"

int main(void) {
  FILE *fp = fopen("sample_a.csv", "r");
  int num_points;
  fscanf(fp, "%d", &num_points);

  float *list = malloc(sizeof(float) * num_points * 2);

  for (int i = 0; i < num_points; i++) {
    fscanf(fp, "%f, %f", &list[i*2], &list[i*2+1]);
  }

  Node *root = kd_build(list, num_points);
  Node *nearest;
  Point pnt;
  pnt.x = 10.0;
  pnt.y = 10.0;
  printf("Dist: %f\r\n", kd_find_nearest(root, &pnt, &nearest));
  printf("Nearest: (%f, %f)\r\n", nearest->loc.x, nearest->loc.y);

  // TODO free Node list
  free(list);
  fclose(fp);
  return 0;
}
