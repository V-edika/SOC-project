class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            if (nums[mid] == target)
                first = mid;
        }
        l = 0;  r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            if (nums[mid] == target)
                last = mid;
        }
        return {first, last};
    }
};
