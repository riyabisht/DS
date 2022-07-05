#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        char S[100001];
        long int N, c = 1, k = 0;
        cin >> N;
        cin >> S;
        for (long int i = 0; i < N - 1; i++)
        {
            if (S[i] != S[i + 1])
            {
                c++;
            }
            else
            {
                k += c;
                c = 0;
            }
        }
        cout << c + k << endl;
    }
    return 0;
}
