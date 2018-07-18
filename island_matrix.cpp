// https://www.hackerrank.com/contests/code-massacre/challenges/islands-in-a-matrix/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool issafe(vector<vector<int>> &matrix,vector<vector<bool>> &visited,int row,int col){
    int n=matrix.size();
    int m=matrix[0].size();
    return (row>=0 && row<n && col>=0 && col<m && (matrix[row][col] && !visited[row][col]));
}

void DFS(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col){
    static int row_ind[8]={-1,-1,-1,0,0,1,1,1};
    static int col_ind[8]={-1,0,1,-1,1,-1,0,1};
    
    // if(visited[row][col])
    //     return;
    
    visited[row][col]=true;
    for(int i=0;i<8;i++)
        if(issafe(matrix,visited,row+row_ind[i],col+col_ind[i]))
            DFS(matrix,visited,row+row_ind[i],col+col_ind[i]);
}

int getcount(vector<vector<int>> &matrix){
    vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
    int count=0;
    cout<<matrix.size()<<endl<<matrix[0].size()<<endl;
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j] && !visited[i][j]){
                DFS(matrix,visited,i,j);
                count++;
            }
        }
    return count;
            
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    
    cout<<getcount(matrix);
    return 0;
}
