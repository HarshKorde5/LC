/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        // Frequency array for the first word
        int freq[26] = {0};
        for(char ch : words[0]) {
            freq[ch - 'a']++;
        }

        // Intersect frequencies with each next word
        for(int i = 1; i < words.size(); i++) {
            int curr[26] = {0};
            for(char ch : words[i]) {
                curr[ch - 'a']++;
            }

            // Keep minimum frequency
            for(int j = 0; j < 26; j++) {
                freq[j] = min(freq[j], curr[j]);
            }
        }

        // Build result using the frequencies
        vector<string> result;
        for(int i = 0; i < 26; i++) {
            while(freq[i]--) {
                char ch = 'a' + i;
                result.push_back(string(1, ch));
            }
        }

        return result;
    }
};



int main() {
    vector<string> words = {"bella", "label", "roller"};

    Solution sol;
    vector<string> ans = sol.commonChars(words);

    cout << "Common characters:\n";
    for (auto &s : ans) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}