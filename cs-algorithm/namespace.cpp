#include "pch.h"
#include "iostream"
#include "string"
#include "math.h"
#include "vector"
using namespace std;

namespace first {
	void func() {
		cout << "first" << endl;
	}
}

namespace second {
	void func(){
		cout << "second" << endl;
	}
}

void  func() {
	cout << "out" << endl;
}

int main() {
	func();
	second::func();
	return 0;
}
