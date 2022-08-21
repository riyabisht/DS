#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

// store a valid nQueens
vector<vector<int>> nQueens;
int N;

bool checkValidPos(int col, int row){

    // check for queen in the left of column same row
    for (int i = 0; i < col; i++)
        if (nQueens[row][i] == 1)
            return false;

    // check other queen in upper left side diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (nQueens[i][j] == 1)
            return false;

    // check other queen in lower left side diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (nQueens[i][j] == 1)
            return false;

    return true;
}

void addToAns(){
    vector<string> ansString;
    for (int i = 0; i < N; i++)
    {
        string str = "";
        for (int j = 0; j < N; j++)
        {
            if (nQueens[i][j] == 0)
                str.push_back('.');
            else
                str.push_back('Q');
        }
        ansString.push_back(str);
    }
    ans.push_back(ansString);
}

void solve(int col){
    // each queen gets one column
    // we just need to find the valid row

    // all queen are placed when col == N
    if (col == N)
    {
        // store solution
        addToAns();
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++)
        //         cout<<nQueens[i][j]<<" ";
        //      cout<<endl;
        // }
        // cout<<endl;

        return;
    }

    // place queen on all rows one by one
    for (int i = 0; i < N; i++)
    {

        if (checkValidPos(col, i))
        {
            // place queen and move to next column to place another queen
            nQueens[i][col] = 1;

            solve(col + 1);

            nQueens[i][col] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    N = n;
    nQueens = vector<vector<int>>(N, vector<int>(N, 0));
    // start from leftmost column
    solve(0);
    return ans;
}

int main(){
    int n;
    cin>>n;
    solveNQueens(n);
    return 0;
}