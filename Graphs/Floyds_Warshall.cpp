#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {

        int N = matrix.size();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = INT_MAX;
                }
            }
        }

        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    {
                        continue;
                    }
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] == INT_MAX)
                {
                    matrix[i][j] = -1;
                }
            }
        }

        // If you want to check whether there exists any negative edge cycle then you can use below function....
        for (int i = 0; i < N; i++)
        {
            if (matrix[i][i] < 0)
            {
                cout << "Negative edge cycle found....";
                break;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    obj.shortest_distance(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}