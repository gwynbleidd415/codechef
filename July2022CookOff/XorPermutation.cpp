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
    if (n == 1)
      cout << "1";
    else if (n == 2)
      cout << "1 2";
    else if (n == 3)
      cout << "-1";
    else
    {
      cout << "1 3 4 2 ";
      for (int i{5}; i <= n; ++i)
        cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}