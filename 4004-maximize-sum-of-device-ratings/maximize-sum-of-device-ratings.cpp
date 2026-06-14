class Solution {
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[1]<b[1];
    }
public:
    long long maxRatings(vector<vector<int>>& units) {
        

        long long ans = 0;
        vector<vector<int>>devices;
        for(auto &unit: units){
            sort(unit.begin(), unit.end());
            if(unit.size()>1) devices.push_back(unit);
            else ans += unit[0];
        }

        if(devices.empty()) return ans;
        
        sort(devices.begin(), devices.end(), comp);
        int n = devices.size();
        int sm = devices[0][0];
        for(int i=1;i<n;i++){
            sm = min(sm, devices[i][0]);
            ans += devices[i][1];
        }
        ans += sm;
        return ans;
       
        
    }
};