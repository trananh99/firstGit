#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 100

using namespace std;



void swap( int &a, int &b)
{
	int tmp = a;
		a = b;
		b = tmp;
}

void print(int *a, int n)
{
	for (int i = 0; i<n; i++)
		{
			cout<<a[i]<<"   ";
		}
}


//selection sort

void selection( int *a, int n)
{
	for (int i = 0; i<n; i++)
	{
		int idmin = i;
		for (int j = i+1; j<n; j++)
		{
			if (a[idmin]>a[j])
			{
				idmin = j;
			}
		}
		if (idmin != i)
		{
			swap(a[idmin], a[i]);
		}
	}
}

//Bubblusort

void bubblusort(int *a, int n)
{
	for (int i = 1; i<n; i++)
	{
		for (int j = n-1; j>=i; j--)
		{
			if (a[j] <a[j-1])
			{
				swap(a[j], a[j-1]);
			}
		}
	}
}

void bubblesort2(float *a, int n)
{
	for (int i = 1; i<n; i++)
	{
		for (int j = n-1; j>=i; j--)
		{
			if (a[j] <a[j-1])
			{
				float tmp = a[j];
				a[j] = a[j-1];
				a[j-1]  = tmp;
			}
		}
	}
}

//Insertsort
void insertsort(int *a, int n)
{
	int tmp, i, j;
	for (i = 1; i<n; i++)
	{
		tmp = a[i];
		j = i-1;
		while (j>=0 && tmp < a[j])
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = tmp;
	}
}

//InsertSort2
void insertsort2(int *a, int n)
{
	
}

//Shellsort

void shellsort(int *a, int n)
{
	int i, j,h;
	int tmp;
	h = n/2;
	while ( h!=0)
	{
		for ( i = h + 1; i<n; i++)
		{
			tmp = a[i];
			j = i-h;
			while (j>=0 && a[j]>tmp)
			{
				a[j+h] = a[j];
				j = j-h;
			}
			a[j+h] = tmp;
		}
		h = h/2;
	}
}


//Mergesort

void merge(int *a, int l, int m, int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int arr1[n1], arr2[n2];
	for ( i = 0; i<n1; i++)
	{
		arr1[i] = a[i+l];
	
	}

	for (j = 0; j<n2; j++)
	{
		arr2[j] = a[j + m+1];
	
	}
	
	i = 0;
	j= 0;
	k = l;
	while( i<n1 && j<n2)
	{
		if (arr1[i] <= arr2[j])
		{
			a[k] = arr1[i];
			i++;
		}
		else 
		{
			a[k] = arr2[j];
			j++;
		}
		k++;
	}
	
	while (i<n1)
	{
		a[k] = arr1[i];
		i++;
		k++;
	}
	
	while (j<n2)
	{
		a[k] = arr2[j];
		j++;
		k++;
	}
}

void mergesort(int *a, int l, int r)
{
	if (l<r)
	{
	
	int m = l + (r-l)/2;
	mergesort(a, l,m);
	mergesort(a, m+1, r);
	merge(a, l, m, r);
	
	}
	
}


///Quicksort

void quicksort(int *a, int l, int r)
{
	int i, j, mid;
	if (l<r)
	{
		mid = rand()%(r-l +1);
		i = l;
		j = r;
		while (i<j)
		{
			while( a[i]< a[mid] && i<r)
			{
				i++;
			}
			while (a[j] > a[mid])
			{
				j--;
			}
			if (i<j)
			{
				swap(a[i], a[j]);
			}
		}
		
		swap(a[mid], a[j]);
		quicksort(a, l, j -1 );
		quicksort(a, j , r);
		
		
	}
	 
	
}

///Counting sort
int findMax(int *a, int n)
{
	int max = a[0];
	for (int i = 1; i<n; i++)
	{
		if (a[i]> max)
			max = a[i];
	}
	return max;
}

void countingsort(int *a, int n)
{
	int out[n+1];
	int max = findMax(a, n);
	int count[max] = {0};
	for (int i  = 0; i<n; i++)
	{
		count[a[i]]++;
	
	}
	for (int i = 1; i<=max; i++)
	{
		count[i] = count[i] + count[i-1];
	
	}
	for (int i =0; i<n; i++)
	{
		
		out[count[a[i]]-1]  = a[i];
	
		count[a[i]]--;
	}
	print(out, n);
	
}

//Bucket sort
struct Bucket{
	int n = 0;
	float arr[MAX];
};

void bucketsort(float *a, int n)
{
	Bucket bucket[10];
	for (int i = 0; i<n; i++)
	{
		int tmp = 10*a[i];
		bucket[tmp].arr[bucket[tmp].n++] = a[i];
	//	cout<<tmp<<"\n";
	}

	for (int i = 0; i<10; i++)
	{
		if (bucket[i].n!=0)
		{
			bubblesort2(bucket[i].arr, bucket[i].n);
		}
	}
	
	int j = 0;
	for (int i = 0; i<10; i++)
	{
		if (bucket[i].n!=0)
		{
			for (int k = 0; k<bucket[i].n; k++)
			{
				a[j++] = bucket[i].arr[k];
			}
		}
	}
	
	for (int i = 0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}

}


//Radix sort

void counting_sort2(int *a, int n, int idx)
{
	int out[n];
	int count[10];
	
	for (int i = 0; i<10; i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i<n; i++)
	{
		count[(a[i]/idx)%10]++;
	}
	
	for (int i =1; i<10; i++)
	{
		count[i] += count[i-1];
	}
	
	for (int i = n-1; i>=0; i--)
	{
		out[count[(a[i]/idx)%10]-1] = a[i];
		count[(a[i]/idx)%10]--;
	}
	
	for (int i = 0; i<n; i++)
	{
		a[i] = out[i];
	
	}
}

void radixsort(int *a, int n)
{
	int max = findMax(a, n);
	for (int idx = 1; max/idx>0; idx*=10)
	{
		
	
		counting_sort2(a, n, idx);
	
	}

	
}

int main()
{
		float a[] = {0.2, 0.1, 0.9, 0.23, 0.99, 0.11};
		int b[] = {121,432,564,23,1,45,788};
		int n = 7;
	    radixsort(b,n);
	    print(b,n);
	  
	return 0;
}
