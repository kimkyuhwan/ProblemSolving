#include <cstdio>
#include <algorithm>
using namespace std;
namespace klight{
    template<typename T>
    class _vector {
        private:
            int _capacity = 0;
            int _size = 0;
            T *vc;

        public:
            _vector(int size = 1) {
                _capacity = size;
                vc = new T[size];
            }
            ~_vector() {
                delete[] vc;
            }
            int size() { return _size; }
            bool empty() { return !_size; }
            void resize(int size) {
                _capacity = size;
                T *tVc = new T[size];
                for (int i = 0; i < _size; i++)
                    tVc[i] = vc[i];
                delete[] vc;

                vc = tVc;
            }
            void clear() {
                delete[] vc;
                _capacity = 1;
                _size = 0;

                vc = new T[1];
            }
            void push_back(T val) {
                if (_size == _capacity) {
                    _capacity *= 2;
                    resize(_capacity);
                }

                vc[_size++] = val;
            }

            void pop_back() {
                if (_size == 0)
                    return;

                vc[--_size] = 0;
            }

            void reverse() {
                for (int i = 0; i < _size / 2; i++)
                {
                    T tmp = vc[i];
                    vc[i] = vc[(_size - 1) - i];
                    vc[(_size - 1) - i] = tmp;
                }
            }
            T &operator[](const int &i) const{ return vc[i]; }
            void operator=(const _vector<T> &tVc) {
                _capacity = tVc._capacity;
                _size = tVc._size;
                delete[] vc;
                vc = new T[_capacity];
                for (int i = 0; i < _size; i++)
                    vc[i] = tVc[i];
            }
            T* begin(){
                return &vc[0];
            }
            T* end(){
                return &vc[size()];
            }
    };
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
        printf("%d %d",(void*)begin,(void*)end);
        int size=(end-begin)/sizeof(T);
        printf("size : %d\n",size);
        quickSort(begin,0,size);
    }


}
int main(){
    klight::_vector<int> vec;
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(3);
    klight::quickSort(vec.begin(),0,2);
    for(int i=0;i<vec.size();i++){
        printf("%d ",vec[i]);
    }


}
