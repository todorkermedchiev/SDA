#include <iostream>

template <typename T>
void swap(T& first, T& second) {
    T tmp = first;
    first = second;
    second = tmp;
}

template <typename T>
void bubbleSortI(T* arr, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    // for (size_t i = 0; i < size; ++i) {
    //     for (size_t j = i + 1; j < size; ++j) {
    //         if (arr[i] > arr[j]) {
    //             swap(arr[i], arr[j]);
    //         }
    //     }
    // }
}

template <typename T>
void selectionSortI(T* arr, size_t size) {
    size_t minIndex = 0;
    for (size_t i = 0; i < size; ++i) {
        minIndex = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

template <typename T>
void selectionSortD(T* arr, size_t size) {
    size_t maxIndex = 0;
    for (size_t i = 0; i < size; ++i) {
        maxIndex = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (arr[maxIndex] < arr[j]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

template <typename T>
void insertionSortI(T* arr, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        T tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = tmp;
    }
}

template <typename T>
void insertionSortD(T* arr, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        T tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < tmp) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = tmp;
    }
}

template <typename T>
void mergeI(T* arr, size_t start, size_t middle, size_t end) {
    size_t firstSize = middle - start + 1;
    T* first = new T[firstSize];
    for (int i = 0; i < firstSize; ++i) {
        first[i] = arr[start + i];
    }

    size_t secondSize = end - middle;
    T* second = new T[secondSize];
    for (int i = 0; i < secondSize; ++i) {
        second[i] = arr[middle + i + 1];
    }


    size_t firstCounter = 0;
    size_t secondCounter = 0;
    for (int i = start; i <= end; ++i) {
        if (firstCounter >= firstSize && secondCounter < secondSize) {
            arr[i] = second[secondCounter++];
            continue;
        }
        if (secondCounter >= secondSize && firstCounter < firstSize) {
            arr[i] = first[firstCounter++];
            continue;
        }
        if (first[firstCounter] < second[secondCounter]) {
            arr[i] = first[firstCounter++];
        }
        else {
            arr[i] = second[secondCounter++];
        }
    }
}

template <typename T>
void mergeSortI(T* arr, size_t start, size_t end) {
    if (start >= end) {
        return;
    }
    size_t middle = (start + end) / 2;
    mergeSortI(arr, start, middle);
    mergeSortI(arr, middle + 1, end);
    mergeI(arr, start, middle, end);
}

template <typename T>
void mergeD(T* arr, size_t start, size_t middle, size_t end) {
    size_t firstSize = middle - start + 1;
    T* first = new T[firstSize];
    for (int i = 0; i < firstSize; ++i) {
        first[i] = arr[start + i];
    }

    size_t secondSize = end - middle;
    T* second = new T[secondSize];
    for (int i = 0; i < secondSize; ++i) {
        second[i] = arr[middle + i + 1];
    }


    size_t firstCounter = 0;
    size_t secondCounter = 0;
    for (int i = start; i <= end; ++i) {
        if (firstCounter >= firstSize && secondCounter < secondSize) {
            arr[i] = second[secondCounter++];
            continue;
        }
        if (secondCounter >= secondSize && firstCounter < firstSize) {
            arr[i] = first[firstCounter++];
            continue;
        }
        if (first[firstCounter] > second[secondCounter]) {
            arr[i] = first[firstCounter++];
        }
        else {
            arr[i] = second[secondCounter++];
        }
    }
}

template <typename T>
void mergeSortD(T* arr, size_t start, size_t end) {
    if (start >= end) {
        return;
    }
    size_t middle = (start + end) / 2;
    mergeSortD(arr, start, middle);
    mergeSortD(arr, middle + 1, end);
    mergeD(arr, start, middle, end);
}

template <typename T>
int partition(T* arr, int left, int right) {
    T pivot = arr[right];
    int index = left;

    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[index], arr[j]);
            ++index;
        }
    }

    swap (arr[index], arr[right]);
    return index;
}

template <typename T>
void quickSort(T* arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int partitionIndex = partition(arr, left, right);

    quickSort(arr, left, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, right);
}

void countingSort(int* arr, int size) {
    int maxElement = arr[0];
    int minElement = arr[0];

    int* old = new int[size];

    for (int i = 0; i < size; ++i) {
        old[i] = arr[i];
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    int diffElementsCount = maxElement - minElement + 1;
    int* count = new int[diffElementsCount]{};

    for (int i = 0; i < size; ++i) {
        ++count[arr[i] - minElement];
    }

    for (int i = 1; i < diffElementsCount; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
        arr[count[old[i] - minElement] - 1] = old[i];
        --count[old[i] - minElement];
    }

    delete[] old;
    delete[] count;
}

int main() {
    int arr[10] = {2, 4, -5, 0, 5, 1, 7, 3, -9, 8};
    countingSort(arr, 10);
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << ' ';
    }
    // int arr[10] = {4, 3, 2, 1, 0, 9, 8, 7, 6, 5};
    // mergeD<int>(arr, 0, 4, 9);
    // for (int i = 0; i < 10; ++i) {
    //     std::cout << arr[i] << ' ';
    // }


    return 0;
}