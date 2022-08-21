#include <bits/stdc++.h>
using namespace std;
#define n 8
int tour(int board[n][n], int moves, int xMoves[], int yMoves[], int x, int y);

int checkAllVisited(int moves){
   if (moves == n * n)
      return 1;
   return 0;
};

int valid(int x, int y, int board[n][n]){
   /* cell us empty */
   return ((x < n && x >= 0) && (y < n && y >= 0) && board[x][y] == -1);
}

void knightTour()
{
   int board[n][n];
   memset(board, -1, sizeof(board));
   board[0][0] = 0;
   int xMoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
   int yMoves[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
   int moves = 1;
   if (tour(board, moves, xMoves, yMoves, 0, 0))
   {
      cout << "PAth found" << endl;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            cout << board[i][j] << " ";
         }
         cout << endl;
      }
   }

   else
      cout << "Not found";
}
int tour(int board[n][n], int moves, int xMoves[n], int yMoves[n], int x, int y)
{
   /* 1 - check all the cells visited  */
   if (checkAllVisited(moves))
      return 1;
   /* 2- select all 8 position one by one  */
   for (int i = 0; i < n; i++)
   {
      int x_move = x + xMoves[i];
      int y_move = y + yMoves[i];
     // cout<<x_move<<" "<<y_move<<endl;
      /* check if position are valid or not */
      if (valid(x_move, y_move, board))
      {
         /* assign move value to position */
         board[x_move][y_move] = moves;
         /* move to cell*/
         if (tour(board, moves + 1, xMoves, yMoves, x_move, y_move) == 1){
            /* path found */
            return 1;
         }
         else
            board[x_move][y_move] = -1;
      }
   }

   return 0;
}




int main()
{
   knightTour();
   return 0;
}