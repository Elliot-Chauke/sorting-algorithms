//Sorting Algorithms

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <math.h>
using namespace std;


//bubble sort algorithm
void bubbleSort(vector<int>& arr,int length)
{
  for(int iter = 1;iter < length; ++iter) //loop to iteration number of times
  {
    for(int index=0;index<length-iter;++index)//loop till the items are sorted
    {
      if(arr[index]>arr[index+1])//checks if the index is greater than the next index
      {
          int temp=arr[index];//declare a temporary variable to store an index
          arr[index]=arr[index+1];//storing the next index to the first index
          arr[index+1]=temp;//store the next index to the temporary index
      }
    }
  }
}

// Function to merge two halves
void merge(vector<int>& arr, int leftIndex, int mid, int rightIndex)
{
    int i = leftIndex; //initialize the starting index for the left sub-array
    int j = mid + 1; //initialize the starting index for the right sub-array
    int k = 0; //Initialize the index for the temporary array

   int size = (rightIndex - leftIndex) + 1; //Calculate the size of the temporary array
   vector<int> temp(size); //Temporary array to store merged elements

    //merging the elements of both sub-arrays to temporary array
    while (i <= mid && j <= rightIndex)
        {
        //Check if the left element is less than the right element
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];//Add the small element into temporary array
            i++; //move to the next element in the left sub-array
            k++; //Add the next element to the temporary array

        }
        //If the right element is smaller than the left element
        else
         {
            temp[k] = arr[j]; //Add the small element into temporary array
            j++; //move to the next element in the right sub-array
            k++; //Add the next element to the temporary array
        }
    }

    //copy the remaining elements from the left sub-array to temporary array
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    //copy the remaining elements from the left sub-array to temporary array
    while (j <= rightIndex)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

   //copy the merged elements into the original array
    for(int n = 0; n < size; n++)
    {
        arr[leftIndex + n] = temp[n];
    }
}

// Function to implement merge sort
void mergeSort(vector<int>& arr, int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) //check if the array has more than one element
    {
        int mid = leftIndex + (rightIndex - leftIndex) / 2; //Divide the array to find the middle point
        mergeSort(arr, leftIndex, mid); //Sort the left sub-array
        mergeSort(arr, mid + 1, rightIndex); //sort the right sub-array
        merge(arr, leftIndex, mid, rightIndex); //Merge the sorted sub-arrays into one array
    }
}

//Generate random input arrays
vector<int> generateRandomInputArray(int arrySize)
{

vector<int> arr(arrySize);
srand(time(0));
for(int i=0;i<arrySize;++i)
{
    arr[i]=rand()%1000;
}

    return arr;
}


void measureSortingTimeFirstSortingAlgorithm(vector<int>& arr, double& timeExecuted, string& timeComplexity)
{
     //measure start time
     auto start = chrono::steady_clock::now();
    // Call your first sorting algorithm
    bubbleSort(arr, arr.size());
    // Measure end time

     auto end = chrono::steady_clock::now();
    // Calculate execution time in nanoseconds for first sorting algorithm
    double time = double(chrono::duration_cast<chrono::nanoseconds>(end-start).count());
    timeExecuted=time/1e9;
  //calculate time comlexity for your sorting algorithm
    timeComplexity = "O(n^2)";


}

void measureSortingTimeSecondSortingAlgorithm(vector<int>& arr , double &timeExecuted, string& timeComplexity )
{    //measure start time
     auto start = chrono::steady_clock::now();
    // Call your first sorting algorithm
    bubbleSort(arr, arr.size());
    // Measure end time

     auto end = chrono::steady_clock::now();
    // Calculate execution time in nanoseconds for first sorting algorithm
    double time = double(chrono::duration_cast<chrono::nanoseconds>(end-start).count());
    timeExecuted=time/1e9;
  //calculate time comlexity for your sorting algorithm
   timeComplexity = "O(nlog(n))";


}


