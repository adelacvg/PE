#include<bits/stdc++.h>
using namespace std;
const double Epsilon = 1e-5;
void eval(const vector<double>& numbers, vector<bool>& used)
{
    if(numbers.size()==1)
    {
        auto result = numbers.front() + Epsilon;
        if(fmod(result, 1)>10*Epsilon)
            return;
        int index = int (result + Epsilon);
        if(index>=0 && index<(int)used.size())
            used[index] = true;
        return;
    }
    auto next = numbers;
    for(int i=0;i<numbers.size();i++)
    {
        for(int j=i+1;j<numbers.size();j++)
        {
            double a = numbers[i];
            double b = numbers[j];

            next = numbers;
            next.erase(next.begin()+j);
            next.erase(next.begin()+i);

            next.push_back(a+b);
            eval(next,used);
            next.back()=a-b;
            eval(next,used);
            next.back()=b-a;
            eval(next,used);
            next.back()=a*b;
            eval(next,used);
            if(b)
            {
                next.back()=a/b;
                eval(next,used);
            }
            if(a)
            {
                next.back()=b/a;
                eval(next,used);
            }
        }
    }
}

int getSeqLen(const vector<double>& numbers)
{
    vector<bool> used(10000,false);
    eval(numbers,used);

    int res=0;
    while(used[res+1])
        res++;
    return res;
}
int main()
{
    int longestSeq=0;
    int longestDig=0;

    for(int a=1;a<=6;a++)
    {
        for(int b=a+1;b<=7;b++)
        {
            for(int c=b+1;c<=8;c++)
            {
                for(int d=c+1;d<=9;d++)
                {
                    auto seqLen = getSeqLen({double(a),double(b),double(c),double(d)});
                    if(longestSeq<seqLen)
                    {
                        longestSeq = seqLen;
                        longestDig = a*1000+b*100+c*10+d;
                    }
                }
            }
        }
    }
    cout<<longestDig<<endl;
}

