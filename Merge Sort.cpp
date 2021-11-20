#include<iostream>
using namespace std;
int count=0;

int mergePartition(int arr[],int low,int high,int mid)
{
	int l,h,k,temp[high-low+1];
	l=low;
	k=0;
	h=mid+1;	
	while(l<=mid&&h<=high) 
	{
		if(arr[l]<arr[h])
		{
			temp[k]=arr[l];
			k++;
			l++;
		}
		else
		{
			temp[k]=arr[h];
			k++;
			h++;
			count=count+(mid-l);
		}
	}
	
	while(l<=mid)  
	{
		temp[k]=arr[l];
		k++;
		l++;
	}
	
	while(h<=high) 
	{
		temp[k]=arr[h];
		k++;
		h++;
		return count;
	}
	
	for(int i=low;i<=high;i++)
	{
		arr[i]=temp[i];
	}
}

int mergeSort(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		count=mergeSort(arr,low,mid);    
		count+=mergeSort(arr,mid+1,high); 
		count+=mergePartition(arr,low,high,mid);  
	}
	return count;
}

int display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
	cout<<"INVERSION COUNT OF ARRAY: "<<count<<endl;
}

int main()
{
	int arr[5]={2,4,1,3,5};
	
	mergeSort(arr,0,4);
	display(arr,5);
}
