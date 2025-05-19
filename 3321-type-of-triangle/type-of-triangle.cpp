class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1], c = nums[2];
        if(c >= a + b) return "none";
        if(a==b && b==c) return "equilateral";
        else if(a==b || b==c) return "isosceles";
        else return "scalene";
    }
};