#include <iostream>
#include "TString.h"
#include "TArray.h"

using namespace std;

int main()
{
	const TString s("Apple"), r("aAppledd");
	TArray<int, 2> a;
	for (char x : s)
		cout << x;
	cout << s << r;
}