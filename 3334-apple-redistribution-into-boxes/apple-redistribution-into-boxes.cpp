class Solution {
    // TC : O(m log m)
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int sum = 0;
        for(int & x : apple){
            sum+=x;
        }
        int boxes=0;
        int m = capacity.size();
        for(int j=m-1;j>=0 && sum>0;j--){
            sum -= capacity[j];
            boxes++;
        }
        return boxes;
    }
};