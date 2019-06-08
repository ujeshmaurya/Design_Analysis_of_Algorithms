#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include <time.h>
#include "sort.h"
int main()
{
	FILE *fp;
    //fp = fopen("input.txt", "w");
    time_t t;
	srand((unsigned) time(&t));
	int n=150000;
    int i,a[n];
    //for(i=0;i<n;i++)
    	//fprintf(fp,"%d\n",rand()%1000000000);
    //fclose(fp);
    long tbs,tbe;
	struct timeval tv;
    printf("\n\tFor data values= %d\n",n);
    
    //Bubble Sorting Portion starts:
    fp = fopen("input.txt", "r");
    for(i=0;i<n;i++)
    	fscanf(fp,"%d",&a[i]);
	gettimeofday(&tv,NULL);
	tbs=(tv.tv_sec *1e+6) + tv.tv_usec;
	bubbleSort(a,n);
	gettimeofday (&tv, NULL);
	tbe=(tv.tv_sec *1e+6) + tv.tv_usec;
	printf("\n\tBubble sort time=\t %ld\n",tbe-tbs);
	fclose(fp);
	//Bubble Sorting Portion ends:
	
	
	//Insertion Sorting Portion starts:
	fp = fopen("input.txt", "r");
    for(i=0;i<n;i++)
    	fscanf(fp,"%d",&a[i]);
	gettimeofday(&tv,NULL);
	tbs=(tv.tv_sec *1e+6) + tv.tv_usec;
	insertionSort(a,n);
	gettimeofday (&tv, NULL);
	tbe=(tv.tv_sec *1e+6) + tv.tv_usec;
	printf("\tInsertion Sort time=\t %ld\n",tbe-tbs);
	fclose(fp);
	//Insertion Sorting Portion ends:
	
	
	//Selection Sorting Portion starts:
	fp = fopen("input.txt", "r");
    for(i=0;i<n;i++)
    	fscanf(fp,"%d",&a[i]);
	gettimeofday(&tv,NULL);
	tbs=(tv.tv_sec *1e+6) + tv.tv_usec;
	selectionSort(a,n);
	gettimeofday (&tv, NULL);
	tbe=(tv.tv_sec *1e+6) + tv.tv_usec;
	printf("\tSelection Sort time=\t %ld\n",tbe-tbs);
	fclose(fp);
	//Selection Sorting Portion ends:
	
	
	
	//Quick Sorting Portion starts:
	fp = fopen("input.txt", "r");
    for(i=0;i<n;i++)
    	fscanf(fp,"%d",&a[i]);
	gettimeofday(&tv,NULL);
	tbs=(tv.tv_sec *1e+6) + tv.tv_usec;
	quickSort(a,0,n-1);
	gettimeofday (&tv, NULL);
	tbe=(tv.tv_sec *1e+6) + tv.tv_usec;
	printf("\tQuick Sort time=\t %ld\n",tbe-tbs);
	fclose(fp);
	//Quick Sorting Portion ends:
	
	
	//Merge Sorting Portion starts:
	fp = fopen("input.txt", "r");
    for(i=0;i<n;i++)
    	fscanf(fp,"%d",&a[i]);
	gettimeofday(&tv,NULL);
	tbs=(tv.tv_sec *1e+6) + tv.tv_usec;
	mergeSort(a,0,n-1);
	gettimeofday (&tv, NULL);
	tbe=(tv.tv_sec *1e+6) + tv.tv_usec;
	printf("\tMerge Sort time=\t %ld\n\n",tbe-tbs);
	fclose(fp);
	//Merge Sorting Portion ends:
	
	return 0;
}
