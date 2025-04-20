#include <iostream>

   std::string mergeAlternately(std::string word1, std::string word2) {

		int asize = word1.size();
		int bsize = word2.size();

		int maxsize = (asize > bsize)? asize: bsize;

        std::string res;
		res.reserve(asize+bsize);
        for (int i = 0; i < maxsize; i++ ){
			if (i < asize)
            	res += word1[i];
			if(i < bsize)
				res += word2[i];
        }
        return res;
    }

int main()
{
	std::string a {"ace"};
	std::string b {"bdfgpq"};

	std::cout <<mergeAlternately(a, b)<< std::endl;

	return 0;
}
