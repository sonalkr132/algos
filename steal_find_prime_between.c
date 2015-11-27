#include <stdio.h>

char a[100001];

int main()
{
    int m,n,t,i,j,poc;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<=n-m;i++)
            a[i]=0;
        for(i=2;i*i<=n;i++)
        {
            poc=(m-1)/i*i+i;
            if (poc==i)
                poc+=i;
            for(j=poc;j<=n;j+=i)
                a[j-m]=1;
        }

        for(i=0;i<=n-m;i++)
            if (!a[i]&&i+m>1)
                printf("%d\n",i+m);
        printf("\n");
    }
    return 0;
}
