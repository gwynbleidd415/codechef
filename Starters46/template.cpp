#include <iostream>
#include <vector>

using namespace std;

class DisjointSet
{
  vector<int> par, size;

public:
  DisjointSet(int n)
  {
    par.resize(n), size.resize(n);
    for (int i{0}; i < n; ++i)
      par[i] = i;
  }
  int find(int i)
  {
    if (par[i] == i)
      return i;
    return par[i] = find(par[i]);
  }
  void unite(int a, int b)
  {
    a = find(a), b = find(b);
    if (a == b)
      return;
    if (size[a] < size[b])
      swap(a, b);
    par[b] = a;
    size[a] += size[b];
  }
};

class FenwickTree
{
  vector<int> ftree;

  void constructTree()
  {
    int temp{};
    for (int i{0}; i < ftree.size(); ++i)
    {
      temp = i | (i + 1);
      if (temp < ftree.size())
        ftree[temp] += ftree[i];
    }
  }

public:
  FenwickTree(vector<int> &arr)
  {
    ftree = arr;
    constructTree();
  }
  void updateTree(int ind, long long sum)
  {
    ftree[ind] += sum;
    while ((ind = ind | (ind + 1)) < ftree.size())
      ftree[ind] += sum;
  }
  int getSum(int ind)
  {
    long long sum{ftree[ind]};
    while ((ind = (ind & (ind + 1)) - 1) >= 0)
      sum += ftree[ind];
    return sum;
  }
};

class SegmentTree
{
  vector<int> stree;
  int endInd;

  int getSize(int n)
  {
    if (n & (n - 1))
    {
      n |= n >> 1;
      n |= n >> 2;
      n |= n >> 4;
      n |= n >> 8;
      n |= n >> 16;
      n += 1;
    }
    return n << 1;
  }
  void constructTree(int sti, int si, int ei, vector<int> &arr)
  {
    if (si == ei)
    {
      stree[sti] = arr[si];
      return;
    }
    int mid{(si + ei) >> 1}, nexti{sti << 1};
    constructTree(nexti, si, mid, arr);
    constructTree(nexti + 1, mid + 1, ei, arr);
    stree[sti] = stree[nexti] + stree[nexti + 1];
  }
  int getSumRangeHelper(int sti, int si, int ei, int rsi, int rei)
  {
    if (rsi > rei)
      return 0;
    if (si == rsi && ei == rei)
      return stree[sti];
    int mid{(si + ei) >> 1}, nexti{sti << 1};
    return getSumRangeHelper(nexti, si, mid, rsi, min(mid, rei)) + getSumRangeHelper(nexti + 1, mid + 1, ei, max(mid + 1, rsi), rei);
  }
  void updateTreeHelper(int sti, int si, int ei, int sum, int ind)
  {
    if (si == ei)
    {
      stree[sti] += sum;
      return;
    }
    int mid{(si + ei) >> 1}, nexti{sti << 1};
    if (mid < ind)
      updateTreeHelper(nexti + 1, mid + 1, ei, sum, ind);
    else
      updateTreeHelper(nexti, si, mid, sum, ind);
    stree[sti] += sum;
  }

public:
  SegmentTree(vector<int> &arr)
  {
    stree.resize(getSize(arr.size()));
    endInd = arr.size() - 1;
    constructTree(1, 0, endInd, arr);
  }
  int getSumRange(int rsi, int rei)
  {
    return getSumRangeHelper(1, 0, endInd, rsi, rei);
  }
  void updateTree(int sum, int ind)
  {
    updateTreeHelper(1, 0, endInd, sum, ind);
  }
};

void inputOutput()
{
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);

  int t{};
  cin >> t;
  while (t--)
    inputOutput();
  return 0;
}
