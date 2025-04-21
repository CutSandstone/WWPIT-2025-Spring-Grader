#include "jngen.h"
using namespace std;
int main(int argc, char** argv){
    registerGen(argc, argv);
    int n = stoi(argv[1]);
    cout << n << "\n";
    if(rnd.next(0,1)){
        for(int i = 0; i<n; i++) cout << (rnd.next(0,1)?'S':'A');
    }else{
        int c = 0;
        for(int i = 0; i<n; i++){
            int num = rnd.next(0,5-c);
            if(num < 3){
                cout << "A";
                c = 0;
            }else{
                cout << "S";
                c++;
            }
        }
    }
    cout << "\n";
}
