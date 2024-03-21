class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int r = score.size();
        int c = score[0].size();

        unordered_map<int,int> hm; //val,idx;
        vector<int> temp;

        for (int i = 0; i < r; i++)
        {
            hm[score[i][k]] = i;
            temp.push_back(score[i][k]);
        }

        sort(temp.begin(),temp.end());
        int last = r-1;

        //auto it = hm.end();
        vector<vector<int>> ans;
        for (int i = 0; i < r; i++)
        {

            int crow = hm[temp[last]];
            last--;
            ans.push_back(score[crow]);
        }

        return ans;
    }
};