void get_nextval(String T, int nextval[]){
	int i = 1, j = 0;
	nextval[1] = 0;

	while(i < T.length){
		if(j = 0 || T.ch[i] == T.ch[j]){
			++i;
			++j;
			if(T.ch[i] != T.ch[j]) nextval[i] = j;
			else nextval[i] = nextval[j]; 
		} else{
			j = nextval[j];
		}
	}
}

int Index_KMP(String S, String T, int nextval[]){
	int i = 1, j = 1;
	while(i <= S.length && j <= T.length){
		if(j == 0 || S.ch[i] == T.ch[j]){
			++i;
			++j;
		} else j = nextval[j];
	}
	if(j > T.length) return i - T.length;
	else return 0;
}