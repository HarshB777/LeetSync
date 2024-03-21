class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int step=0, i=0, temp=capacity;
        while(i<plants.size()-1){
            step++;
            temp-=plants[i];
            if(temp<plants[i+1]){
                step+=2*(i+1);
                temp=capacity;
            }
            i++;
        }
        return step+1;
    }
};