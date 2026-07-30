#include<bits/stdc++.h>
using namespace std;



class heap{
    private :

    vector<int> array ;

    void heapify(int i);

    public:

    heap()=default;
    void insert(int val);
    int extract_max();
    void delete_key(int i);
    void print_heap() const;

};

void heap::heapify(int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int size =array.size();
    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(largest);

}
}

void heap::insert(int val){
    
    array.push_back(val);
    int i = array.size() - 1;
    while (i != 0 && array[(i - 1) / 2]< array[i]) {
        swap(array[i], array[(i - 1) / 2]);
        i = (i - 1) / 2;
}

}

int heap::extract_max(){
    if(array.size()<=0){
        throw overflow_error("Heap is empty");
    }

    if (array.size()==1){
        int root=array[0];
        array.pop_back();
        return root;

    }
    int root=array[0];
    array[0]=array.back();
    array.pop_back();
    heapify(0);
    
    return root;

}


void heap::delete_key(int i){
    if(array.size()<=0){
        throw overflow_error("Heap is empty");
    }
    array[i]=array.back();
    array.pop_back();
    heapify(0);

}

void heap::print_heap() const
{
    for (int val : array)
        cout << val << " ";
    cout << endl;
}


int main(){

    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);

    cout << "Max Heap: ";
    h.print_heap();

    cout << "Extracted max: " << h.extract_max() << endl;
    cout << "Max Heap after extraction: ";
    h.print_heap();

    h.delete_key(1);
    cout << "Max Heap after deleting key at index 1: ";
    h.print_heap();

    return 0;
    

}