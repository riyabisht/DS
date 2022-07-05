#include <iostream>
#include <cstring>
using namespace std;
int palin(char S[], int len)
{
    if (len == 1)
    {
        return 0;
    }
    char temp;
    int i;
    for (int j = 0, i = len - 1; j < i; i--, j++)
    {
        if(S[j]!=S[i])
        {
            return len;
        }

    }

    palin(S, len - 1);

}

int main()
{
    char S[100001];
    cin >> S;
    int L;
    L = strlen(S);

    cout << palin(S, L);

    return 0;
}