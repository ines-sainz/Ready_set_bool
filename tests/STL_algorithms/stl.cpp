#include <vector>
#include <algorithm>
#include <iostream>

//with lambda
int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    std::for_each(nums.begin(), nums.end(), [](int n) {
        std::cout << n * n << " ";
    });
}



//without lambda
void printSquare(int n) {
    std::cout << n * n << " ";
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    std::for_each(nums.begin(), nums.end(), printSquare);
}
