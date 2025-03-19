#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> memo;

vector<string> wordBreakHelper(string s, unordered_set<string>& wordSet) {
    if (memo.count(s)) return memo[s];
    
    vector<string> result;
    if (wordSet.count(s)) result.push_back(s);
    
    for (int i = 1; i < s.size(); i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (wordSet.count(left)) {
            vector<string> subResults = wordBreakHelper(right, wordSet);
            for (string sub : subResults) {
                result.push_back(left + " " + sub);
            }
        }
    }
    return memo[s] = result;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    return wordBreakHelper(s, wordSet);
}
