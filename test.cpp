auto d = malloc_shared<long long>(100,q1);
for (int i=0;i!=10;i++)
{
    for(int j=0;j!=20;j++)
    {
        for(int k = 0;k!=10;k++)
        {
            d[i*10+k] += b[i*20+j]*c[j*10+k];
        }
    }
}