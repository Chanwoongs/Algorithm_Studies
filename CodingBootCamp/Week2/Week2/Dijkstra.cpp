// ������ ����Ʈ
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
���� ����ġ�� ���� ���
���ͽ�Ʈ�� �˰����� �׸��� �˰��� �̱� ������
���� ����ġ�� �ִ� ��� ��� ��θ� Update �ϰ� �� ���� ��ΰ� �߰ߵǴµ�
���ͽ�Ʈ�� �˰����� �̹� �ּ��� ������ ��� �߱� ������ �̸� ã�� �� ����.
*/

/*
�׸��� �˰���

�׸��� �˰����̶� ���� �ܰ迡�� ���� ������ �� �� �ּ��� �ظ� �����ϸ� ������ �ظ� ã�� �˰����̴�.
�׻� optimal solution�� �ִ��� ������ �ʿ��ϴ�.

�� )  Best-first search, Kruskal, Prim, Dijkstra

Kruskal �˰����� ����Ͽ� Minimum Spanning Tree�� ã�� �� �׷������� ������ ����ġ�� ���� ���� ������ �˻��ϸ�, Tree�� ��ģ��.
�׷��Ƿ� ���������� ��� ����ġ�� ���� ���� ���� Spanning Tree�� �ϼ��ȴ�.

*/