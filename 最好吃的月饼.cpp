#include<iostream>
#include<algorithm>
using namespace std;

struct yuebing{
	int id, num;
	yuebing(){
		num = 0;
		id = 0;
	}
}yb[1010];

bool cmp(yuebing a, yuebing b){
	if(a.num == b.num) return a.id < b.id;
	else return a.num > b.num;
}

int main(){
	int n, m, temp;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &temp);
			yb[j].id = j + 1;
			yb[j].num += temp;
		}
	}
	sort(yb, yb + n, cmp);
	int ans = yb[0].num;
	printf("%d\n", ans);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(yb[i].num != ans) break;
		else cnt++;
	}
	for(int i = 0; i < cnt - 1; i++){
		printf("%d ", yb[i].id);
	}
	printf("%d", yb[cnt - 1].id);

	system("pause");
	return 0;
}