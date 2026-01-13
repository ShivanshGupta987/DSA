class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total = 0;
        unordered_map<long long, long long> diff;
        for (auto& sq : squares){
            long long y = sq[1];
            long long s = sq[2];
            total += s * s;
            diff[y] += s;
            diff[y + s] -= s;
        }
        vector<long long> curr;
        curr.reserve(diff.size());
        for (auto& k : diff){
            curr.push_back(k.first);
        }
        sort(curr.begin(), curr.end());
        long long area = 0;
        long long target = 0;
        for (int i = 0; i + 1 < (int)curr.size(); i++){
            long long y = curr[i];
            long long y2 = curr[i + 1];
            target += diff[y];
            area += target * (y2 - y);
            if (area * 2 >= total){
                return (double)y2 - (double)(area * 2 - total) / (double)(target * 2);
            }
        }
        return (double)curr.back();
    }
};