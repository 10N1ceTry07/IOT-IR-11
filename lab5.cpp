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
    friend void inputMatrix(Matrix arrayOfRows[]);
    friend void outputMatrix(Matrix arrayOfRows[]);
    int elementsOfLine[n];
};

void calculations(Matrix arrayOfRows[]);
void repassingTheMatrix(Matrix arrayOfRows[]);

void merge (int leftPartArray[], int lengthLeftSideArray, int array2[], int lengthRightSideArray, int array[]);
void mergeSort(int array[], int lengthArray);

int main()
{
    Matrix array[n];
    inputMatrix(array);
    cout<<"Old matrix"<<endl;
    outputMatrix(array);
    cout << endl;
    repassingTheMatrix(array);
    cout<<"New matrix"<<endl;
    outputMatrix(array);
    cout << endl;
    calculations(array);
}

void merge (int leftPartArray[], int lengthLeftSideArray, int rightPartArray[], int lengthRightSideArray, int array[])
{
    int row = 0, column = 0, k = 0;

    while(row < lengthLeftSideArray || column < lengthRightSideArray)
    {
        if (row < lengthLeftSideArray && column < lengthRightSideArray)
        {
            if (leftPartArray[row] > rightPartArray[column])
            {
                array[k] = leftPartArray[row];
                row++;
                k++;
            }
            else
            {
                array[k] = rightPartArray[column];
                column++;
                k++;
            }
        }
        else if (row >= lengthLeftSideArray)
        {
            array[k] = rightPartArray[column];
            column++;
            k++;
        }
        else if (column >= lengthRightSideArray)
        {
            array[k] = leftPartArray[row];
            row++;
            k++;
        }
    }
}

void mergeSort(int array[], int lengthArray)
{
    int lengthLeftSideArray, lengthRightSideArray;
    if (lengthArray%2 == 0)
    {
        lengthLeftSideArray = lengthArray/2;
        lengthRightSideArray = lengthArray/2;
    }
    else
    {
        lengthLeftSideArray = lengthArray/2;
        lengthRightSideArray = lengthArray/2 + 1;
    }

    int leftPartArray[lengthLeftSideArray];
    int rightPartArray[lengthRightSideArray];
    for (int row = 0; row < lengthLeftSideArray; row++)
    {
        leftPartArray[row] = array[row];
    }
    for (int column = 0; column < lengthRightSideArray; column ++)
    {
        rightPartArray[column] = array[lengthLeftSideArray + column];
    }

    if (lengthArray == 2)
    {
        merge (leftPartArray, lengthLeftSideArray, rightPartArray, lengthRightSideArray, array);
    }
    else if (lengthArray == 3)
    {
        mergeSort(rightPartArray, lengthRightSideArray);
        merge (leftPartArray, lengthLeftSideArray, rightPartArray, lengthRightSideArray, array);
    }
    else
    {
        mergeSort(leftPartArray, lengthLeftSideArray);
        mergeSort(rightPartArray, lengthRightSideArray);
        merge (leftPartArray, lengthLeftSideArray, rightPartArray, lengthRightSideArray, array);
    }
}

void inputMatrix(Matrix arrayOfRows[])
{
    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++)
        {
            cin>>arrayOfRows[row].elementsOfLine[column];
        }
    }
}

void outputMatrix(Matrix arrayOfRows[])
{
    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++)
        {
            cout<<arrayOfRows[row].elementsOfLine[column]<<"\t";
        }
        cout<<endl<<endl;
    }
}

void repassingTheMatrix(Matrix arrayOfRows[])
{
    for (int row = 0; row < n; row++)
    {
        mergeSort(arrayOfRows[row].elementsOfLine, n);
    }
}

    void calculations(Matrix arrayOfRows[]){
        int multiplyOfElements = 1, row, column;
        double resultOfAddition=0;
        for( column = 1 ; column < n; column++){

            for( row = n - column; row < n; row++){
                multiplyOfElements *= arrayOfRows[row].elementsOfLine[column];

            }
            resultOfAddition +=multiplyOfElements;
            printf("Result of addition of multiplied elements[%d]= %d\n", column, multiplyOfElements);
            multiplyOfElements=1;
        }
        cout << "F[f]="<< resultOfAddition/4;
    }