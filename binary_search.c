#include<stdio.h>


int binary_search(int [],int, int, int);

int main(){

	int  input_arr[] = {1,2,3,4,5,6,7,8,9,10};
	int high = sizeof(input_arr)/sizeof(input_arr[0]);
	int low = 0;
	int ret = binary_search(input_arr,low,high-1,1);
	if (ret == -1)
		printf("Not found");
	else
		printf("Found at %d\n",ret);
}

int binary_search(int arr[],int low, int high, int data){

	int mid = low + (high-low)/2;
	if ( low > high )
		return -1;
	if(arr[mid] == data){
		printf("Found\n");
		return mid;
	}
	if(arr[mid] > data){
	  return binary_search(arr, low,mid,data);
	} else
	  return binary_search(arr,mid+1, high,data);

}

