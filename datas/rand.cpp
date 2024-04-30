#include <iostream>
#include <vector>
using namespace std;

int combinations(std::vector<int> items){

int s=1;
for(auto i : items){
    if(items[i] != 0)
    s *= items[i];
    }
    return s;
}

bool profitableGamble(int prob, int prize, int pay){

    if(prob * prize > pay){
        return true;
    }
    return false;
}

bool tradeWorthy(int price, int peRatio, int twoHun_DailyMovingAverage){

    bool priceCondition = (price < twoHun_DailyMovingAverage );
    bool peRatioCondition = (peRatio < 20 );
    bool maCondition = (price < 0.95 * twoHun_DailyMovingAverage && price > 1.05 * twoHun_DailyMovingAverage );
    bool betaCondition = (beta < 1);
    bool dividendYieldCondition = (dividendYield > 2.0);
    bool marketComparisonCondition = (price > marketIndexAverage);

    return priceCondition && peRatioCondition && maCondition && betaCondition && dividendYieldCondition && marketComparisonCondition;

}

int main(){
    if(tradeWorthy){
        std::cout<<"Proceed with Trade";

    } else {
        std::cout<<"Negative";
    }
    std::cout<< profitableGamble(10,200,50);

}