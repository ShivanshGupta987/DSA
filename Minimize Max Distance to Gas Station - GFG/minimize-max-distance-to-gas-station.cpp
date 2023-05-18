//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // class comp{
    //   public :
    //     bool operator()(const vector<int>& a, const vector<int>& b){
    //         return (1.0*a[0]/a[1])+ 1e-6 < (1.0*b[0]/b[1]); 
    //     }
    // };
    bool isPossible(vector<int>& stations, double x, int k){
        int cnt=0;
        for(int i=1;i<stations.size();i++){
            cnt += int((stations[i]-stations[i-1])/x);
        }
        return cnt<=k;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int k){
      // Code here
        double l=0, r=1e9;
        double delta = 1e-5;
        while(r-l>delta){
            double mid = (l+r)/2.0;
            if(isPossible(stations,mid,k)){
                r=mid;
            }
            else l=mid;
        }
        return l+delta;
      
    }
};
    
// ----------- USING MAX HEAP ---------------   

// priority_queue<vector<int>,vector<vector<int>>,comp>pq;
//       double max_dist=0;
//       for(int i=1;i<stations.size();i++){
//           pq.push(vector<int>{stations[i]-stations[i-1],1});
       
//       }
    
//       while(k--){
//           vector<int>v = pq.top();
//           pq.pop();
//           v[1]++;
//           pq.push(v);
//       }
//       return (double)pq.top()[0]/pq.top()[1];

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends