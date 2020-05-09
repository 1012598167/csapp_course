#include <stdio.h>
unsigned float_twice(unsigned uf) {
    unsigned x;
    x = uf;
    if(!x) return 0;
    if(!(x<<1)) return (1<<31);
    int s=(x>>31)&1;
    int a23=(((((0x7F)<<8)|0xFF)<<8)|0xFF);
    int c=x&a23;
    int count=x<<1>>24;
/*    printf("%x\n",count);
    printf("%x\n",c);*/
    if (!(count+~0xFF+1)) return (x);
    if (!count)
    {
        if (c&(1<<22))
        {
            count=1;
        }
        c=(c<<1)&a23;
    }
    else
    {
        count+=1;
    }
    if (!(count+~0xFF+1))
    {
        c=0;
    }
    return ((((s<<8)|count)<<23)|c);
}
int main()
{
    printf("%x\n",float_twice(0x3f7fffff));
    return 0;
}