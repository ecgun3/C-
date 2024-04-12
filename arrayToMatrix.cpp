//lets turn the array into a matrix: 
#include <iostream>
#include <new>
#include <ctime>
#include <cmath> //for using the abs() function
using namespace std;

void printArray(int* arr,int n)
{
    for(int i=0;i<n;i++)
        arr[i] = rand()%10;
    cout<<"arr["<<n<<"] = {";
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
            cout<<arr[i]<<", ";
        else
            cout<<arr[i];
    }
    cout<<"}"<<endl;
}

void deleteArray(int* arr)
{
    if(arr!=nullptr)
    {
        delete[] arr;
        arr = nullptr;
    }
}

/*void bakalım(int n)
{
    int row = rand() % (n - 1) + 1;
    int cols = abs(rand() % (n - row) + 1); 
    cout << "row = " << row << "\tcols = " << cols << endl;
}*/

int** createMatrix(int row,int cols)
{
    int** mat = new int*[row];
    int* arr = new int[row*cols];
    for(int i=0;i<row;i++)
        mat[i] = &arr[i*cols];
    return mat;
}

void fillMatrix(int* arr,int**mat,int row,int cols)
{
    //filling the matrix with array elements:
    for(int i=0;i<row;i++)
        for(int j=0;j<cols;j++)
            mat[i][j] = arr[i*2+j];
    //printing the matrix elements:
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<"mat["<<i<<"]["<<j<<"]: "<<mat[i][j]<<endl;
        cout<<endl;
    }
}

void deleteMatrix(int** mat)
{
    if(mat!=nullptr)
    {
        delete[] mat[0];
        delete[] mat;
        mat = nullptr;
    }
}

int main()
{
    srand(time(NULL));
    int n;
    do
    {
        n = rand()%10+1;
    } while (n%2!=0 && n>2); //sadece çift sayılar üretiyor.
    
    cout<<"n : "<<n<<endl;
    
    int* arr = new int[n];
    printArray(arr,n);
    
    int row,cols;
    do
    {
        cout<<"Enter row (should be divide "<<n<<") = ";
        cin>>row;
    } while(n % row != 0);

    cols = n/row;
    cout<<"row: "<<row<<"\tcols: "<<cols<<endl;
    
    int** mat = createMatrix(row,cols);
    fillMatrix(arr,mat,row,cols);
    
    deleteMatrix(mat);
    deleteArray(arr);
        
    return 0;
}