class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n =barcodes.size();
        vector<int>freq(10001,0);
        for(int i =0;i<n;i++){
            freq[barcodes[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(int i =1;i<=10000;i++){
            if(freq[i]!=0){
            pq.push({freq[i],i});
            }
        }
        vector<int>ans;
        int k;
        while(!pq.empty()){
             k =2;
            vector<pair<int,int>>help(2);
            while(k>0&&!pq.empty()){
                int fre=pq.top().first;
                int val=pq.top().second;
                pq.pop();
                ans.push_back(val);
                fre--;
               
                k--;
                 if(fre!=0){
                   help[k]={fre,val};
                }
            }
             for(int i =0;i<2;i++){
                if(help[i].first!=0){
                    pq.push(help[i]);
                }
                
             }
        }
        return ans ;
    }
};