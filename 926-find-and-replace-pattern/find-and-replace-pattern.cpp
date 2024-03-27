class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       /* vector<int> hm;
        int n = pattern.size();
        int i = 0;
        int j = 0;

        while (j < n)
        {
            j = i;
            while (j <n && pattern[j]==pattern[i])
            {
                j++;
            }
            hm.push_back(j-i);
            i = j;
        }

        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            vector<int> curr;

            int m = words[i].size();
            int k = 0;
            int l = 0;
            while (l < m)
            {
                l = k;

                while (l<m && words[i][l] == words[i][k])
                {
                    l++;
                }
                curr.push_back(l-k);
                k = l;
            }

            if (hm.size() == curr.size())
            {
                if (hm == curr)
                {
                    ans.push_back(words[i]);
                }
            }
        }

        return ans;*/

/* METHOD 2
        unordered_map<char,int> hm1; //char, freq
        unordered_map<char,int> hm2; //char, idx in vector
        vector<vector<int>> vec; //vector

        int i = 0, j = 0, n = pattern.size();
        int idx = 0;

        while (j < n)
        {
            j = i;
            char curr = pattern[i];
            vec.push_back({});
            int flag = 0;
            if (hm1.find(curr)!=hm1.end())
                flag = 1; //now, we have to update in vector... not pushback
            
            while (j < n && pattern[j] == curr)
            {
                hm1[curr]++;
                j++;
            }

            if (flag != 1)
            {
                hm2[curr] = idx;
                vec[idx].push_back(hm1[curr]);
                idx++;
            }
            else
            {
                vec[hm2[curr]] = hm1[curr];
            }

            i = j;

        }

         c out<<"main pattern: "<<endl;
        for (auto x: vec)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<endl;
        

        vector <string> ans;
        for (string x: words)
        {
            unordered_map<char,int> um1; //char,freq
            unordered_map<char,int> um2; //char,idx
            vector<int> temp; //to store final vals

            int m = x.size();
            int idx2 = 0;
            int k = 0, l = 0;
            while (l < m)
            {
                l = k;
                temp.push_back({});
                char curr = x[l];
                int flag = 0;
                if (um1.find(curr)!=um1.end())
                {
                    flag = 1;
                }

                while (l < m && x[l] == curr)
                {
                    um1[curr]++;
                    l++;
                }

                if (flag != 1)
                {
                    um2[curr] = idx2;
                    temp[idx2].push_back(um1[curr]);
                    idx2++;
                }
                else
                {
                    temp[um2[curr]] = um1[curr];
                }
                k = l;

            }//end of while loop

            if (temp.size() == vec.size())
            {
                if (vec == temp)
                    ans.push_back(x);
            }


            /*cout<<"x = "<<x<<endl;
            for (auto z: temp)
            {
                cout<<z<<" ";
            }
            cout<<endl;
            cout<<endl;

            

        }



        return ans;
            end of method 2
        */


        unordered_map<int,vector<int>> hm1; //index,frequency
        unordered_map<char,int> hm2; //char,index

        int i = 0, j = 0, n = pattern.size();
        int idx = 0; //idx for characters in maps
        while (j < n)
        {
            j = i;
            char curr = pattern[i];
            int flag = 0;
            if (hm2.find(curr)!=hm2.end())
            {
                flag = 1;
            }

            while (j < n && pattern[j]==curr)
            {
                if (flag == 1)
                {
                    int curridx = hm2[curr];
                    hm1[curridx].push_back(j);
                }
                else
                {
                    hm2[curr] = idx;
                    idx++;
                    hm1[hm2[curr]].push_back(j);
                    flag = 1;
                }

                j++;
            }

            i = j;
        }
        vector<string> ans;
        for (string s: words)
        {
            unordered_map<int,vector<int>> um1; //index,frequency
            unordered_map<char,int> um2; //char,index

            int i1 = 0, j1 = 0, n1 = s.size();
            int idx1 = 0; //idx for characters in maps
            while (j1 < n1)
            {
                j1 = i1;
                char curr = s[i1];
                int flag = 0;
                if (um2.find(curr)!=um2.end())
                {
                    flag = 1;
                }

                while (j1 < n1 && s[j1]==curr)
                {
                    if (flag == 1)
                    {
                        int curridx = um2[curr];
                        um1[curridx].push_back(j1);
                    }
                    else
                    {
                        um2[curr] = idx1;
                        idx1++;
                        um1[um2[curr]].push_back(j1);
                        flag = 1;
                    }

                    j1++;
                }

                i1 = j1;
            }


            /*cout<<"for s = "<<s<<endl;
            for (auto x: um1)
            {
                cout<<x.first<<" "<<x.second.size()<<endl;
            }
            cout<<"********"<<endl;
            */

            if (hm1.size() == um1.size())
            {
                if (hm1 == um1)
                {
                    ans.push_back(s);
                }
            }
        }


        return ans;


        
    }
};