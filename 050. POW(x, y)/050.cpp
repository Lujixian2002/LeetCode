#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {

		double ans = 1.0;
		long long N = n;
		if (abs(N) > 10000 && N < 1 && n > -1)
			return 0;
		for (int i = 0;i < abs(N);i++)
		{
			if (abs(N) > 2 * i)
			{
				ans *= ans;
				i = 2 * i;
			}
			ans *= x;
		}

		if (N < 0)
			return 1 / ans;
		else
			return ans;
	}
};


int main()
{
	Solution s;
	cout << s.myPow(2, -2147483648);
}	