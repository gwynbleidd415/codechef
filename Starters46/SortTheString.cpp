#include <iostream>
#include <string>

using namespace std;

int solve(int n, string &str)
{
  int i{0};
  while (i < n && str[i] == '0')
    ++i;
  int ans{0};
  while (i < n)
  {
    while (i < n && str[i] == '1')
      ++i;
    if (i < n)
      ++ans;
    while (str[i] == '0')
      ++i;
  }
  return ans;
}

void inputOutput()
{
  int n;
  cin >> n;
  string str;
  cin >> str;
  cout << solve(n, str) << '\n';
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
