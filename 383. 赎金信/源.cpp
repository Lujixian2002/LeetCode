#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;


class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> r, m;
		for (int i = 0;i < ransomNote.size();i++)
			r[ransomNote[i]]++;
		for (int i = 0;i < magazine.size();i++)
			m[magazine[i]]++;

		for (const auto& c : r)
			if (c.second > m[c.first])
				return false;
		return true;
	}
};



int main()
{
	Solution s;

}