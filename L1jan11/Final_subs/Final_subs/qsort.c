void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high],j,temp;
    int i = (low - 1);  
 
    for (j=low;j<=high-1;j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            temp=arr[j];
	    arr[j]=arr[i];
	    arr[i]=temp;
        }
    }
    	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
