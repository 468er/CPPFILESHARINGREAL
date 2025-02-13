#include <iostream>
#include <vector>
#include <map>
using std::map;

using std::cout;
using std::cin;
using std::vector;
using std::endl;

template<class T>
void swap(T &a, T &b){
    //cout << "&a: " << &a << "a: " << a << endl;
    T temp = a;
    a = b;
    b = temp;
}
int main(){
    int N;
    cin >> N;

    vector<int> a(N );
    vector<int> b(N);
    for(int &i: a){
        cin >> i;
    }
     for(int &i: b){
        cin >> i;
    }

    vector<int> result(N+1);
    for(int &i: result){
        i = 0;
    }
    //l is position in array
        //r is position in array
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
             vector<int> temp = a; 

            int left = l;
            int right = r;
            while (left < right) {
                swap(temp[left], temp[right]);
                left++;
                right--;
            }

            
            int matched = 0;
            for (int i = 0; i < N; i++) {
                if (temp[i] == b[i]){
                    matched++;
                } 
            }

             left = l;
             right = r;
            while (left < right) {
                swap(temp[left], temp[right]);
                left++;
                right--;
            }

            result[matched]++;
        }
    }


    for(int &i: result){
        cout << i << std::endl;
    }
  /*  cout << N << endl;
    for(int &i: a){
        cout << "a" << i << endl;
    }
     for(int &i: b){
        cout <<"b" <<  i << endl;;
    }*/
    return 0;
}
