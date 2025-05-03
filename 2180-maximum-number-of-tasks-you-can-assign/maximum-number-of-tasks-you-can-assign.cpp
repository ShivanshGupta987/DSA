class Solution {
    // TC : O( N*log N + M*log M + min(M, N)* log^2(min(M,N)))
    // SC : O(log N + log M + min(M,N))

    bool solve(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int n = tasks.size();
        int m = workers.size();
        multiset<int>ws;

        for(int i=m-mid; i<m; i++){
            ws.insert(workers[i]);
        }

        for(int i=mid-1; i>=0; i--){
            auto it = prev(ws.end());
            if(*it >= tasks[i]){
                ws.erase(it);
            }
            else{
                if(pills==0) return false;
                auto itr = ws.lower_bound(tasks[i]-strength);
                if(itr==ws.end()) return false;
                ws.erase(itr);
                pills--;
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int n = tasks.size();
        int m = workers.size();
        
        int left = 1, right = min(m, n), ans = 0;

        while(left <= right){
            int mid = left + (right-left)/2;
            if(solve(tasks, workers, pills, strength, mid)){
                ans = mid; 
                left = mid+1;
            }
            else right = mid-1;
        }


        return ans;
    }
};