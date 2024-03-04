class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int i = 0;
        int j = n-1;
        int score = 0;
        int maxScore = 0;
        while (i<n){
            if (tokens[i] <= power)
            {
                score++;
                power-=tokens[i];
                i++;
            }

            else if (tokens[i] > power)
            {
                if (score < 1)
                    break;
                
                power+=tokens[j];
                score--;
                j--;

            }

            maxScore = max(score,maxScore);

            cout<<"score = "<<score<<" power = "<<power<<endl;
        }



        return maxScore;
    }
};