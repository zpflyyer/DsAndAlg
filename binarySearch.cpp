#include <iostream>
using namespace std;
int binarySearch(int arr[], int from, int to, int key){
    if(from < to){
        int mid = (from+to)/2;
        if(arr[mid] == key){
            return mid;
        } else if(arr[mid] < key){
            return binarySearch(arr,mid+1,to,key);
        } else{
            return binarySearch(arr,from,mid-1,key);
        }
    }
    else{
        return arr[from] == key ? from : -1;
    }
}


int main(){
    int len;
    int* a;
    int key;
    cin >> len; cin >> key;
    a = new int[len];
    for (int i = 0; i < len; i++) {
        cin >> a[i];
    }
    cout << binarySearch(a,0,len-1,key);
}


