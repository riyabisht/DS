#include<bits/stdc++.h>
using namespace std;
int SCS(string A,string B,int n, int m){
    
    if(n==0 && m==0)
        return 0;
    if(n==0||m==0)
        return (n)?n:m;
    if(A[n-1]==B[m-1])
        return 1+SCS(A,B,n-1,m-1);
    else
        return 1+ min(SCS(A,B,n-1,m),SCS(A,B,n,m-1));
}

int main(){
    string A;
    string B;
    A = "brute";
    B = "groot";
    cout<<SCS(A,B,A.size(),B.size());
    return 0 ;
}