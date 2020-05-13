#include <iostream>
#include<iostream>
#include<climits>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define MAX 10000


int sparseMatrix[MAX][3],len;



void insert(int r, int c, int val)
{
    sparseMatrix[len][0] = r;

    sparseMatrix[len][1] = c;

    sparseMatrix[len][2] = val;

    len++;
}


void Bellman_Ford(int graph[][3], int V, int E,
                 int src)
{
    int dis[V];
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;

    dis[src] = 0;


    for (int i = 0; i < V - 1; i++) {

        for (int j = 0; j < E; j++) {
            if (dis[graph[j][0]] + graph[j][2] <
                               dis[graph[j][1]])
                dis[graph[j][1]] =
                  dis[graph[j][0]] + graph[j][2];
        }
    }


    for (int i = 0; i < E; i++) {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];

    }

    cout << "Total cost count of the path" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
}


int main()
{

      int i,j, numOfPoints=7;


       srand(time(0));
 int graphMatrix[numOfPoints][numOfPoints];

 for( i = 0; i < numOfPoints; ++i)
  {for( j = 0;  j < numOfPoints; ++j)
     {graphMatrix[i][j] = abs((i-j)*rand());
cout<<graphMatrix[i][j]<<'\t';

}
cout<<'\n';

  }

    for (i = 0; i < numOfPoints; i++)
        for (j = 0; j < numOfPoints; j++)
            if (graphMatrix[i][j] > 0)
                insert(i, j, graphMatrix[i][j]);

Bellman_Ford(sparseMatrix, numOfPoints, len, 0);


    return 0;
}
//https://www.geeksforgeeks.org/bellman-ford-algorithm-simple-implementation/
//https://www.geeksforgeeks.org/c-program-to-convert-a-matrix-to-sparse-matrix/
//https://www.codespeedy.com/generate-a-matrix-of-random-numbers-in-cpp/
