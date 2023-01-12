// 참고한 사이트
// https://favtutor.com/blogs/dijkstras-algorithm-cpp

#include <iostream>
#include <queue>

using namespace std;

#define SIZE 6
#define INFINITY 100000000

void Dijkstra(int graph[SIZE][SIZE], int src)
{
    int distance[SIZE];
    int visitedOrder[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        distance[i] = INFINITY;
        visitedOrder[i] = -1;
    }

    distance[src] = 0;

    for (int i = 0; i < SIZE; i++)
    {
        int index;
        auto min = INFINITY;

        // Extract Min
        for (int k = 0; k < SIZE; k++)
        {
            if (visitedOrder[k] < 0 && distance[k] <= min)
            {
                min = distance[k];
                index = k;
            }
        }
        visitedOrder[index] = i;

        // Set Distances
        for (int j = 0; j < SIZE; j++)
        {
            if (visitedOrder[j] < 0 && graph[index][j] && distance[index] != INFINITY && distance[index] + graph[index][j] < distance[j])
            {
                distance[j] = distance[index] + graph[index][j];
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << visitedOrder[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << distance[i] << endl;
    }
}

int main()
{
    int graph[SIZE][SIZE] = {
    {0, 1, 2, 0, 0, 0},
    {1, 0, 0, 5, 1, 0},
    {2, 0, 0, 2, 3, 0},
    {0, 5, 2, 0, 2, 2},
    {0, 1, 3, 2, 0, 1},
    {0, 0, 0, 2, 1, 0} 
    };

    Dijkstra(graph, 0);
    return 0;
}

/*
음의 가중치가 있을 경우
다익스트라 알고리즘은 그리디 알고리즘 이기 때문에
음의 가중치가 있는 경우 모든 경로를 Update 하고도 더 좋은 경로가 발견되는데
다익스트라 알고리즘은 이미 최선의 선택을 모두 했기 때문에 이를 찾을 수 없다.
*/

/*
그리디 알고리즘

그리디 알고리즘이란 현재 단계에서 선택 가능한 것 중 최선의 해를 선택하며 최적의 해를 찾는 알고리즘이다.
항상 optimal solution을 주는지 검증이 필요하다.

예 )  Best-first search, Kruskal, Prim, Dijkstra

Kruskal 알고리즘을 사용하여 Minimum Spanning Tree를 찾을 때 그래프에서 간선의 가중치가 가장 낮은 간선을 검사하며, Tree에 합친다.
그러므로 최종적으로 모든 가중치의 합이 가장 작은 Spanning Tree가 완성된다.

*/