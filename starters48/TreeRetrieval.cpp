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
PII ask(VI &arr)
{
  cout << "? " << SIZE(arr) << ' ';
  FOREACH(itr, arr) { cout << itr << ' '; }
  cout << '\n';
  PII ans{};
  cin >> ans.first >> ans.second;
  return ans;
}

void printAns(vector<PII> &edges)
{
  cout << "!\n";
  FOREACH(itr, edges) { cout << itr.first << ' ' << itr.second << '\n'; }
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n{};
  cin >> n;
  VI arr(n), orphans;
  iota(ALL(arr), 1);
  PII ofirst{ask(arr)}, osecond{};
  vector<PII> edges;
  orphans.push_back(ofirst.first);
  while (SIZE(arr) > 2)
  {
    arr.erase(find(ALL(arr), ofirst.first));
    osecond = ask(arr);
    if (osecond.second != ofirst.second - ofirst.first)
    {
      int parr{osecond.second - (ofirst.second - ofirst.first)};
      edges.push_back({ofirst.first, parr});
      orphans.erase(find(ALL(orphans), ofirst.first));
      int ptr{0};
      while (true)
      {
        int lo{ptr}, hi{SIZE(orphans)}, mid{};
        while (lo < hi)
        {
          mid = (hi + lo + 1) >> 1;
          VI newArr = arr;
          int goal{ofirst.second - ofirst.first};
          REP(i, mid)
          {
            newArr.push_back(orphans[i]);
            goal += orphans[i];
          }
          if (ask(newArr).second == goal)
            hi = mid - 1;
          else
            lo = mid;
        }
        if (lo == SIZE(orphans))
          break;
        edges.push_back({orphans[lo], parr});
        orphans.erase(orphans.begin() + lo);
        ptr = lo;
      }
    }
    ofirst = osecond;
    orphans.push_back(ofirst.first);
  }
  edges.push_back({arr[0], arr[1]});
  assert(SIZE(edges) == n - 1);
  printAns(edges);
}

/**************************** Main Function *************************/
int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
    int foo;
    cin >> foo;
    if (foo != 1)
      break;
  }
  return 0;
}
