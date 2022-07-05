#include <iostream>
using namespace std;
int main()
{
    char S[10000];
    cin >> S;
    int h[25];

    for (int i = 0; S[i] != '\0'; i++)
    {
        int index = S[i] - 97;
        h[index]++;
    }
    for (int i = 0; i < 25; i++)
    {
        if (h[i] > 1)
        {
            char ch;
            ch = i + 97;
            cout << ch << " ";
        }
    }

    return 0;
}