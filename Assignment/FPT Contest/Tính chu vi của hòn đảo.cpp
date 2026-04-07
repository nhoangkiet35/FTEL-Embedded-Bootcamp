#include <bits/stdc++.h>
using namespace std;

// === ONLY CODE WITHIN THE DESIGNATED AREA . DO NOT MODIFY OTHER PARTS ===
int islandPerimeter(vector<vector<int>> &grid)
{
    // Start your code here
    return 0;
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