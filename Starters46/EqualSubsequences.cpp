#include <iostream>
#include <vector>

using namespace std;

const int mod{998244353};

// class SegmentTree
// {
//   vector<int> stree;
//   int endInd;

//   int getSize(int n)
//   {
//     if (n & (n - 1))
//     {
//       n |= n >> 1;
//       n |= n >> 2;
//       n |= n >> 4;
//       n |= n >> 8;
//       n |= n >> 16;
//       n += 1;
//     }
//     return n << 1;
//   }

// public:
//   SegmentTree(int n)
//   {
//     stree.resize(getSize(n));
//     endInd = n - 1;
//   }
// };

class FenwickTree
{
  vector<int> ftree;

  int getSum(int ind, long long sum)
  {
    return (sum + ftree[ind]) % mod;
  }

public:
  FenwickTree(int n)
  {
    ftree.resize(n);
  }
  void updateTree(int ind, long long sum)
  {
    sum = (sum + mod) % mod;
    ftree[ind] = getSum(ind, sum);
    while ((ind = ind | (ind + 1)) < ftree.size())
      ftree[ind] = getSum(ind, sum);
  }
  int getSum(int ind)
  {
    long long sum{ftree[ind]};
    while ((ind = (ind & (ind + 1)) - 1) >= 0)
      sum = getSum(ind, sum);
    return sum;
  }
};

void inputOutput()
{
  int n{};
  cin >> n;
  int n2{n << 1};
  vector<int> arr(n2), dp(n2);
  vector<vector<int>> ind(n + 1);
  FenwickTree ftree(n2);
  for (int i{0}; i < n2; ++i)
  {
    cin >> arr[i];
    ind[arr[i]].push_back(i);
  }
  long long temp{};
  for (int i{1}; i < n2; ++i)
  {
    if (i == ind[arr[i]][0])
    {
      dp[i] = dp[i - 1];
      continue;
    }
    temp = ((long long)dp[ind[arr[i]][0]] * 2 + ftree.getSum(ind[arr[i]][0]) + 1) % mod;
    dp[i] = (temp + dp[i - 1]) % mod;
    ftree.updateTree(ind[arr[i]][0], temp);
    ftree.updateTree(ind[arr[i]][1], -temp);
  }
  cout << ((long long)dp.back() * 2) % mod << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t{};
  cin >> t;
  while (t--)
    inputOutput();
}
