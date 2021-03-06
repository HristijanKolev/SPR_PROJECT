#include<stdio.h> 
#include<stdlib.h> 
#include <time.h>
#include <pthread.h>
const char* filename="first.txt";
const char* filename2="second.txt";
const char* filename3="third.txt";
const char* filename4="fourth.txt";
const char* filename5="fifth.txt";
float result[4];
float result1[3];
#define NUM_THREADS     4
#define NUM_THREAD     3

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUICK SORT!!!!! ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
}
 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 


/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
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




// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ BUBBLE SORT!!!!! ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void swap_b(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
int i, j; 
for (i = 0; i < n-1; i++)	 

	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap_b(&arr[j], &arr[j+1]); 
} 


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ SHELL SORT!!!!! ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// Shell Sort in C programming



// Shell sort
void shellSort(int array[], int n) {

  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
        array[j] = array[j - gap];
      }
      array[j] = temp;
    }
  }
}



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ MERGE SORT!!!!! ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


/* C program for Merge Sort */


// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Benchmark quick_sort Function!!!!! ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
float Benchmark_q_s(const char* filename, int size)
{
time_t start,end;
FILE *fp = NULL;
int arr[size];
int i;
if(NULL==(fp = fopen(filename, "r"))) {printf("ERROR");}

for (i = 0; i < size; i++)
    	{
        fscanf(fp, "%d", &arr[i]);
    	}
	int n = sizeof(arr)/sizeof(arr[0]); 
	time(&start);
	quickSort(arr, 0, n-1); 
	time(&end);
	fclose(fp);
	long result = end -start;
	return result;
}

