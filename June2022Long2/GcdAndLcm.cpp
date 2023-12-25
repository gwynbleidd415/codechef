#include <iostream>
#include <cmath>
using namespace std;
typedef long long int ll;

ll gcdSq(ll a, ll b)
{
  if (b == 0)
    return a * a;
  return gcdSq(b, a % b);
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n{};
    cin >> n;
    ll sqrtn = sqrt(n);
    ll lcmsq{}, asq{}, bsq{}, b{}, sumsq{}, subsq{}, ans{0};
    for (ll a{1}; a <= sqrtn; ++a)
    {
      asq = a * a;
      for (ll lcm{a}; lcm <= sqrtn; lcm += a)
      {
        lcmsq = lcm * lcm;
        sumsq = asq + lcmsq;
        if (sumsq >= n)
          break;
        subsq = (n - sumsq) * lcmsq;
        if (subsq % sumsq != 0)
          continue;
        bsq = subsq / sumsq;
        b = sqrt(bsq);
        if (b * b != bsq)
          continue;
        if (asq + bsq + gcdSq(a, b) + lcmsq == n)
          ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}