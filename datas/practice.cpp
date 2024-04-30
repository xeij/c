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

int main(){

    std::cout<< profitableGamble(10,200,50);

}