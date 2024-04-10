#include<iostream>
using namespace std;




class Solution {
public:
    string maximumBinaryString(string binary) {
        int zeronum = 0;
        for (int i = 0; i < binary.size() ; i++)
            if (binary[i] == '0')
                zeronum++;
        int zeromeet = 0;
        int zeromeetfirpos = 0;
        for (int i = 0; i < binary.size(); i++)
        {
            // 如果只剩一个0则退出
            if (zeronum == 1)
                return binary;
            if (binary[i] == '1')
                continue;
            else if (binary[i] == '0' && i < binary.size()-1 && binary[i + 1] == '0')
            {
                binary[i] = '1';
                zeronum--;
                continue;
            }
            else if (binary[i] == '0')
            {
                if (zeromeet == 0)
                    zeromeetfirpos = i;
                zeromeet++;
            }
            if (zeromeet == 2)
            {
                binary[zeromeetfirpos] = '1';
                binary[zeromeetfirpos + 1] = '0';

                zeromeetfirpos++;
                binary[i] = '1';
                zeromeet--;
                zeronum--;
            }
        }


        return binary;
    }
};

// 直接计算

class Solution2 {
public:
    string maximumBinaryString(string binary) {
        int zeronum = 0;
        int zeromeetfirpos = 0;
        for (int i = 0; i < binary.size(); i++)
            if (binary[i] == '0')
            {
                if (zeronum == 0)
                    zeromeetfirpos = i;
                zeronum++;
            }
        for (int i = 0; i < binary.size(); i++)
            if (i == zeromeetfirpos + zeronum-1)
                binary[i] = '0';
            else
                binary[i] = '1';
        return binary;
    }
};