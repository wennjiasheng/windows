void Insertsort(int *array, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = array[i];//key是与前面元素比较的元素
		int end = i - 1;//有序中的最后一个元素
		while (key < array[end] && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
