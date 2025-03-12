#include <iostream>
#include <algorithm>

using namespace std;

/*
* Labmda Expression
* 익명 함수(Annoymous function)를 정의하는 기능
*/

int main(void)
{
    /*
    * [람다식 구조]
    * 
    * [capture][parameters] -> return_type{ body }
    * 
    */ 

    int A = 10, B = 20;

    auto sum1 = [=](int a, int b) {return a + b;};
    auto sum2 = [&](int a, int b) {return a + b;};

    cout << sum1(A, B) << "\n";
    cout << sum2(A, B) << "\n";

	return 0;
}