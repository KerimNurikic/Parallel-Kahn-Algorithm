#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <chrono>

#include "functions.h"
#include "linked_list.h"

int main()
{
    // int threads = 2;
    // omp_set_num_threads(threads);

    std::queue<int> nodesQueue;
    std::vector<int> sortedGraph;

    int size = getAdjacencyMatrixSize("dagt.txt");
    int **matrix = getAdjacencyMatrixArray("dagt.txt");

    int *indegree = initialIndegree(matrix, size);

    for (int i = 0; i < size; i++)
    {
        if (indegree[i] == 0)
        {
            nodesQueue.push(i);
        }
    }

    int count = 0;
    int tempValue;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    while (count < size)
    {

        tempValue = nodesQueue.front();

        if (std::find(sortedGraph.begin(), sortedGraph.end(), tempValue) == sortedGraph.end())
        {
            sortedGraph.push_back(tempValue);
        }

        count++;
        int j = 0;
        #pragma omp parallel for num_threads(4)
        for (j = 0; j < size; j++)
        {
            if (matrix[tempValue][j] == 1)
            {
                indegree[j] -= 1;

                if (indegree[j] == 0)
                {
                    nodesQueue.push(j);
                }
            }
        }
        
        nodesQueue.pop();
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    if (sortedGraph.size() < size)
    {
        printf("Graph is cyclic. No topological sort.\n");
    }
    else
    {
        std::cout << "The topological sort is: \n";
        //printGraph(sortedGraph);
    }

    std::cout << "Elapsed time = " << std::chrono::duration<double, std::milli>(end - begin).count() << "[ms]" << std::endl;

    return 0;
}
