#ifndef _MASK_H_
#define _MASK_H_
#include <string>
#include <bitset>

class Address;

class Mask
{
private:
	unsigned char _first_oktet;
	unsigned char _second_oktet;
	unsigned char _third_oktet;
	unsigned char _fouth_oktet;
	Mask StringToMask(std::string str);
	int* StringToArr(std::string str);
	bool IsValidIP(int first, int second, int third, int fouth);
public:
	Mask();
	Mask(std::string mask);
	Mask(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet);
	unsigned int AmountOfNodes();									
	long long int IPToLongInt();
	bool CorrespondenceBetweenAddressAndMask(Address addr);			
	bool operator==(const Mask addr);

	friend std::istream& operator>>(std::istream& in, Mask& mask);
};
#endif
