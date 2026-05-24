class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lMax = 0, rMax = 0;
        long long int water = 0;

    while (l< r) {
        if (height[l] < height[r]) {
            if (height[l] > lMax) {
                lMax = height[l];
            } else {
                water += lMax - height[l];
            }
            l++;
        } else {
            if (height[r] > rMax) {
                rMax = height[r];
            } else {
                water += rMax - height[r];
            }
            r--;
        }
    }

    return water;

    }
};
