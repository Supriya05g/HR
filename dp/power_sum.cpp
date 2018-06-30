#include <bits/stdc++.h>

using namespace std;

int nthroot(int X,int N){
    int res=pow(X,1.0/N);
    // if(pow(res,N)==X)
    return res;
    // return res+1;
}

// Complete the powerSum function below.
int powerSum(int X, int N) {
    vector<int> numways(X+1);
    numways[0]=1;
    for(int i=1;i<pow(X,1.0/N)+1;i++){
        int num=pow(i,N);
        for(int j=X;j>=num;j--){
            numways[j]+=numways[j-num];
            
        }
    }
    return numways[X];
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    // fout << result << "\n";
    cout<<result;

    // fout.close();

    return 0;
}
