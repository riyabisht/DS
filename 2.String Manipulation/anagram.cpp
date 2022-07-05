#include <iostream>
using namespace std;
int main()
{
    char S1[10000], s2[10000];
    int c[25], flag = 0, L1, L2;
    cin >> S1 >> s2;
    for (int i = 0; S1[i] != '\0'; i++)
        L1 = i;
    for (int i = 0; S1[i] != '\0'; i++)
        L2 = i;

    if (L1 != L2)
    {
        flag = 1;
        cout << "not anagram";
    }
    else
    {
        for (int i = 0; S1[i] != '\0'; i++)
        {
            int index = S1[i] - 97;
            c[index]++;
        }
        for (int i = 0; s2[i] != '\0'; i++)
        {
            int index = s2[i] - 97;
            c[index]--;
        }
        for (int i = 0; i < 25; i++)
        {
            if (c[i] > 0)
            {
                flag = 1;
                cout << " not a anagram";
                break;
            }
        }
    }
    if (flag == 0)
        cout << "anagram";

    return 0;
}