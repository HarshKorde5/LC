/*
You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res = {words[0]};

        int n = words.size();

        auto compare = [](const string& s, const string& t) -> bool{
            vector<int> freq(26);
            for(char ch : s){
                ++freq[ch - 'a'];
            }
            for(char ch : t){
                --freq[ch - 'a'];
            }

            return all_of(freq.begin(), freq.end(), [](int x){ return x == 0; });
        };

        for(int i = 1; i < n; i++){
            if(compare(words[i], words[ i - 1])){
                continue;
            }
            res.push_back(words[i]);
        }

        return res;
    }

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> counter;

        for (char ch : s) {
            counter[ch] = counter[ch] + 1;
        }

        for (char ch : t) {
            if (counter.find(ch) == counter.end() || counter[ch] == 0) {
                return false;
            }
            counter[ch] = counter[ch] - 1;
        }

        return true;        
    }

    vector<string> removeAnagrams_1(vector<string>& words) {
        
        vector<string> result;

        int i = 0, j = 1;
        int n = words.size();

        while(i < n){
            while(j < n && isAnagram(words[i], words[j])){
                j++;
            }

            result.push_back(words[i]);

            i = j;
            j = i + 1;
        }

        return result;
    }


};

int main(){

    Solution sobj;
    vector<string> words = {"abba","baba","bbaa","cd","cd"};

    vector<string> result = sobj.removeAnagrams(words);

    for(string s : result){

        cout<<s<<endl;
    }

    return 0;
}