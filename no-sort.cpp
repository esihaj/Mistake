#include <iostream>
#include <vector>
//#include<algorithm>
using namespace std;

void quick_sort (vector<int>& x, int low, int high)
{
    if (high - low <= 0)
        return;
    int pivot = (high + low) / 2;
    int i;
    for (i = low; i < pivot; i++)
        if (x[i] > x[pivot])
        {
            x.insert(x.begin() + pivot + 1, x[i]);//insert just after pivot point
            x.erase(x.begin() + i);
        }
    for (i = pivot + 1; i <= high; i++)
        if (x[i] < x[pivot])
        {
            x.insert(x.begin() + pivot, x[i]);//insert just before pivot point
            x.erase(x.begin() + i + 1);//added an item so remove index+1
        }
    quick_sort(x, low, pivot - 1);
    quick_sort(x, pivot + 1, high);

}

int main_in_cin_search ()
{
    //2 minute
    //super slow more than 1 minute!
    vector<int> nums;
    vector<bool> ch;
    int i, j;

    while (cin >> i)
    {
        nums.push_back(i);
        ch.push_back(false);
        for (j = 0; j < nums.size() - 1; j++)
        {
            if (ch[j])
                continue;
            if (nums[j] == i)
            {
                ch[j] = ch[nums.size() - 1] = true;
                break;
            }
        }
        if (nums.size() % 10000 == 0)
            cout << " i : " << nums.size() << endl;
    }
    for (i = 0; i < nums.size(); i++)
        if (!ch[i])
        {
            cout << nums[i] << endl;
            return 0;
        }
    cout << 0 << endl;
    return 0;

}

int main_n2_check_loop_no_sort ()
{
    //700ms
    //yezare faster than main_checke_list
    //agar fard bashe hatman ghalat dare
    vector<int> nums;
    int i;
    bool found = false;

    while (cin >> i)
        nums.push_back(i);

    if (nums.size() % 2 == 0)
        cout << 0 << endl;
    for (i = 0; i < nums.size() - 1; i++)

    {
        found = false;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << nums[i] << endl;
            return 0;
        }
    }
    cout << nums[nums.size() - 1] << endl;

    /*sort(nums.begin(), nums.end());
    int wrong_num = 0;
    for (i = 0; i < nums.size(); i += 2)
    {
            if (i+1 == nums.size() || nums[i] != nums[i + 1])
            {
                    wrong_num = nums[i];
                    break;
            }
    }
    cout << wrong_num << endl;*/
    return 0;
}

int main_checked_list_check_loop_no_sort ()
{
    //724ms
    //ye list nigah midaram ke to for e to dar toom check konam ghablan check shode ya na
    vector<int> nums;
    vector<bool> checked;
    int i;
    bool found = false;

    while (cin >> i)
        nums.push_back(i);

    if (nums.size() % 2 == 0)
        cout << "Result " << 0 << endl;
    checked.reserve(nums.size());
    for (i = 0; i < nums.size(); i++)
        checked[i] = false;

    for (i = 0; i < nums.size() - 1; i++)

    {
        if (checked[i])
            continue;

        found = false;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                found = true;
                checked[i] = checked[j] = true;
                break;
            }
        }
        if (!found)
        {
            cout << nums[i] << endl;
            return 0;
        }
    }
    if (!checked[nums.size() - 1])
        cout << nums[nums.size() - 1] << endl;
    else cout << 0 << endl;

    /*sort(nums.begin(), nums.end());
    int wrong_num = 0;
    for (i = 0; i < nums.size(); i += 2)
    {
            if (i+1 == nums.size() || nums[i] != nums[i + 1])
            {
                    wrong_num = nums[i];
                    break;
            }
    }
    cout << wrong_num << endl;*/
    return 0;
}
int main ()
{
	main_n2_check_loop_no_sort();
    /*vector<int> nums;
    int i;

    while (cin >> i)
        nums.push_back(i);
    cout << endl << endl;
    quick_sort(nums, 0, nums.size() - 1);
    for (i = 0; i < nums.size(); i++)
        cout << nums[i] << endl;*/
}
