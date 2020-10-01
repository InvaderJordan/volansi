/******************************************************************************
* @file kdtree.c
* @author Jacob Crabill <jacob@flyvoly.com>
* @date September 2020
* @brief Source file implementing K-D Tree library
*
* For Volans-i's Fall 2020 Embedded Software Team Interview Exercise
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "kdtree.h"
#include "kd_internals.h"


/* -------- External Function Definitions -------- */

static void print_tree_recurse(Node *node) {
  if (node == NULL) {
    return;
  }
  printf("(%f,%f) %d\r\n", node->loc.x, node->loc.y, node->loc.id);
  print_tree_recurse(node->left);
  print_tree_recurse(node->right);
}

Node *kd_build(const float *points, uint32_t n_points)
{
    Node *list = malloc(sizeof(Node) * n_points);

    for (int i = 0; i < n_points*2; i+= 2) {
      list[i/2].loc.x = points[i];
      list[i/2].loc.y = points[i+1];
      list[i/2].loc.id = i/2;
      list[i/2].left = NULL;
      list[i/2].right = NULL;
    }

    Node *root = kd_build_recurse(list, 0, n_points, 0);
    //printf("Root: (%f, %f) %d\r\n", root->loc.x, root->loc.y, root->loc.id);
    print_tree_recurse(root);

    return root;
}

float kd_find_nearest(Node *kdtree, const Point *loc, Node **nearest)
{
    /// TODO
    return 0.0;
}

/* -------- Internal Function Definitions -------- */

void sort_points(Node *list, uint32_t n_points, uint8_t axis)
{
    qsort(list, n_points, sizeof(list[0]), axis ? compare_y : compare_x);
}

Node *kd_build_recurse(Node *list, uint32_t min, uint32_t max, uint8_t depth)
{
  if ((min) >= max) {
    return NULL;
  }

  //printf("Min: %d, Max: %d\r\n", min, max);

  uint8_t axis = depth % 2;
  uint32_t median = find_median(&list[min], max - min, axis);
  //printf("Median: %d, Depth: %d\r\n", min + median, depth);
  list[min + median].left = kd_build_recurse(list, min, min + median, depth + 1);
  list[min + median].right = kd_build_recurse(list, min + median + 1, max, depth + 1);

  return &list[min + median];
}

float kd_nearest_recurse(Node *tree, const Point *loc, float min_dist, Node **best, uint8_t depth)
{
    /// TODO
    return 0.0;
}
