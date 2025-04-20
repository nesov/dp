#include <iostream>

bool isPalindrome(int x)
{

	std::string str = std::to_string(x);
	if (str.size() < 2)
		return false;	

	for (int i = 0, j = str.size() - 1; i < str.size() / 2; i++, j--)
	{
		if (str[i] != str[j])
		{
			return false;
		}
	}
	return true;
}

int main()
{

	std::cout << isPalindrome(10) << std::endl;

	return 0;
}
