#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

/**
 * 冒泡排序:
 *          循环数组长度 -1次
 *          每次把最大的排在后面
 * 
 * 冒泡排序2:
 *          循环[数组长度-1]次
 *          建立一个flag 如果有后面比前面的数组大 flag=1
 *          flag 初始化为0 如果一次循环完了 flag还是 0
 *          说明没有需要排序的
 * 
 *  
*/

#define swap(a,b) (a^=b,b^=a,a^=b)
#define LENGTH(array) ((sizeof(array)) /(sizeof(array[0])))


//冒泡排序2:
void bubble_sort(int *arr,int len){
    while(--len){
        for(int i=0;i<len;i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
    }
}

//冒泡排序2:
void bubble_sort2(int *arr,int len){
    int flag;
    while(--len)
    {
        flag=0;
        for(int i=0;i<len;i++){
            if(arr[i] > arr[i+1]){
            flag=1;
            swap(arr[i],arr[i+1]);
            }
        
    }
    if(!flag)return;
}

}


int main(){
    srand(time(NULL));
    int len=1000;
    int *ptr=(int *)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++){
        ptr[i]=rand() %(len*10);
    }

    // bubble_sort(ptr,len);
    bubble_sort2(ptr,len);

    for(int i=0;i<len;i++){
        printf("%4d ",ptr[i]);
        if(i % 10 == 9){
            putchar(10);
        }
            
    }



    return 0;
}