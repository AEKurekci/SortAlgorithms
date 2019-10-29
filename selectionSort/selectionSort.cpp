#include<iostream>

using namespace std;

int* selectionSort(int numbers[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		int maxId = i;
		for (int j = 0; j < i; j++) {
			if (numbers[j] >= numbers[maxId]) {
				maxId = j;
			}
		}
		//swapping
		int val1 = numbers[i];
		numbers[i] = numbers[maxId];
		numbers[maxId] = val1;
	}
	
	return numbers;
}

int main() {
	int numbers[] = { 3, 43, 56, 17, 13, 5, 87, 103, 121, 9};
	int arraySize = sizeof(numbers) / sizeof(*numbers);
	
	cout<<"#############---SELECTION SORTING--#############"<<endl;
	
	cout<<"Before Sorting: "<<endl;
	
	for (int i = 0; i < arraySize; i++) {
		cout <<numbers[i]<<" ";
	}
	
	int* sortedNumbers = selectionSort(numbers, arraySize);
	
	cout<<endl;
	cout<<"After Sorting: "<<endl;
	
	for (int i = 0; i < arraySize; i++) {
		cout <<sortedNumbers[i]<<" ";
	}
	
	cout<<endl<<"Complexty is O(n^2)";
}
