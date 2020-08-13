#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse_vec(vector<int> v1);
void reverse_org_vec(vector<int> &v1);
void helper(vector<int>::iterator itr_b,vector<int>::iterator itr_e,vector<int> &v1);

int main() {
    cout << "reverse vector" << endl;
    int myints[] = {1,2,3,4,5,6,7,8};
    vector<int> v1 (myints,myints + sizeof(myints)/sizeof(int));
//    vector<int> v2 = reverse_vec(v1);
//    for(vector<int>::iterator itr = v2.begin(); itr != v2.end();itr++){
//        cout << *itr << endl;
//    }

    reverse_org_vec(v1);
    for(vector<int>::iterator itr = v1.begin(); itr != v1.end();itr++){
        cout << *itr << endl;
    }

    return 0;
}



//return a new vector
vector<int> reverse_vec(vector<int> v1){
    vector<int> new_vec;
    for(vector<int>::iterator itr = v1.end() -1 ; itr != v1.begin() - 1; itr--){
        new_vec.push_back(*itr);
    }
    return new_vec;
}

//return previous vector
void reverse_org_vec(vector<int> &v1){
    for(vector<int>::iterator itr = v1.end()-1; itr !=v1.begin() - 1;itr--){
        helper(v1.begin(),itr,v1);
    }
}

void helper(vector<int>::iterator itr_b,vector<int>::iterator itr_e,vector<int> &v1){
    if(itr_b == itr_e){
        return;
    }
    else{
        int temp = *itr_b;
        *itr_b = *(itr_b+1);
        *(itr_b+1) = temp;
        helper(itr_b+1,itr_e,v1);
    }
}