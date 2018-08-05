// Given an array A, find distinct prime factors of the product of all elements.

void build_spf(vector<int> &spf,int max_val){
    for(int i=1;i<=max_val;i++){
        if(i%2==0) spf[i]=2;
        else if(i%3==0) spf[i]=3;
        else spf[i]=i;
    }
    
    for(int i=4;i*i<=max_val;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=max_val;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

int Solution::solve(vector<int> &A) {
    int max_val=0;
    for(auto ele: A){
        if(ele==0) return 0;
        max_val=max(max_val,ele);
    }
        
    
    vector<int> spf(max_val+1);
    build_spf(spf,max_val);
    
    unordered_set<int> hash;
    
    for(int i=0;i<A.size();i++){
        int num=A[i];
        while(num!=1){
            hash.insert(spf[num]);
            num/=spf[num];
        }
    }
    return hash.size();
}
