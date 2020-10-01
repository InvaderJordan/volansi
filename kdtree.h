/******************************************************************************
* @file kdtree.h
* @author Jacob Crabill <jacob@flyvoly.com>
* @date September 2020
* @brief Header file defning K-D Tree library API
*
* For Volans-i's Fall 2020 Embedded Software Team Interview Exercise
******************************************************************************/

#ifndef KDTREE_H
#define KDTREE_H

#include <stdint.h>

typedef struct {
    float x;
    float y;
    uint32_t id; // Index of point from input file
} Point;

typedef struct {
    Point loc;
    void *left;
    void *right;
} Node;

/* @brief build a 2D K-D Tree from a list of points
 * 
 * The nodes/points will be ID'd based on their position within the input array,
 * in the range [0, n_points - 1]
 * 
 * @param points - The array of (x, y) points (AoS data format)
 * @param n_points - The number of (x, y) point pairs in 'points'
 * @return Pointer to the root node of the tree
 */
Node* kd_build(const float *points, uint32_t n_points);

/* @brief Find the nearest tree node to the given 2D point
 * 
 * @param kdtree - Root of the k-d tree to search
 * @param loc - Search point
 * @param nearest - Upon return, points to nearest node in tree
 * @return Distance from 'loc' to nearest node
 */
float kd_find_nearest(Node *kdtree, const Point *loc, Node **nearest);

#endif /* KDTREE_H */