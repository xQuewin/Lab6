#ifndef Reader_h
#define Reader_h

#include <string>

class Reader
{

public:

	Reader();
	~Reader();


	void ReadFile();

	bool BadInputCheck(const std::string& str);

	void GetBinaryForm(const std::string& BinaryNumb);

private:

	int decimalNumber;
	bool badInput = false;


};

#endif // !Reader_h
