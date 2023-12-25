#include <bits/stdc++.h>

using namespace std;

/*********************************** ShortCuts for basic things ***********************************/
/**************************** Variable Shortcuts ****************************/
#define LL long long
#define UL unsigned long
#define ULL unsigned long long
#define LD long double
#define PII pair<int, int>
#define PLLLL pair<LL, LL>
#define VI vector<int>
#define VB vector<bool>
#define VD vector<double>
#define VLL vector<LL>
#define USET unordered_set
#define UMAP unordered_map
/**************************** Inbuilt Function Shortcuts ****************************/
#define LB lower_bound
#define UB upper_bound
/**************************** Common Function Shortcuts ****************************/
#define SIZE(x) ((int)x.size())
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, start, endExc, inc) for (int i = start; i < endExc; i += inc)
#define RFOR(i, start, endInc, dec) for (int i = start; i >= endInc; i -= dec)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FORI(itr, start, end) for (auto itr = start; itr != end; ++itr)
#define REPI(itr, obj) FORI(itr, ALL(obj))
#define FOREACH(it, l) for (auto const &it : l)
#define MFOREACH(it, l) for (auto &it : l)

/*********************************** Main Solution Starts Here ***********************************/
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
  int merge(int a, int b)
  {
    return max(a, b);
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
    stree[sti] = merge(stree[nexti], stree[nexti + 1]);
  }
  int getAnsRangeHelper(int sti, int si, int ei, int rsi, int rei)
  {
    if (rsi > rei)
      return 0;
    if (si == rsi && ei == rei)
      return stree[sti];
    int mid{(si + ei) >> 1}, nexti{sti << 1};
    return merge(getAnsRangeHelper(nexti, si, mid, rsi, min(mid, rei)), getAnsRangeHelper(nexti + 1, mid + 1, ei, max(mid + 1, rsi), rei));
  }
  void updateTreeHelper(int sti, int si, int ei, int sum, int ind)
  {
    if (si > ind || ei < ind)
      return;
    if (si == ei)
    {
      stree[sti] += sum;
      return;
    }
    int mid{(si + ei) >> 1}, nexti{sti << 1};
    updateTreeHelper(nexti + 1, mid + 1, ei, sum, ind);
    updateTreeHelper(nexti, si, mid, sum, ind);
    stree[sti] = merge(stree[nexti], stree[nexti + 1]);
  }

public:
  SegmentTree(vector<int> &arr)
  {
    stree.resize(getSize(arr.size()));
    endInd = arr.size() - 1;
    constructTree(1, 0, endInd, arr);
  }
  int getAnsRange(int rsi, int rei)
  {
    return getAnsRangeHelper(1, 0, endInd, rsi, rei);
  }
  void updateTree(int sum, int ind)
  {
    updateTreeHelper(1, 0, endInd, sum, ind);
  }
};

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, m{};
  cin >> n >> m;
  VI heights(m);
  REP(i, m) { cin >> heights[i]; }
  SegmentTree stree(heights);
  int q{};
  cin >> q;
  int x1{}, y1{}, x2{}, y2{}, k{};
  int miny{}, maxy{};
  REP(i, q)
  {
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    miny = min(y1, y2), maxy = max(y1, y2) - 2;
    if (abs(x2 - x1) % k || abs(y2 - y1) % k)
    {
      cout << "NO\n";
      continue;
    }
    if (miny > maxy || x1 + ((n - x1) / k) * k > stree.getAnsRange(miny, maxy))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int TC{1};
  // cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
