#include <iostream>
#include<vector>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    vector<vector<int>> r;
    vector<int> row;
    int ans = 0;
    int n1 = n + 1, n2 = n + 1;

    while (n1--)
        row.push_back(0);
    while (n2--)
        r.push_back(row);

    while (m--)
    {
        int u, v;
        char chr;
        cin >> u >> v >> chr;
        if (chr == 'R')
            r[u][v] = 1;
        if (chr == 'W')
            r[u][v] = -1;

        r[v][u] = r[u][v];
    }

    for (int i = 1;i <= n;i++)
    {
        bool flag = true;
        for (int j = 1;j <= n;j++)
            if (r[i][j] == -1 )
            {
                flag = false;
                break;
            }
        if (flag == true)
        {
            cout << i;
            ans++;
        }
    }
    cout << ans;




}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include<vector>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;

    vector<vector<int>> r;
    vector<int> row;
    int ans = 0;
    int n1 = n + 1, n2 = n + 1;

    while (n1--)
        row.push_back(0);
    while (n2--)
        r.push_back(row);

    while (m--) {
        int u, v;
        char chr;
        cin >> u >> v >> chr;
        if (chr == 'R')
            r[u][v] = 1;
        if (chr == 'W')
            r[u][v] = -1;

        r[v][u] = r[u][v];
    }

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j < n + 1; j++)
            if (r[i][j] == -1) {
                flag = false;
                break;
            }
        if (flag == true)
            ans++;
    }
    cout << ans;




}
// 64 位输出请用 printf("%lld")