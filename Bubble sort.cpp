#include <iostream> // std::cout
#include <algorithm> // std::swap()
#include <chrono> // std::chrono::high_resolution_clock::now()
#include <ctime> // time()
#include <cstdlib> // std::rand(), str::srand()
using namespace std;
using namespace chrono;
int randnums(){return (rand()%101);}
void bubble_sort(int *arr, int s){
    int i = 0, k = 0; bool flag, repeat = 1;
    while(repeat){
        flag = false;
        k = 0;
        while(k<s - i){
            // Checks if current element is greater than next element.
            if(arr[k] > arr[k + 1]){
                // Swaps elements if condition is true.
                swap(arr[k], arr[k + 1]);
                flag = true;
            }k++;
        }
        // Breaks the loop if no element swapped.
        if(!flag){break;}
        repeat = (i++<s);        
    }
}
void print_arr_elements(int *arr, int s){
    cout<<endl;
    for(int i = 0; i<s; i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    srand(time(0));
    int arr[10];
    
    // Stores random numbers to the array arr of type int
    generate(begin(arr), end(arr), randnums);
    
    cout<<"Unsorted array elements: ";
    print_arr_elements(arr, size(arr)), cout<<endl;
    
    auto fun_start = high_resolution_clock::now();
    
    // Sorting elements using bubble sort algorithm
    bubble_sort(arr, size(arr));
    auto fun_end = high_resolution_clock::now();
    
    auto temp = duration_cast<nanoseconds>(fun_end - fun_start).count();
    float res = (float)temp / 1000;
    
    // Prints sorted array 
    cout<<"Sorted array elements: ";
    print_arr_elements(arr, size(arr)), cout<<endl;
    cout<<"Time taken : "<<res<<"microseconds."<<endl;
    return 0;
}
