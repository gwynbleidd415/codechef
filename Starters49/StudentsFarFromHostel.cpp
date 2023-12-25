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

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, m{};
  cin >> n >> m;
  vector<VI> A(n, VI(m)), B(n, VI(m));
  REP(i, n)
  {
    REP(j, m) { cin >> A[i][j]; }
  }
  REP(i, n)
  {
    REP(j, m) { cin >> B[i][j]; }
  }
  vector<vector<LL>> dpA(n, vector<LL>(m)), dpB(n, vector<LL>(m)), dpM(n, vector<LL>(m));
  REP(i, n)
  {
    dpA[i][0] = A[i][0];
    FOR(j, 1, m, 1) { dpA[i][j] = dpA[i][j - 1] + A[i][j]; }
  }
  REP(j, m)
  {
    dpB[0][j] = B[0][j];
    FOR(i, 1, n, 1) { dpB[i][j] = dpB[i - 1][j] + B[i][j]; }
  }
  dpM[0][0] = max(dpA[0][0], dpB[0][0]);
  FOR(i, 1, n, 1) { dpM[i][0] = max(dpA[i][0] + dpM[i - 1][0], dpB[i][0]); }
  FOR(j, 1, m, 1) { dpM[0][j] = max(dpA[0][j], dpB[0][j] + dpM[0][j - 1]); }
  FOR(i, 1, n, 1)
  {
    FOR(j, 1, m, 1) { dpM[i][j] = max(dpA[i][j] + dpM[i - 1][j], dpB[i][j] + dpM[i][j - 1]); }
  }
  cout << dpM.back().back() << '\n';
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
