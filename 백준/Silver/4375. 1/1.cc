#include <iostream>

using namespace std;
int n;

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        long long cnt = 1;
        long long ret = 1;
        while (1)
        {
            if (cnt % n == 0)
            {
                printf("%lld\n", ret);
                break;
            }
            else
            {
                cnt = (cnt * 10 + 1) % n;
                ret++;            
            }
        }
    }
        
}