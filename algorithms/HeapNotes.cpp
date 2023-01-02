/* Comparator implementation inside STL */


void push(T element) {
  // Add the element to the end of the heap.
  heap.append(element);

  // Restore the heap property by sifting the element up the heap until
  // it is in the correct position.
  int i = heap.size() - 1;
  while (i > 0 && comparator(heap[i], heap[parent(i)])) {
    swap(heap[i], heap[parent(i)]);
    i = parent(i);
  }
}

void pop() {
  // Remove the element at the front of the heap (the one with the highest
  // priority).
  heap[0] = heap.back();
  heap.pop_back();

  // Restore the heap property by sifting the element down the heap until
  // it is in the correct position.
  int i = 0;
  while (true) {
    int left = left_child(i);
    int right = right_child(i);
    int smallest = i;
    if (left < heap.size() && comparator(heap[left], heap[smallest])) {
      smallest = left;
    }
    if (right < heap.size() && comparator(heap[right], heap[smallest])) {
      smallest = right;
    }
    if (smallest != i) {
      swap(heap[i], heap[smallest]);
      i = smallest;
    } else {
      break;
    }
  }
}
