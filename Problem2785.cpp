/*
Sort Vowels in a String
Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

*/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Returns true if the character is a vowel.
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }

    string sortVowels(string s) {
        string temp;

        // Store the vowels in the temporary string.
        for (char c : s) {
            if (isVowel(c)) {
                temp += c;
            }
        }
        
        // Sort the temporary string characters in ascending order.
        sort(temp.begin(), temp.end());

        int j = 0;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            // If the character is a vowel, replace it with the character in the string temp.
            if (isVowel(s[i])) {
                ans += temp[j];
                j++;
            } else {
                ans += s[i];
            }
        }
        
        return ans;
    }
};


int main(){

    Solution s;

    string str = "lEetcOde";
    cout<<"String before sorting vowels : "<<str<<"\n";

    string ret = s.sortVowels(str);

    cout<<"String after sorting vowels : "<<ret<<"\n";

    return 0;
}