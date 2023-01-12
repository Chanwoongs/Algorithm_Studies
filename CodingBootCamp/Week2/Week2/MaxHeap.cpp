// 참고한 사이트
// https://kbw1101.tistory.com/51

#include <iostream>

using namespace std;

#define SIZE 100

typedef struct {
	int key;
} element;

typedef struct {
	element heap[SIZE];
	int heapSize;
} Heap;

void heapPush(Heap* h, element item)
{
	// 트리 가장 마지막 노드의 인덱스
	int index = h->heapSize++;

	// Root가 아니고 부모의 값보다 크다면
	while ((index != 0) && (h->heap[index / 2].key < item.key))
	{
		// 부모와 Swap
		h->heap[index] = h->heap[index / 2];
		index /= 2;
	}

	h->heap[index] = item;
}

void percolateDown(Heap* h, int index)
{
	auto child = 2 * index + 1;
	auto right = 2 * index + 2;

	if (child <= h->heapSize - 1)
	{
		if (right <= h->heapSize - 1 && h->heap[child].key < h->heap[right].key)
		{
			child = right;
		}
		if (h->heap[index].key < h->heap[child].key)
		{
			int temp = h->heap[index].key;
			h->heap[index].key = h->heap[child].key;
			h->heap[child].key = temp;

			percolateDown(h, child);
		}
	}
}

element heapPop(Heap* h)
{
	element max = h->heap[0];
	h->heap[0] = h->heap[h->heapSize];
	h->heapSize--;

	percolateDown(h, 0);

	return max;
}

int main()
{
	Heap h;
	h.heapSize = 0;

	srand(time(NULL));
	for (int i = 0; i < 7; i++)
	{
		element e = { rand() % 100 + 1 };
		heapPush(&h, e);
	}

	for (int i = 0; i < 7; i++)
		cout << heapPop(&h).key << " ";
	cout << '\n';

	return 0;
}