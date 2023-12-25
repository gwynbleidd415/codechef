#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool isVowel(char ch)
{
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  return false;
}

void solve(int n, string &str)
{
  string res{};
  deque<char> dq;
  dq.push_back(str[0]);
  bool pushBack(true);
  for (int i{1}; i < n; ++i)
  {
    if (isVowel(str[i]))
      pushBack = !pushBack;
    if (pushBack)
      dq.push_back(str[i]);
    else
      dq.push_front(str[i]);
  }
  if (pushBack)
  {
    deque<char>::iterator itr;
    for (itr = dq.begin(); itr != dq.end(); ++itr)
      cout << *itr;
  }
  else
  {
    deque<char>::reverse_iterator itr;
    for (itr = dq.rbegin(); itr != dq.rend(); ++itr)
      cout << *itr;
  }
  cout << '\n';
}

void inputOutput()
{
  int n{};
  cin >> n;
  string str{};
  cin >> str;
  solve(n, str);
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
