class Solution {
public:
    int shoppingOffers(const vector<int>& price,const vector<vector<int>>& special,const vector<int>& needs) {
        int result = inner_product(price.begin(),price.end(),needs.begin(),0);
            
            for(const vector<int>& offers : special){
                    vector<int>new_need= update(offers,needs);
                   if(new_need.empty())continue;
                    
                   result= min (result, offers.back()+shoppingOffers(price,special, new_need));
            }
            return result;
    }
        
        vector<int> update(const vector<int>&offers,const vector<int>& needs){
                vector<int>new_need;
                int n=needs.size();
                for(int i=0;i<n;i++){
                        if(offers[i]>needs[i])return {};
                        new_need.push_back(needs[i]-offers[i]);
                }
                return new_need;
        }
};