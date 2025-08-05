#include <iostream>
#include <cstddef>
#include "TString.h"
#include "TVector.h"
#include "TAllocator.h"

using namespace std;

int main()
{
	const TString s("Apple"), r("aAppledd");
	size_t d = 4;
	TVector<TString> a(d,s);
	TVector<int> f(2, 4);
	cout << a<<f;
}