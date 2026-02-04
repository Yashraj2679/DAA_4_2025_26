#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int heap[MAX];
int heapSize = 0;
int K = 3;

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void insertScore(int val) {
    if (heapSize < K) {
        heap[heapSize] = val;
        heapSize++;
        heapifyUp(heapSize - 1);
    }
    else if (val > heap[0]) {
        heap[0] = val;
        heapifyDown(0);
    }
}

int main() {
    int scores[] = {10, 20, 5, 15, 25, 8};
    int n = 6;

    for (int i = 0; i < n; i++) {
        insertScore(scores[i]);
        if (heapSize < K)
            cout << -1 << endl;
        else
            cout << heap[0] << endl;
    }

    return 0;
}
