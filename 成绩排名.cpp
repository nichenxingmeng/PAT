#include<iostream>
using namespace std;

struct student{
	char name[11];
	char num[11];
	int grade;
}stu[100000];

int main(){
	int n;
	scanf("%d", &n);
	int max = -1, min = 101, temp_max, temp_min;
	for(int i = 0; i < n; i++){
		scanf("%s %s %d", stu[i].name, stu[i].num, &stu[i].grade);
		if(stu[i].grade > max){
			temp_max = i;
			max = stu[i].grade;
		}
		if(stu[i].grade < min){
			temp_min = i;
			min = stu[i].grade;
		}
	}
	printf("%s %s\n", stu[temp_max].name, stu[temp_max].num);
	printf("%s %s", stu[temp_min].name, stu[temp_min].num);

	system("pause");
	return 0;
}