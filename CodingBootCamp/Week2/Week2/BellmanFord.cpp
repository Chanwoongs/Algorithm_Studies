#include <iostream>
#include <vector>

struct EdgeList
{
	EdgeList(int row, int col) : row(row), col(col)
	{}

	int row;
	int col;
};

using namespace std;
#define SIZE 5
#define INFINITY 100000000

void BellmanFord(int graph[SIZE][SIZE])
{
	int distance[SIZE];
	vector<EdgeList*> edgeList;

	for (int i = 0; i < SIZE; i++)
	{
		distance[i] = INFINITY;
		for (int j = 0; j < SIZE; j++)
		{
			if (graph[i][j] != 0)
			{
				edgeList.push_back(new EdgeList(i, j));
			}
		}
	}

	distance[0] = 0;

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < edgeList.size(); j++)
		{
			if (distance[edgeList[j]->row] + graph[edgeList[j]->row][edgeList[j]->col] < distance[edgeList[j]->col])
			{
				distance[edgeList[j]->col] = distance[edgeList[j]->row] + graph[edgeList[j]->row][edgeList[j]->col];
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << distance[i] << endl;
		delete edgeList.at(i);
	}
}

int main()
{
	int graph[5][5] = {
		{0, -1, 4, 0, 0},
		{0, 0, 3, 2, 2},
		{0, 0, 0, 0, 0},
		{0, 1, 5, 0, 0},
		{0, 0, 0, -3, 0}
	};

	BellmanFord(graph);
	return 0;
}

/*
�������� �˰��򿡼� ���� ����Ŭ���� ������ �� �ִ�.
n - 1 �� ���� �� n ��° ���࿡ ���� ���Ѵٸ� ���� ����Ŭ�� �ִ� �� �̴�.
*/