#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int pexpand(int i, int p_i, string &s)
    {
        int c = p_i + 1;
        while (i + c < s.length() && i - c >= 0 && (s[i - c] == s[i + c]))
        {
            c += 1;
        }

        return c - 1;
    }
    string addhashes(string &s)
    {
        string temp;
        temp.reserve(s.size() * 2 + 1);
        temp.push_back('#'); // start with #

        for (char c : s)
        {
            temp.push_back(c);
            temp.push_back('#'); // add # after every character
        }

        return temp;
    }
    string substr_no_hash(int indx, int chars, string &s)
    {
        string temp;
        for (int i = indx; i < indx + chars; i++)
        {
            if (s[i] == '#')
                continue;
            else
                temp.push_back(s[i]);
        }
        return temp;
    }

    string longestPalindrome(string s)
    {
        s = addhashes(s);
        int center = 0, R = 0;
        int len = s.length();
        int maxindex, maxval = 0;
        vector<int> P(len, 0);
        for (int i = 1; i < len; i++)
        {
            int mirror = 2 * center - i;
            bool noexpand = false;
            if (i < R)
            {
                P[i] = min(P[mirror], R - i);
                noexpand = P[mirror] + i < R;
            }

            if (!(noexpand))
            {
                P[i] = Solution::pexpand(i, P[i], s);
                if (i + P[i] > R)
                {
                    center = i;
                    R = i + P[i];
                    if (R - center > maxval)
                    {
                        maxval = R - center;
                        maxindex = i;
                    }
                }
            }
        }

        string plaindrome = substr_no_hash(maxindex - maxval, 2 * maxval + 1, s);
        return plaindrome;
    }
};
int main()
{
    Solution f;
    string s = "cbbd";
    string plaindrome = f.longestPalindrome(s);
    cout << plaindrome;
    return 0;
}