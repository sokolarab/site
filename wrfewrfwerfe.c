#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#define N 5

int comparechar(const void* a, const void* b){
	if(*(char*)a < *(char*)b) return -1;
	if(*(char*)a > *(char*)b) return 1;
	if(*(char*)a == *(char*)b) return 0;
}

int compareint(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int comparefloat(const void* a, const void* b){
	if (fabs(*(float*)a - *(float*)b <= FLT_EPSILON)) return 0;
	if (*(float*)a < *(float*)b) return -1;
	else return 1;
}

void swap(void* a, void* b, int size_of_elem){
	for(int i=0; i<size_of_elem; i++){
		char bait=*(char*)(a+i);
		*(char*)(a+i)=*(char*)(b+i);
		*(char*)(b+i)=bait;
	}
}

void bubbleSort(void *arr, int arr_len, int size_of_elem, int(*cmp)(const void* a, const void* b)){
	for(int i=0; i<arr_len; i++)
		for(int j=0; j<arr_len-i-1; j++)
			if(cmp(arr+j*size_of_elem, arr+(j+1)*size_of_elem) > 0)
				swap(arr+j*size_of_elem, arr+(j+1)*size_of_elem, size_of_elem);
}

int main(void){
	int a;
	scanf("%d\n", &a);
	char array1[N];
	int array4[N];
	float array5[N];
	switch(a){
	case 1:
		for(int i=0; i<N; i++)
			scanf("%c ", &array1[i]);
		bubbleSort(array1, N, a, comparechar);
		for(int i=0; i<N; i++)
			printf("%c ", array1[i]);
		break;
	case 4:
		for(int i=0; i<N; i++)
			scanf("%d", &array4[i]);
		bubbleSort(array4, N, a, compareint);
		for(int i=0; i<N; i++)
			printf("%d ", array4[i]);
		break;
	case 5:
		for(int i=0; i<N; i++)
			scanf("%f", &array5[i]);
		bubbleSort(array5, N, 4, comparefloat);
		for(int i=0; i<N; i++)
			printf("%lg ", array5[i]);
		break;
	
	default: 
		printf("Error\n");
	}
	return 0;
}
