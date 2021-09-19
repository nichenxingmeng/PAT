#include<iostream>
using namespace std;

const int maxn = 10010;

int father[maxn], isRoot[maxn];

int find(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b){
	int faA = find(a);
	int faB = find(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

int main(){
	int n, k, t, Q, a, b, pic[maxn] = {0};
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
    fill(isRoot, isRoot + maxn, 0);
	for(int i = 1; i <= n; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
            scanf("%d", &t);
            if(pic[t] == 0) pic[t] = i;
			Union(i, find(pic[t]));
		}
	}
    
    for(int i = 1; i <= n; i++){
        isRoot[find(i)]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(isRoot[i] != 0) cnt++;
    }
    printf("%d ", cnt);
    int ans = 0;
    for(int i = 1; i < maxn; i++){
        if(pic[i] != 0) ans++;
    }
    printf("%d\n", ans);
    scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		scanf("%d%d", &a, &b);
		if(find(pic[a]) == find(pic[b])){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}

	return 0;
}