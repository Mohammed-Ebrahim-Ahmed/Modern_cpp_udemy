#include <iostream>
#include <array>
#include <limits>
#include <algorithm>
void selectionSort(std::array<int,10> &arr)
{


    for(int i = 0; i < arr.size() ; i++)
    {
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void bubbleSort(std::array<int,10> &arr)
{
    for(int i = 0; i < arr.size()-1; i++)
    {
        for(int j = 0; j < arr.size()-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionSort(std::array<int,10> &arr)
{

    for(int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];

        int j = i -1;

        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(std::array<int,10> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    std::array<int,6> L;
    std::array<int,5> R;

    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for(int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while(i < n1)
    {
        arr[k++] = L[i++];
    }
    while(j < n2)
    {
        arr[k++] = R[j++];
    }
}

int partition(std::array<int,10> & arr, int l, int r)
{
    int i = l;
    int j = r;
    int pivot = arr[l];

    while(i < j)
    {
        do{
            i++;
        }while(arr[i] <= pivot);
        do{
            j--;
        }while(arr[j] > pivot);
        if(i < j)
        {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[l], arr[j]);
    return j;

}

int partition2(std::array<int,10> & arr, int l, int r)
{
    int i = l;
    int j = r;
    int pivLoc = l;

    while(true)
    {
        while(arr[pivLoc] <= arr[j] && j != pivLoc)
        {
            j--;
        }

        if(j == pivLoc)
        {
            break;
        }
        else if(arr[pivLoc] > arr[j])
        {
            std::swap(arr[pivLoc], arr[j]);
            pivLoc = j;
        }
        while(arr[pivLoc] >= arr[i] && i != pivLoc)
        {
            i++;
        }

        if(i == pivLoc)
        {
            break;
        }
        else if(arr[pivLoc] < arr[i])
        {
            std::swap(arr[pivLoc], arr[i]);
            pivLoc = i;
        }
    }
    return pivLoc;

}

void quickSort(std::array<int,10> &arr, int l, int r)
{
    if(l < r)
    {
        int pivot = partition2(arr, l, r);
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }
}
void mergeSort(std::array<int, 10> &arr, int l, int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2 ;
        mergeSort(arr, l, m );
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void heapify(std::array<int,10> & arr, int n, int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int max = i;
    if(l < n && arr[max] < arr[l])
    {
        max = l;
    }
    if(r < n && arr[max] < arr[r])
    {
        max = r;
    }

    if(max != i)
    {
        std::swap(arr[max], arr[i]);
        heapify(arr, n, max);
    }
}

void buildHeap(std::array<int,10>& arr, int n)
{
    for(int i = n/2 -1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(std::array<int,10> &arr)
{
    buildHeap(arr, arr.size());

    for(int i = arr.size() - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
class Singleton
{
    static inline Singleton* instance = nullptr;
    int value;
    Singleton(int val = 0) : value(val) { }
    
public:
    static Singleton& getInstance()
    {
        if (!instance)
            instance = new Singleton();
        return *instance;
    }

    ~Singleton() { delete instance; 
    instance = nullptr; }
    void setValue(int val) { value = val; }
    int getValue() const { return value; }
};

int linearSearch(std::array<int,10>& arr, int key)
{
    for(int i = 0 ; i < arr.size(); i++)
    {
        if(key == arr[i])
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(std::array<int,10>& arr, int key)
{
    int l = 0;
    int r = arr.size() -1;

    while(l < r)
    {
        int m = l + (r - l)/2;

        if(arr[m] == key)
        {
            return m;
        }
        else if(arr[m] > key)
        {
            r = m-1;
        }
        else if(arr[m] < key)
        {
            l = m+1;
        }
    }
    return -1;
}
int rBinarySearch(std::array<int, 10> & arr,int l, int r, int key)
{
    int m = l + (r - l)/2 ;
    if(l <= r)
    {
        if(key == arr[m])
        {
            return m;
        }
        else if( key < arr[m])
        {
            return rBinarySearch(arr, l, m -1, key);
        }
        else
        {
            return rBinarySearch(arr, m+1, r, key);
        }
    }

        return -1;

}
int rrBinarySearch(std::array<int, 10>& arr, int l, int r, int key) {
    if (l <= r) {
        int m = l + (r - l) / 2; // Calculate the mid-point index

        if (arr[m] == key) { // Key is found
            return m;
        } else if (key < arr[m]) { // Search in the left half
            return rBinarySearch(arr, l, m - 1, key);
        } else { // Search in the right half
            return rBinarySearch(arr, m + 1, r, key);
        }
    }
    return -1; // Key is not found
}
int main(int argc, char* argv[])
{

    std::array<int,10> arr = {11,2,99,3,9,10,20,7,6,20};
    std::sort(arr.begin(), arr.end());
    int index = rrBinarySearch(arr,0, 9, 11);
    std::cout << index << std::endl;
    for(const auto& x: arr)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    Singleton& s = Singleton::getInstance();
    // {
    // Singleton s2 = Singleton::getInstance();
    // }
    s.setValue(10);
    std::cout << "Singleton value: " << s.getValue() << std::endl;
    // selectionSort(arr);
    // bubbleSort(arr);

    // insertionSort(arr);
    // mergeSort(arr,0,9);
    // quickSort(arr, 0, 9);



    heapSort(arr);
    for(const auto& x: arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;


    std::string mystring = "mohammed";

    std::string::iterator it = mystring.end() -1;
    std::string newString;
    while(it >= mystring.begin()){
        newString.push_back(*it--);
    }
    std::cout << newString <<std::endl;

    int l = 0;
    int r = newString.length()-1;

    while(l < r)
    {
        std::swap(newString[l++], newString[r--]);
    }

    std::cout << newString.substr(1, 3) <<std::endl;
    return 0;
}



