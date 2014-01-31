#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
#define ARR_CHUNK 1000

#pragma warning(disable : 4996)

void merge_sort(unsigned int * x, int size)
{
	if (size > 6000)
	{
		//calculate a good pivot using 20 items of list
		int step = size / 20;
		unsigned long long sum = 0;
		for (int i = 0; i < size; i += step)
		{
			sum += x[i];
		}
		int pivot = sum / 20;
		//int pivot = x[1];

		int m_index = 0, l_index = 0;
		int m_size = 1, l_size = 1;
		unsigned int * more = (unsigned int *)malloc(ARR_CHUNK*sizeof(unsigned int));
		unsigned int * less = (unsigned int *)malloc(ARR_CHUNK*sizeof(unsigned int));
		
		if (!more || !less)
			exit(1);

		for (int i = 0; i< size; i++)
		{
			if (x[i] > pivot)
			{
				more[m_index++] = x[i];
				if (m_index >= m_size * ARR_CHUNK - 20)
				{
					more = (unsigned int *)realloc(more, (++m_size)*ARR_CHUNK * sizeof(unsigned int));
					if (!more)
						exit(1);
				}
			}
			else
			{
				less[l_index++] = x[i];
				if (l_index >= l_size * ARR_CHUNK - 20)
				{
					less = (unsigned int *)realloc(less, (++l_size)*ARR_CHUNK * sizeof(unsigned int));
					if (!less)
						exit(1);
				}
			}
		}
		free(x);
		merge_sort(less, l_index);
		merge_sort(more, m_index);
	}
	else
	{
		bool * checked = (bool *)malloc(sizeof(bool)* size);
		memset(checked, false, sizeof(bool)* size);

		for (unsigned int i = 0; i < size; i++)
		{
			if (checked[i])
				continue;
			bool found = false;
			for (unsigned int j = i + 1; j < size; j++)
			{
				if (x[i] == x[j])
				{
					found = true;
					checked[i] = checked[j] = true;
					break;
				}
			}
			if (!found)
			{
				printf("%u\n", x[i]);
				exit(0);
			}
		}
		free(checked);
		free(x);
	}
}
int main()
{
	freopen("list5", "r", stdin);
	unsigned int * nums = (unsigned int *)malloc(ARR_CHUNK*sizeof(int));
	unsigned long long i = 0;
	int size = 1;
	//reading input
	while (scanf("%u", nums + i++) == 1)
	{
		if (i >= size * ARR_CHUNK - 20)
		{
			nums = (unsigned int *)realloc(nums, (++size)*ARR_CHUNK * sizeof(int));
			if (!nums)
				return -1;
		}
	}
	if (--i % 2 == 0)
	{
		printf("0\n");
		return 0;
	}
	merge_sort(nums, i);
	return 0;
}