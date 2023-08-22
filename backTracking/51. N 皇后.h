#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
private:
    vector<string> path;
    vector<vector<string>> result;
public:
    vector<vector<string>> solveNQueens(int n)
    {
        //数值>0表示不可放入Queen，数值a大小代表该格可以被a个Queen攻击
        vector<vector<int>> chessboard(n, vector<int>(n,0));
        backTrack(0,n,chessboard);
        return result;
    }
    void backTrack(int row, int n, vector<vector<int>>& chessboard)
    {
        //递归终止条件
        //处理完N行返回
        if(row == n)
        {
            result.push_back(path);
            return;
        }
        // 从该行遍历
        int i = 0;
        for(; i < n; i++)
        {
            // 找到棋盘该行可以放入的位置
            if(chessboard[row][i] == 0)
            {
                path.push_back(string(i,'.') + "Q" + string(n-1-i,'.'));
                // 处理不能放入Q的位置
                //行
                for (int boardRow = 0; boardRow < n; boardRow++)
                {
                    if(boardRow != i)
                        chessboard[row][boardRow]++;
                }
                //列
                for(int boardCol = 0; boardCol < n; boardCol++)
                {
                    if(boardCol != row)
                        chessboard[boardCol][i]++;
                }
                //斜边
                for(int boardRow = row-min(row,i), boardCol=i-min(row,i); boardRow < n && boardCol < n; boardRow++,boardCol++)
                {
                    if(boardRow != row && boardCol != i)
                        chessboard[boardRow][boardCol]++;
                }
                for (int boardRow = row + i - min(i + row, n - 1), boardCol = min(i + row, n - 1); boardRow < n && boardCol >= 0; boardRow++, boardCol--)
                {
                    if (boardRow != row && boardCol != i)
                        chessboard[boardRow][boardCol]++;
                }

                backTrack(row+1,n,chessboard);

                // 撤回不能放入Q的位置
                for (int boardRow = 0; boardRow < n; boardRow++)
                {
                    if (boardRow != i)
                        chessboard[row][boardRow]--;
                }
                // 列
                for (int boardCol = 0; boardCol < n; boardCol++)
                {
                    if (boardCol != row)
                        chessboard[boardCol][i]--;
                }
                // 斜边
                for (int boardRow = row - min(row, i), boardCol = i - min(row, i); boardRow < n && boardCol < n; boardRow++, boardCol++)
                {
                    if (boardRow != row && boardCol != i)
                        chessboard[boardRow][boardCol]--;
                }
                for (int boardRow = row + i - min(i + row, n - 1), boardCol = min(i + row, n - 1); boardRow < n && boardCol >= 0; boardRow++, boardCol--)
                {
                    if (boardRow != row && boardCol != i)
                        chessboard[boardRow][boardCol]--;
                }
                path.pop_back();
            }
        }
        if(i == n) //剪枝
        {
            return;
        }
    }
};