/*
You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

Count the occurrences of all elements in the array.
Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
Calculate the sum of the resulting array.
Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long findXSumOfSubarray(unordered_map<int, int>& freq, int x) {
        long long sum = 0;

        priority_queue<pair<int, int>> maxHeap;
        for (auto& p : freq) {
            maxHeap.push({p.second, p.first});
        }

        for (int i = 0; i < x; i++) {

            if (!maxHeap.empty()) {
                auto [f, v] = maxHeap.top();

                sum += (long long)f * v;

                maxHeap.pop();
            }
        }

        return sum;
    }

    vector<long long> findXSum_1(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> result;

        unordered_map<int, int> freq;

        for (int i = 0; i < k - 1; i++) {
            freq[nums[i]]++;
        }

        for (int i = 0; i < (n - k + 1); i++) {
            int left = i;
            int right = i + k - 1;
            
            freq[nums[right]]++;
            
            result.push_back(findXSumOfSubarray(freq, x));

            freq[nums[left]]--;
            
        }

        return result;
    }

public:

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        
        vector<long long> result;

        unordered_map<int, int> freq;

        using entry = pair<int, int>;
        auto cmp = [](const entry &a, const entry &b){
            if(a.first != b.first){
                return a.first > b.first;                
            }

            return a.second > b.second;
        };


        multiset<entry ,decltype(cmp)> top(cmp);
        multiset<entry, decltype(cmp)> rest(cmp);


        long long runningSum = 0;
    

        auto removePair = [&](int freq, int val){
            entry e = {freq, val};
            auto it = top.find(e);

            if(it != top.end()){
                runningSum -= (long long)freq * val;
                top.erase(it);
            }else{
                it = rest.find(e);
                if(it != rest.end()){
                    rest.erase(it);
                }
            }
        };

        auto insertPair = [&](int freq, int val){
            entry e = {freq, val};

            if((int)top.size() < x){
                top.insert(e);
                runningSum += 1LL*freq*val;
            }else{
                auto worstTop = prev(top.end());

                if(cmp(e, *worstTop)){
                    runningSum -= (long long)worstTop -> first * worstTop -> second;

                    rest.insert(*worstTop);
                    top.erase(worstTop);

                    top.insert(e);
                    runningSum += (long long)freq*val;

                }else{
                    rest.insert(e);
                }
            }
        };

        auto balanceTop = [&](){
            while((int)top.size() > x){
                auto it = prev(top.end());
                runningSum -= (long long)it -> first * it -> second;
                rest.insert(*it);
                top.erase(it);
            }
        };

        auto promote = [&](){
            if(!rest.empty() && (int)top.size() < x){
                auto it = rest.begin();

                runningSum += (long long)it->first * it->second;

                top.insert(*it);
                rest.erase(it);

            }
        };

        for(int i = 0; i < nums.size(); i++){
            int value = nums[i];

            int old = freq[value];

            if(old > 0){
                removePair(old, value);
            }

            freq[value] = old + 1;

            insertPair(old + 1, value);
            balanceTop();
            promote();

            if(i >= k){
                int oldVal = nums[i - k];
                int oldFreq = freq[oldVal];

                removePair(oldFreq, oldVal);

                if(oldFreq == 1){
                    freq.erase(oldVal);
                }else{
                    freq[oldVal] = oldFreq - 1;

                    rest.insert({oldFreq - 1, oldVal});

                }

                balanceTop();
                promote();

            }

            if( i + 1 >= k){
                result.push_back(runningSum);
            }
        }

        return result;
    }

};




int main() {
    

    vector<int> nums = {1,1,2,2,3,4,2,3};
    int k = 6;
    int x = 2;

    Solution sobj;

    vector<long long> result = sobj.findXSum(nums, k, x);

    cout << "Output: ";
    for(long long val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}