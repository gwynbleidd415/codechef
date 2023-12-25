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
int fillStreeSz(vector<VI> &adj, VI &streeSz, int i)
{
  streeSz[i] = 1;
  FOREACH(itr, adj[i]) { streeSz[i] += fillStreeSz(adj, streeSz, itr); }
  return streeSz[i];
}

void fillAns(vector<VI> &adj, VI &streeSz, VB &ans, int i, int k)
{
  if (k == 0)
    return;
  --k;
  ans[i] = true;
  int k2{};
  FOREACH(itr, adj[i])
  {
    if (k == 0)
      break;
    k2 = min(streeSz[itr], k);
    fillAns(adj, streeSz, ans, itr, k2);
    k -= k2;
    ans[i] = !ans[i];
  }
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{}, k{};
  cin >> n >> k;
  vector<VI> adj(n);
  int tmp{};
  REP(i, n - 1)
  {
    cin >> tmp;
    adj[tmp - 1].push_back(i + 1);
  }
  VI streeSz(n);
  fillStreeSz(adj, streeSz, 0);
  VB ans(n, false);
  fillAns(adj, streeSz, ans, 0, k);
  FOREACH(itr, ans) { cout << (itr ? 1 : 0); }
  cout << '\n';
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
