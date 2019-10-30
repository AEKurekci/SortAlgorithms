#include <iostream>
using namespace std;

int partition(int list[], int i, int j){
	int pivot = list[i];
	int m = i;
	
	for (int k = i + 1;k <= j;k++){
		if(list[k] < pivot){
			m++;
			//swapping
			int swapItem = list[k];
			list[k] = list[m];
			list[m] = swapItem;
		}
	}
	//swapping
	int swapItem2 = list[i];
	list[i] = list[m];
	list[m] = swapItem2;
	return m;
}

int* quickSort(int list[], int low, int high){
	if(low < high){
		int pivotId = partition(list, low, high);
		
		quickSort(list, low, pivotId - 1);
		quickSort(list, pivotId + 1, high);
	}
	return list;
}


int main() {int numbers[] = { 3, 43, 56, 17, 13, 5, 87, 103, 121, 9};
	int lengthOfList = sizeof(numbers)/sizeof(*numbers);
	
	cout<<"############--QUICK SORT--############"<<endl;
	cout<<"Before Sorting:"<<endl;
	for(int i = 0; i < lengthOfList;i++){
		cout<<numbers[i]<<"\t";
	}
	cout<<endl<<"After Sorting:"<<endl;
	int* sortedList = quickSort(numbers, 0, lengthOfList - 1);
	for(int i = 0; i < lengthOfList;i++){
		cout<<sortedList[i]<<"\t";
	}
	
	cout<<endl<<"Complexity is O(n^2)";
	return 0;
}
