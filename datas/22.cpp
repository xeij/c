#include <iostream>
#include <cstring>
using namespace std;

int method(char a[],char b[]){

    if (strcmp(a, b) > 0) {
        // This block will be executed because "10" > "100" as strings
        cout << "10 is greater" << endl;
    
        return 21;
        
    }
    return 22; 
    
}

int main() {
    char a[] = "10";
    char b[] = "100";
cout << method(a,b) <<endl;


}
