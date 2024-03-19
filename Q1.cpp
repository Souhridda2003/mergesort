#include<iostream>
#include<vector>
using namespace std;
void mergesort(vector<int>&v,vector<int>&a,vector<int>&b){
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>=b[j]){
            v[k++]=a[i++];
        }
        else{
            v[k++]=b[j++];
        }
    }
    if(i==a.size()){
        while(j<b.size()){
        v[k++]=b[j++];
        }
    }
    if(j==b.size()){
        while(i<a.size()){
        v[k++]=a[i++];
        }
    }
}
void merge(vector<int>&v){
    int n=v.size();
    if(n==1){
        return;
    }
    int n1=n/2;
    int n2=n-n/2;
    vector<int>a(n1),b(n2);
    for(int i=0;i<a.size();i++){
        a[i]=v[i];
    }
    for(int i=0;i<b.size();i++){
        b[i]=v[i+n1];
    }
    merge(a);
    merge(b);
    mergesort(v,a,b);
    a.clear();
    b.clear();
}
int main(){
    int a[]={5,4,3,2,1,7,6,9};
    int n=sizeof(a)/sizeof(a[0]);
    vector <int>v(a,a+n);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    merge(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}