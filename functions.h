#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "linked_list.h"
#include <vector>
// Returns the Adjacency Matrix(2D array) given the filename
int **getAdjacencyMatrixArray (const char* fileName);

// Returns the Adjacency Matrix size (int) given the filename
int getAdjacencyMatrixSize(const char* fileName);

// Returns the initial indegree array
int *initialIndegree(int **arr, int size);

void printGraph(std::vector<int> v);

#endif