int main()
{
 //Initialize the size of the array
 int inputSize1=100;
 int inputSize2=1000;
 int inputSize3=5000;
 //Generate random input array for different sizes and store them
 vector<int> arr1=generateRandomInputArray(inputSize1);
 vector<int> arr2=generateRandomInputArray(inputSize2);
 vector<int> arr3=generateRandomInputArray(inputSize3);
 double timeExecuted1, timeExecuted2, timeExecuted3;
 string timeComplexity1, timeComplexity2, timeComplexity3;

 //Input array of size 100
 cout<<"Input Size: "<<inputSize1<<endl;
 cout<<"======================="<<endl;

 //Bubble sort
 cout<<"Bubble sort: "<<endl;
 bubbleSort(arr1,inputSize1); //Call bubble sort function
 //call the function that measure time executed
 measureSortingTimeFirstSortingAlgorithm(arr1,timeExecuted1,timeComplexity1);
 cout<<"Execution Time: "<<fixed<<setprecision(5)<<timeExecuted1<<" seconds"<<endl;
 cout<<"\n"<<endl;

 //Merge sort
 cout<<"Merge sort: "<<endl;
 mergeSort(arr1 ,0 ,inputSize1-1);  //Call merge sort function
 //call the function that measure time executed
 measureSortingTimeSecondSortingAlgorithm(arr1,timeExecuted1,timeComplexity1);
 cout<<"Execution Time: "<<fixed<<setprecision(5)<<timeExecuted1<<" seconds"<<endl;
 cout<<"\n"<<endl;

 //Input array of size 1000
 cout<<"Input Size: "<<inputSize2<<endl;
 cout<<"======================="<<endl;

 //Bubble sort
 cout << "Bubble sort: " << endl;
 bubbleSort(arr2,inputSize2); //Call bubble sort function
 //call the function that measure time executed
 measureSortingTimeFirstSortingAlgorithm(arr2,timeExecuted2,timeComplexity2);
 cout<<"Execution Time: "<<fixed<<setprecision(5)<<timeExecuted2<<" seconds"<<endl;
 cout<<"\n"<<endl;

 //Merge sort
 cout<<"Merge sort: "<<endl;
 mergeSort(arr2 ,0 ,inputSize2-1);  //Call merge sort function
 measureSortingTimeSecondSortingAlgorithm(arr2,timeExecuted2,timeComplexity2);
 cout<<"Execution Time: "<<fixed<<setprecision(5)<<timeExecuted2<<" seconds"<<endl;
 cout<<"\n"<<endl;

 ////Input array of size 5000
 cout<<"Input Size: "<<inputSize3<<endl;
 cout<<"======================="<<endl;

 //Bubble sort
 cout<<"Bubble sort: "<<endl;
 bubbleSort(arr3,inputSize3);  //Call bubble sort function
 measureSortingTimeFirstSortingAlgorithm(arr3,timeExecuted3,timeComplexity3);
 cout<<"Execution Time: "<<fixed<<setprecision(5)<<timeExecuted3<<" seconds"<<endl;
 cout<<"\n"<<endl;

 //Merge sort
 cout<<"Merge sort: "<<endl;
 mergeSort(arr3 ,0 ,inputSize3-1);  //Call merge sort function
 measureSortingTimeSecondSortingAlgorithm(arr3,timeExecuted3,timeComplexity3);
 cout<<"Execution Time: "<<fixed<<setprecision(5)<<timeExecuted3<<" seconds"<<endl;
 cout<<"\n"<<endl;


  //Time Complexity
  measureSortingTimeFirstSortingAlgorithm(arr3,timeExecuted3,timeComplexity3);
  cout<<"The time complexity formula for Bubble sort: "<<timeComplexity1<<endl;
  measureSortingTimeSecondSortingAlgorithm(arr3,timeExecuted3,timeComplexity3);
  cout<<"The time complexity formula for Merge sort: "<<timeComplexity2<<endl;


 return 0;
}
