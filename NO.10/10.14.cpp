#include<iostream>

int func10_14()
{
	int a=10;
	auto f = [a](int b) {return a + b; };
}