#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 200010;

int n, m, s1[maxn], s2[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &s1[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &s2[i]);
	}
	int ans;
	if((n + m) & 1){
		ans = (n + m) / 2 + 1;
	} else{
		ans = (n + m) / 2; 
	}
    if(n != 0 && m != 0){
        int cnt = 0, i = 0, j = 0;
	    while(cnt < ans){
		    if((s1[i] <= s2[j] && i < n) || (j >= m)){
			    i++;
			    cnt++;
		    } else if((s1[i] >= s2[j] && j < m) || (i >= n)){
			    j++;
			    cnt++;
		    }
	    }
	    cout << max(s1[i - 1], s2[j - 1]) << endl;
    } else if(n == 0){
        cout << s2[ans - 1] << endl;
    } else{
        cout << s1[ans - 1] << endl;
    }

	return 0;
}