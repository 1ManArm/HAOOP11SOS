#include <iostream>
#include <Windows.h>
#include <string>
#include <cassert>
#include "funcs.h"
#include "Address.h"

void testEqualOperator()
{
	Address a1("192.168.1.0");
	Address a2("192.168.1.0");
	Address a3("192.168.1.1");
	assert(a1 == a2);
}

void testLessOperator()
{
	Address a1("192.168.1.0");
	Address a2("192.168.1.1");
	Address a3("192.169.1.1");
	assert(a1 < a2);
	assert(a1 < a3);
}

void testAmountOfNodes()
{
	Mask m1("255.255.255.0");
	Mask m2("255.255.0.0");
	assert(m1.AmountOfNodes() == 254);
	assert(m2.AmountOfNodes() == 65534);

}

void testCorrespondenceBetweenAddressAndMask()
{
	Mask m1("255.255.255.0");
	Address a1("192.168.1.100");
	assert(1 == m1.CorrespondenceBetweenAddressAndMask(a1));
	Mask m2("255.255.0.0");
	assert(0 == m2.CorrespondenceBetweenAddressAndMask(a1));
}


void testInputStreamOperatorMask()
{
	std::cout << "¬ведите маску 255.255.254.0 -> ";
	Mask m1;
	Mask m2("255.255.254.0");
	std::cin >> m1;
	assert(m1 == m2);
}


void testInputStreamOperatorAddress()
{
	std::cout << "¬ведите адрес 192.168.1.100 -> ";
	Address a1;
	Address a2("192.168.1.100");
	std::cin >> a1;
	assert(a1 == a2);
}

void testIsValidIPMask()
{
	Mask m1("255.256.255.128");
	Mask m2;
	assert(m1 == m2);

}

void testIsValidIPAddress()
{
	Address a1("255.256.255.128");
	Address a2;
	assert(a1 == a2);

}

void testConvertToNetworkAddress()
{
	Address a1("192.168.1.100");
	Address a2("192.168.1.0");
	Mask m1("255.255.255.0");
	Address networkAddress(a1.convertToNetworkAddress(m1));
	assert(networkAddress == a2);
}

void Test()
{
	testCorrespondenceBetweenAddressAndMask();
	testIsValidIPMask();
	testIsValidIPAddress();
	testEqualOperator();
	testLessOperator();								
	testAmountOfNodes();							
	testConvertToNetworkAddress();					
	testInputStreamOperatorAddress();				
	testInputStreamOperatorMask();					
}


int main() {
	setlocale(LC_ALL, "Russian");
	system("cls");
	Test();


	return 0;
}