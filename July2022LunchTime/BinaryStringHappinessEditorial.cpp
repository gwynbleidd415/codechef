#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include <sys/resource.h>
//#define int long long
#define double long double
#define initrand mt19937 mt_rand(time(0));
#define rand mt_rand()
#define MOD 1000000007
#define INF 1000000000
#define mid(l, u) ((l + u) / 2)
#define rchild(i) (i * 2 + 2)
#define lchild(i) (i * 2 + 1)
#define mp(a, b) make_pair(a, b)
#define lz lazup(l, u, i);
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
const int N = 1e5;
struct node
{
  int sum = 0, maxp = -1, smaxp = -1, maxs = -1, smaxs = -1, maxsum = 0;
};
string s[N];
int a[N], b[N], c[N], d[N]; // sum, pref, suff, max
node seg[4 * N];
node merge(node x, node y)
{
  node z;
  z.sum = x.sum + y.sum;
  z.maxsum = max(x.maxsum, y.maxsum);
  priority_queue<pair<int, int>> temp;
  temp.push({b[x.maxp], x.maxp});
  temp.push({b[y.maxp], y.maxp});
  if (x.smaxp >= 0)
    temp.push({b[x.smaxp], x.smaxp});
  if (y.smaxp >= 0)
    temp.push({b[y.smaxp], y.smaxp});
  pair<int, int> lol = temp.top();
  z.maxp = lol.second;
  temp.pop();
  lol = temp.top();
  z.smaxp = lol.second;

  while (!temp.empty())
    temp.pop();
  temp.push({c[x.maxs], x.maxs});
  temp.push({c[y.maxs], y.maxs});
  if (x.smaxp >= 0)
    temp.push({c[x.smaxs], x.smaxs});
  if (y.smaxp >= 0)
    temp.push({c[y.smaxs], y.smaxs});
  lol = temp.top();
  z.maxs = lol.second;
  temp.pop();
  lol = temp.top();
  z.smaxs = lol.second;
  return z;
}
int getAns(node x)
{
  int ans = 0;
  ans = max(ans, x.maxsum);
  int temp = x.sum;
  ans = max(ans, temp);
  if (x.maxp != x.maxs)
    ans = max(ans, temp + c[x.maxs] + b[x.maxp]);
  else
  {
    if (x.smaxp != -1)
      ans = max(ans, temp + b[x.smaxp] + c[x.maxs]);
    if (x.smaxs != -1)
      ans = max(ans, temp + c[x.smaxs] + b[x.maxp]);
  }
  return ans;
}
void build(int l, int u, int i)
{
  if (l == u)
  {
    seg[i].sum = a[l];
    seg[i].maxp = l;
    seg[i].smaxp = -1;
    seg[i].maxs = l;
    seg[i].smaxs = -1;
    seg[i].maxsum = d[l];
    return;
  }
  build(l, mid(l, u), lchild(i));
  build(mid(l, u) + 1, u, rchild(i));
  seg[i] = merge(seg[lchild(i)], seg[rchild(i)]);
}
node query(int l, int u, int i, int ll, int uu)
{
  if (l >= ll && u <= uu)
    return seg[i];
  if (ll > mid(l, u))
    return query(mid(l, u) + 1, u, rchild(i), ll, uu);
  if (uu <= mid(l, u))
    return query(l, mid(l, u), lchild(i), ll, uu);
  return merge(query(l, mid(l, u), lchild(i), ll, uu), query(mid(l, u) + 1, u, rchild(i), ll, uu));
}
signed main()
{
  int n, q;
  cin >> n >> q;
  vector<int> v[n];
  for (int i = 0; i < n; i++)
  {
    int m;
    cin >> m;
    cin >> s[i];
    a[i] = 0;
    for (int j = 0; j < m; j++)
    {
      if (s[i][j] == '1')
        v[i].push_back(1);
      else
        v[i].push_back(-1);
      a[i] += v[i][j];
    }
    a[i] = max(a[i], 0);
    d[i] = c[i] = b[i] = 0;
    int currsum = 0, cp = 0, cs = 0;
    for (int j : v[i])
    {
      currsum += j;
      d[i] = max(d[i], currsum);
      currsum = max(currsum, 0);
      cp += j;
      b[i] = max(b[i], cp);
    }
    b[i] -= a[i];
    for (int xx = m - 1; xx >= 0; xx--)
    {
      cs += v[i][xx];
      c[i] = max(c[i], cs);
    }
    c[i] -= a[i];
  }
  build(0, n - 1, 0);
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << getAns(query(0, n - 1, 0, l - 1, r - 1)) << endl;
  }
}
