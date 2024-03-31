class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = 0;
        int empty = 0;
        
        drank += numBottles;
        empty += numBottles;
        numBottles = 0;
       
        
        
        
        while (empty >= numExchange)
        {
            empty -= numExchange;
            numBottles += 1;
            numExchange++;
            
            
            drank += numBottles;
            empty += numBottles;
            numBottles = 0;
          
        }
       
        
        return drank;
     
    }
};