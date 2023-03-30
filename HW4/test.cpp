#include "ypglpk.hpp"
#include <iostream>
using namespace std;
int main()
{
    int n, m; // n: vertices, m:edges
    cin >> n >> m;
    std::vector<std::vector<double>> A((m + 3 * n), std::vector<double>(m + n, 0));
    std::vector<double> b(m + 3 * n, 0), c(m + n, 0);
    vector<int> in[n];
    vector<int> out[n];
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        u -= 1;
        v -= 1;
        c[i] = w;
        A[i][i] = 10000;
        A[i][m + u] = 1;
        A[i][m + v] = -1;
        in[v].push_back(i);
        out[u].push_back(i);
        b[i] = 9999;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < in[i].size(); j++)
        {
            A[m + 2 * i][in[i][j]] = 1;
            A[m + 2 * i + 1][in[i][j]] = -1;
        }
        for (int j = 0; j < out[i].size(); j++)
        {
            A[m + 2 * i][out[i][j]] = -1;
            A[m + 2 * i + 1][out[i][j]] = 1;
        }
        int set = 0;
        if (i == 0)
            set = -1;
        else if (i == n - 1)
            set = 1;
        b[m + 2 * i] = set;
        b[m + 2 * i + 1] = -set;
        for (int j = 0; j < out[i].size(); j++)
        {
            A[m + 2 * n + i][out[i][j]] = 1;
        }
        b[m + 2 * n + i] = 1;
    }
    std::pair<double, std::vector<double>>
        res;
    std::vector<int> vartype(m + n);
    for (int i = 0; i < m + n; i++)
    {
        if (i < m)
            vartype[i] = GLP_BV;
        else
            vartype[i] = GLP_IV;
    }
    res = ypglpk::mixed_integer_linear_programming(A, b, c, vartype);
    if (res.first == -ypglpk::INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        printf("%.0lf\n", res.first);
        for (int i = 0; i < m; i++)
        {
            cout << res.second[i];
        }
        cout << "\n";
    }
    return 0;
}