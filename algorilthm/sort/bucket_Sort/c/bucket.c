#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

/**
 * @file 桶排序
 * 
*/

void bucket_sort(int arr[],int arrLen){
    assert(arrLen>0);
    int min=arr[0];
    int max=arr[0];
    for(int i=1;i<arrLen;i++){
        min = min <arr[i] ?min:arr[i];
        max = max >arr[i] ?max:arr[i];
    }
//分配一个桶 malloc 堆空间
    int *bucket =(int *)malloc(max-min +1);
    assert(bucket !=NULL);
    for(int i=0;i<max-min+1;i++){
        bucket[i]=0;
    }
//只在桶的index++ 
    for(int i=0;i<arrLen;i++){
        bucket[arr[i]-min]++;
    }

    int index=0;
    
    for(int i=0;i<max-min +1;i++){
        while(bucket[i]--)
            arr[index++] = i +min;

    }
        
    free(bucket);

}

int main(){
    int arr[]={9,8,7,6,5,4,3,2,1,4,0,0};
    bucket_sort(arr,sizeof(arr)/sizeof(int));
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        printf("%d ",arr[i]);
    }
    return 0;
}