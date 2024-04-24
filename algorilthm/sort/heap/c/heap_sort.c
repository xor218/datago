#include <stdio.h>

/**file 堆排序  TODO:: 未完成 不懂
 * 暂时不懂 index 的子节点是 2 *index +1 和 2*index +2
 * index的父亲节点是 （index -1）/2
*/

#define LENGTH(array) sizeof(array)/sizeof(array[0]) 
#define swap(a,b) (a^=b,b^=a,a^=b)


void maxheap_down(int arr[],int start,int end){
    int c= start;        //index
    int l= 2*c +1 ;      //left child index;
    int value = arr[c];  //Current Value 

    for(; l <= end;    c=l,l =l*2+1){
        //l是左孩子 l+1 是右孩子
        #if defined(NEEDDEBUG)
            printf("line :[%2d] c:[%2d],l:[%2d],value:[%d]\n",__LINE__,c,l,value);
        #endif
        if(l < end && arr[l] < arr[l+1]){

            l++;
        #if defined(NEEDDEBUG)
            printf("l++ line :[%2d] c:[%2d],l:[%2d],value:[%d]\n",__LINE__,c,l,value);
        #endif
        }
#if 1
        if (value >= arr[l])  //已经是最大的了
            // break;
            continue;
        else{
#else
        if(value < arr[l]){
#endif  
            arr[c] = arr[l];
            arr[l] =value;
        }
       

    }
}


void heapsort_asc(int arr[],int n){
    int i;
    for(int i= n/2 -1;i>=0;i--){
        maxheap_down(arr,i,n-1);
    }
    static int count=0;
    for(i =n -1;i> 0 ;i--)
    {
        
        swap(arr[0],arr[i]); //将最大的放到最后？？？ TODO:: 不懂
        printf("Count = %d\n",++count);
        maxheap_down(arr,0,i-1);
    }
}


int main(){

    int arr[]={1,2,3,4,5,6,7,8,9};
    int len=LENGTH(arr);
    heapsort_asc(arr,len);
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }

return 0;


}