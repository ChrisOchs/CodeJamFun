#include <algorithm>
#include <iostream>
#include <vector>

int minimumScalarProduct(std::vector<int>& a, std::vector<int>& b);

int main() {

    std::vector<int> a;

    a.push_back(1);
    a.push_back(3);
    a.push_back(-5);

    std::vector<int> b;

    b.push_back(-2);
    b.push_back(4);
    b.push_back(1);

    std::cout<<minimumScalarProduct(a, b)<<std::endl;

    return 0;
}

// Need to use some type of big int to prevent overflow...
int minimumScalarProduct(std::vector<int>& a, std::vector<int>& b) {

    // Assuming a and b are same size...
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int result = 0;

    size_t n = a.size();

    for(int c = 0; c < n; c++) {
        result += a[c] * b[n - c - 1];
    }

    return result;
}
