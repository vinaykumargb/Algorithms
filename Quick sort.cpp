#include <iostream> // std::cout
#include <algorithm> // std::swap, std::generate
#include <ctime> // time()
#include <cstdlib> // srand(), rand()
using namespace std;
int rnd()
{return (rand()%101+1);}
int partition(int arr[], int first, int last){
    // To swap values.
    int i = first + 1;

    // Pick the first element as pivot.
    int pivot = first, k = first;

    // Start loop from first value to last value
    while(k++<=last){
        // Check if any element between first
        // and last is lesser than pivot value.
        if(arr[k] < arr[pivot])
            // If condition true, swap them.
            swap(arr[i++], arr[k]);
    }
    // Swap pivot to proper index.
    swap(arr[pivot], arr[i - 1]);

    // Return index of pivot.
    return (i - 1);

}
void quick_sort(int arr[], int first, int last){
    if(first < last){
        // Swap if pivot value is greater than any value till last.
        // Also, get the index of pivot.
        int pivot = partition(arr, first, last);

        // Sort pivot left side values.
        quick_sort(arr, first, pivot - 1);

        // Sort pivot right side values.
        quick_sort(arr, pivot + 1, last);
    }
}
void print_elements(int arr[], int s){
    for(int i = 0; i < s; i++)        
        cout<<arr[i]<<" ";
}
int main(){
    srand(time(nullptr));
    int arr[10];
    generate(begin(arr), end(arr), rnd);
    cout<<"Unsorted array..\n";
    print_elements(arr, size(arr));cout<<endl;
    cout<<"Calling quick sort function..\n";
    quick_sort(arr, 0, (size(arr) - 1));
    cout<<"Sorted array..\n";
    print_elements(arr, size(arr));
    return 0;
}
