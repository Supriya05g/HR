// The edit distance or Levenshtein distance is the minimum number of edit operations needed to transform a string into another string.
// Allowed operations 
// 1) Insert a character
// 2) Remove a character
// 3) Modify a character


#include<bits/stdc++.h>

using namespace std;

int min_distance(string a, string b){
    int n=a.length();
    int m=b.length();
    vector<vector<int>> distance(n+1,vector<int>(m+1));
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                distance[i][j]=i+j;
                cout<<distance[i][j]<<" ";
                continue;
            }
            distance[i][j]=min(distance[i-1][j]+1,distance[i][j-1]+1);
            if(a[i-1]==b[j-1])
                distance[i][j]=min(distance[i][j],distance[i-1][j-1]);
            else
                distance[i][j]=min(distance[i][j],distance[i-1][j-1]+1);
            cout<<distance[i][j]<<" ";
        }
        cout<<"\n";
    }
    

    
    return distance[n][m];
}

int main(){
    cout<<min_distance("LOVE","MOVIE");
}