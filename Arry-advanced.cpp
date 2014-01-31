#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define ARR_CHUNK 1000
using namespace std;

void quick_sort_v1_1(vector<int>& x, long long  parent_pivot)
{
	if (x.size() > 3000)
	{
		int pivot = x[x.size() / 2];
		int i;
		vector<int> more;
		x.erase(x.begin() + x.size() / 2);
		/*for (auto i = x.begin(); i != x.end(); i++)
			cout << *i << " ";
			cout << endl;*/
		//int x_size = x.size();
		for (i = 0; i < x.size(); i++)
		{
			if (x[i] >= pivot)
			{
				more.push_back(x[i]);
				x.erase(x.begin() + i);
				i--;
			}
		}
		if (more.size() > 1)
			quick_sort_v1_1(more, pivot);
		if (x.size() > 1)
			quick_sort_v1_1(x, pivot);
		x.push_back(pivot);
		x.insert(x.end(), more.begin(), more.end());
	}
	else
	{
		printf("switching operation: size = %u, parent_pivot = %lld\n",x.size(), parent_pivot);
		//cout << "parent : "<<parent_pivot<<endl;
		bool * checked = (bool *) malloc(sizeof(bool) * x.size());
		memset(checked, false, sizeof(bool) * x.size());

    	for (unsigned int i = 0; i < x.size() ; i++)
    	{
	        if (checked[i])
	            continue;
	        bool found = false;
	        for (unsigned int j = i + 1; j < x.size() ; j++)
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
	        	if(x[i] == parent_pivot)
	        	{
	        		checked[i] = true;
	        	}
	        	else
	        	{
	        		printf("%u\n", x[i]);
		            //cout << x[i] << endl;
		            exit(0);
	        	}
	        }
	    }
    	free(checked);
	}
}

unsigned int partion(unsigned int x[], unsigned low, unsigned int high)
{
	int pivot_value = x[(low + high) / 2];
	unsigned int swap_temp;
	x[(low + high) / 2] = x[high];
	x[high] = pivot_value;
	for (int i = low; i < high; i++)
	if (x[i] <= pivot_value)
	{
		swap_temp = x[i];
		x[i] = x[low];
		x[low++] = swap_temp;
	}
	swap_temp = x[low];
	x[low] = x[high];
	x[high] = swap_temp;
	return low;
}
void quick_sort_v2(unsigned int x[], unsigned int low, unsigned int high)
{
	if (low >= high)
		return;
	unsigned int pivot = partion(x, low, high);
	  cout <<"left = "<<low<<" right = "<<high <<"     ";
	  for(unsigned int v = low; v<=high ;v++)
	  {
	  	if(v == (low + high)/2)
	  	{
	  		cout<<"["<<x[v]<<"] ";
	  		continue;
	  	}
	  	cout <<x[v]<<" ";
	  }
	  cout<<endl;
	quick_sort_v2(x, low, pivot - 1);
	quick_sort_v2(x, pivot + 1, high);
}

void quickSort(unsigned int arr[], int left, int right, long long int parent_pivot)
 {
 	/*if(right - left >= 6000)
 	{*/
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
	  cout <<"left = "<<left<<" right = "<<right <<"     ";
	  for(int v = left; v<=right ;v++)
	  {
	  	if(v == (left + right)/2)
	  	{
	  		cout<<"["<<arr[v]<<"] ";
	  		continue;
	  	}
	  	cout <<arr[v]<<" ";
	  }
	  cout<<endl;
	  if (left < j)
	     quickSort(arr, left, j, pivot); 
	  if (i < right)
	     quickSort(arr, i, right, pivot);
	/*}
	else
	{
		printf("switching operation: left = %u, right = %u, parent_pivot = %lld\n",left, right, parent_pivot);
		//cout << "parent : "<<parent_pivot<<endl;
		bool * checked = (bool *) malloc(sizeof(bool) * (right - left + 1));
		memset(checked, false, sizeof(bool) * (right - left + 1));

    	for (unsigned int i = left; i <= right ; i++)
    	{
	        if (checked[i])
	            continue;
	        bool found = false;
	        for (unsigned int j = i + 1; j <= right; j++)
	        {
	            if (arr[i] == arr[j])
	            {
	                found = true;
	                checked[i] = checked[j] = true;
	                break;
	            }
	        }
	        if (!found)
	        {
	        	if(arr[i] == parent_pivot)
	        	{
	        		checked[i] = true;
	        	}
	        	else
	        	{
	        		printf("%u\n", arr[i]);
		            //cout << arr[i] << endl;
		            exit(0);
	        	}
	        }
	    }
    	free(checked);
	}*/
}
int main()
{
	unsigned int * nums = (unsigned int *) malloc(ARR_CHUNK * sizeof(unsigned int));
	unsigned long long i = 0;
	short temp;
	int size = 1;
	//reading input
	while (scanf("%u", nums + i++) == 1)
	{
		if (i >= size * ARR_CHUNK - 20)
		{
			nums = (unsigned int *) realloc(nums, (++size) * ARR_CHUNK * sizeof(unsigned int));
			if (!nums)
				return -1;
		}
	}
	i--;
    printf("scan done\n");
    if(i % 2 == 0)
    {
    	//cout << 0 << endl;
    	printf("0\n");
    	return 0;
    }
    /*
    cout <<"left = "<<0<<" right = "<<18<<"     ";
     for(i = 0; i<19;i++)
	{

		cout <<nums[i]<<" ";
	}
	cout<<endl;*/
	//quickSort(nums, 0, i-1, -1);
    //std::sort(nums,nums + i -1);
    quick_sort_v1_1(nums,-1);
   /* cout <<"left = "<<0<<" right = "<<18<<"     ";
     for(i = 0; i<19;i++)
	{

		cout <<nums[i]<<" ";
	}
	cout<<endl;*/
    printf("sort done\n");
    /*for (j = 0; j < i; j += 2)
	{
		if (j + 1 >= i || nums[j] != nums[j + 1])
		{
			printf("%d\n", nums[j]);
			return 0;
		}

	}
	printf("%d\n", 0);*/
	return 0;
}
