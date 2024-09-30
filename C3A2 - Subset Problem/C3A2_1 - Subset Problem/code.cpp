#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Enter the number of elements in the set: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the elements (integers) of the set:\n";
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    int total_subsets = 1 << n; // 2^n subsets

    std::cout << "\nAll subsets are:\n";
    for (int i = 0; i < total_subsets; ++i) {
        std::cout << "{ ";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j))
                std::cout << nums[j] << " ";
        }
        std::cout << "}\n";
    }

    return 0;
}
