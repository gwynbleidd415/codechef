#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print(vector<vector<int>> &arr, int n, int m)
{
  for (int i{0}; i < n; ++i)
  {
    for (int j{0}; j < m; ++j)
      cout << arr[i][j] << ' ';
    cout << '\n';
  }
}

void printTrav(vector<vector<int>> &arr, int n, int m)
{
  for (int i{0}; i < m; ++i)
  {
    for (int j{0}; j < n; ++j)
      cout << arr[j][i] << ' ';
    cout << '\n';
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    bool trav{false};
    int n, m;
    cin >> n >> m;
    if (n > m)
    {
      swap(n, m);
      trav = true;
    }
    vector<vector<int>> arr(n, vector<int>(m));
    if (n == m)
    {
      arr[0][0] = 1;
      for (int i{1}; i < n; ++i)
        arr[i][0] = arr[i - 1][0] + 2;
      for (int i{0}; i < n; ++i)
        for (int j{1}; j < m; ++j)
          arr[i][j] = arr[i][j - 1] + arr[i][0];
      print(arr, n, m);
      continue;
    }
    iota(arr[0].begin(), arr[0].end(), 1);
    int add(n + m);
    for (int j{m - 1}; j >= 0; --j)
    {
      for (int i{1}; i < n; ++i)
        arr[i][j] = arr[i - 1][j] + add;
      --add;
    }
    if (trav)
      printTrav(arr, n, m);
    else
      print(arr, n, m);
  }
  return 0;
}
