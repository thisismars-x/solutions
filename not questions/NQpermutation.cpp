#include <iostream>
#include <vector>

void printPermutation(std::vector<int>& vec, int start, int end) {
    if (start == end) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        for (int i = start; i <= end; ++i) {
            std::swap(vec[start], vec[i]); 
            printPermutation(vec, start + 1, end); 
            std::swap(vec[start], vec[i]); 
        }
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    printPermutation(vec, 0, vec.size() - 1);
    return 0;
}
