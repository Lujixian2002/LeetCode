#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int getWinner(vector<int>& arr, int k) {
		int winner = arr[0];
		int con = 0;

		if (k == 1 && arr.size() > 1)
			return max(arr[0], arr[1]);

		for (int i = 1;i < arr.size();i++)
		{
			if (winner > arr[i])
				con++;
			else
			{
				con = 1;
				winner = arr[i];
				continue;
			}
			if (con == k)
				return winner;
		}
		return winner;
	}
};