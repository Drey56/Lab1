

template<class T> void merge(T a[], long low, long mid, long high)
{
	T* b = new T[high + 1 - low];
	long h, i, j, k;
	h = low;
	i = 0;
	j = mid + 1;

	while ((h <= mid) && (j <= high))
	{
		if (a[h] <= a[j])
		{
			b[i] = a[h];
			h++;
		}
		else
		{
			b[i] = a[j];
			j++;
		}
		i++;
	}

	if (h > mid)
	{
		for (k = j;k <= high;k++)
		{
			b[i] = a[k];
			i++;
		}
	}
	else
	{
		for (k = h;k <= mid;k++)
		{
			b[i] = a[k];
			i++;
		}
	}
	// Prints into the original array
	for (k = 0;k <= high - low;k++)
	{
		a[k + low] = b[k];
	}
	delete[] b;
}

template<class T> void merge_sort(T a[], long low, long high)
{
	long mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}
