#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
void genericSwap(void* a,void* b,int size) //assume size > 0
{
    //size specifies no of bytes
    void* tempmemory =malloc(size);
    //Memory cpy function with syntax below:
    //void * memcpy(void * dest, const voit * src, size_t number)
    memcpy(tempmemory, a, size);
    memcpy(a, b, size);
    memcpy(b, tempmemory, size);

    free(tempmemory);
}

int main()
{
    int num1=5, num2=7;
    double average1=78.2, average2=89.1;
    genericSwap(&num1, &num2, sizeof(int));
}


int findmin(int num1, int num2)
{
    if (num1>num2)
    return num2;
    else
    return num1;
}

int main()
{
    int a =5, b =7;
    int min;
    min = findmin(a,b);
    printf("Minimum is %d",min);
}

#define SIZE 4

int findanarrayinarray(int *arr, int size, int key)
{
    int i;
    for (i=0;i<SIZE;i++)
    {
        if (arr[i]==key)
        return 1;
    }
    return 0;
}

int main()
{
    int grades[SIZE]= {80,85,90,87};
    int result;
    result = findanarrayinarray(grades,SIZE,85);
    printf("The key %d is present",result);
    return 0;
}


//Write a function that should receive an array and it's size .
//The function should also find and return the maximum value in the array

#define SIZE 4

int findmaxofarray(int *arr, int size)
{
    int maxsofar;
    int i;
    if (size <= 0)
        return size;
    maxsofar = arr[0];
    for (i=1;i < size ; i++)
    {
        if (arr[i] > maxsofar)
        maxsofar = arr[i];
    }
    return maxsofar;
}

int main()
{
    int imran[SIZE]= {12,58,67,34};
    int maxofimran;
    maxofimran = findmaxofarray(imran, SIZE);
    printf("max of imran is %d",maxofimran);
    return 0;
}*/

//Write a function that should receive an array and it's size .
//The function should also find and return the average value of the array

/*
#define SIZE 4

int sumArray(int* arr, int size)
{
    int i, sum =0;
    for (i=0;i < size;i++)
    {
        sum = sum + arr[i];
    }
    return sum; 
}

double averageofarray(int *arr, int size)
{
    int sumofarray;
    sumofarray = sumArray(arr, size);
    return (double)sumofarray/size;
}

int main()
{
    int grades[SIZE] = {80,98,69,50};
    double average;
    average = averageofarray(grades, SIZE);
    printf("The average of the array is %f",average);
    return 0;
}

#define SIZE 4

//Input Array Function

void inputArray(int *arr, int size)
{
    int i;
    for(i=0;i < size;i++)
    {
        printf("Enter the value #%d is:\n",i +1);
        scanf("%d",&arr[i]);
    }
    
}
//  Display array functiion

void displayarray(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("value no #%d is %d\n",i+1,arr[i]);
    }
}

int main()
{
    int grades[SIZE];
    inputArray(grades,SIZE);
    //grade array should be filled with values
    displayarray(grades, SIZE);
    return 0;
}

void minMax(int *pArr, int size, int *minValue, int *maxValue)
{
    int i;
    *minValue = pArr[0];
    *maxValue = pArr[0];
    for (i=1; i < size;i++)
    {
        if (pArr[i] < *minValue)
            *minValue = pArr[i];
        if (pArr[i] > *maxValue)
            *maxValue = pArr[i];
    }
}


int main()
{
    int myGrades[] = {99,69,111};
    int min, max;
    minMax(myGrades, 3, &min, &max);
    printf("Minimum value of array is : %d\n",min);
    printf("Maximum value of array is : %d\n",max);
    return 0;
}


//Write a function called "updateAverage"
//The function should recive 2 values and update by "reference" the average (of the caller)
//The function should not print/return anything

void updateAverage(int num1, int num2, float *avg)
{
    *avg = (num1+num2)/2.0;
}

int main()
{
    int value1;
    int value2;
    printf("Enter the first element : \n");
    scanf("%d",&value1);
    printf("Enter the first element : \n");
    scanf("%d",&value2);
    float average;
    updateAverage(value1, value2, &average);
    printf("The average is %f",average);
    return 0;
}


//Work with Neighbors!
//Write an function  that receives an array and it's size
//Return 1, If that array has some elements which value equals to sum of both of its Neighbors (Right Side, Left Side)
//Else Return 0

int hasNeighbors(int *arr, int size)
{
    int i;
    for (i =1;i < size-1;i++)
    {
        if (arr[i] == arr[i-1] + arr[i+1])
            return 1;
    }
    return 0;
}

int main()
{
    int grades[5] = {1,3,7,4,2};
    hasNeighbors(grades, 5);
}

//Write a Function checks if the array is "Really Sorted", "Sorted", "Not Sorted".
//The function should RETURN 1 and PASS 1 By Reference if the array is "Really Sorted"
//The function should RETURN 1 and PASS 0 By Reference if the array is "Sorted"
//The function should RETURN 0 and PASS 0 By Reference if the array is "Not Sorted"

//Example : [1,2,5,7,10] --> "Really Sorted" Return-1 PASS-1 //For any Pair : Left Element < Right Element
//Example : [1,2,2,5,10] --> "Sorted" R-1 P-0 //For any Pair : Left Element <= Right Element
//Example : [1,2,5,3,10] --> "Not Sorted" R-0 P-0

//Iterative Approch Solution

int CheckifSorted(int *arr, int size, int *pass)
{
    int i;
    *pass = 1; //Assuming that the array is really sorted.
    for (i = 1; i < size; i++)
    {
        if (arr[i] <= arr[i-1]) //If the element on the right is less that or equal to the element on the left
            *pass = 0; //The array is not really sorted
        if (arr[i] < arr[i-1]) //If the element on the left is less than the element on the right
            return 0; 
    }
    return 1;
}

int main()
{
    int arrValue[] = {1,2,5,3,10};
    int passValue;
    int result;
    
    result = CheckifSorted(arrValue, 5, &passValue);

    if (result == 1)
        printf("The Array is Really Sorted / Sorted \n");
    else if (result == 0)
        printf("The Array is NOT Sorted at ALL \n");

    if (passValue ==1)
        printf("The Array is Really Sorted \n");
    else if (passValue == 0)
        printf("The Array is NOT Sorted \n");
    return 0;
}

//The below Solution Using Recursive Approach::::
//Recursive Call (with some logic behind them )
//Base/Stopping Condition

int CheckifSortedRecursive(int *arr,int size, int *pass)
{
    int result; //The return result
    if (size == 1) //The array has just one element 
    {
        *pass = 1; //We will assume that the array is really sorted
        return 1;
    }
    result = CheckifSortedRecursive(arr, size-1, pass);
    if (result != 0 && arr[size-1] == arr[size-2]) 
    {
        *pass = 0;
    }
    if (result != 0 && arr[size-1] < arr[size-2])
    {
        *pass = 0;
        return 0;
    }
    return result;
}

int main ()
{
    int arrValue[] = {1,2,5,3,10};
    int passValue;
    int output;
    output = CheckifSortedRecursive(arrValue, 5, &passValue);
    if (output == 1)
        printf("The array is really Sorted/ Sorted \n");
    else if (output == 0)
        printf("The value is Not at all sorted \n");

    if (passValue ==1)
        printf("The Array is Really Sorted \n");
    else if (passValue == 0)
        printf("The Array is NOT Sorted \n");
    return 0;
}*/

