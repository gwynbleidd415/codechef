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

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{};
  cin >> n;
  VI cntarr(1001);
  int temp{};
  REP(i, n)
  {
    cin >> temp;
    ++cntarr[temp];
  }
  VI uniq;
  set<int> pros, upros;
  FOR(i, 1, 1001, 1)
  {
    if (cntarr[i] == 1)
      uniq.push_back(i), upros.insert(i);
    else if (cntarr[i] != 0)
      pros.insert(i);
  }
  int ans = n - uniq.size();
  FOR(i, 1, 1000, 1)
  {
    int tans{n - SIZE(uniq)};
    VB shoo(1001, false);
    FOREACH(itr, uniq)
    {
      if (shoo[itr])
        continue;
      if (pros.find(itr - i) != pros.end() || pros.find(itr + i) != pros.end())
      {
        ++tans;
        continue;
      }
      if (upros.find(itr - i) != upros.end() && !shoo[itr - i])
      {
        ++tans;
        continue;
      }
      if (upros.find(itr + i) != upros.end())
      {
        tans += 2;
        shoo[itr + i] = true;
        continue;
      }
    }
    ans = max(ans, tans);
  }
  cout << ans << '\n';
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
