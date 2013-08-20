#include <iostream>
#include <set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s);

int main(int argc, char **argv)
{
        cout << lengthOfLongestSubstring("abcabcbb") << endl;

        return 0;
}

int lengthOfLongestSubstring(string s)
{
        int max = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
                set<char> tmp;
                for (int j = i; j < s.size(); ++j) {
                        if (tmp.count(s[j]) != 0) {
                                break;
                        } else {
                                tmp.insert(s[j]);
                        }
                }
                if (max < tmp.size()) {
                        max = tmp.size();
                }
        }

        return max;
}
