void ft_burbble_sort(int array_to_sort[], int size)
{
	int i = 0;
	int j = 0;
	int aux = 0;

	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array_to_sort[j] > array_to_sort[j + 1])
			{
				aux = array_to_sort[j];
				array_to_sort [j] = array_to_sort[j + 1];
				array_to_sort [j + 1] = aux;
			}
			j++;
		}
		i++;
	}
}
