#include<bits/stdc++.h>
using namespace std;
long double qpow(long double a,unsigned long long b)
{
    long double ans=1;
    while(b)
    {
        if(b&1)
        {
            ans*=a;
        }
        b>>=1;
        a*=a;
        // cout<<ans<<endl;
    }
    return ans;
}

double s(double r)
{
  double result = 0;
  double x = 1; // r^0 is always 0
  for (int k = 1; k <= 5000; k++)
  {
    result += (900 - 3 * k) * x;
    x *= r;
  }
  return result;
}
int main()
{
    cout<<"start"<<endl;
    long double l=0.0,r=2.0;

    // for(auto i=-1.0;i<=1;i+=0.1)
    //     cout<<f(i)<<endl;
    // cout<<qpow(2,3)<<endl;
    while(r-l>1e-13)
    {
        auto mid=(l+r)/2;
        if(s(mid)>-6e11*1.0)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
        // cout<<mid<<endl;
    }
    cout << fixed << setprecision(12) << l << endl;
}

// compute s(r) according to problem statement
// double s(double r)
// {
//   double result = 0;
//   double x = 1; // r^0 is always 0
//   for (int k = 1; k <= 5000; k++)
//   {
//     result += (900 - 3 * k) * x;
//     x *= r;
//   }
//   return result;
// }

// int main()
// {
//   // initial lower and upper bounds
//   double lower = 0;
//   double upper = 2;

//   // until the range is small enough
//   while (upper - lower > 1e-13)
//   {
//     double mid = (upper + lower) / 2;
//     // find result at midpoint
//     double current = s(mid);

//     // adjust borders
//     if (current < -6e11*1.0)
//       upper = mid;
//     else
//       lower = mid;
//   }

//   // print result (use midpoint but upper and/or lower should yield the same output)
//   std::cout << std::fixed << std::setprecision(12) << (upper + lower) / 2 << std::endl;
//   return 0;
// }