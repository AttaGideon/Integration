#include <iostream>
#include <vector>
#include <numeric>


using namespace std;

typedef vector<double> dVec;


double trapezRule(dVec v, int a, int b, int n) // initial limit, a; end limit, b; No. of intervals, n
{
    double cx = (b - a) / n; // the change in x

    double x0 = cx/2 * ( v[0] + v[n]); 
    double sum1 = cx * accumulate(v.cbegin() + 1, v.cend() - 1, 0.0);

    return (x0 + xn + sum1);
}

double SimRule(dVec vec, int a, int b, int n)
{
	double cx = (b-a)/n;
	double X  = cx/3 * (vec[0] + vec[n]);
	int i = 1;
	double oddSum=0, evenSum=0;

	for(auto elem=vec.cbegin()+1; elem!=vec.cend()-1; ++elem)
	{
		if((i%2) != 0)
			oddSum += (4*cx/3) * (*elem);
		else
			evenSum += (2*cx/3) * (*elem);

		i++;
	}
	return (X + oddSum + evenSum);
}


int main()
{
    /* tried examples from: https://math24.net/simpsons-rule.html */
  
    //dVec v{0, 4, 5, 3, 10, 11, 2}; // a=-4, b=2, n=6
    dVec v{4,6,6,4,4,5}; // a=0, b=10, n=5
	  //dVec v{3,7,11,9,3}; // a=0, b=8, n=4

    //dVec v{2,7,12,10,5};  // a=0, b=4, n=4
    //dVec v{1,3,4,4,6,9,14};  // a=-4, b=8, n=6
    //dVec v{3,7,11,9,3};  // a=0, b=8, n=4
    //dVec v{4,3,2,3,6,6,4};  // a=-1, b=5, n=6

    double t = trapezRule(v, 0, 10, 5);

    cout << "The trapezoidal value: " << t << endl;


    double simpIntegral = SimRule(v, 0, 10, 5);

    cout << "Simpson's integral value: " << simpIntegral << endl;

    return 0;
}
