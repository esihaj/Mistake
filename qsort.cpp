#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void quick_sort_v4(vector<int>&x, int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = x[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (x[i] < pivot)
			i++;
		while (x[j] > pivot)
			j--;
		if (i <= j) {
			tmp = x[i];
			x[i] = x[j];
			x[j] = tmp;
			i++;
			j--;
		}
	}
	/* recursion */
	if (left < j)
		quick_sort_v4(x, left, j);
	if (i < right)
		quick_sort_v4(x, i, right);
}

unsigned int partion(vector<int>&x, unsigned low, unsigned int high)
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
void quick_sort_v2(vector<int>& x, unsigned low, unsigned int high)
{
	if (low >= high)
		return;
	unsigned int pivot = partion(x, low, high);
	quick_sort_v2(x, low, pivot - 1);
	quick_sort_v2(x, pivot + 1, high);
}

void quick_sort_v3(vector<int>& x, unsigned int low, unsigned int high)
{
	if (low >= high)
		return;
	int pivot_value = x[(low + high) / 2];
	unsigned int swap_temp;
	x[(low + high) / 2] = x[high];
	x[high] = pivot_value;
	int store_index = low;
	for (int i = low; i < high; i++)
	if (x[i] <= pivot_value)
	{
		if (store_index == i)
		{
			store_index++;
			continue;
		}
		swap_temp = x[i];
		x[i] = x[store_index];
		x[store_index++] = swap_temp;
	}
	swap_temp = x[store_index];
	x[store_index] = x[high];
	x[high] = swap_temp;

	quick_sort_v3(x, low, store_index - 1);
	quick_sort_v3(x, store_index + 1, high);
}

void quick_sort_v1(vector<int>& x)
{
	int pivot = x.size() / 2;
	int i;
	vector<int> more, less;
	for (i = 0; i < x.size(); i++)
	{
		if (i == pivot)
			continue;
		if (x[i] >= x[pivot])
		{
			more.push_back(x[i]);
		}
		else less.push_back(x[i]);
	}
	i = x[pivot];
	x.clear();
	if (more.size() > 1)
		quick_sort_v1(more);
	if (less.size() > 1)
		quick_sort_v1(less);
	x.insert(x.begin(), less.begin(), less.end());
	x.push_back(i);
	x.insert(x.end(), more.begin(), more.end());
}

int main()
{
	vector<int> nums;
	int i;
	while (cin >> i)
		nums.push_back(i);
	cout << "khoondam\n";
	cout << endl << endl;
	cout << "last " << nums[nums.size() - 1] << " size : " << nums.size() << endl;
	//sort(nums.begin(), nums.end());
	i = 0;
	//quick_sort_v4(nums, 0, nums.size() - 1);
	/*for (i = 0; i < nums.size(); i++)
		cout << nums[i] << endl;*/
	cout << "done";
	return 0;
}
