#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i{0}; i < n; ++i)
      cin >> arr[i];
    if (n == 2)
    {
      if (arr[0] == 1)
      {
        if (arr[1] == 1)
          cout << 0 << '\n';
        else
          cout << 1 << '\n';
      }
      else if (arr[1] == 1)
        cout << 1 << '\n';
      else
        cout << 2 << '\n';
      continue;
    }
    int maxc{0}, temp{};
    unordered_map<int, int> umap;
    for (int i{0}; i < n; ++i)
    {
      temp = arr[i];
      if (!(arr[i] & 1))
      {
        ++umap[2];
        maxc = max(maxc, umap[2]);
        while (!(arr[i] & 1))
          arr[i] >>= 1;
      }
      if (arr[i] % 3 == 0)
      {
        ++umap[3];
        maxc = max(maxc, umap[3]);
        while (arr[i] % 3 == 0)
          arr[i] /= 3;
      }
      for (int j{5}; j * j <= arr[i]; j += 6)
      {
        int k{j + 2};
        if (arr[i] % j == 0)
        {
          ++umap[j];
          maxc = max(maxc, umap[j]);
          while (arr[i] % j == 0)
            arr[i] /= j;
        }
        if (arr[i] % k == 0)
        {
          ++umap[k];
          maxc = max(maxc, umap[k]);
          while (arr[i] % k == 0)
            arr[i] /= k;
        }
      }
      if (arr[i] != 1)
      {
        ++umap[arr[i]];
        maxc = max(maxc, umap[arr[i]]);
      }
      arr[i] = temp;
      if (maxc < i)
        break;
    }
    if (maxc == arr.size())
      cout << arr.size() << '\n';
    else if (maxc == arr.size() - 1)
    {
      long long int mult{1};
      int cnt{0};
      for (auto i : umap)
        if (i.second == maxc)
          mult *= i.first;
      for (int itr : arr)
      {
        if (itr % mult != 0)
          ++cnt;
      }
      cout << cnt << '\n';
    }
    else
      cout << 0 << '\n';
  }
  return 0;
}
