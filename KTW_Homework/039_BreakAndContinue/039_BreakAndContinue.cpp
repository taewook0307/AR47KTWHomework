#include <iostream>

int main()
{
    for (int i = 0; i < 100; i++) {
        if (i > 50) {
            // switch문의 브레이크와 다름
            // 반복문에서의 break는 가장 가까운 반복문을 탈출
            break;
        }

        else if (i % 2 == 0)
        {
            continue;
            // 가장 가까운 반복문의 조건문으로 이동
        }

        printf_s("%d\n", i);
    }
}