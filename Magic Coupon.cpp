#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> czheng;
vector<int> cfu;
vector<int> pzheng;
vector<int> pfu;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int nc, np;
    int c, p;
	scanf("%d", &nc);
	for(int i = 0; i < nc; i++){
		scanf("%d", &c);
		if(c > 0){
			czheng.push_back(c);
		} else if(c < 0){
			cfu.push_back(c);
		}
	}
	sort(czheng.begin(), czheng.end(), cmp);
    sort(cfu.begin(), cfu.end());
	scanf("%d", &np);
	for(int i = 0; i < np; i++){
		scanf("%d", &p);
		if(p > 0){
			pzheng.push_back(p);
		} else if(p < 0){
			pfu.push_back(p);
		}
	}
	sort(pzheng.begin(), pzheng.end(), cmp);
    sort(pfu.begin(), pfu.end());
	int ans = 0, cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < pfu.size(); i++){
		if(cnt1 < cfu.size()){
			ans += pfu[i] * cfu[cnt1++];
		} else break;
	}
	for(int i = 0; i < pzheng.size(); i++){
		if(cnt2 < czheng.size()){
			ans += pzheng[i] * czheng[cnt2++];
		} else break;
	}
	cout << ans;

	return 0;
}