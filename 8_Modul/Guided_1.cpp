#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int heapsize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftchild(int i) {
    return ((2 * i) + 1);
}

int rightchild(int i) {
    return ((2 * i) + 2);
}

void shiftup(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftdown(int i) {
    int maxindex = i;
    int l = leftchild(i);
    if (l <= heapsize && H[l] > H[maxindex]) {
        maxindex = l;
    }
    int r = rightchild(i);
    if (r <= heapsize && H[r] > H[maxindex]) {
        maxindex = r;
    }
    if (i != maxindex) {
        swap(H[i], H[maxindex]);
        shiftdown(maxindex);
    }
}

void insert(int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftup(heapsize);
}

int extractmax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftdown(0);
    return result;
}

void changepriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftup(i);
    } else {
        shiftdown(i);
    }
}

int getmax() {
    return H[0];
}

void remove(int i) {
    H[i] = getmax() + 1;
    shiftup(i);
    extractmax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    cout << "Priority Queue: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority: " << extractmax() << "\n"; 
    cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    changepriority(2, 49);
    cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    remove(3);
    cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    return 0;
}