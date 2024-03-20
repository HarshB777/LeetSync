class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(),0);
        int cnt = 0;
        int prev=0;
        for(int i = 0;i<boxes.size();i++){
            prev = prev + cnt;
            ans[i]+=prev;
            if(boxes[i]=='1')
            cnt++;
        }
        prev = 0;
        cnt = 0;
        for(int i = boxes.size()-1;i>=0;i--){
            prev = prev + cnt;
            ans[i]+=prev;
            if(boxes[i]=='1')
            cnt++;
        }
        return ans;
    }
};