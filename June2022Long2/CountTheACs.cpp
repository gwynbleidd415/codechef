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
    int x{n % 100}, y{n / 100};
    if (x + y <= 10)
      cout << x + y << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
