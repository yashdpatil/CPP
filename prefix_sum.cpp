// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Write C++ code here
    std::cout << "Try programiz.pro";
    vector<int> v = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < v.size(); i++)
    {
        v[i] += v[i - 1];
    }
    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}