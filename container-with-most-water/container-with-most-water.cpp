class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
            int i=0; int j=height.size()-1;
            while(i<j){
                  
                   int max_height=max(height[i],height[j]);
                   int min_height=min(height[i],height[j]);
                   int area=(j-i)*min_height;
                   bool flag=(height[i]>=height[j])?true:false;
                   max_area=max(area,max_area);
                    
                            if(flag){j--;}
                            else{i++;}
                    
            }
     return max_area;       
    }
};