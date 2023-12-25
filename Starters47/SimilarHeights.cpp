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

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{};
  cin >> n;
  UMAP<int, int> heights;
  int temp{}, maxx{0}, maxc{1};
  REP(i, n)
  {
    cin >> temp;
    ++heights[temp];
    maxx = max(maxx, temp);
  }
  int num{0};
  FOREACH(itr, heights)
  {
    if (itr.second == 1)
      ++num;
    else
      maxc = max(maxc, itr.second);
  }
  if (num == 1 && heights[maxx] == 1)
  {
    if (maxc > 2)
      cout << 1 << '\n';
    else
      cout << 2 << '\n';
  }
  else
    cout << ((num + 1) >> 1) << '\n';
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
