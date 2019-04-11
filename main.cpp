#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <chrono>

//Muniru Lamin
//COSC320 Lab-3

using namespace std;

struct Heap{
	int *arr;
	int length;
	int heap_size;

	int& operator[](int i)
	{	
		return arr[i - 1];
	}
	~Heap()
	{
		delete [] arr;
	}
};

//Prints out the numbers of the array in a heap tree form.
void PrintMaxHeap(Heap &A)
{

	int level = 0;
	int numItems = 1;
	int numprinted = 0;

	for(int i = 1; i <= A.length; i++)
	{
		if(numprinted == 0)
			cout << endl;

		cout << A[i] << " ";
		++numprinted;

		if(numprinted == numItems)
		{	
			++level;
			numItems *= 2;
			numprinted = 0;
		}

	}
	cout << endl;
}


//Does a tournament between 3 of the numbers in the heap tree, where the top one gets placed at the top.
//It does this until the tree is in a max heap form, meaning the largest number is root of other numbers.
void MaxHeapify(Heap &A, int i)
{
	int left = (2 * i);
	int right = (2 * i + 1);
	int largest;

	if(left <= A.heap_size && A[left] > A[i])
	{
		largest = left;
	}
	else
	{
		largest = i;
	}
	if(right <= A.heap_size && A[right] > A[largest])
	{
		largest = right;
	}
	if(largest != i)
	{
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		MaxHeapify(A, largest);
	}
}

//Calls maxheapify to do to sort tree in max heap form.
void BuildMaxHeap(Heap &A)
{
	A.heap_size = A.length;
	for(int i = (A.length / 2); i >= 1; i--)
	{
		MaxHeapify(A, i);
	}
}

//Sorts heap in ascending order.
void HeapSort(Heap &A)
{
	BuildMaxHeap(A);
	for(int i = A.length; i >= 2; i--)
	{
		int temp = A[1];
		A[1] = A[i] ;
		A[i] = temp;
		A.heap_size = A.heap_size - 1;
		MaxHeapify(A, 1);
	}
}

int main()
{
	srand(time(NULL));
	int size = 15;
	Heap Arr;
	Arr.length = size;
	Arr.arr = new int[Arr.length];

	int choice;
	do{

		cout << "Array Menu" << endl;
		cout << "input 1 for sorted arrays " << endl;
		cout << "input 2 for backwards arrays " << endl;
		cout << "input 3 for duplicate arrays " << endl;
		cout << "input 4 for random arrays " << endl;
		cout << "input 5 to end program " << endl;
		cin >> choice;

		if(choice == 1)
		{
			int num;
			cout << "input a size of the array: ";
			cin >> num;
			Heap SortArr;
			SortArr.length = num;
			SortArr.arr = new int[SortArr.length];
			for(int i = 1; i <= num; i++)
			{
				SortArr[i] = (i + 1);
			}
			cout << "Sorted array" << endl;
			auto start = std::chrono::system_clock::now();
			HeapSort(SortArr);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
			//delete [] SortArr.arr;
		}

		if(choice == 2)
		{
			int num;
			cout << "input a size of the array: ";
			cin >> num;
			Heap BackArr;
			BackArr.length = num;
			BackArr.arr = new int[BackArr.length];
			for(int i = 1; i <= num; i++)
			{
				BackArr[i] = (num - (i + 1));
			}
			cout << "BackWards array" << endl;
			auto start = std::chrono::system_clock::now();
			HeapSort(BackArr);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
			//delete [] BackArr.arr;
		}


		if(choice == 3)
		{
			int num;
			cout << "input a size of the array: ";
			cin >> num;
			Heap DupArr;
			DupArr.length = num;
			DupArr.arr = new int[DupArr.length];
			for(int i = 1; i <= num/2; i++)
			{
				DupArr[i] = (i + 1);
			}
			for(int i = num / 2; i < num; i++)
			{
				DupArr[i] = (num - (i + 1));
			}
			cout << "Duplicated array" << endl;
			auto start = std::chrono::system_clock::now();
			HeapSort(DupArr);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
			//delete [] DupArr.arr;
		}


		if(choice == 4)
		{
			int num;
			cout << "input a size of the array: ";
			cin >> num;
			Heap RandArr;
			RandArr.length = num;
			RandArr.arr = new int[RandArr.length];
			for(int i = 1; i <= num; i++)
			{
				RandArr[i] = rand() % 100 + 1;
			}
			cout << "Random array" << endl;
			auto start = std::chrono::system_clock::now();
			HeapSort(RandArr);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
			//delete [] RandArr.arr;
		}

	}while(choice != 5);

//	BuildMaxHeap(Arr);
	//HeapSort(Arr);
	for(int i = 1; i <= size; i++)
	{
		Arr[i] = rand() % 100 + 1;
	}
	

	BuildMaxHeap(Arr);


	int choice1;
	cout << "Print menu" << endl;
	cout << "1 For regular" << endl;
	cout << "2 for heap tree" << endl;
	cin >> choice1;

	if(choice1 == 1)
	{
		for(int i = 1; i <= size; i++)
		{
			cout << Arr[i] << " ";
		}
	}

	if(choice1 == 2 )
	{
		PrintMaxHeap(Arr);
	}
//	delete [] Arr.arr;
	return 0;
}
