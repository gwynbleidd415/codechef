#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// void solve(int n, string &str)
// {
// }

int calcgcd(int a, int b)
{
  if (b == 0)
    return a;
  return calcgcd(b, a % b);
}

void inputOutput()
{
  int n;
  cin >> n;
  vector<int> arr(n + 1);
  unordered_set<int> st;
  for (int i{1}; i <= n; ++i)
  {
    cin >> arr[i];
    st.insert(abs(arr[i] - i));
  }
  st.erase(0);
  int gcd{0};
  for (int it : st)
  {
    gcd = calcgcd(gcd, it);
    if (gcd == 1)
      break;
  }
  cout << gcd << '\n';
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
