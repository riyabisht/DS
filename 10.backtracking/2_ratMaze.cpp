#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> xMove, yMove;
vector<string> ans;

bool checkValid(int x, int y, vector<vector<int>> &m)
{
    return (x >= 0 && x < N && y >= 0 && y < N && m[x][y] == 1);
}

void solve(vector<vector<int>> &m, int x, int y, string &str)
{

    // reach end cell store path
    if (x == N - 1 && y == N - 1)
    {
        ans.push_back(str);
        return;
    }
    m[x][y] = 0;
    // from current position move to valid position , out of 4 position
    // down
    // right
    // left
    // up
    for (int i = 0; i < 4; i++)
    {

        int next_x = x + xMove[i];
        int next_y = y + yMove[i];

        if (checkValid(next_x, next_y, m))
        {
            // valid

            if (i == 0)
                str.push_back('D');
            else if (i == 1)
                str.push_back('R');
            else if (i == 2)
                str.push_back('L');
            else
                str.push_back('U');
            // go to next move
            solve(m, next_x, next_y, str);
            str.pop_back();
        }
    }
    m[x][y] = 1;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    N = n;
    xMove = vector<int>({1, 0, 0, -1});
    yMove = vector<int>({0, 1, -1, 0});
    string str = "";
    ans = vector<string>();
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        return ans;
    else
    {
        solve(m, 0, 0, str);
        return ans;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>>m({
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}});
    findPath(m,4);
    return 0;
}