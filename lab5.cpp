#include <iostream>
#include <math.h>
using namespace std;
#define n 5
/*
   10   32    1   -8   -1
    2    4   91  -82   96
   33   62   -1   -8    0
    5   -5    6   -6    7
  -19    0    3  -22   -3
  */
class Matrix
{
public:
    friend void InputMatrix(Matrix vector[]);
    friend void OutputMatrix(Matrix vector[]);
    int elementsOfLine[n];
};

void Azart(Matrix vector[]);
void MatrixDescendSort(Matrix vector[]);

void merge (int array1[], int len1, int array2[], int len2, int array[]);
void mergeSort(int array[], int len);

int main()
{
    Matrix array[n];
    InputMatrix(array);
    cout<<"Old matrix"<<endl;
    OutputMatrix(array);
    cout << endl;
    MatrixDescendSort(array);
    cout<<"New matrix"<<endl;
    OutputMatrix(array);
    cout << endl;
    Azart(array);
}

void merge (int array1[], int len1, int array2[], int len2, int array[])
{
    int i = 0, j = 0, k = 0;

    while(i < len1 || j < len2)
    {
        if (i < len1 && j < len2)
        {
            if (array1[i] > array2[j])
            {
                array[k] = array1[i];
                i++;
                k++;
            }
            else
            {
                array[k] = array2[j];
                j++;
                k++;
            }
        }
        else if (i >= len1)
        {
            array[k] = array2[j];
            j++;
            k++;
        }
        else if (j >= len2)
        {
            array[k] = array1[i];
            i++;
            k++;
        }
    }
}

void mergeSort(int array[], int len)
{
    int len1, len2;
    if (len%2 == 0)
    {
        len1 = len/2;
        len2 = len/2;
    }
    else
    {
        len1 = len/2;
        len2 = len/2 + 1;
    }

    int array1[len1];
    int array2[len2];
    for (int i = 0; i < len1; i++)
    {
        array1[i] = array[i];
    }
    for (int j = 0; j < len2; j ++)
    {
        array2[j] = array[len1 + j];
    }

    if (len == 2)
    {
        merge (array1, len1, array2, len2, array);
    }
    else if (len == 3)
    {
        mergeSort(array2, len2);
        merge (array1, len1, array2, len2, array);
    }
    else
    {
        mergeSort(array1, len1);
        mergeSort(array2, len2);
        merge (array1, len1, array2, len2, array);
    }
}

void InputMatrix(Matrix vector[])
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        {
            cin>>vector[i].elementsOfLine[j];
        }
    }
}

void OutputMatrix(Matrix vector[])
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        {
            cout<<vector[i].elementsOfLine[j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

void MatrixDescendSort(Matrix vector[])
{
    for (int i = 0; i < n; i++)
    {
        mergeSort(vector[i].elementsOfLine, n);
    }
}

    void Azart(Matrix vector[]){
        int tempResult = 1, i, j;
        double result=0;
        for( j = 1 ; j < n; j++){

            for( i = n-j; i < n; i++){
                tempResult *= vector[i].elementsOfLine[j];

            }
            result +=tempResult;
            printf("f[%d]= %d\n", j, tempResult);
            tempResult=1;
        }
        cout << "F[f]="<< result/4;
    }