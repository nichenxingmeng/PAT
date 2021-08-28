#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100010;

struct Student{
	int id, defen, caifen;
}stu1[maxn], stu2[maxn], stu3[maxn], stu4[maxn];

bool cmp(Student a, Student b){
	if(a.defen + a.caifen == b.defen + b.caifen){
		if(a.defen != b.defen) return a.defen > b.defen;
		else return a.id < b.id;
	} else return a.defen + a.caifen > b.defen + b.caifen; 
}

int main(){
	int N, L, H;
	scanf("%d %d %d", &N, &L, &H);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	int id, defen, caifen;
	for(int i = 0; i < N; i++){
		scanf("%d %d %d", &id, &defen, &caifen);
		if(defen < L || caifen < L) continue;
		if(defen >= H && caifen >= H){
			stu1[cnt1].id = id;
			stu1[cnt1].defen = defen;
			stu1[cnt1].caifen = caifen;
			cnt1++;
		} else if(defen >= H && caifen < H){
			stu2[cnt2].id = id;
			stu2[cnt2].defen = defen;
			stu2[cnt2].caifen = caifen;
			cnt2++;
		} else if(defen >= caifen){
			stu3[cnt3].id = id;
			stu3[cnt3].defen = defen;
			stu3[cnt3].caifen = caifen;
			cnt3++;
		} else{
			stu4[cnt4].id = id;
			stu4[cnt4].defen = defen;
			stu4[cnt4].caifen = caifen;
			cnt4++;
		}
	}
	sort(stu1, stu1 + cnt1, cmp);
	sort(stu2, stu2 + cnt2, cmp);
	sort(stu3, stu3 + cnt3, cmp);
	sort(stu4, stu4 + cnt4, cmp);
	printf("%d\n", cnt1 + cnt2 + cnt3 + cnt4);
	for(int i = 0; i < cnt1; i++){
		printf("%d %d %d\n", stu1[i].id, stu1[i].defen, stu1[i].caifen);
	}
	for(int i = 0; i < cnt2; i++){
		printf("%d %d %d\n", stu2[i].id, stu2[i].defen, stu2[i].caifen);
	}
	for(int i = 0; i < cnt3; i++){
		printf("%d %d %d\n", stu3[i].id, stu3[i].defen, stu3[i].caifen);
	}
	for(int i = 0; i < cnt4; i++){
		if(i < cnt4 - 1) printf("%d %d %d\n", stu4[i].id, stu4[i].defen, stu4[i].caifen);
		else printf("%d %d %d", stu4[i].id, stu4[i].defen, stu4[i].caifen);
	}

	system("pause");
	return 0;
}