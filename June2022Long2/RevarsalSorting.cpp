#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i{0}; i < n; ++i)
      cin >> arr[i];
    bool isPossible{true};
    set<int, greater<int>> arset;
    set<int, greater<int>>::iterator itr;
    arset.insert(arr.back());
    for (int i{(int)arr.size() - 2}; i >= 0; --i)
    {
      itr = arset.upper_bound(arr[i]);
      if (itr != arset.end() && *itr + arr[i] > x)
      {
        isPossible = false;
        break;
      }
      arset.insert(arr[i]);
    }
    if (isPossible)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}