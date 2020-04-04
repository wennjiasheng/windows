void Select2(int *n, int size)
{
	int start = 0;
	int end = size - 1;
	while (start < end)
	{
		int min = start;
		int max = end;
		for (int i = start + 1; i <= end; i++)
		{
			if (n[i]>n[max]) max = i;
			if (n[i] < n[min]) min = i;
		}
		if (max != end)  Swap(&n[max], &n[end]);
		if (min == end)  min = max;
		if (min != start) Swap(&n[min], &n[start]);
		start++, end--;
	}
}
