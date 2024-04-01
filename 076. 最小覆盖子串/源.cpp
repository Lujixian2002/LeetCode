#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	unordered_map<char, int> maps, mapt;

	bool contain()
	{
		for (const auto& c : mapt)
			if (maps[c.first] < c.second)
				return false;
		return true;
	}


	string minWindow(string s, string t) {
		if (s.length() < t.length())
			return "";

		for (int i = 0;i < t.length();i++)
			mapt[t[i]]++;


		// 遍历一边把所有含有目标元素的位置记下来
		vector<int> pos;
		for (int i = 0;i < s.length();i++)
			for (int j = 0;j < t.length();j++)
				if (s[i] == t[j])
					pos.push_back(i);



		string ans = "-1";

		int p = 0, q = 0;

		int posp = 0, posq = 0;
		while (q < s.length())
		{
			string news = s.substr(p, q - p);
			maps.clear();
			for (int i = 0;i < news.length();i++)
				maps[news[i]]++;

			while (!contain())
			{
				if (q == s.length())
					break;

				q = pos[++posq];
				news = s.substr(p, q - p);
				maps.clear();
				for (int i = 0;i < news.length();i++)
					maps[news[i]]++;

			}

			while (contain())
			{
				posp++;
				if (posp == pos.size())
					break;
				p = pos[posp];

				news = s.substr(p, q - p);
				maps.clear();
				for (int i = 0;i < news.length();i++)
					maps[news[i]]++;
			}
			p = pos[--posp];


			if (p < 0)
				return "";
			if (ans == "-1")
				ans = s.substr(p, q - p);
			ans = ans.length() < s.substr(p, q - p).length() ? ans : s.substr(p, q - p);

			posp++;
			p = pos[posp];

		}

		return ans == "-1" ? "" : ans;
	}
};




int main()
{
	Solution s;
	string ss = "aaflslflsldkalskaaa";
	string st = "aaa";
	cout << s.minWindow(ss, st);
}