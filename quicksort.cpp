#include <iostream>
using namespace std;
void printArr(int array[], int from, int to){
    for (int i = from;i <= to ;i++) {
        cout << array[i] << "\t";
    }
    cout << endl;
}
int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if(array[j] < pivot){
            i++;
            if(i<j){
                array[i] = array[i] + array[j];
                array[j] = array[i] - array[j];
                array[i] = array[i] - array[j];
            }
        }
    }
    array[high] = array[i+1];
    array[i+1] = pivot;
    return i+1;
}
void quicksort(int array[], int low, int high){
    if(low < high){
        int pi = partition(array, low, high);
        quicksort(array, low, pi-1);
        quicksort(array, pi+1, high);
    }
}
int main(){
    int length;
    cout << "enter how many number to be sorted: " << endl;
    cin >> length;
    
    int* array = new int[length];
    cout << "enter " << length << " numbers: " << endl;
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }
    
    quicksort(array, 0, length-1);
    cout << "after sorted: " << endl;
    printArr(array,0,length-1);
    delete []array;
    return 0;
}
