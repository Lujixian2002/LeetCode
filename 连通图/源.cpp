#include <iostream>
#include<vector>
using namespace std;

int main() {
	int m, n;
	cin >> n >> m;
	int n1 = n;
	vector<int> map;
	map.push_back(0);
	while (n1--)
		map.push_back(-1);
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		map[max(u, v)] = min(u, v);
	}

	int p = 0;

	for (int i = 1;i < map.size();i++)
		while (map[i] != -1&&map[map[i]]!=-1)
			map[i] = map[map[i]];
		

	int group = 0;
	for (int i = 1;i < map.size();i++)
		if (map[i] == -1)
			group++;
	if (group != 2)
	{
		cout << 0;
		return 0;
	}
	int k1 = 1, grouphead;
	for (int i = 1;i < map.size();i++)
		if (map[i] ==1)
			k1++;

	cout << k1 * (n - k1);

}
// 64 Î»Êä³öÇëÓÃ printf("%lld")