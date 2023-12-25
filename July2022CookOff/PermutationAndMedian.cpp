#include <iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int l{1}, r{n};
    while (r > l)
      cout << r-- << ' ' << l++ << ' ';
    if (r == l)
      cout << l;
    cout << '\n';
  }
  return 0;
}