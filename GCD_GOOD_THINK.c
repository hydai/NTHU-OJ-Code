int gcd (int a, int b)
{
    if (b) {
        while ((a%=b)&&(b%=a)) ;
    }
    return a+b;
}
