#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

class Solution
{
    int deep = 0;
    ofstream f;
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        f.open("recird.txt",ios::out);
        backTrack(0,board);
    }
    bool backTrack(int row,vector<vector<char>> &board)
    {
        f << "第" << deep++ << "层递归\n";
        printBoard(board);
        for(int i = row; i < board.size(); i++)
        {
            //该行的每一格填入数字
            for(int j = 0; j < board.size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char num = '1'; num <= '9'; num++)
                    {
                        if(isValid(i,j,num,board))
                        {
                            board[i][j] = num;

                            if(backTrack(i,board)) return true;
  
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }  
        }
        return true;
    }
    bool isValid(int i, int j, char num, vector<vector<char>> &board)
    {
        //检查行
        for(int k = 0; k < board.size(); k++)
        {
            if(board[i][k] == num) return false;
        }
        //检查列
        for(int k = 0; k < board.size(); k++)
        {
            if(board[k][j] == num) return false;
        }
        //检查九宫格
        for (int row = i - i % 3; row < i - i % 3 + 3; row++)
        {
            for(int col = j - j % 3; col < j - j % 3 + 3; col++)
            {
                if(board[row][col] == num) return false;
            }
        }
        return true;
    }


    void printBoard(const vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                f << board[i][j] << " ";
            }
            f << endl;
        }
        f << endl;
    }
};