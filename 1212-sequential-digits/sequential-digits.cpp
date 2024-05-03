class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int cntlow = 0;
        int cnthigh = 0;


        cntlow = to_string(low).size();
        cnthigh = to_string(high).size();
        //cout<<cntlow<<" "<<cnthigh<<endl;
        vector<int> ans;


        int cnt = 0;
        for (int sz = cntlow; sz <= cnthigh; sz++)
        {
          //  cout<<"for sz = "<<sz<<endl;
            int k = 1;

            while (k <= 10-sz)
            {
                string curr = "";
                int z = k;
                for (int i = 0; i < sz; i++)
                {
                    curr += (char('0' + z));
                    z++;
                }
                

                int curr_int = stoi(curr);
                if (curr_int >= low && curr_int <= high)
                {
                    //cout<<"for curr_int = "<<curr_int<<endl;
                    ans.push_back(curr_int);
                    cnt++;
                }
                k++;
            }
            //cout<<endl;
        }


        return ans;


    }
};