#include <iostream>
using namespace std;

void merge(int list[], int low, int mid, int high){
	int n = high - low + 1;
	int* b = new int[n];
	int left = low, right = mid + 1;
	int bId = 0;
	while (left <= mid && right <= high){
		if(list[left] <= list[right]){
			b[bId++] = list[left++];
		}
		else{
			b[bId++] = list[right++];
		}
	}
	while(left <= mid){
		b[bId++] = list[left++];
	}
	while(right <= high){
		b[bId++] = list[right++];
	}
	
	for(int k = 0; k < n;k++){
		list[low + k] = b[k];
	}
	delete [] b;
}

int* mergeSort(int list[], int low, int high){
	if(low < high){
		int mid = (low + high) / 2;
		mergeSort(list, low, mid);
		mergeSort(list, mid + 1, high);
		//all items separated until calling merge
		merge(list, low, mid, high);
		//then merged(birleþtirildi)
		return list;
	}
}

int main() {
	int numbers[] = { 3, 43, 56, 17, 13, 5, 87, 103, 121, 9};
	int lengthOfList = sizeof(numbers)/sizeof(*numbers);
	
	cout<<"############--MERGE SORT--############"<<endl;
	cout<<"Before Sorting:"<<endl;
	for(int i = 0; i < lengthOfList;i++){
		cout<<numbers[i]<<"\t";
	}
	cout<<endl<<"After Sorting:"<<endl;
	int* sortedList = mergeSort(numbers,0 , lengthOfList - 1);
	for(int i = 0; i < lengthOfList;i++){
		cout<<sortedList[i]<<"\t";
	}
	
	cout<<endl<<"Complexity is O(n*logn)";
	return 0;
}
