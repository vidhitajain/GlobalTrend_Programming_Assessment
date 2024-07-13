#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateArray(vector<int> &nums, int k)
{
  int n = nums.size();
  k = k % n;
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  int k = 3;
  rotateArray(nums, k);

  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
