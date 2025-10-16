#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (int num : nums) {
            sum += num;
            if (map.find(sum - k) != map.end()) {
                count += map[sum - k];
            }
            map[sum]++;
        }

        return count;
    }
    
    int subarraySum_1(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k){
                    count++;
                }
            }
        }

        return count;
    }
};

int main(){
    Solution sobj;
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << sobj.subarraySum(nums, k) << endl; // Output: 2
    return 0;
}