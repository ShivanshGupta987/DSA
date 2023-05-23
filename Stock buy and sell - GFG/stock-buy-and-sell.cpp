//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    
    int start_day=0;
    int total_profit = 0;
    for(int i=1;i<n;i++){
        if(price[i]>=price[i-1] && i!=n-1)continue;
        else{
            int end_day = i-1;
            if(i==n-1 && price[i]>=price[i-1])end_day = i;
            total_profit += price[end_day]-price[start_day];
            if(start_day!=end_day){
                cout<<"("<<start_day<<" "<<end_day<<") ";
            }
            start_day = i;
        }
    }
    if(total_profit==0)cout<<"No Profit";
    cout<<"\n";
}