#include<iostream>
using namespace std;

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    while(n != 1){
        if(n & 1){
            n = (3*n + 1)/2;
        } else{
            n = n / 2;
        }
        ans++;
    }
    printf("%d", ans);
    return 0;
}