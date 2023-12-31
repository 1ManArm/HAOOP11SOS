#ifndef _ADDRESS_H_
#define _ADDRESS_H_
#include <string>
#include <iostream>
#include "Mask.h"

class Address
{
private:
	unsigned char _first_oktet;
	unsigned char _second_oktet;
	unsigned char _third_oktet;
	unsigned char _fouth_oktet;
	Address stringToAddress(std::string str);
	bool IsValidIP(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet); 
	Address(long long int addr);
	int* stringToArr(std::string str);
public:
	Address();
	Address(std::string addr);
	Address(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet);
	bool operator==(const Address addr);
	bool operator<(const Address& addr);
	Address convertToNetworkAddress(Mask& mask);										
	long long int IPToLongInt();

	friend std::istream& operator>>(std::istream& in, Address& addr);
};
#endif

