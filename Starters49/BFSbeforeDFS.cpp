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
template <long long mod>
struct modular
{
  long long value;
  modular(long long x = 0)
  {
    value = x % mod;
    if (value < 0)
      value += mod;
  }
  modular &operator+=(const modular &other)
  {
    if ((value += other.value) >= mod)
      value -= mod;
    return *this;
  }
  modular &operator-=(const modular &other)
  {
    if ((value -= other.value) < 0)
      value += mod;
    return *this;
  }
  modular &operator*=(const modular &other)
  {
    value = value * other.value % mod;
    return *this;
  }
  modular &operator/=(const modular &other)
  {
    long long a = 0, b = 1, c = other.value, m = mod;
    while (c != 0)
    {
      long long t = m / c;
      m -= t * c;
      swap(c, m);
      a -= t * b;
      swap(a, b);
    }
    a %= mod;
    if (a < 0)
      a += mod;
    value = value * a % mod;
    return *this;
  }
  friend modular operator+(const modular &lhs, const modular &rhs) { return modular(lhs) += rhs; }
  friend modular operator-(const modular &lhs, const modular &rhs) { return modular(lhs) -= rhs; }
  friend modular operator*(const modular &lhs, const modular &rhs) { return modular(lhs) *= rhs; }
  friend modular operator/(const modular &lhs, const modular &rhs) { return modular(lhs) /= rhs; }
  modular &operator++() { return *this += 1; }
  modular &operator--() { return *this -= 1; }
  modular operator++(int)
  {
    modular res(*this);
    *this += 1;
    return res;
  }
  modular operator--(int)
  {
    modular res(*this);
    *this -= 1;
    return res;
  }
  modular operator-() const { return modular(-value); }
  bool operator==(const modular &rhs) const { return value == rhs.value; }
  bool operator!=(const modular &rhs) const { return value != rhs.value; }
  bool operator<(const modular &rhs) const { return value < rhs.value; }
};
template <long long mod>
string to_string(const modular<mod> &x)
{
  return to_string(x.value);
}
template <long long mod>
ostream &operator<<(ostream &stream, const modular<mod> &x)
{
  return stream << x.value;
}
template <long long mod>
istream &operator>>(istream &stream, modular<mod> &x)
{
  stream >> x.value;
  x.value %= mod;
  if (x.value < 0)
    x.value += mod;
  return stream;
}

constexpr long long mod = 998244353;
using mint = modular<mod>;
typedef vector<mint> VM;
typedef vector<VM> VVM;

VM ifac(7);

void removePar(int par, vector<VI> &adj)
{
  FOREACH(itr, adj[par])
  {
    sort(ALL(adj[itr]));
    adj[itr].erase(lower_bound(ALL(adj[itr]), par));
    removePar(itr, adj);
  }
}

void fillProbDFS(int n, int src, vector<VI> &adj, VVM &probdfs)
{
  FOREACH(itr, adj[src])
  {
    REP(i, n - 1)
    {
      if (probdfs[src][i] == 0)
        continue;
      probdfs[itr][i + 1] = probdfs[src][i] * ifac[SIZE(adj[src])];
    }
    fillProbDFS(n, itr, adj, probdfs);
  }
}

void summProbDFS(int n, VVM &probdfs)
{
  mint temp(0), temp1(0);
  REP(i, n)
  {
    temp1 = probdfs[i][n - 1];
    probdfs[i][n - 1] = 0;
    RREP(j, n - 2)
    {
      temp = probdfs[i][j];
      probdfs[i][j] = temp1;
      temp1 += temp;
    }
  }
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{};
  cin >> n;
  vector<VI> adj(n);
  int t1{}, t2{};
  REP(i, n - 1)
  {
    cin >> t1 >> t2;
    --t1, --t2;
    adj[t1].push_back(t2);
    adj[t2].push_back(t1);
  }
  sort(ALL(adj[0]));
  removePar(0, adj);
  VVM probbfs(n, VM(n)), probdfs(n, VM(n));
  probbfs[0][0] = 1, probdfs[0][0] = 1;
  fillProbDFS(n, 0, adj, probdfs);
  summProbDFS(n, probdfs);
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  ifac[1] = 1;
  FOR(i, 2, 7, 1) { ifac[i] = mint(1) / mint(i); }

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
