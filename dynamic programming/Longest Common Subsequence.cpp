#include <iostream>
#include <vector>
#include <string>

using namespace std;

string findLCS(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Building the DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstructing the LCS
    int len = dp[m][n];
    string lcs(len, ' ');
    int i = m, j = n;
    while (len > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs[len - 1] = s1[i - 1];
            i--;
            j--;
            len--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return lcs;
}

int main()
{

    string s1 = "BCDAACD";
    string s2 = "ACDBAC";
    string lcs = findLCS(s1, s2);

    cout << "Longest Common Subsequence: " << lcs << endl
         << endl;

    return 0;
}
