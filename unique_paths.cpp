#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int paths=0;
int n=3;
vector<vector<int>> visited(3,vector<int>(3,0));

void count_paths(int x,int y){
    if(y==n-1 && x==n-1){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(!visited[i][j]) {
                    // cout<<i<<" "<<j<<endl;
                    return;
                }
        paths++;
        return;
    }
    if(x>0 && !visited[x-1][y]){
        
        visited[x-1][y]=1;
        count_paths(x-1,y);
        visited[x-1][y]=0;
    }
    if(x<n-1 && !visited[x+1][y]){
        visited[x+1][y]=1;
        count_paths(x+1,y);
        visited[x+1][y]=0;
    }
    if(y>0 && !visited[x][y-1]){
        visited[x][y-1]=1;
        count_paths(x,y-1);
        visited[x][y-1]=0;
    }
    if(y<n-1 && !visited[x][y+1]){
        visited[x][y+1]=1;
        count_paths(x,y+1);
        visited[x][y+1]=0;
    }
}

int main(){
    visited[0][0]=1;
    visited[0][1]=1;
    count_paths(0,1);
    cout<<paths*2<<endl;

}