#include <stdio.h>

#define N 5

struct num{
	int a;
	int (*cmp)(struct num *, struct num*);
	};

int comparator(struct num * q1, struct num * q2){
	return (q1->a)-(q2->a);
}

int MaxEl(struct num array[]){
	struct num test=array[0];
	int index=0;
	for (int i=1;i<N;i++)
		if (array[i].cmp(&test,&array[i]) < 0){
			index=i;
			test=array[i];
		}
	return index;
}

int main(){
	struct num array[N];
	int max;
	for (int i=0;i<N;i++){
		scanf("%d",&(array[i].a));
		array[i].cmp=comparator;
	}
	printf("index maxEl = %d\n", MaxEl(array));
	return 0;
}