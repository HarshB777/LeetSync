class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int c = 1; //time taken to collect
        int gs = g.size(); //garbage size
        vector<vector<int>> vec(gs,vector<int> (3,0));
        vector<int> last(3,-1);
        // [ G P M]

        for (int i = 0; i < gs; i++)
        {
            for (char y: g[i])
            {
                if (y == 'G')
                {
                    vec[i][0]++;
                    last[0] = i;
                }
                else if (y == 'P')
                {
                    vec[i][1]++;
                    last[1] = i;
                }
                else if (y == 'M')
                {
                    vec[i][2]++;
                    last[2] = i;
                }
            }
        }

        int time = 0;
        for (int i = 0; i < gs; i++)
        {
            //garbage truck
            int flag = 0;
            if (i <= last[0])
            {
                time += vec[i][0];
                if (i!=last[0])
                    flag++;
            }
            
            if (i <= last[1]){
                time += vec[i][1];
                if (i!=last[1])
                    flag++;
            }

            if (i <= last[2])
            {
                time += vec[i][2];
                if (i!=last[2])
                    flag++;
            }
            if (flag == 0)
            {
                break;
            }
            
            if (i==gs-1)
            {
                break;
            }
            time += flag*(t[i]);
            
        }   

        return time;
    }
};