#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int hei = board.size();
        int wei = board[0].size();
        int cellnum = 0;

        // 为了使用原地算法，给所有结果标定改变
        // 1 -> 0 11
        // 1 -> 1 1
        // 0 -> 1 10

        for (int i = 0; i < hei; i++)
            for (int j = 0; j < wei; j++)
            {
                cellnum = 0;
                for (int p = (i - 1 >= 0 ? i - 1 : 0);
                    p < (i + 2 < hei ? i + 2 : hei); p++)
                    for (int q = (j - 1 >= 0 ? j - 1 : 0);
                        q < (j + 2 < wei ? j + 2 : wei); q++)
                        if (board[p][q] % 10 == 1 && !(p == i && q == j))
                            cellnum++;
                if (board[i][j] % 10 == 1 && (cellnum < 2 || cellnum>3))
                    board[i][j] = 11;
                else if (board[i][j] % 10 == 1 && (cellnum == 2 || cellnum == 3))
                    board[i][j] = 1;
                else if (board[i][j]%10 == 0 && cellnum == 3)
                    board[i][j] = 10;
            }

        for (int i = 0; i < hei; i++)
            for (int j = 0; j < wei; j++)
                if (board[i][j] == 10)
                    board[i][j] = 1;
                else if (board[i][j] == 11)
                    board[i][j] = 0;

        return;
    }
};