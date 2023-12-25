#include <iostream>
#include <string>

using namespace std;

// void solve(int n, string &str)
// {
// }

void inputOutput()
{
  int x{}, y{};
  cin >> x >> y;
  int a{2}, b{}, c{};
  if (x & 1 && y & 1)
  {
    b = x ^ a;
    c = y ^ a;
  }
  else
  {
    if (x & 1)
      b = x ^ a;
    else
      b = y ^ a;
    c = x ^ y ^ a;
  }
  if (b > c)
    swap(b, c);
  cout << a << ' ' << b << ' ' << c << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    inputOutput();
}
