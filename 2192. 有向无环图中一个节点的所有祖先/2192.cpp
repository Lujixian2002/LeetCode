#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


// 利用集合进行存储，提高速度，时间复杂度依旧太高
class Solution1 {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> ans(n);
        unordered_map < int, unordered_set<int>> parentNodes;

        int edgeNum = edges.size();
        for (int i = 0; i < edgeNum; i++)
            parentNodes[edges[i][1]].insert(edges[i][0]);
        unordered_map < int, unordered_set<int>> pastAns = parentNodes;
        while (1)
        {
            pastAns = parentNodes;
            for (int i = 0; i < parentNodes.size(); i++)
                for (int num : parentNodes[i])
                    for (int num2 : parentNodes[num])
                        parentNodes[i].insert(num2);

            if (pastAns == parentNodes)
                break;
        }
        for (int i = 0; i < parentNodes.size(); i++)
        {
            for (int num : parentNodes[i])
                ans[i].push_back(num);
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

class Solution {
public:
    void dfs(int node, unordered_map<int, unordered_set<int>>& parentNodes, vector<vector<int>>& ancestors) {

        for (int parent : parentNodes[node]) {
            dfs(parent, parentNodes, ancestors);
            ancestors[node].insert(ancestors[node].end(), ancestors[parent].begin(), ancestors[parent].end());
        }
    }

    //void dfs(int node, unordered_map<int, unordered_set<int>>& parentNodes, vector<vector<int>>& ancestors) {
    //    for (int parent : parentNodes[node]) {
    //        if (find(ancestors[node].begin(), ancestors[node].end(), parent) == ancestors[node].end())
    //        {
    //            ancestors[node].push_back(parent);
    //            for (int grandparent : ancestors[parent])
    //                if (find(ancestors[node].begin(), ancestors[node].end(), grandparent) == ancestors[node].end())
    //                    ancestors[node].push_back(grandparent);
    //        }
    //        dfs(parent, parentNodes, ancestors);
    //    }
    //}

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ancestors(n);
        unordered_map<int, unordered_set<int>> parentNodes;

        for (const auto& edge : edges) 
            parentNodes[edge[1]].insert(edge[0]);

        for (int i = 0; i < n; i++) 
        {
            dfs(i, parentNodes, ancestors);
            sort(ancestors[i].begin(), ancestors[i].end());
        }

        return ancestors;
    }
};
