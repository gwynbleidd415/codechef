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

/**************************** For Debugging ****************************/
void __PRINT(int x) { cerr << x; }
void __PRINT(long x) { cerr << x; }
void __PRINT(LL x) { cerr << x; }
void __PRINT(unsigned x) { cerr << x; }
void __PRINT(UL x) { cerr << x; }
void __PRINT(ULL x) { cerr << x; }
void __PRINT(float x) { cerr << x; }
void __PRINT(double x) { cerr << x; }
void __PRINT(LD x) { cerr << x; }
void __PRINT(char x) { cerr << '\'' << x << '\''; }
void __PRINT(const char *x) { cerr << '\"' << x << '\"'; }
void __PRINT(const string &x) { cerr << '\"' << x << '\"'; }
void __PRINT(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __PRINT(const pair<T, V> &x)
{
  cerr << '{';
  __PRINT(x.first);
  cerr << ',';
  __PRINT(x.second);
  cerr << '}';
}
template <typename T>
void __PRINT(const T &x)
{
  int f = 0;
  cerr << '{';
  for (auto const &i : x)
    cerr << (f++ ? "," : ""), __PRINT(i);
  cerr << "}";
}
void _PRINT() { cerr << "]\n"; }
template <typename T, typename... V>
void _PRINT(T t, V... v)
{
  __PRINT(t);
  if (sizeof...(v))
    cerr << ", ";
  _PRINT(v...);
}
#ifndef ONLINE_JUDGE
#define DEBUG(x...)             \
  cerr << "[" << #x << "] = ["; \
  _PRINT(x)
#else
#define DEBUG(x...)
#endif

/*********************************** Main Solution Starts Here ***********************************/
struct beauty
{
  int total{}, left{}, right{}, maxx{};
  beauty() : total{0}, left{0}, right{0}, maxx{0} {};
  beauty(int maxx, int total, int left, int right) : total{total}, left{left}, right{right}, maxx{maxx} {};
};

class SegmentTree
{
  struct node
  {
    int total{}, left{}, right{}, maxx{}, sleft{}, sright{};
    node() : total{0}, left{0}, right{0}, maxx{0}, sleft{0}, sright{0} {}
    node(int maxx, int total, int left, int right, int sleft, int sright) : total{total}, left{left}, right{right}, maxx{maxx}, sleft{sleft}, sright{sright} {}
  };
  vector<node> stree;
  vector<beauty> const &happy;
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

  void setLeftHelper(node &s1, node &s2, node &s3)
  {
    s3.left = s1.left;
    if (s1.sleft != 0 && happy[s1.sleft].left > happy[s2.left].left)
      s3.sleft = s1.sleft;
    else
      s3.sleft = s2.left;
  }
  void setRightHelper(node &s1, node &s2, node &s3)
  {
    s3.right = s1.right;
    if (s1.sright != 0 && happy[s1.sright].right > happy[s2.right].right)
      s3.sright = s1.sright;
    else
      s3.sright = s2.right;
  }

  node merge(node &s1, node &s2)
  {
    node s3;

    s3.total = s1.total + s2.total;
    s3.maxx = max(s1.maxx, s2.maxx);

    if (happy[s1.left].left > happy[s2.left].left)
      setLeftHelper(s1, s2, s3);
    else
      setLeftHelper(s2, s1, s3);
    if (happy[s1.right].right > happy[s2.right].right)
      setRightHelper(s1, s2, s3);
    else
      setRightHelper(s2, s1, s3);

    int ileft{s3.left}, iright{s3.right};
    if (ileft == iright)
    {
      if (happy[ileft].left + happy[s3.sright].right > happy[iright].right + happy[s3.sleft].left)
        iright = s3.sright;
      else
        ileft = s3.sleft;
    }
    s3.maxx = max(s3.maxx, happy[ileft].left + happy[iright].right + s3.total);

    return s3;
  }

  void constructTree(int sti, int si, int ei)
  {
    if (si == ei)
    {
      stree[sti] = node(happy[si].maxx, happy[si].total, si, si, 0, 0);
      return;
    }
    int mid{(si + ei) >> 1}, nexti{sti << 1};
    constructTree(nexti, si, mid);
    constructTree(nexti + 1, mid + 1, ei);
    stree[sti] = merge(stree[nexti], stree[nexti + 1]);
  }
  node getMaxRangeHelper(int sti, int si, int ei, int rsi, int rei)
  {
    if (si == rsi && ei == rei)
      return stree[sti];
    int mid{(si + ei) >> 1}, nexti{sti << 1};
    if (rsi > min(mid, rei))
      return getMaxRangeHelper(nexti + 1, mid + 1, ei, max(mid + 1, rsi), rei);
    if (max(mid + 1, rsi) > rei)
      return getMaxRangeHelper(nexti, si, mid, rsi, min(mid, rei));
    node left = getMaxRangeHelper(nexti, si, mid, rsi, min(mid, rei));
    node right = getMaxRangeHelper(nexti + 1, mid + 1, ei, max(mid + 1, rsi), rei);
    return merge(left, right);
  }

public:
  SegmentTree(vector<beauty> &arr) : happy{arr}
  {
    stree.resize(getSize(arr.size()));
    endInd = arr.size() - 1;
    constructTree(1, 1, endInd);
  }
  int getMaxRange(int rsi, int rei)
  {
    return getMaxRangeHelper(1, 1, endInd, rsi, rei).maxx;
  }
};

beauty calculateHappiness(int n, string &str)
{
  int maxLeft{0}, total{0}, maximum{0}, maxRight{0};
  int rtot{0}, maxcnt{0};
  REP(i, n)
  {
    if (str[i] == '1')
    {
      ++total, ++maxcnt;
      maximum = max(maximum, maxcnt);
      maxLeft = max(maxLeft, total);
    }
    else
    {
      --total;
      if (maxcnt > 0)
        --maxcnt;
    }
  }
  RREP(i, n - 1)
  {
    if (str[i] == '1')
    {
      ++rtot;
      maxRight = max(maxRight, rtot);
    }
    else
      --rtot;
  }
  if (total < 0)
    total = 0;
  return beauty(maximum, total, maxLeft - total, maxRight - total);
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, q{};
  cin >> n >> q;
  vector<beauty> happy(++n);
  happy[0] = beauty();
  int tmp{};
  string tmpstr{};
  FOR(i, 1, n, 1)
  {
    cin >> tmp >> tmpstr;
    happy[i] = calculateHappiness(tmp, tmpstr);
  }
  // DEBUG(happy);
  SegmentTree stree(happy);
  int t1{}, t2{};
  REP(i, q)
  {
    cin >> t1 >> t2;
    cout << stree.getMaxRange(t1, t2) << '\n';
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
