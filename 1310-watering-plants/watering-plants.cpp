class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();

        int src = -1;
        int bot = capacity;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (bot >= plants[i])
            {
                cnt++;
                bot -= plants[i];
            }

            else
            {
                cnt += (i-src-1);
                bot = capacity;
                cnt += (i-src);
                bot -= plants[i];
            }


        }

        return cnt;
    }
};