#include<bits/stdc++.h>
using namespace std;
int partition1(int a[],int p,int r){
    int x = a[r],i;
    i=p-1;
    for(int j=p;j<r;j++){
        if(a[j]<x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
int quick_sort(int a[],int p,int r){
    int q,ini=p,nd=r;
    if(p<r){
        q = partition1(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}
int main(){
 int n;
 cout<<"Enter size of array: ";
 cin>>n;
 int a[n],i;
 for(i=1;i<=n;i++){
    cin>>a[i];
 }
 quick_sort(a,1,n);
 cout<<"Sorted Array..."<<endl;
 for(i=1;i<=n;i++){
    cout<<a[i]<<endl;
 }
return 0;
}













