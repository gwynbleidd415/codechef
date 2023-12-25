#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long int ll;

using namespace std;

int modulo{(int)1e9 + 7};

ll powNormal(ll a, int b)
{
  ll ret{1};
  while (b)
  {
    if (b & 1)
      ret = (ret * a) % modulo;
    a = (a * a) % modulo;
    b /= 2;
  }
  return ret;
}

ll modInv(int a)
{
  return powNormal(a, modulo - 2);
}

ll pow2(int b)
{
  return powNormal(2, b);
}

ll ncr(int n, int r)
{
  r = min(r, n - r);
  if (r == 0)
    return 1;
  ll ans{n};
  for (int i{2}; i <= r; ++i)
  {
    ans = (ans * (n - i + 1)) % modulo;
    ans = (ans * modInv(i)) % modulo;
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> score(n);
    ll ans{0};
    for (int i{0}; i < n; ++i)
      cin >> score[i];
    sort(score.begin(), score.end());
    score.push_back(0);
    vector<int> multiples(n + 1);
    int cnt{};
    int i{0}, j{}, temp{}, smlr{}, num{};
    while (i < n)
    {
      j = i;
      while (i < n && score[i] == score[i + 1])
        ++i;
      cnt = i - j + 1;
      if (cnt > 1)
      {
        ans = (ans + pow2(cnt)) % modulo;
        ans = ((ans - (cnt + 1)) % modulo + modulo) % modulo;
      }
      num = score[i];
      smlr = min((int)sqrt(num), n);
      if (num <= n)
      {
        multiples[num] += cnt;
        if (num > 1 && num <= cnt)
          ans = ((ans - ncr(cnt, num)) % modulo + modulo) % modulo;
      }
      for (int i{2}; i <= smlr; ++i)
      {
        if (num % i == 0)
        {
          if (i <= cnt)
            ans = ((ans - ncr(cnt, i)) % modulo + modulo) % modulo;
          multiples[i] += cnt;
          temp = num / i;
          if (temp <= n && temp != i)
          {
            multiples[temp] += cnt;
            if (temp <= cnt)
              ans = ((ans - ncr(cnt, temp)) % modulo + modulo) % modulo;
          }
        }
      }
      ++i;
    }
    for (int i{2}; i <= n; ++i)
      if (multiples[i] >= i)
        ans = (ans + ncr(multiples[i], i)) % modulo;
    cout << ans << '\n';
  }
  return 0;
}
