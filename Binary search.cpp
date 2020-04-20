#include <iostream> // std::cout
#include <algorithm> // std::binary_search(), std::genarate(), std::sort()
#include <ctime> // time()
#include <cstdlib> // srand(), rand()
#include <iomanip> // std::quoted()
#include <string> // std::to_string()
#include <vector> // std::vector
using namespace std;

int randnums(){return (rand()%101+ 1);}

int BinarySearch(vector<int>v, int comp){
    int s = v.size();
    int mid = s / 2;
    if(binary_search(v.begin(), v.end(), comp)){
        while(true){
            if(v[mid] == comp)
                return mid;
            else if(v[mid] < comp) mid += 1; 
            else mid -= 1;
        }
    }
    return -1;
}

int Binary_Search(vector<int>v, int comp){
    int s = v.size();
    int mid = s / 2;
    for(unsigned int i = 0;i<v.size(); i++){
        if(v[mid] == comp)
        return mid;
        else if(v[mid] < comp) mid += 1; 
        else mid -= 1;
    }
    return -1;
}

void print_array_elements(int arr[], int s){
    for(int i = 0; i < s; i++){
        cout<<setw(2)<<arr[i]<<" ";
    }
    cout<<endl;
}

void print(int i, int p, int e){
    cout<<"\nSearching for "<<quoted(to_string(e))<<"...\n";
    if(p>=0){
        cout<<"Value "<<quoted(to_string(e))<<" found at index "<<p<<endl;
    }else{
        cout<<"Value "<<quoted(to_string(e))<<" isn't found in the array :(\n";
    }
}
int main() {
    srand(time(nullptr));
    int arr[10];
    generate(begin(arr), end(arr), randnums);
    sort(begin(arr), end(arr));
    print_array_elements(arr, size(arr));
    for(int i = 0; i<10; i++) 
        cout<<setw(2)<<i<<" ";
    cout<<"\n";
    vector<int>ar;
    ar.assign(arr, arr + size(arr));
    int temp = arr[rand()%10];
    int index;
    for(int i = 1; i <= 2; i++){
        if(i==1){
            temp = ar[rand()%10];
            index = BinarySearch(ar, temp);
            print(i, index, temp);
        }else{
            temp = randnums();
            index = Binary_Search(ar, temp);
            print(i, index, temp);
        }
    }
    return 0;
}
