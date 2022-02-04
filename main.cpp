#include <iostream>
#include "Heap.h"
int main() {
    Heap h = Heap(false);
    h.insert(4);
    h.insert(2);
    h.insert(10);
    h.insert(7);
    h.insert(1);
    h.pop();
    h.insert(3);
    return 0;
}
