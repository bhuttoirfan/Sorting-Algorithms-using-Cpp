#include<iostream>
#include <ctime> //calculates time taken in milliseconds
using namespace std;

//Selection Sort
void swap(int *x,int *y){ 
    int tmp=*x; 
    *x=*y; 
    *y=tmp; 
}

void selectionSort(int arr[],int n){ 
    int i,j,index; 
    float start=clock();    //Starting calculating time
	// One by one move boundary of unsorted subarray 
    for(i=0;i<n-1;i++){ 
        // Find the minimum element in unsorted array 
        index=i; 
        for(j=i+1;j<n;j++){
          if(arr[j]<arr[index]) 
            index=j;
		}
        // Swap the found minimum element with the first element     
		swap(&arr[index],&arr[i]);
	}
	float stop=clock();  //Calculating Total time
cout << "time taken: " <<(stop-start)/double(CLOCKS_PER_SEC)*1000<<endl; 
} 
//End of Selection Sort.

//Bubble Sort 
void bubbleSort(int arr[], int n){ 
   int i,j;
   float start,stop;
   start=clock(); 
   for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){  
           if (arr[j]>arr[j+1]) 
              swap(&arr[j], &arr[j+1]);
		}
   }
   stop=clock();
   cout << "time taken:" <<(stop-start)/double(CLOCKS_PER_SEC)*1000<<endl; 
} 
//End of Bubble Sort.

//Insertion Sort
void insertionSort(int arr[], int n){ 
   int i,j,k;
   float start,stop;
   start=clock(); 
   for (i=1;i<n;i++){ 
       k=arr[i]; 
       j=i-1;
       while (j>=0 && arr[j]>k){ 
           arr[j+1]=arr[j]; 
           j=j-1; 
       } 
       arr[j+1]=k; 
   }
   stop=clock();
   cout << "time taken: " <<(stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;	 
} 
//End of Insertion Sort.

//Merge Sort
void Merge(int *a,int low,int high,int mid){
	// We have low to mid and mid+1 to high already sorted.
	int i,j,k,temp[high-low+1];
	i=low;
	k=0;
	j=mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high){
		if(a[i]<a[j]){
			temp[k]=a[i];
			k++;
			i++;
		}else{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	// Insert all the remaining values from i to mid into temp[].
	while(i<=mid){
		temp[k]=a[i];
		k++;
		i++;
	}
	// Insert all the remaining values from j to high into temp[].
	while(j<=high){
		temp[k]=a[j];
		k++;
		j++;
	}
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++){
		a[i] = temp[i-low];
	}
}
   void mergeSort(int *arr,int low,int high){
	int mid;
	float start,stop;
	start=clock();
	if(low<high){
		mid=(low+high)/2;
		// Split the data into two half.
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		// Merge them to get sorted output.
		Merge(arr, low, high, mid);
	}
	stop=clock();
	cout << "time taken: " <<(stop-start)/double(CLOCKS_PER_SEC)*1000<<endl;
}

//Quick Sort
int partition (int arr[], int low, int high){ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for(int j=low;j<=high-1;j++){ 
        // If current element is smaller than or 
        // equal to pivot 
        if(arr[j]<=pivot){ 
            i++;    // increment index of smaller element 
            swap(&arr[i],&arr[j]); 
        } 
    } 
    swap(&arr[i + 1],&arr[high]); 
    return (i + 1); 
} 

void quickSort(int array[],int low,int high){ 
    int start,stop;
    start=clock();
	if(low<high){ 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi=partition(array,low,high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(array,low,pi-1); 
        quickSort(array,pi+1,high); 
    }
	stop=clock();
	cout << "time taken: " <<stop-start<<endl; 
} 

//Output Display
void Display(int array[],int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<"\t";
	}
}

int main(){
	int ch,a[11]={12,54,9,1,44,53,7,8,20,66,45};
	int num;
	
	do{
	cout<<"Enter choice \n1 for Selection sort\n2 for Bubble sort sort\n3 for Insertion sort\n4 for Merge sort\n5 for Quick sort:";
	cin>>ch;
	
	switch(ch){
		case 1:
			selectionSort(a,11);
			Display(a,11);
			break;
		case 2:
			bubbleSort(a,11);
			Display(a,11);
			break;
		case 3:
			insertionSort(a,11);
			Display(a,11);
			break;
		case 4:
			mergeSort(a,0,10);
			Display(a,11);
			break;
		case 5:
			mergeSort(a,0,10);
			Display(a,11);
			break;					
	}
	cout<<endl<<"Enter 0 to End sorting else any number:";
	cin>>num;cout<<endl;
	}while(num!=0);
}
