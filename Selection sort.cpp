#include <iostream> // std::cout
#include <algorithm> // std::swap, std::genarate
#include <chrono> // std::chrono, std::chrno::high_resolution_clock::now!() 
#include <ctime> // time()
#include <cstdlib> // std::srand(), std::rand()
using namespace std;
using namespace chrono;
int randnums(){return (rand()%101+1);}
void selection_sort(int *arr, int s){
    int min, i, k = 0;
    bool repeat;
    do{
        // Initially k value will be the min element index
        min = k, i = k + 1;
        while(i < s){
        
            // Checks if any element less than element at k and stores value of i into min.
            if(arr[i] < arr[min])
                min = i;
            i++;
        }
        // Swaps elements at k to element at min, means minimum element to begin.
        swap(arr[k], arr[min]);
        repeat = (k++ != s);
    }while(repeat);
}
void print_arr_elements(int *arr, int s){
    for(int i = 0; i < s; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main() {
    srand(time(NULL));
    int arr[10];
    float res;
    
    // Stores random numbers to an array
    generate(begin(arr), end(arr), randnums);
    
    // Prints unsorted array elements
    cout<<"Unsorted array elements:\n";
    print_arr_elements(arr, size(arr));
    
    // To measure execution time
    auto f_start = high_resolution_clock::now();
    selection_sort(arr, size(arr));
    auto f_end = high_resolution_clock::now();
    
    auto temp = duration_cast<nanoseconds>(f_end - f_start).count();
    
    res = (float)temp / 1000;
    
    // Prints sorted array elements
    cout<<"Sorted array elements:\n";
    print_arr_elements(arr, size(arr));
    
    cout<<"Time taken: "<<res<<"microseconds.";
    return 0;
}
