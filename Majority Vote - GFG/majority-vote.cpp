//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
    
        // There can be atmost 2 elements having cnt > floor(n/3)
        // hence we are maintaining 2 variables to capture the 2 possible majority element
        int first = INT_MAX , second = INT_MAX;
        int cnt1 = 0, cnt2 = 0;

        for(auto & x : nums){
            // if it matches with first element increase cnt1
            if(x==first) cnt1++;
            // if it matches with second element increase cnt2
            else if(x==second) cnt2++;

            // now minority element has dominated the frequency(cnt1) of majority element "first" hence we can safely say for now "first" element can't be a majority element and giving chance to a new element
            else if(cnt1==0){
                first = x;
                cnt1++;
            }
            else if(cnt2==0){
                second = x;
                cnt2++;
            }

            // since x is a minority element hence we don't know the frequecny of which one of possible two majority elements will get dominated by minority elements 
            // hence we decrease the frequecy of both possible majority elements
            else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int>res;
        cnt1=0,cnt2=0;
        for(auto & x : nums){
            if(first==x) cnt1++;
            if(second==x) cnt2++;
        }
        if(cnt1>n/3) res.push_back(first);
        if(cnt2>n/3) res.push_back(second);
        if(res.empty()) return {-1};
        else return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends