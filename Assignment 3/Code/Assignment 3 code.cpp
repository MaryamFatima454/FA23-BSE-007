#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index != 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void printHeap() {
        cout << "Heap: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        printHeap();
    }

    void deleteRoot() {
        if (heap.empty()) return;

        cout << "Deleting root: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        printHeap();
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
};

int main() {
    MaxHeap h;
    vector<int> values = {50, 10, 30, 20, 60, 70};

    cout << "Inserting into Max Heap:\n";
    for (int val : values) {
        cout << "Inserting: " << val << endl;
        h.insert(val);
    }

    cout << "\nDeleting two nodes from Max Heap:\n";
    h.deleteRoot(); // First deletion
    h.deleteRoot(); // Second deletion

    return 0;
}
