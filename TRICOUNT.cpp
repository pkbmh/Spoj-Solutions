#include <cstdio>
using namespace std;
#define LLI long long int
int main() {

    LLI T,n,result;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n%2==0)
        {
            result=((n*(n+2))*(2*n+1))/8;
             printf("%lld\n",result);
        }
        else
        {
                result=(((n*(n+2))*(2*n+1))-1)/8;
                 printf("%lld\n",result);
        }

    }
    return 0;
return 0;
}

