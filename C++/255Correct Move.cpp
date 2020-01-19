#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int king, krow, kcol;
    int queen, qrow, qcol;
    int nextpos, nrow, ncol;
    bool find;
    int currow, curcol;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    
    while(cin>>king>>queen>>nextpos){
        // the given state is not legal
        if(king==queen){
            cout << "Illegal state" << endl;
            continue;
        }
        krow=king>>3;
        kcol=king&7;
        qrow=queen>>3;
        qcol=queen&7;
        nrow=nextpos>>3;
        ncol=nextpos&7;
        
        find=false;
        for(int i=0; i<4; i++){
            currow=qrow+dir[i][0];
            curcol=qcol+dir[i][1];
            while(currow>=0 && currow<8 && curcol>=0 && curcol<8 && (currow!=krow || curcol!=kcol)){
                if(currow==nrow && curcol==ncol){
                    find=true;
                    break;
                }
                currow+=dir[i][0];
                curcol+=dir[i][1];
            }
            if(find) break;
        }
        if(!find){
            cout << "Illegal move" << endl;
            continue;
        }

        find=false;
        for(int i=0; i<4; i++){
            currow=krow+dir[i][0];
            curcol=kcol+dir[i][1];
            if(currow>=0 && currow<8 && curcol>=0 && curcol<8){
                if(currow==nrow && curcol==ncol){
                    find=true;
                    break;
                }
            }
        }
        if(find){
            cout << "Move not allowed" << endl;
            continue;
        }

        for(int i=0; i<4; i++){
            currow=krow+dir[i][0];
            curcol=kcol+dir[i][1];
            find=false;
            if(currow>=0 && currow<8 && curcol>=0 && curcol<8){
                if(currow==nrow || curcol==ncol)
                    find=true;
                if(!find) break;
            }
            else find=true;
        }
        if(!find) cout << "Continue" << endl;
        else cout << "Stop" << endl;
    }
    return 0;
}
