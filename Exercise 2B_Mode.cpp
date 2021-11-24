#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot */
int partition (int arr[], int low, int high) 
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++) 
    {
		if (arr[j] <= pivot) 
        {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
 * arr[] --> Array to be sorted,
 * low --> Starting index,
 * high --> Ending index
 */
void quickSort(int arr[], int low, int high) 
{
	if (low < high) 
    {
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void print_array(int arr[], int size)
{
	int a;
	for (a = 0; a < size; a++)
    {
	    cout << arr[a];
    }
}

void modeFinder(int arr[], int size) //Only use after Sort Ascending or Descending 
{
    int a;

    int past = arr[0];

    int mode = arr[0];

    int combo_1 = 1;
    int combo_2 = 1;

    for (a = 0; a < size; a++)
    {
        if(arr[a] = past)
        {
            combo_2++;
        }
        else if(arr[a] != past)
        {
            if(combo_2 > combo_1)
            {
                combo_1 = combo_2;
                combo_2 = 1;
                mode = arr[a];
            }
            else
            {
                combo_2 = 1;
            }
        }
    }

    //Print out mode
}


int main()
{
    ifstream myFile;
    string line;

    int count = 1;
    int n;
    int i = 0;
    int j = 0;

    int arrX[n];
    int arrY[n];

    myFile.open("D:\\Download\\data1.csv");
    
    while(myFile.good())
    {
        getline(myFile, line, ',');

        if(count % 2 != 0)
        {
            arrX[i] = stoi(line);
            i++;
        }
        else
        {
            arrY[j] = stoi(line);
            j++;
        }
        count++;
    }

    int finArrX[i];
    for(int a = 0; a < i; a++)
    {
        finArrX[a] = arrX[a];
    }
    quickSort(finArrX, 0, i - 1);
    modeFinder(finArrX, i);


    int finArrY[j];
    for(int a = 0; a < j; a++)
    {
        finArrX[a] = arrX[a];
    }
    quickSort(finArrY, 0, j - 1);
    modeFinder(finArrY, j);

    myFile.close();
}
