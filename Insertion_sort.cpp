#include<bits/stdc++.h>
using namespace std;
int insertion_sort(int arr[],int n){
    int i,j,key;
    for(j=1;j<n;j++){
        key = arr[j];
        i=j-1;
        while (arr[i]>key){
            arr[i+1]=arr[i];
            i=i-1;
            arr[i+1]=key;
        }
    }
}
int main(){
int n,key,j,i;
    cout<<"enter the size of an array: ";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    for(i=0;i<n;i++){
        cout<<arr[i]<<endl;

    }

}
