#include <string.h>
#include <stdio.h>

// swap two integer values passed as pointers
void swap(int* xp, int* yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(int arr[], int n, int swapCount[]) {
  // declare counters for loops
  int i, j;

  // loop through starting from the first element to the second last element
  // because last element will be in place after first pass
  for (i = 0; i < n-1; i++) {
    // loop through assuming that the last i elements are already in place
    for (j = 0; j < n-i-1; j++) {
      // swap elements if current word is greater than the next element
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);

        // Increment swap count for both elements
        swapCount[arr[j]]++;
        swapCount[arr[j+1]]++;
      }
    }
  }
}

void selectionSort(int arr[], int n, int swapCount[]) {
  // declare counters and value for the minimum index
  int i, j, min_idx;

  for (i = 0; i < n-1; i++) {
    // set minimum index to first element
    min_idx = i;
    
    // loop through the array to find the minimum element
    for (j = i+1; j < n; j++) {
      // if item at j is less than current min set min_idx to j
      if (arr[j] < arr[min_idx]) 
        min_idx = j;
    }

    // if min_idx is not the same as original i, swap the elements so that smallest
    // element is at the beginning
    if (min_idx != i) {
      // increment swap count for both elements
      swapCount[arr[min_idx]]++;
      swapCount[arr[i]]++;

      swap(&arr[min_idx], &arr[i]);
    }
  }
}

void printSwapCounts(int arr[], int n, int swapCount[]) {
  // value to store total numbre of swaps
  int totalSwaps = 0;
  
  // loop through the array and print the number of swaps for each element
  for (int i = 0; i < n; i++) {
    printf("%d: swapped %d time(s)\n", arr[i], swapCount[arr[i]]);
    totalSwaps += swapCount[arr[i]]; // increment totalswaps
  }
  
  // divide by 2 each individual swap is being counted twice once on each number swapped
  printf("Total Swaps: %d\n", totalSwaps/2); 
}

int main() {
  // initialize the example arrays
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

  // calculate the size of the arrays for length values
  int n1 = sizeof(array1)/sizeof(array1[0]);
  int n2 = sizeof(array2)/sizeof(array2[0]);

  // initialize swap count arrays to hold ints for up to 100 elements
  int swapCount1[101] = {0};
  int swapCount2[101] = {0};

  // perform bubble sort on first array
  bubbleSort(array1, n1, swapCount1);
  printf("array1 bubble sort:\n");
  printSwapCounts(array1, n1, swapCount1);

  // reset swap count1 array
  memset(swapCount1, 0, sizeof(swapCount1));

  // reset array to unsorted state
  int array1Reset[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  memcpy(array1, array1Reset, sizeof(array1Reset));

  // perform selection sort on new reset array
  selectionSort(array1, n1, swapCount1);
  printf("\narray1 selection sort:\n");
  printSwapCounts(array1, n1, swapCount1);


  // perform bubble sort on the second array
  bubbleSort(array2, n2, swapCount2);
  printf("\narray2 bubble sort:\n");
  printSwapCounts(array2, n2, swapCount2);

  // reset swap count2 array
  memset(swapCount2, 0, sizeof(swapCount2));

  // reset array2 to unsorted state
  int array2Reset[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  memcpy(array2, array2Reset, sizeof(array2Reset));

  // perform selection sort on the second array
  selectionSort(array2, n2, swapCount2);
  printf("\narray2 selection sort:\n");
  printSwapCounts(array2, n2, swapCount2);

  return 0;
}
