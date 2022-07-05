#include<iostream>
#include<string>
using namespace std;
int main()
{
    char n[10],copy[10];
    cin>>n;
    strcpy(copy,n);
    char temp;
    int i;
    int l=n.length();
    for(int j=0, i=l-1;j<i;j++,i--)
    {
        temp=n[i];
        n[i]=n[j];
        n[j]=temp;
        
    }
    n[l]='\0';
    
    cout<<n;
    return 0;
}