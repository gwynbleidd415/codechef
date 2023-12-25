#include <iostream>
#include <vector>
#include <set>

using namespace std;

int getGCD(int a, int b)
{
  if (b > a)
    swap(a, b);
  int c{};
  while (b)
  {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}

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
    stree[sti] = getGCD(stree[nexti], stree[nexti + 1]);
  }
  int getGCDRangeHelper(int sti, int si, int ei, int rsi, int rei)
  {
    if (rsi > rei)
      return 0;
    if (si == rsi && ei == rei)
      return stree[sti];
    int mid{(si + ei) >> 1}, nexti{sti << 1};
    return getGCD(getGCDRangeHelper(nexti, si, mid, rsi, min(mid, rei)), getGCDRangeHelper(nexti + 1, mid + 1, ei, max(mid + 1, rsi), rei));
  }

public:
  SegmentTree(vector<int> arr)
  {
    stree.resize(getSize(arr.size()));
    endInd = arr.size() - 1;
    constructTree(1, 0, endInd, arr);
  }
  int getGCDRange(int rsi, int rei)
  {
    return getGCDRangeHelper(1, 0, endInd, rsi, rei);
  }
};

void inputOutput()
{
  int n{}, k{};
  cin >> n >> k;
  vector<int> arr(n);
  for (int i{0}; i < n; ++i)
    cin >> arr[i];
  SegmentTree stree(arr);
  set<pair<int, int>, greater<pair<int, int>>> st;
  set<pair<int, int>, greater<pair<int, int>>>::iterator itr1, itr2;
  st.insert({arr[0], 0});
  st.insert({arr[1], 1});
  int l{0}, r{1}, gcdDiff{}, ans{INT32_MAX};
  while (r < n)
  {
    itr1 = st.begin(), itr2 = ++st.begin();
    gcdDiff = itr1->first - getGCD(stree.getGCDRange(l, itr1->second - 1), stree.getGCDRange(itr1->second + 1, r));
    if (itr2->first != itr1->first)
      gcdDiff = max(gcdDiff, itr2->first - getGCD(stree.getGCDRange(l, itr2->second - 1), stree.getGCDRange(itr2->second + 1, r)));
    if (gcdDiff < k)
    {
      ++r;
      if (r < n)
        st.insert({arr[r], r});
    }
    else
    {
      ans = min(ans, r - l + 1);
      st.erase({arr[l], l});
      ++l;
      if (l == r)
      {
        ++r;
        if (r < n)
          st.insert({arr[r], r});
      }
    }
  }
  if (ans == INT32_MAX)
    ans = -1;
  cout << ans << '\n';
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
