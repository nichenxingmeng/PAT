#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1010;
int num[maxn];
vector<int> A1;
vector<int> A2;
vector<int> A3;
vector<int> A4;
int A5 = 0;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
		if(num[i] % 5 == 0 && !(num[i] & 1)) A1.push_back(num[i]);
		else if(num[i] % 5 == 1) A2.push_back(num[i]);
		else if(num[i] % 5 == 2) A3.push_back(num[i]);
		else if(num[i] % 5 == 3) A4.push_back(num[i]);
		else if(num[i] % 5 == 4 && num[i] > A5) A5 = num[i];
	}

	if(A1.empty()) printf("N ");
	else{
		int ans1 = 0;
		for(int i = 0; i < A1.size(); i++){
			ans1 += A1[i];
		}
		printf("%d ", ans1);
	}

	if(A2.empty()) printf("N ");
	else{
		int ans2 = 0;
		for(int i = 0; i < A2.size(); i++){
			if(i & 1) ans2 -= A2[i];
			else ans2 += A2[i];
		}
		printf("%d ", ans2);
	}

	if(A3.empty()) printf("N ");
	else printf("%d ", A3.size());

	if(A4.empty()) printf("N ");
	else{
		double ans4 = 0;
		for(int i = 0; i < A4.size(); i++){
			ans4 += A4[i];
		}
		ans4 /= A4.size();
		printf("%.1f ", ans4);
	}

	if(!A5) printf("N");
	else printf("%d", A5);

	system("pause");
	return 0;
}