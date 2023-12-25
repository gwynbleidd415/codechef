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

/*********************************** Main Solution Starts Here ***********************************/
void performOR(int &a, int b)
{
  cout << 1 << ' ' << a << ' ' << b << '\n';
  a |= b;
}
void performXOR(int &a, int b)
{
  cout << 2 << ' ' << a << ' ' << b << '\n';
  a ^= b;
}
void notPossible()
{
  cout << -1 << '\n';
}
int maxPow2(int n)
{
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;

  return (n + 1);
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, k{};
  cin >> n >> k;
  if (n == 2)
  {
    if (k == 3)
      cout << 1 << ' ' << 1 << ' ' << 2 << '\n';
    else
      notPossible();
    return;
  }
  int curr{3};
  int maxx{maxPow2(n)};
  if (k >= maxx || (!(n & (n - 1)) && !(k & n)))
  {
    notPossible();
    return;
  }
  FOR(i, 5, n + 1, 1)
  {
    if (i & (i - 1))
      performOR(curr, i);
  }
  int xx{1};
  while (xx < maxx)
  {
    if (k & xx)
      performOR(curr, xx);
    else
      performXOR(curr, xx);
    xx <<= 1;
  }
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
