#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct student{
	string id;
	int grade;
}stu[10010];

struct Kaochang{
	int bianhao;
	int renshu;
	Kaochang(){
		bianhao = 0;
		renshu = 0;
	}
}kaochang[1010];

bool cmp(student a, student b){
	if(a.grade != b.grade) return a.grade > b.grade;
	else return a.id < b.id;
}

bool cmp_(Kaochang a, Kaochang b){
	if(a.renshu == b.renshu) return a.bianhao  < b.bianhao;
	else return a.renshu > b.renshu;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		cin >> stu[i].id;
		scanf("%d", &stu[i].grade);
	}
	sort(stu, stu + n, cmp);

	int zhi, cnt = 1;
	string zhiling;
	bool flag1 = false, flag2 = false, flag3 = false;
    int ans2_0 = 0, ans2_1 = 0,  ans3_0 = 0;
	string temp2, temp3, temp4;
	for(int i = 0; i < m; i++){
		scanf("%d", &zhi);
		cin >> zhiling;
		if(zhi == 1){
			printf("Case %d: 1 ", cnt++);
			cout << zhiling;
			printf("\n");
			for(int i = 0; i < n; i++){
				if(stu[i].id[0] == zhiling[0]){
					cout << stu[i].id;
					flag1 = true;
					printf(" %d\n", stu[i].grade);
				}
			}
			if(!flag1) printf("NA\n");
            flag1 = false;
		} else if(zhi == 2){
			printf("Case %d: 2 ", cnt++);
			cout << zhiling;
			printf("\n");
			for(int i = 0; i < n; i++){
				temp2 = stu[i].id.substr(1, 3);
				if(temp2 == zhiling){
					ans2_0++;
					ans2_1 += stu[i].grade;
					flag2 = true;
				}
			}
			if(!flag2) printf("NA\n");
			else printf("%d %d\n", ans2_0, ans2_1);
            flag2 = false;
            ans2_0 = 0;
            ans2_1 = 0;
		} else if(zhi == 3){
			printf("Case %d: 3 ", cnt++);
			cout << zhiling;
			printf("\n");
			for(int i = 0; i < n; i++){
				temp3 = stu[i].id.substr(4, 6);
                temp4 = stu[i].id.substr(1, 3);
				if(temp3 == zhiling){
					for(int i = 0; i < 3; i++){
						ans3_0 = ans3_0 * 10 + temp4[i] - '0';
					}
					if(!kaochang[ans3_0].bianhao) kaochang[ans3_0].bianhao = ans3_0;
					kaochang[ans3_0].renshu++;
					ans3_0 = 0;
					flag3 = true;
				}
			}
			if(!flag3) printf("NA\n");
			else{
				sort(kaochang, kaochang + 1010, cmp_);
				for(int i = 0; i < 1010; i++ ){
                    if(kaochang[i].renshu == 0) break;
					printf("%d %d\n", kaochang[i].bianhao, kaochang[i].renshu);
				}
			}
            flag3 = false;
            for(int i = 0; i < 1010; i++ ){
                kaochang[i].renshu = 0;
			    kaochang[i].bianhao = 0;
			}
		} else{
            printf("Case %d: %d ", cnt++, zhi);
			cout << zhiling;
			printf("\n");
            printf("NA\n");
        }
	}

	return 0;
}