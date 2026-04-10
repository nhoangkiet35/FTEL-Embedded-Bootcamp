#include <bits/stdc++.h>
using namespace std;

// === ONLY CODE WITHIN THE DESIGNATED AREA . DO NOT MODIFY OTHER PARTS ===
int islandPerimeter(vector<vector<int>> &grid)
{
    // Start your code here
    int rows = grid.size();
    int cols = grid[0].size();
    int perimeter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                perimeter += 4;
                if (i > 0 && grid[i - 1][j] == 1)
                    perimeter -= 2;
                if (j > 0 && grid[i][j - 1] == 1)
                    perimeter -= 2;
            }
        }
    }
    return perimeter;
}

// === DO NOT MODIFY OTHER PARTS ===
int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> grid[i][j];
    cout << "\n__JUDGE_RESULT__\n"
         << islandPerimeter(grid);
    return 0;
}