#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
   
    int i,n,sum;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    sum = 0;
    for(i=0; i<n; i++){
        sum = sum + a[i];
    }
    cout<<sum;
    return 0;
}
