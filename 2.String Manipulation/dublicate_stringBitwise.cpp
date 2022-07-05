#include <iostream>
using namespace std;
int main()
{
    char S[10000];
    cin >> S;
    int h, x;
    for (int i = 0; S[i] != '\0'; i++)
    {
        x = 1;
        int shift = S[i] - 97;
        x = x << shift;
        int check = x & h;
        if (check > 0)
            cout << S[i];
        else
            h = x | h;
    }

    return 0;
}