#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string A;
    string B;
    A = "AGGTAB";
    B = "GXTXAYB";
    int n = A.size();
    int m = B.size();

    //create DP
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = 1+ dp[i - 1][j - 1];
            }
            else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    /*
DP of LCS with max length created 
0 0 0 0 0 0 0 
0 1 1 1 1 1 1 
0 1 1 2 2 2 2 
0 1 2 2 2 2 2 
0 1 2 3 3 3 3 
0 1 2 3 3 3 4 */

/* Store the character if A[i-1] == B[j-1]
If not equal to that index which has greater length of Subsequence
 */
    string ans;
    for(auto i:dp)
    {
        for(auto j:i ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    while (n != 0 && m != 0)
    {
        if (A[n - 1] == B[m - 1])
        {
            ans.push_back(A[n - 1]);
            n = n - 1;
            m = m - 1;
            continue;
        }

        int len1 = dp[n - 1][m];
        int len2 = dp[n][m - 1];
        if (len1 > len2)
        {
            n = n - 1;
        }
        else
            m = m - 1;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    //GTAB
    return 0;
}