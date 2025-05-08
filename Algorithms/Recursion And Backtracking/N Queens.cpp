#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<string> &board)
{
    for (const auto &row : board)
    {
        cout << row << endl;
    }
    cout << endl;
}

void solveNQueensUtil(int n, int row, vector<string> &board, vector<vector<string>> &result)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        bool safe = true;
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q' || (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') || (col + (row - i) < n && board[i][col + (row - i)] == 'Q'))
            {
                safe = false;
                break;
            }
        }
        if (safe)
        {
            board[row][col] = 'Q';
            solveNQueensUtil(n, row + 1, board, result);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    if (n <= 0)
        return {};
    if (n == 1)
        return {{"Q"}};
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    solveNQueensUtil(n, 0, board, result);
    return result;
}

int main()
{
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    for (const auto &solution : solutions)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}