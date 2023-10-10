#include <bits/stdc++.h>

using namespace std;

bool isValid(char ch, vector<vector<char>> &board, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == ch)
            return false;
        if (board[row][i] == ch)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            return false;
    }
    // cout << "t\n";
    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isValid(ch, board, i, j))
                    {
                        board[i][j] = ch;
                        if (solve(board) == true)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board(9, vector<char>(9, '.'));

    for (auto &it : board)
    {
        for (auto &it1 : it)
        {
            cin >> it1;
        }
    }
    cout << "Original Sudoku answer\n";
    for (auto &it : board)
    {
        for (auto &it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    cout << "Final Sudo with answer\n";
    solve(board);
    for (auto &it : board)
    {
        for (auto &it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }

    return 0;
}