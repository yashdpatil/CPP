// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
void landRQuerbased()
{
    // 🔥 Extra(Prefix Sum – O(1) range query)

    //  If you are doing many range sums :
    vector<int> v = {5, 5, 1, 1, 8}; // firstly added zero
    int l = 1;
    int r = 5;
    vector<int> pref(v.size(), 0);
    for (int i = 1; i < v.size(); i++)
    {
        pref[i] = pref[i - 1] + v[i];
    }

    int sumLR = pref[r] - pref[l - 1];
}
int main()
{
    // Write C++ code here
    std::cout << "Try programiz.pro";
    vector<int> v = {5, 5, 1, 1, 8}; //  sum =16   8
    int ans = 0;
    int sum = 0;
    //   int prefix_sum = v[0]+v[1];
    //     for (int i = 0; i < v.size(); i++)
    //     {
    //       ans += v[i];
    //     }
    //      cout << ans << endl;

    //      int last_pref = (ans - prefix_sum) - prefix_sum;
    //      if( last_pref == 0){
    //          cout<<"yes";
    //      }else{
    //           cout<<"NO";
    //      }

    // gpt approched
    int total = 0;
    for (int x : v)
        total += x;
    cout << total;

    int prefix = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        prefix += v[i];
        cout << prefix << endl;
        if (prefix == total - prefix)
        {
            cout << "yes";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}