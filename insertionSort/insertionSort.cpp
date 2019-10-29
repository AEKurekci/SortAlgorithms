#include <iostream>
using namespace std;


int* insertionSort(int list[], int size){
	for (int i; i < size; i++){
		int next = list[i];
		int j;
		
		for(j = i - 1; j >=0 && list[j]>next; j--){
			list[j + 1] = list[j];
		}
		list[j + 1] = next;
	}
	return list;
}

int main() {
	int numbers[] = { 3, 43, 56, 17, 13, 5, 87, 103, 121, 9};
	int lengthOfList = sizeof(numbers)/sizeof(*numbers);
	
	cout<<"############--INSERTION SORT--############"<<endl;
	cout<<"Before Sorting:"<<endl;
	for(int i = 0; i < lengthOfList;i++){
		cout<<numbers[i]<<"\t";
	}
	cout<<endl<<"After Sorting:"<<endl;
	int* sortedList = insertionSort(numbers, lengthOfList);
	for(int i = 0; i < lengthOfList;i++){
		cout<<sortedList[i]<<"\t";
	}
	
	cout<<endl<<"Complexity is O(n^2)";
	return 0;
}
