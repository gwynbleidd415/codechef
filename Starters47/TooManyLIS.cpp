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
const int MOD{(int)1e9 + 7};

int pow(int aa, int b)
{
  LL res{1};
  LL a{aa};
  while (b)
  {
    if (b & 1)
      res = (res * a) % MOD;
    a = (a * a) % MOD;
    b /= 2;
  }
  return res;
}

int modInv(int a)
{
  return pow(a, MOD - 2);
}

int ncr(int n, int r)
{
  r = min(r, n - r);
  LL res{n};
  FOR(i, 2, r + 1, 1)
  {
    res = (res * (n - i + 1)) % MOD;
    res = (res * modInv(i)) % MOD;
  }
  return res;
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{};
  cin >> n;
  int start{(n + 1) >> 1};
  FOR(i, 1, start, 1) { cout << 0 << ' '; }
  if (n & 1)
    --start;
  LL comb{ncr(n, start)}, comb1{};
  RFOR(i, start, 1, 1)
  {
    comb1 = (((comb * i) % MOD) * modInv(n - i + 1)) % MOD;
    cout << (comb - comb1 + MOD) % MOD << ' ';
    comb = comb1;
  }
  cout << 1 << '\n';
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
