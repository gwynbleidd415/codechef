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
PLLLL dfs(int src, int par, vector<VI> &adj, vector<VI> &arr)
{
  int sz{SIZE(adj[src]) >> 1}, median{SIZE(adj[src]) & 1 ? arr[adj[src][sz]][1] : (arr[adj[src][sz]][1] + arr[adj[src][sz - 1]][1]) >> 1};
  int nval{(arr[src][0] <= median && arr[src][2] >= median) ? median : (arr[src][0] > median ? arr[src][0] : arr[src][2])};
  // DEBUG(src, par, sz, median, nval);
  PLLLL summ{make_pair(0, 0)}, temp{};
  FOREACH(itr, adj[src])
  {
    if (itr != par)
    {
      temp = dfs(itr, src, adj, arr);
      summ = {summ.first + min(temp.first + llabs(arr[src][1] - arr[itr][1]), temp.second), summ.second + temp.first};
    }
    summ.second += llabs(nval - arr[itr][1]);
  }
  return summ;
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{};
  cin >> n;
  vector<VI> arr(n, VI(3));
  vector<VI> adj(n);
  REP(i, n) { cin >> arr[i][0] >> arr[i][1] >> arr[i][2]; }
  int tmp1{}, tmp2{};
  REP(i, n - 1)
  {
    cin >> tmp1 >> tmp2;
    --tmp1, --tmp2;
    adj[tmp1].push_back(tmp2);
    adj[tmp2].push_back(tmp1);
  }
  auto cmp = [&arr](int a, int b)
  {
    return arr[a][1] < arr[b][1];
  };
  MFOREACH(itr, adj) { sort(ALL(itr), cmp); }
  // DEBUG(adj, arr);
  PLLLL pans{dfs(0, -1, adj, arr)};
  cout << min(pans.first, pans.second) << '\n';
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
