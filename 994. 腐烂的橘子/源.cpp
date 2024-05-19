#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
		int num = 0;
		int badTime[10][10];
		queue <pair<int,int>> Q;

		for (int i = 0;i < m;i++)
			for (int j = 0;j < n;j++)
				if (grid[i][j] == 2)
				{
					Q.emplace(i, j);
					badTime[i][j] = 0;
				}
		while (!Q.empty())
		{
			
			int i = Q.front().first;
			int j = Q.front().second;
			Q.pop();
			if (i < m - 1&& grid[i + 1][j]==1)
			{
				grid[i + 1][j] = 2;
				Q.emplace(i + 1, j);
				badTime[i + 1][j] = badTime[i][j] + 1;
			}

			if (i > 0&& grid[i - 1][j]==1)
			{
				grid[i - 1][j] = 2;
				Q.emplace(i - 1, j);
				badTime[i - 1][j] = badTime[i][j] + 1;

			}
			if (j < n - 1&& grid[i][j + 1]==1)
			{
				grid[i][j + 1] = 2;
				Q.emplace(i, j + 1);
				badTime[i][j+1] = badTime[i][j] + 1;
			}
			if (j > 0&& grid[i][j - 1]==1)
			{
				grid[i][j - 1] = 2;
				Q.emplace(i, j - 1);
				badTime[i][j - 1] = badTime[i][j] + 1;
			}
		}
		for (int i = 0;i < m;i++)
			for (int j = 0;j < n;j++)
				if (grid[i][j] == 1)
					return -1;
		for (int i = 0;i < m;i++)
			for (int j = 0;j < n;j++)
				num = max(num, badTime[i][j]);
        return num;
    }
};


int main()
{

}