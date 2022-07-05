#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int K;
        cin >> K;
        K = K % n;

        long long a[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (long long i = 0; i < n; i++)
        {
            long long index;
            index = ((i + (n - K)) % n);
            cout << a[index] << " ";
        }

        cout << endl;
    }

    return 0;
}