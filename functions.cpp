#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include "functions.h"
#include "linked_list.h"

int **getAdjacencyMatrixArray (const char* fileName)
{
    FILE* file = fopen (fileName, "r");

    // In case of an error
    if(file == NULL)
    {
        printf("File does not exist...\n");
        exit(0);
    }

    int id, degree;
    int start, finish;
    int s1, s2, edges;
    int i, j, row;

    // Scan the first line
    if (fscanf(file, "%d %d %d", &s1, &s2, &edges) != 3)
    {
        printf("Failed to read file");
    }

    // Initialise the array
    int **arr = (int **)malloc(s1 * sizeof(int *));
    for (row = 0; row < s2; row++)
    {
        arr[row] = (int *)malloc(s2 * sizeof(int));
    }

    // Fill the array with zeros
    for(i = 0; i < s1; i++)
    {
        for(j = 0; j < s2; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Read the file and update the values
    while (!feof(file))
    {  
        if (fscanf(file, "%d %d", &start, &finish) != 2)
        {
            printf("Failed to read filet");
        }
        arr[start][finish] = 1;
    }
    
    fclose (file);

    return arr;
}

int getAdjacencyMatrixSize(const char* fileName)
{
    FILE* file = fopen (fileName, "r");

    // In case of an error
    if(file == NULL)
    {
        printf("File does not exist...\n");
        exit(0);
    }

    int s1;

    // Scan the first number
    if (fscanf(file, "%d", &s1) != 1)
    {
        printf("Failed to read file");
    }

    return s1;
}


int *initialIndegree(int **arr, int size)
{
    int i, j, sum;
    int *result = (int*)malloc(size * sizeof(int));

    // Sum of every row
    for (i = 0; i < size; i++)
    {
        sum = 0;

        for (j = 0; j < size; j++)
        {
            sum += arr[j][i];
        }

        result[i] = sum;
    }

    return result;
}

void printGraph(std::vector<int> v){
    for ( int const& element: v){
        std::cout<<element<<" ";
    }
}
