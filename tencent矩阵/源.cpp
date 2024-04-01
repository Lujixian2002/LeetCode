#include <iostream>
#include<vector>
#include<string>
using namespace std;


int ans = 0;
string target = "tencent";
vector<char> row;
vector<vector<char>> map;

void dfs(int i,int j,int n,int m,int tar)
{
	if (tar == 6)
	{
		ans++;
		return;
	}
	tar++;
	if (i + 1 < n && map[i + 1][j] == target[tar])
		dfs(i + 1, j, n, m, tar);
	if (i - 1 >= 0 && map[i - 1][j] == target[tar])
		dfs( i - 1, j, n, m, tar);
	if (j + 1 < n && map[i][j + 1] == target[tar])
		dfs( i, j + 1, n, m, tar);
	if (j - 1 >= 0 && map[i][j - 1] == target[tar])
		dfs(i, j - 1, n, m, tar);
}




int main() {
	int n, m;
	cin >> n >> m;
	int n1 = n, n2 = n;
	int m1 = m;



	while (n1--)
	{
		m1 = m;
		while (m1--)
			row.push_back('1');

		map.push_back(row);
	}
	for (int i = 0;i < n;i++)
	{
		int m2 = m;
		char c = '1';
		for (int j = 0;j < m;j++)
		{
			cin >> c;
			map[i][j] = c;
		}
	}
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			if (map[i][j] == 't')
				dfs(i, j, n, m, 0);

	cout << ans;

}
// 64 Î»Êä³öÇëÓÃ printf("%lld")