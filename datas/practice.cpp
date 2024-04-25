using namespace std;

int combinations(std::vector<int> items){

int s=1;
for(auto i : items){
    if(items[i] != 0)
    s *= items[i];
    }
    return s;
}

int main(){

}