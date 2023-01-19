#include <bits/stdc++.h>
#define whatis(x) cout << "***********" << #x << " is " << x << endl;
#define MOD 1000000007
#define endl "\n"
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define MAX 100005

#define forn(i, a, n) for (int i = a; i < n; i++) //[a,n)
using namespace std;

class Solution
{
public:
    bool rowf[9][9];
    bool colf[9][9];
    bool grid[9][9];
    void fill_cell(vector<vector<char>> &board, int row, int col, int val)
    {
        board[row][col] = '0' + val;
        int g = (row / 3) * 3 + col / 3;
        rowf[row][val - 1] = true;
        colf[col][val - 1] = true;
        grid[g][val - 1] = true;
    }
    bool is_feasible(int i, int j, int val)
    {
        int g = (i / 3) * 3 + j / 3;
        if (rowf[i][val - 1] || colf[j][val - 1] || grid[g][val - 1])
            return false;
        else
            return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
         forn(i, 0, 9) forn(j, 0, 9)
        {
            rowf[i][j] = false;
            colf[i][j] = false;
            grid[i][j] = false;
            fixed[i][j] = false;
        }
        forn(i, 0, 9) forn(j, 0, 9)
        {
            if ('.' != board[i][j])
            {
                int val = board[i][j] - '0';
                if(is_feasible(i,j,val))
                    fill_cell(board, i, j, val);
                else
                    return false;
            }
        }
        return true;
    }
};