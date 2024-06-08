#include <iostream>
#include <ctime>
using namespace std;

int* generateArr(int size);
void printArr(int* arr, int size);
void fillArr(int* arr,int size);
int countDigits(int num);

int main() {
    srand(time(NULL));
    
    int size = rand() % 5 + 1; //5-1
    cout << "size:"  << size << endl;
    
    
    int* arr = generateArr(size);
    fillArr(arr,size);
    
    cout << "Arr: ";
    printArr(arr,size);
    
    //////////////
    int num = 0;
    for(int i = 0; i < size; i++)
            num = 10*num + arr[i];
        
    num += 1;
    cout << endl << "Plus one: " << num << endl;
    
    int digits = countDigits(num);
    int* newArr = generateArr(digits); //count digits
    for(int i = digits - 1; i >= 0; i--)
    {
        newArr[i] = num % 10;
        num /= 10;
    }
    
    cout << "New arr: ";
    printArr(newArr,digits);
        
    //////////////
    delete[] newArr;
    delete[] arr;
}

int* generateArr(int size)
{
    int* arr = new int[size];
    return arr;
}

void fillArr(int* arr,int size)
{
    if(arr != nullptr)
        for(int i = 0 ; i < size; i++)
            arr[i] = rand() % 10; //0-9
}

void printArr(int* arr,int size)
{
    if(arr!=nullptr)
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
}

int countDigits(int num)
{
    int digits = 1;
    
    while(num > 10)
    {
        num /= 10;
        digits++;
    }
    
    return digits;
}
