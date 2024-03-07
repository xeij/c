#include <iostream>
#include <vector>

using namespace std;

double mean(const vector<double>& v) {
    double sum = 0.0;
    for (double x : v) sum += x;
    return sum / v.size();
}

void leastSquares(const vector<double>& x, const vector<double>& y, double& m, double& b) {
    double xMean = mean(x);
    double yMean = mean(y);
    double num = 0.0;
    double den = 0.0;

    for (size_t i = 0; i < x.size(); ++i) {
        num += (x[i] - xMean) * (y[i] - yMean);
        den += (x[i] - xMean) * (x[i] - xMean);
    }

    m = num / den;
    b = yMean - m * xMean;
}

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 3, 5, 7, 11};

    double m, b;
    leastSquares(x, y, m, b);

    cout << "Estimated coefficients:" << endl;
    cout << "Slope (m) = " << m << endl;
    cout << "Intercept (b) = " << b << endl;

    return 0;
}
