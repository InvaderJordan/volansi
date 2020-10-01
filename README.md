# K-D Tree Library

## Problem Statement

Implement a very basic library to perform [k-d tree](https://en.wikipedia.org/wiki/K-d_tree) operations.  A header file with the desired API will be provided.  Functions in the library will include building a tree from a list of points, and searching the tree to find the node closest to a given (x, y) location.  Several test datasets will be provided, along with a precompiled test program, dynamically linked to libtree.so, that can be used to test your library.

## Setup

**Provided files:**
+ **kdtree.h**: Header file defining the libtree API
+ **kdtree.c**: Starter code skeleton of functions to implement
+ **kd_internals.h**: Header file with “hints” for the functions to implement in kdtree.c
+ **sample_a.csv**, **sample_b.csv**, **sample_c.csv**: 3 sets of points input files to test with
+ **generate_random_points.py**: Helper script to generate sets of test point input files
+ **TreeTester**: Executable that will test your libtree.so alongside the “solution” and print PASS or FAIL
    + The TreeTester executable was compiled on Ubuntu 18.04 with gcc; any Ubuntu / Debian Linux derivative **should** be able to use it just fine.

## Requirements

Your output should be the following:

+ The source file for libtree, **kdtree.c**, written in the C language and using only standard C libraries, implementing 2D k-d tree operations and conforming to the API in kdtree.h
+ The source file for a test executable, **main.c**, which loads a dataset from a file and makes use the library on a given search point
+ A **Makefile** that can build both **main** and **libtree**, with separate build targets to do both **static** and **dynamic** linking.

## The Algorithms

Feel free to read the Wikipedia article for the details of the construction and search algorithms, along with the pseudocode shown there.  The construction of the tree is fairly simple:

```
function kdtree (list of points pointList, int depth)
{
    // Select axis based on depth so that axis cycles through all valid values
    var int axis := depth mod k;

    // Sort point list and choose median as pivot element
    select median by axis from pointList;

    // Create node and construct subtree
    node.location := median;
    node.leftChild := kdtree(points in pointList before median, depth+1);
    node.rightChild := kdtree(points in pointList after median, depth+1);
    return node;
}
```
Psuedocode source: https://en.wikipedia.org/wiki/K-d_tree

To find the node nearest a given point (a random (x,y) point not belonging to the tree), you must traverse the tree and calculate the distance from each node you visit to the input point.  Ideally you keep track of the bounding box of the region defined by each node in the tree to avoid visiting nodes that you know are farther away than the current minimum distance (see below), but a simple / unoptimized implementation could simply use the distance to the current splitting plane instead (you can do this for speed of coding, so you don't have to keep track of the bounding box at each node -- the exercise is long enough as it is).

```
def NN(Point Q, kdTree T, int cd, Rect BB):
    // if this bounding box is too far, do nothing
    if T == NULL or distance(Q, BB) > best_dist: return
    
    // if this point is better than the best:
    dist = distance(Q, T.data)
    if dist < best_dist:
        best = T.data
        best_dist = dist
    
    // visit subtrees is most promising order:
    if Q[cd] < T.data[cd]:
        NN(Q, T.left, next_cd, BB.trimLeft(cd, t.data))
        NN(Q, T.right, next_cd, BB.trimRight(cd, t.data))
    else:
        NN(Q, T.right, next_cd, BB.trimRight(cd, t.data))
        NN(Q, T.left, next_cd, BB.trimLeft(cd, t.data))
```
Pseudocode source: https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/kdtrees.pdf