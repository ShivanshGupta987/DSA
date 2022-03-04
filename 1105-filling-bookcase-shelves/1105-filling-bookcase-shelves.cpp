class Solution {
        // TC : O(N*M)
        // N -> no. of books // M -> shelfWidth
        // SC : O(N)
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
            int n = books.size();
            vector<int>height(n+1);
            
            for(int i=1;i<=n;i++){
                    // choice 1 
                    // put it into the new shelf
                    height[i] = height[i-1] + books[i-1][1];
                    
                    // choice 2 
                    // put into current shelf 
                    // ( which can currently contain books of total sum of width <                         shelfWidth)
                    int j = i-1;
                    int width =  books[i-1][0];
                    int ht = books[i-1][1];
                    
                    while(j>0 && width + books[j-1][0]<= shelfWidth){
                            width += books[j-1][0];
                            ht = max(ht,books[j-1][1]);
                            height [i] = min( height[i] , ht + height[j-1]);
                            j--;
                    }
                    
                   
            }
            return height[n];
            
    }
};


