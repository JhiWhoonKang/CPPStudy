#include <iostream>
#include <algorithm>

using namespace std;

/*
* Labmda Expression
* �͸� �Լ�(Annoymous function)�� �����ϴ� ���
*/

int main(void)
{
    /*
    * [���ٽ� ����]
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