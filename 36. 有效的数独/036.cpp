#include<iostream>
#include<vector>

using namespace std;
//
//// 三个分别遍历
//class Solution {
//public:
//	bool isValidSudoku(vector<vector<char>>& board) {
//		int rec[10] = {};
//		for (int i = 0;i < 9;i++)
//		{
//			for (int j = 0;j < 10;j++)
//				rec[j] = 0;
//			for (int j = 0;j < 9;j++)
//				if (board[i][j] != '.')
//					rec[board[i][j] - '0'] += 1;
//
//			for (int j = 0;j < 10;j++)
//				if (rec[j] > 1)
//					return false;
//		}
//		for (int i = 0;i < 9;i++)
//		{
//			for (int j = 0;j < 10;j++)
//				rec[j] = 0;
//			for (int j = 0;j < 9;j++)
//				if (board[j][i] != '.')
//					rec[board[j][i] - '0'] += 1;
//
//			for (int j = 0;j < 10;j++)
//				if (rec[j] > 1)
//					return false;
//		}
//		for (int i = 0;i < 3;i++)
//			for (int j = 0;j < 3;j++)
//			{
//				for (int p = 0;p < 10;p++)
//					rec[p] = 0;
//
//				for (int p = i * 3;p < i * 3 + 3;p++)
//					for (int q = j * 3;q < j * 3 + 3;q++)
//						if (board[p][q] != '.')
//							rec[board[p][q] - '0'] += 1;
//
//				for (int p = 0;p < 10;p++)
//					if (rec[p] > 1)
//						return false;
//			}
//		return true;
//	}
//};

// 改进为一次遍历，利用哈希表存储
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool row[9][10] = { false };
		bool col[9][10] = { false };
		bool box[9][10] = { false };
		for(int i=0;i<9;i++)
			for (int j = 0;j < 9;j++)
			{
				if (board[i][j] == '.')
					continue;

				int tar = board[i][j] - '0';
				if (row[i][tar])
					return false;
				if (col[j][tar])
					return false;
				if (box[i / 3 * 3 + j / 3][tar])
					return false;
				row[i][tar] = true;
				col[j][tar] = true;
				box[i / 3 * 3 + j / 3][tar] = true;
			}
		return true;
	}

};



int main()
{


}