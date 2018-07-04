#include <stdio.h>

int compar(int key, int *pelem)
{ int pl = key - *pelem;
return (key-*pelem);};


int *mybesearch(int key, int *arr, size_t n, int(*compar)(int *, int *)){
    int *s = NULL;
    if(n!=1){
      s = mybesearch(key, arr, n/2, compar);
      if(!s)
        s = mybesearch(key, arr+n/2, n/2+n%2, compar);
    }
    else{
      if(compar(key, arr)==0)
          return arr;
    }
    return s;
};

int main(){
        int arr[5] = {8,0,9,6,4};
        int key = 4;
        int *k=mybesearch(key, arr, 5, compar);
        return 0;
}
