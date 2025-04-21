class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long cur=0;
        long long maxx = 0, minn = 0;
        for(int i=0;i<differences.size();i++){
            cur += differences[i];
            maxx = max(maxx, cur);
            minn = min(minn, cur);
        }
        if(upper-lower < maxx-minn) return 0;
        return (upper-lower+1) - (maxx-minn);

    }
};