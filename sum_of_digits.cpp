#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
  int sum = 0;

  while (n > 0)
  {
    sum += n % 10; // Add the last digit to sum
    n /= 10;       // Remove the last digit from n
  }

  return sum;
}

int main()
{
  int number;

  cin >> number;

  int result = sumOfDigits(number);

  cout << "Sum of digits of " << number << " is: " << result << endl;

  return 0;
}
