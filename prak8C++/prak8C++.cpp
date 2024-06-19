#include <iostream>
#include <thread>
#include <vector>

class MergeSort {
public:
    void Sort(std::vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }

        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());

        Sort(left);
        Sort(right);
        Merge(arr, left, right);
    }

private:
    void Merge(std::vector<int>& result, const std::vector<int>& left, const std::vector<int>& right) {
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                result[k++] = left[i++];
            }
            else {
                result[k++] = right[j++];
            }
        }
        while (i < left.size()) {
            result[k++] = left[i++];
        }
        while (j < right.size()) {
            result[k++] = right[j++];
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr(10);
    std::cout << "Введите 10 целых чисел для заполнения массива: ";
    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }

    MergeSort mergeSort;
    auto sortFunc = [&mergeSort, &arr]() { mergeSort.Sort(arr); };
    std::thread mergeSortThread(sortFunc);

    mergeSortThread.join();

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
