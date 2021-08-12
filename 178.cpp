#include<bits/stdc++.h>
using namespace std;
long long NoDigits = 0;
long long AllDigits = (1<<10) - 1;
long long MaxDigits = 40;
unsigned long long search(long long mask, long long currentDigit, long long numDigitsLeft)
{
    mask|=1<<currentDigit;

    if(numDigitsLeft == 1)
    {
        if(mask == AllDigits)
            return 1;
        return 0;
    }
    long long hash = mask * MaxDigits * 10 + (numDigitsLeft - 1)*10 + currentDigit;
    static vector<unsigned long long> cache(1024*100*MaxDigits, 0);
    if(cache[hash]!=0)
        return cache[hash];
    unsigned long long result = 0;
    if(currentDigit>0)
        result += search(mask, currentDigit - 1, numDigitsLeft - 1);
    if(currentDigit<9)
        result += search(mask, currentDigit + 1, numDigitsLeft - 1);
    cache[hash] = result;
    return result;
}
int main()
{
    unsigned long long Digit = 40;
    long long res = 0;
    for(int numDigits=1;numDigits<=Digit;numDigits++)
    {
        for(long long digit = 1;digit <= 9;digit++)
            res+=search(NoDigits, digit, numDigits);
    }

    cout<<res;
}
