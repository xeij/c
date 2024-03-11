#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Estimates Pi using Monte Carlo method
double estimatePi(int numberOfSamples) {
    int pointsInsideCircle = 0;
    double x, y;

    for (int i = 0; i < numberOfSamples; ++i) {
        x = (double)rand() / RAND_MAX * 2 - 1;
        y = (double)rand() / RAND_MAX * 2 - 1;

        if (x * x + y * y <= 1) {
            pointsInsideCircle++;
        }
    }

    return 4 * (double)pointsInsideCircle / numberOfSamples;
}

int main() {
    srand(time(NULL));

    int numberOfSamples = 1000000; 
    double piEstimate = estimatePi(numberOfSamples);

    cout << "Estimated Pi value: " << piEstimate << endl;

    return 0;
}