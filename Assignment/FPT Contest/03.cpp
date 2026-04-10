#include <bits/stdc++.h>
using namespace std;

// === ONLY CODE WITHIN THE DESIGNATED AREA . DO NOT MODIFY OTHER PARTS ===
int lastAntFall(int n, vector<int> &right2left, vector<int> &left2right)
{
    // Start your code here
    int maxTime = 0;
    for (int pos : right2left)
        maxTime = max(maxTime, pos);
    for (int pos : left2right)
        maxTime = max(maxTime, n - pos);
    return maxTime;
}

// === DO NOT MODIFY OTHER PARTS ===
vector<int> parseLine(const string &line)
{
    vector<int> values;
    stringstream ss(line);
    int x;
    while (ss >> x)
        values.push_back(x);
    return values;
}

int main()
{
    string line;
    if (!getline(cin, line))
        return 0;
    int n = stoi(line);

    string leftLine, rightLine;
    if (!getline(cin, leftLine))
        leftLine = "";
    if (!getline(cin, rightLine))
        rightLine = "";

    vector<int> left = parseLine(leftLine);
    vector<int> right = parseLine(rightLine);

    cout << "\n__JUDGE_RESULT__\n"
         << lastAntFall(n, left, right);
    return 0;
}