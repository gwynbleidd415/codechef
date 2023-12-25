#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> score(n + 2);
    int li{}, ri{};
    for (int i{1}; i <= n; ++i)
    {
      cin >> li >> ri;
      ++score[li], --score[ri + 1];
      if (li <= i && ri >= i)
      {
        score[li] += 1;
        score[0] -= 1;
        score[ri + 1] -= 1;
        score[i] -= 2;
        score[i + 1] += 2;
      }
    }
    for (int i{1}; i <= n; ++i)
      score[i] += score[i - 1];
    int cnt{0};
    for (int i{1}; i <= n; ++i)
      if (score[i] == n - 1)
        ++cnt;
    cout << cnt << '\n';
    for (int i{1}; i <= n; ++i)
      if (score[i] == n - 1)
        cout << i << '\n';
  }
  return 0;
}
