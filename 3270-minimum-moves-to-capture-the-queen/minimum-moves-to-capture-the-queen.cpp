class Solution {
public:
    int color(int x, int y)
    {
        x+=y;
        if (x%2==0)
        {
            return 1;
        }else
        {
            return -1;
        }
    }

    int bishop(int rx, int ry, int bx, int by, int qx, int qy, int bi)
    {
        cout<<"Inside Bishop:"<<endl;
        int ro = color(rx,ry);

        if (ro!=bi) //if rook and bishop are on different colors
        {
            cout<<"If rook & bishop lie on diff colors"<<endl;
            if (abs(qx-bx) == abs(qy-by)) {
                //if queen is on bishop's diagonal 
                cout<<"Queen and Bishop on same diagonal"<<endl;
                cout<<"Bishop captures queen - moves = 1"<<endl;
                return 1;
            }
            else {   //bishop takes one extra step to kill queen
                cout<<"Bishop takes a detour and captures queen - moves = 2"<<endl;
                return 2;
            }
        }

        else
        {
            cout<<"If rook & bishop lie on same colors"<<endl;
            if (abs(qx-bx) == abs(qy-by)) //if queen is on the bishops diagonal
            {
                //rook bishop queen same color.
                //edge case when rook is in our attacking line
                cout<<"Queen and Bishop on same diagonal"<<endl;
                if (abs(rx-bx)==abs(ry-by) && abs(rx-qx)==abs(ry-qy) && (abs(rx-qx)+abs(rx-bx) == abs(qx-bx))) //if rook is on the attacking diagonal of the bishop
                {
                    cout<<"Rook in between queen and bishop, hence a detour - moves = 2"<<endl;
                    return 2;
                }else  //if rook is not on the attacking diagonal and in between the queen and bishop
                {
                    cout<<"Nothing bewteen queen and bishop"<<endl;
                    cout<<"bishop captures queen - moves = 1"<<endl;
                    return 1; //since queen is already on bishop's diagonal
                }


            }else //if queen is not on bishops diagonal
            {
                cout<<"Queen and bishop lie on different diagonals"<<endl;
                return 4; //arbitary non-min value
            }
        }
    }

    int rook(int rx, int ry, int bx, int by, int qx, int qy)
    {
        //if rook is on same horizontal axis as queen
        if (rx==qx)
        {
            if (bx==rx && ((by>ry && by<qy) || (by>qy && by<ry)))//bishop in rook's attacking line
            {
                //in this case, we remove the bishop from attacking line and capture
                return 2;
            }
            else
            {
                return 1;
            }
        }
        
        //if rook is on the same vertical axis as queen
        else if (ry==qy)
        {
            if (by==ry && ((bx>rx && bx<qx) || (bx>qx && bx<rx)))//bishop in rook's attacking line
            {
                //in this case, we remove the bishop from attacking line and capture
                return 2;
            }
            else
            {
                return 1;
            }

        }
        else//wide case covering possiblities when rook and queen are on different x/y
        {
            return 2;
            //hoping this works

        }
    }
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        //rook - a b
        //bishop - c d
        //queen - e f

        /*

horizontal:   X
1
2
3

horizontal:   Y
1 2 3 4

        */

        int bi = color(c,d);
        int ro = color(a,b);
        int q = color(e,f);
        int m = 3;
        if (bi==q)
        {
            cout<<"Inside if: "<<endl;
            m = min(m,bishop(a,b,c,d,e,f,bi));
        }

        m = min(m,rook(a,b,c,d,e,f));

        return m;
    }
};