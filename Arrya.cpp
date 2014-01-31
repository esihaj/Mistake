#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define ARR_CHUNK 1000

void quickSort(unsigned int arr[], int left, int right)
 {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];

  while (i <= j) 
  {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) 
        {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
  	}
  }
  if (left < j)
     quickSort(arr, left, j); 
  if (i < right)
     quickSort(arr, i, right);
}
int main()
{
	unsigned int * nums = (unsigned int *) malloc(ARR_CHUNK*sizeof(int));
	unsigned long long i = 0;
	short temp;
	int size = 1;
	unsigned long long j,k;
	//reading input
	while (scanf("%u", nums + i++) == 1)
	{
		if (i >= size * ARR_CHUNK - 20)
		{
			nums = (unsigned int *) realloc(nums, (++size)*ARR_CHUNK * sizeof(int));
			if (!nums)
				return -1;
		}
	}
	i--;
        printf("scan done\n");
	//quickSort(nums, 0, i-1);
        std::sort(nums,nums + i -1);
        printf("sort done\n");
        for (j = 0; j < i; j += 2)
	{
		if (j + 1 >= i || nums[j] != nums[j + 1])
		{
			printf("%d\n", nums[j]);
			return 0;
		}

	}
	printf("%d\n", 0);
	return 0;
}
