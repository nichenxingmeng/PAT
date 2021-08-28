#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int num[100000];
bool num_[100000] = {false};
bool flag[100000] = {false};

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	
	int num_i;
	for(int i = 0; i < n; i++){
		if(num[i] == 0) continue;
		num_i = num[i];
		while(num_i != 1){
			if(flag[num_i]){
				flag[num[i]] = true;
				break;
			}
			if(num_i & 1){
				num_i = (3*num_i + 1)/2;
			} else{
				num_i = num_i / 2;
			}
			num_[num_i] = true;
		}
		flag[num[i]] = true;
	}
	sort(num, num + n, cmp);
	
	vector<int> ans;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(!num_[num[i]] && num[i] != 0){
			ans.push_back(num[i]);
			cnt++;
		}
	}
	for(int i = 0; i < cnt; i++){
		if(i != cnt - 1) printf("%d ", *(ans.begin() + i));
		else printf("%d", *(ans.begin() + i));
	}

	system("pause");
	return 0;
}