#include <iostream>
using namespace std;
void printArr(int a[], int from, int to){
    for (int i = from;i <= to ;i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if(a[j] < pivot){
            i++;
            if(i<j){
                a[i] = a[i] + a[j];
                a[j] = a[i] - a[j];
                a[i] = a[i] - a[j];
            }
        }
    }
    a[high] = a[i+1];
    a[i+1] = pivot;
    return i+1;
}
void quicksort(int a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quicksort(a, low, pi-1);
        quicksort(a, pi+1, high);
    }
}
int main(){
    cout << "number of elements: ";
    int length;
    cin >> length;
    int* a = new int[length];
    cout << "enter " << length << " numbers: ";
    quicksort(a, 0, length-1);
    for (int i = 0; i < length; i++) {
        cin >> a[i];
    }
    printArr(a,0,length-1);
    return 0;
}
