#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int maxDifference(vector<int> &nums)
{
  if (nums.empty() || nums.size() < 2)
    return 0;

  int min_element = nums[0];
  int max_diff = nums[1] - nums[0];

  for (int i = 1; i < nums.size(); ++i)
  {
    max_diff = max(max_diff, nums[i] - min_element);
    min_element = min(min_element, nums[i]);
  }

  return max_diff;
}

int main()
{
  vector<int> nums = {2, 7, 3, 1, 9, 4};

  int result = maxDifference(nums);

  cout << "Maximum difference between any two elements in the array is: " << result << endl;

  return 0;
}
