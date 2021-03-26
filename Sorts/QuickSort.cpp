#include <algorithm>
#include <iostream>
#include <chrono>

int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

bool checkOrder(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[i-1])
            return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    int vals[] = {1,2,3,4,5,6,7,8,10,10,11,12,13,14,15,16,17,18,19,20};
    int length = 20;
    size_t repetitionTimes = 1000000;
    std::cout << "Array length: " << length << std::endl;
    std::cout << "Repetition count: " << repetitionTimes << std::endl;

    auto timeStart = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < repetitionTimes; i++) {
        std::random_shuffle(vals, vals+length);
        quickSort(vals, 0, length-1);
    }
    auto timeEnd = std::chrono::high_resolution_clock::now();
    std::cout << "My quicksort time: " << std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count() << std::endl;

    timeStart = std::chrono::high_resolution_clock::now();
    std::random_shuffle(vals, vals+length);
    for (size_t i = 0; i < repetitionTimes; i++) {
        std::random_shuffle(vals, vals+length);
        std::sort(vals, vals+length);
    }
    timeEnd = std::chrono::high_resolution_clock::now();
    std::cout << "The 'std::sort' time: " << std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count() << std::endl;

    return 0;
}
