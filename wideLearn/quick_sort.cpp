#include <cstdio>
int data[]={9,7,6,4,3,2,1,14,25,4};

template <typename T>
void swap(T *data,T i,T j){
    T temp=data[i];
    data[i]=data[j];
    data[j]=temp;
}

template<typename T>
void quickSort(T *data,T start,T end){
    if(start>=end) return;

    int pivot = start;
    int i = pivot +1;
    int j = end;

    while(i<=j){
        while(i <= end && data[i] <=data[pivot]) i++;
        while(j > start && data[j] >= data[pivot]) j--;
        if(i > j) swap(data,pivot,j);
        else swap(data,i,j);
    }
    quickSort(data,start,j-1);
    quickSort(data,j+1,end);
}

template<typename T>
void sort(T* begin,T* end){
    int size=(end-begin)/sizeof(T);
    quickSort(begin,0,size);
}


int main(){
    quickSort(data,0,9);
    for(int i=0;i<10;i++){
        printf("%d ",data[i]);
    }
    return 0;
}
