#include<iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b)? a:b; // using ternary operator to find max of two numbers
}

int  MaxCrossingSum (int arr[], int low, int mid, int high)
{

    int sum = 0; // initializing sum to zero
    int leftpartsum = -1; // initializing leftpartsum to -1
    for (int i = mid; i >= low; i--) // loop to find max sum of left subarray
    {
        sum = sum + arr[i]; // adding elements of left subarray
        if (sum > leftpartsum) // checking if sum is greater than leftpartsum
            leftpartsum = sum; // if yes then leftpartsum is equal to sum
    }

    sum = 0; // initializing sum to zero
    int rightpartsum = -1; // initializing rightpartsum to -1
    for (int i = mid+1; i <= high; i++) // loop to find max sum of right subarray
    {
        sum = sum + arr[i]; // adding elements of right subarray
        if (sum > rightpartsum) // checking if sum is greater than rightpartsum
            rightpartsum = sum; // if yes then rightpartsum is equal to sum
    }

    return leftpartsum + rightpartsum; // returning sum of leftpartsum and rightpartsum
}

int MaxSubArraySum(int arr[], int low, int high)
{
    int mid; // initializing mid
    if (low == high) // checking if low is equal to high
        return arr[low]; // if yes then return arr[low]


    mid = (low + high)/2; // finding mid
    int  max_sum_left_subarray = MaxSubArraySum(arr, low, mid); // finding max sum of left subarray

    int max_sum_right_subarray =  MaxSubArraySum(arr, mid+1, high); // finding max sum of right subarray

    int  max_sum_crossing_subarray = MaxCrossingSum(arr, low, mid, high); // finding max sum of crossing subarray

    return max ( max ( max_sum_left_subarray,max_sum_right_subarray ), max_sum_crossing_subarray  ); // returning max of three subarrays using max function
}

int main()
{
    int n, i; // initializing n and i
    cout << "Enter the number of data element in the array: ";
    cin >> n; // taking input of n

    int a[n]; // initializing array a
    cout <<"Enter element "<< endl;
    for(i = 0; i < n; i++) // loop to take input of array elements
    {

        cin >> a[i]; // taking input of array elements
    }


    cout <<"Maximum sub-array sum is: "<< MaxSubArraySum(a, 0, n-1); // printing max sum of subarray

    return 0; // returning 0
}
