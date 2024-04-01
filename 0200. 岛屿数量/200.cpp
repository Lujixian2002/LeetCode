#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

	void dfs(vector<vector<char>>& grid, int i, int j)
	{
		// 将格子标记为已经遍历过
		grid[i][j] = '0';
		int h = grid.size();
		int w = grid[0].size();

		if (i + 1 < h && grid[i + 1][j] == '1')
			dfs(grid, i + 1, j);
		if (j + 1 < w && grid[i][j + 1] == '1')
			dfs(grid, i, j + 1);
		if (i - 1 >= 0 && grid[i - 1][j] == '1')
			dfs(grid, i - 1, j);
		if (j - 1 >= 0 && grid[i][j - 1] == '1')
			dfs(grid, i, j - 1);


		// 四个都不满足则return了
	}



	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;
		int h = grid.size();
		int w = grid[0].size();
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (grid[i][j] == '1')
				{

					ans++;
					dfs(grid, i, j);
				}

		return ans;
	}
};