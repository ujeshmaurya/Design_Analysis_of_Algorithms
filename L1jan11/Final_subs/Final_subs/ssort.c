void selectionSort(int a[], int n)
{
    int i,j,m,temp;
    for (i = 0; i < n-1; i++)
    {
        m= i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[m])
            m = j;
        temp=a[i];
	a[i]=a[m];
	a[m]=temp;
    }
}
