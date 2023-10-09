#include <bits/stdc++.h>

using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &bottom, vector<int> &top, vector<int> &leftToRight, int n)
{

    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        int b = (n - 1) + (col - row);
        int t = (row + col);
        if (leftToRight[row] == 0 && bottom[b] == 0 && top[t] == 0)
        {
            board[row][col] = 'Q';
            leftToRight[row] = 1;
            bottom[b] = 1;
            top[t] = 1;
            solve(col + 1, board, ans, bottom, top, leftToRight, n);
            board[row][col] = '.';
            leftToRight[row] = 0;
            bottom[b] = 0;
            top[t] = 0;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    vector<int> bottom((2 * n) - 1, 0);
    vector<int> top((2 * n) - 1, 0);
    vector<int> leftToRight(n, 0);

    solve(0, board, ans, bottom, top, leftToRight, n);
    int count = 1;
    for (auto &it : ans)
    {
        cout << count << "-th queen\n\n";
        for (auto &it1 : it)
        {
            cout << it1 << endl;
        }
        cout << endl
             << endl;
        count++;
    }
}