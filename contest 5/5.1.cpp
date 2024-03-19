//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> findMinimums(const vector<int>& nums, int n, int k)
{
    vector<int> result;
    deque<int> window;

    for (int i = 0; i < k; ++i)
    {
        while (!window.empty() && nums[i] < nums[window.back()])
        {
            window.pop_back();
        }
        window.push_back(i);
    }
    result.push_back(nums[window.front()]);

    for (int i = k; i < n; ++i)
    {
        while (!window.empty() && window.front() <= i - k)
        {
            window.pop_front();
        }
        while (!window.empty() && nums[i] < nums[window.back()])
        {
            window.pop_back();
        }
        window.push_back(i);
        result.push_back(nums[window.front()]);
    }

    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    vector<int> minimums = findMinimums(nums, n, k);
    for (int num: minimums)
    {
        cout << num << endl;
    }
    return 0;
}