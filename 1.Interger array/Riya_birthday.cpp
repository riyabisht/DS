#include <iostream>
using namespace std;
const long long M = 1000000007;

int main()
{
    unsigned long long t;
    cin >> t;
    while (t--)
    {
        unsigned long long N, ans = 0;
        cin >> N;
        N = N % M;
        ans = (N % M * N % M) % M;
        ans = (ans + ((N - 1) * N) % M) % M;
        cout << ans;
        cout << endl;
    }

    return 0;
}