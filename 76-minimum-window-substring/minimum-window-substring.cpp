class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty())  return "";

        unordered_map<char, int> have, need;

        for(char c : t){
            need[c] += 1;
        }

        int haveCount = 0, needCount = need.size();

        pair<int, int> res = {-1,-1};

        int resLen = INT_MAX;
        
        int l = 0, r = 0;

        while(r < s.length()){
            char ch = s[r];

            have[ch] += 1;


            if(need.count(ch) && have[ch] == need[ch] ){
                haveCount += 1;
            }

            while( haveCount == needCount ){
                if( (r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l, r};
                }

                have[s[l]] -= 1;
                if(need.count(s[l]) && have[s[l]] < need[s[l]]){
                    haveCount -= 1;
                }

                l++;
            }

            r++;
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