//Exersise
//write a function that receives an array of characters.
//The function should "return" the array (Recursively)
/*
#define SIZE 5

void swap(char *ptr1, char *ptr2)
{
    char temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void printarray(char *arr, int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%c",arr[i]);
    printf("\n");
}

void arrReverseIterative(char *arr,int size)
{
    int i;
    for(i = 0; i < size/2;i++)
    swap(&arr[i],&arr[size-1-i]);
    //Option 2 ==> swap(arr+1,arr+size-1-i);
}

void arrReverseRecursive(char *arr, int size)
{
    if (size > 1)
    {
        swap(&arr[0],&arr[size - 1]);
        //Option 2 ==> swap(arr,arr+size-1);
        arrReverseRecursive(arr + 1, size - 2);
    }
}

int main ()
{
    char arr[SIZE]={'a','s','d','f','g'};
    printarray(arr, SIZE);
    arrReverseIterative(arr, SIZE);
    printarray(arr, SIZE);
    return 0;
}


//Recursively Reverse an anrray
//Example1 : {1,2,6,4,3}
//Example2 : {2,5,1,5,8,4}

#define SIZE 6

void swap(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void printarray(int *arr, int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d",arr[i]);
    printf("\n");
}

void arrRecursiveReverse(int *arr, int n)
{
    if (n > 1) //The size of array is more than just 1 element
    {
        swap(arr,arr + n-1);
        arrRecursiveReverse(arr + 1,n-2);
    }
}

int main()
{
    int arr[SIZE] = {2,5,1,5,8,4};
    printarray(arr, SIZE);
    arrRecursiveReverse(arr,SIZE);
    printarray(arr, SIZE);
    return 0;
}*/

//Exercise :: Write a funtion that receives an array.
//            The function should count and print the 
//            frequency of each of the array Elements.
/*
#define SIZE 5

void printValueFrequency(int *arr, int size)
{
    int i, j;
    int LeftFlag;
    int CountValue;
    for (i=0; i < size; i++)
    {
        CountValue =1;
        LeftFlag =0;
        //Left Part
        for (j=0; j < i; j++)
        {
            if (arr[j] == arr[i])
                //CountValue++;
                LeftFlag = 1;
                break;
        }
    //}
    if (LeftFlag == 1)
        continue;
    }
    //Right Part
    for (j = i + 1; j < size; j++)
    {
        if (arr[j] == arr[i])
        printf("%d for loop\n",arr[i]);
        CountValue++;
    }
    printf("The Value at arr %d is Appears %d times...\n",arr[i],CountValue);
} 


int main()
{
    int Bhalu[SIZE] = {5,6,7,6,5};
    printValueFrequency(Bhalu, SIZE);
    return 0;
}




void countFrequency(int *arr, int size)
{
    // Initialize a frequency array with zeros
    int freq[size];
    for (int i = 0; i < size; i++) {
        freq[i] = 0;
    }

    // Count frequency of each element
    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    // Print frequency of each element
    for (int i = 0; i < size; i++) {
        if (freq[i] != 0) 
            printf("Frequency of %d = %d\n", i, freq[i]);
    }
}

int main() {
    int arr[] = {5, 6, 7, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    countFrequency(arr, size);

    return 0;
}
*/
/*
void countFrequency(int *arr, int size) {
    int i, j;
    int freq[size]; // Array to store frequencies

    // Initialize frequencies to 0
    for (i = 0; i < size; i++) {
        freq[i] = 0;
    }

    // Calculate frequencies
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                freq[i]++;
            }
        }
    }

    // Print frequencies
    printf("Element\tFrequency\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%d\n", arr[i], freq[i]);
    }
}

int main() {
    int arr[] = {5, 6, 7, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    countFrequency(arr, size);

    return 0;
}*/