void* Benchmark_quick_sort()
{
//printf("\nQuicksort: \n");
float first = Benchmark_q_s(filename, 100000);
//printf("1st file took %f seconds to sort.\n",first);
float second = Benchmark_q_s(filename2, 100000);
//printf("2nd file took %f seconds to sort.\n",second);
float third = Benchmark_q_s(filename3, 500000);
//printf("3rd file took %f seconds to sort.\n",third);
float fourth = Benchmark_q_s(filename4, 150000);
//printf("4th file took %f seconds to sort.\n",fourth);
float fifth = Benchmark_q_s(filename5, 1000000);
//printf("5th file took %f seconds to sort.\n",fifth);

	float r = (first + second + third + fourth + fifth)/(float)5;
	
	FILE* fptr; 
	fptr = fopen("quick_s_result.txt", "a"); 
	if (fptr == NULL) { 
	printf("ERROR"); 
	exit(1); 
	} 
	fprintf(fptr, "Quicksort benchmark results:\n1st file took %f seconds to sort.\n2nd file took %f seconds to sort.\n3rd file took %f seconds to sort.\n4th file took %f seconds to sort.\n5th file took %f seconds to sort.\nAverage is:%f\n-----------------------------------------\n",first, second, third, fourth, fifth,r); 	 
	fclose(fptr);

	result[0] = r;

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Benchmark shell_sort Function!!!!! ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
float Benchmark_s_s(const char* filename, int size)
{
time_t start,end;
FILE *fp = NULL;
int arr[size];
int i;
if(NULL==(fp = fopen(filename, "r"))) {printf("ERROR");}

for (i = 0; i < size; i++)
    	{
        fscanf(fp, "%d", &arr[i]);
    	}
	int n = sizeof(arr)/sizeof(arr[0]); 
	time(&start);
	shellSort(arr, n); 
	time(&end);
	fclose(fp);
	long result = end -start;


	return result;
}
void* Benchmark_shell_sort()
{
//printf("\nShell sort: \n");
float first = Benchmark_s_s(filename, 100000);
//printf("1st file took %f seconds to sort.\n",first);
float second = Benchmark_s_s(filename2, 100000);
//printf("2nd file took %f seconds to sort.\n",second);
float third = Benchmark_s_s(filename3, 500000);
//printf("3rd file took %f seconds to sort.\n",third);
float fourth = Benchmark_s_s(filename4, 150000);
//printf("4th file took %f seconds to sort.\n",fourth);
float fifth = Benchmark_s_s(filename5, 1000000);
//printf("5th file took %f seconds to sort.\n",fifth);

	float r = (first + second + third + fourth + fifth)/(float)5;
	
	FILE* fptr; 
	fptr = fopen("shell_s_result.txt", "a"); 
	if (fptr == NULL) { 
	printf("ERROR"); 
	exit(1); 
	} 
	fprintf(fptr, "Shell sort benchmark results:\n1st file took %f seconds to sort.\n2nd file took %f seconds to sort.\n3rd file took %f seconds to sort.\n4th file took %f seconds to sort.\n5th file took %f seconds to sort.\nAverage is:%f\n-----------------------------------------\n",first, second, third, fourth, fifth,r); 	 
	fclose(fptr);
	
	result[1] = r;
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Benchmark merge_sort Function!!!!! ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

float Benchmark_m_s(const char* filename, int size)
{
time_t start,end;
FILE *fp = NULL;
int arr[size];
int i;
if(NULL==(fp = fopen(filename, "r"))) {printf("ERROR");}

for (i = 0; i < size; i++)
    	{
        fscanf(fp, "%d", &arr[i]);
    	}
	int n = sizeof(arr)/sizeof(arr[0]); 
	time(&start);
	shellSort(arr, n); 
	time(&end);
	fclose(fp);
	long result = end -start;

	return result;
}
void* Benchmark_merge_sort()
{
//printf("\nMerge sort: \n");
float first = Benchmark_m_s(filename, 100000);
//printf("1st file took %f seconds to sort.\n",first);
float second = Benchmark_m_s(filename2, 100000);
//printf("2nd file took %f seconds to sort.\n",second);
float third = Benchmark_m_s(filename3, 500000);
//printf("3rd file took %f seconds to sort.\n",third);
float fourth = Benchmark_m_s(filename4, 150000);
//printf("4th file took %f seconds to sort.\n",fourth);
float fifth = Benchmark_m_s(filename5, 1000000);
//printf("5th file took %f seconds to sort.\n",fifth);

	float r = (first + second + third + fourth + fifth)/(float)5;
	
	FILE* fptr; 
	fptr = fopen("merge_s_result.txt", "a"); 
	if (fptr == NULL) { 
	printf("ERROR"); 
	exit(1); 
	} 
	fprintf(fptr, "Merge sort benchmark results:\n1st file took %f seconds to sort.\n2nd file took %f seconds to sort.\n3rd file took %f seconds to sort.\n4th file took %f seconds to sort.\n5th file took %f seconds to sort.\nAverage is:%f\n-----------------------------------------\n",first, second, third, fourth, fifth,r); 	 
	fclose(fptr);
	
	result[2] = r;
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Benchmark bubble_sort !!!!! +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
 float Benchmark_b_s(const char* filename, int size)
{
time_t start,end;
FILE *fp = NULL;
int arr[size];
int i;
if(NULL==(fp = fopen(filename, "r"))) {printf("ERROR");}

for (i = 0; i < size; i++)
    	{
        fscanf(fp, "%d", &arr[i]);
    	}
	int n = sizeof(arr)/sizeof(arr[0]); 
	time(&start);
	shellSort(arr, n); 
	time(&end);
	fclose(fp);
	long result = end -start;


	return result;
}
void* Benchmark_bubble_sort()
{
//printf("\nBubble sort: \n");
float first = Benchmark_b_s(filename, 100000);
//printf("1st file took %f seconds to sort.\n",first);
float second = Benchmark_b_s(filename2, 100000);
//printf("2nd file took %f seconds to sort.\n",second);
float third = Benchmark_b_s(filename3, 500000);
//printf("3rd file took %f seconds to sort.\n",third);
float fourth = Benchmark_b_s(filename4, 150000);
//printf("4th file took %f seconds to sort.\n",fourth);
float fifth = Benchmark_b_s(filename5, 1000000);
//printf("5th file took %f seconds to sort.\n",fifth);

	float r = (first + second + third + fourth + fifth)/(float)5;
	
	FILE* fptr; 
	fptr = fopen("bubble_s_result.txt", "a"); 
	if (fptr == NULL) { 
	printf("ERROR"); 
	exit(1); 
	} 
	fprintf(fptr, "Bubble sort benchmark results:\n1st file took %f seconds to sort.\n2nd file took %f seconds to sort.\n3rd file took %f seconds to sort.\n4th file took %f seconds to sort.\n5th file took %f seconds to sort.\nAverage is:%f\n-----------------------------------------\n",first, second, third, fourth, fifth,r); 	 
	fclose(fptr);
	
	result[3] = r;
}

 
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ MAIN Function!!!!! ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void* (*ptr[4])() = {Benchmark_quick_sort, Benchmark_shell_sort, Benchmark_merge_sort, Benchmark_bubble_sort};





int main() 
{ 
	

float quick;
float shell;
float merge;
float bubble;
int best;
int worst;
int i;
int r;
char answer;

/*
pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, ptr[t], NULL);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
	//pthread_join(threads[t],NULL);
   }
        

	pthread_exit(NULL);

	printf("HELLO");		
*/	

    pthread_t threads[NUM_THREADS];
    pthread_create(&threads[0], NULL, ptr[0], NULL);
    pthread_create(&threads[1], NULL, ptr[1], NULL);
    pthread_create(&threads[2], NULL, ptr[2], NULL);
    pthread_create(&threads[3], NULL, ptr[3], NULL);
    pthread_join(threads[0],NULL);
    pthread_join(threads[1],NULL);
    pthread_join(threads[2],NULL);
    pthread_join(threads[3],NULL);	
	

quick = result[0];
shell = result[1];
merge = result[2];
bubble = result[3];
	printf("\nQuicksort result: %f.\n",result[0]);
	printf("\nShell sort result: %f.\n",result[1]);
	printf("\nMerge sort result: %f.\n",result[2]);
	printf("\nBubble sort result: %f.\n",result[3]);	
	

if((quick<shell) && (quick<merge) && (quick<bubble))
        {printf("\nQuicksort is the best sorting algorithm\n");}
    else if((shell<quick) && (shell<merge) && (shell<bubble))
        {printf("\nShell sort is the best sorting algorithm\n");}
    else if((merge<shell) && (merge<quick) && (merge<bubble))
        {printf("\nMerge sort is the best sorting algorithm\n");}
    else if((bubble<shell) && (bubble<merge) && (bubble<quick))
        {printf("\nBubble sort is the best sorting algorithm\n");}
        
        
        else if((bubble==shell))
        {printf("\nBubble and Shell are best!\n");}
        else if((bubble==quick))
        {printf("\nBubble and Quick are best!\n");}
        else if((bubble==merge))
        {printf("\nBubble and Merge are best!\n");}
	else if((shell==merge))
        {printf("\nMerge and Shell are best!\n");}
        else if((shell==quick))
        {printf("\nQuick and Shell are best!\n");}
        else if((merge==quick))
        {printf("\nMerge and Quick are best!\n");}
	
	
	
	
pthread_t thread[NUM_THREAD];
if((quick>shell) && (quick>merge) && (quick>bubble))
        {
        printf("\nQuicksort is the worst sorting algorithm\n");
        ptr[0] = NULL;
        printf("\nDo you want to continue? Type y/n\n");
        scanf("%s", &answer);
        if(answer == 'y'){
        
    pthread_create(&thread[0], NULL, ptr[1], NULL);
    pthread_create(&thread[1], NULL, ptr[2], NULL);
    pthread_create(&thread[2], NULL, ptr[3], NULL);
    
    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);
    pthread_join(thread[2],NULL);	
	


shell = result[0];
merge = result[1];
bubble = result[2];

	printf("\nShell sort result: %f.\n",result[0]);
	printf("\nMerge sort result: %f.\n",result[1]);
	printf("\nBubble sort result: %f.\n",result[2]);
        }
        }
    else if((shell>quick) && (shell>merge) && (shell>bubble))
        {
        printf("\nShell sort is the worst sorting algorithm\n");
        ptr[1] = NULL;
        printf("\nDo you want to continue? Type y/n\n");
        scanf("%s", &answer);
        if(answer == 'y'){
        pthread_create(&threads[0], NULL, ptr[0], NULL);

    pthread_create(&threads[1], NULL, ptr[2], NULL);
    pthread_create(&threads[2], NULL, ptr[3], NULL);
    pthread_join(threads[0],NULL);

    pthread_join(threads[1],NULL);
    pthread_join(threads[2],NULL);	
	

quick = result[0];

merge = result[1];
bubble = result[2];
	printf("\nQuicksort result: %f.\n",result[0]);

	printf("\nMerge sort result: %f.\n",result[1]);
	printf("\nBubble sort result: %f.\n",result[2]);
        }
        
        }
    else if((merge>shell) && (merge>quick) && (merge>bubble))
        {
        printf("\nMerge sort is the worst sorting algorithm\n");
        ptr[2] = NULL;
        printf("\nDo you want to continue? Type y/n\n");
        scanf("%s", &answer);
        if(answer == 'y'){
        pthread_create(&threads[0], NULL, ptr[0], NULL);
    pthread_create(&threads[1], NULL, ptr[1], NULL);

    pthread_create(&threads[2], NULL, ptr[3], NULL);
    pthread_join(threads[0],NULL);
    pthread_join(threads[1],NULL);

    pthread_join(threads[2],NULL);	
	

quick = result[0];
shell = result[1];

bubble = result[2];
	printf("\nQuicksort result: %f.\n",result[0]);
	printf("\nShell sort result: %f.\n",result[1]);

	printf("\nBubble sort result: %f.\n",result[2]);
        }
        }
    else if((bubble>shell) && (bubble>merge) && (bubble>quick))
        {
        printf("\nBubble sort is the worst sorting algorithm\n");
        ptr[3] = NULL;
        printf("\nDo you want to continue? Type y/n\n");
        scanf("%s", &answer);
        if(answer == 'y'){
        pthread_create(&threads[0], NULL, ptr[0], NULL);
    pthread_create(&threads[1], NULL, ptr[1], NULL);
    pthread_create(&threads[2], NULL, ptr[2], NULL);

    pthread_join(threads[0],NULL);
    pthread_join(threads[1],NULL);
    pthread_join(threads[2],NULL);
	
	

quick = result[0];
shell = result[1];
merge = result[2];

	printf("\nQuicksort result: %f.\n",result[0]);
	printf("\nShell sort result: %f.\n",result[1]);
	printf("\nMerge sort result: %f.\n",result[2]);

        }
        }
	return 0; 
} 

