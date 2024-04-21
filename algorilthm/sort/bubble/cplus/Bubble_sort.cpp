#include <iostream>
#include <initializer_list>

class BubbleSort{
    private:
        int *arr;
        int len;
    
    public:
        BubbleSort(std::initializer_list<int> list){
            len = list.size();
            arr = new int[len];
            int i = 0;
            for(auto &e : list){
                arr[i++] = e;
            }
        }

        ~BubbleSort(){
            delete[] arr;
        }

        void Sort(){
            int n=len;
            while(n--){
                for(int i=0;i<n;i++){
                    if(arr[i] > arr[i+1]){
                        std::swap(arr[i],arr[i+1]);
                    }
                }   
            }
        }

        void show(){
            for(int i=0;i<len;i++){
                std::cout<<arr[i]<<" ";
            }
            std::cout<<std::endl;
        
        }
};

int main(){
    BubbleSort bs({11,1,2,3,4,5,6,7,8,955,55,32,123234123,5,10});
    bs.Sort();
    bs.show();

    return 0;
}