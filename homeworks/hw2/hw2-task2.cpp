#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define NAME_LENGTH 10
using namespace std;

struct Pair {
    char name[NAME_LENGTH];
    size_t points;

    bool operator<(const Pair& other) const {
        return points < other.points || (points == other.points && strcmp(name, other.name) > 0);
    }
};

ostream& operator<<(ostream& out, const Pair& obj) {
    out << obj.name << " " << obj.points;
    return out;
}

void merge(Pair arr[], int start, int middle, int end){
    int firstSize = middle - start + 1;
    Pair* first = new Pair[firstSize];
    for (int i = 0; i < firstSize; ++i) {
        first[i] = arr[start + i];
    }

    int secondSize = end - middle;
    Pair* second = new Pair[secondSize];
    for (int i = 0; i < secondSize; ++i) {
        second[i] = arr[middle + i + 1];
    }

    int firstCounter = 0;
    int secondCounter = 0;
    for (int i = start; i <= end; ++i) {
        if(first[firstCounter] < second[secondCounter] && secondCounter < secondSize) {
            arr[i] = second[secondCounter];
            ++secondCounter;
        }
        else if(firstCounter < firstSize) {
            arr[i] = first[firstCounter];
            ++firstCounter;
        }
    }

    delete[] first;
    delete[] second;
}

void mergeSort(Pair arr[], int left, int right) {
    if (left < right)
    {
        int middle = (left + right)/2;
        mergeSort(arr, left, middle);
        mergeSort(arr , middle+1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
    size_t count;
    cin >> count;

    Pair* students = new Pair[count];

    for (size_t i = 0; i < count; ++i) {
        cin >> students[i].name;
    }

    for (size_t i = 0; i < count; ++i) {
        cin >> students[i].points;
    }

    mergeSort(students, 0, count - 1);

    for (size_t i = 0; i < count; ++i) {
        cout << students[i] << endl;
    }
    
    delete[] students;

    return 0;
}