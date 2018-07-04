#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#define N 5


int comparechar(const void* a, const void* b){
	if((int)(*(char*) a < *(char*) b)) return -1;
	if((int)(*(char*) a > *(char*) b)) return 1;
	if((int)(*(char*) a == *(char*) b)) return 0;
}

int compareint(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int comparefloat(const void* a, const void* b){
	if (fabs(*(float*)a - *(float*)b <= FLT_EPSILON)) return 0;
	if (*(float*)a < *(float*)b) return -1;
	else return 1;
}


int main(void){
	int a;
	scanf("%d\n", &a);
	char array1[N]={q,w,e,r,t};
	int array4[N]={1,5,7,9,34};
	float array8[N]={1.2345,5,5467,56.345,78.2345,99.7};
	char key1;
	int key4;
	float key8;
	scanf("%c",&key1);
	bsearch(&key1,array1, N, 1, comparechar)-array1));
	scanf("%d",&key4);
	bsearch(&key4,array4, N, 4, compareint)-array4));
	scanf("%f",&key8);
	bsearch(&key8,array8, N, 4, comparefloat)-array8));
	return 0;
}
