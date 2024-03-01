class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(begin(s),end(s),'1');
        cout<<ones<<" ones"<<endl;
        int n = s.size();
        cout<<"n = "<<n<<endl;
        int zeroes = n;
        zeroes-=ones;
        cout<<zeroes<<" zeroes"<<endl;

        string res = "1";
        ones--;

        
        
        while (zeroes>0)
        {
            res+="0";
            zeroes--;
        }
        cout<<"after zeroes: "<<res<<endl;
        
        while (ones>0){
            res+="1";
            ones--;
        }

        reverse(begin(res),end(res));

        return res;
    }
};