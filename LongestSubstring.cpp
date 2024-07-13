#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(const std::string &s)
{
  std::unordered_map<char, int> charIndexMap;
  int longest = 0;
  int left = 0;

  for (int right = 0; right < s.length(); ++right)
  {
    if (charIndexMap.find(s[right]) != charIndexMap.end())
    {
      // Move the left pointer to the right of the same character's last occurrence
      left = std::max(charIndexMap[s[right]] + 1, left);
    }
    charIndexMap[s[right]] = right;
    longest = std::max(longest, right - left + 1);
  }

  return longest;
}

int main()
{
  std::string s = "abcabcbb";
  std::cout << "The length of the longest substring without repeating characters is: "
            << lengthOfLongestSubstring(s) << std::endl;
  return 0;
}
