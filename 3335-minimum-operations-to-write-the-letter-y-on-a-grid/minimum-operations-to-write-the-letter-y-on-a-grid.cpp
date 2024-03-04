class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<int> cells(3,0);
        vector<int> sh(3,0);
        int r = grid.size();
        int c = grid[0].size();
        
        int mid = r/2;
        
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                
                if (i<=mid)
                {
                    if (i==j || j==r-i-1){
                        sh[grid[i][j]]++;

                    }
                }else if (i>mid)
                {
                    if (j==mid){
                        sh[grid[i][j]]++;
                      
                    }
                }
                
                cells[grid[i][j]]++;
            }
        }

        //cout<<"Outside y:"<<endl;
        for (int i = 0; i < 3; i++)
        {
            cells[i]-=sh[i];
          //  cout<<cells[i]<<" ";
        }
        //cout<<endl;

        /*cout<<"Inside y: "<<endl;
        for (auto x: sh)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        */

        int numY = r + (r/2);
        int numC = (r*r) - numY;

        int mO = INT_MAX;
        int mY = INT_MAX;
        int mC = INT_MAX;
        int delY = 0;
        int delC = 0;

        for (int i = 0; i < 3; i++)
        {
            delY = numY - sh[i];

            for (int j = 0; j < 3; j++)
            {
                if (i!=j)
                {
                    delC = numC - cells[j];

                    if (delY+delC < mO)
                    {
                        mO = delY+delC;
                    }
                }
            }
        }

        //cout<<mO<<endl;

        return mO;
        

    }
};