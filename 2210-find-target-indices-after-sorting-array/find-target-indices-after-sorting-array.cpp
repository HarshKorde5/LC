class Solution {
public:
    int firstoccurence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return first;
    }
    int lastOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return last;
    }
    vector<int> targetIndices_01(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> res;
        int first = firstoccurence(nums, target);
        if (first == -1)
            return res;

        int last = lastOccurrence(nums, target);

        for (int i = first; i <= last; i++) {
            res.push_back(i);
        }
        return res;
    }

    int bsearch(vector<int>& a, int x) {
        int l = 0;
        int r = a.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m] == x)
                return m;
            else if (a[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    vector<int> targetIndices_02(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int index = bsearch(nums, target);
        vector<int> res;
        if (index == -1)
            return {};
        int i = index - 1;
        while (i >= 0) {
            if (nums[i] == target)
                res.push_back(i);
            else
                break;
            i--;
        }
        res.push_back(index);
        i = index + 1;
        while (i < nums.size()) {
            if (nums[i] == target)
                res.push_back(i);
            else
                break;

            i++;
        }
        sort(res.begin(), res.end());
        return res;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt = 0, rank = 0;
        for(auto e: nums){
            cnt += e == target;
            rank  += e < target;
        }
        vector<int> res;
        while(cnt--){
            res.push_back(rank++);
        }
        return res;
    }
};