#include <iostream>
#include <vector>
using namespace std;

int a[30][2];

void preorder(int x){ // DLR
    if (x == -1)
        return;
    cout << char(x + 'A');
    preorder(a[x][0]);
    preorder(a[x][1]);
}

void inorder(int x){ // LDR
    if (x == -1)
        return;
    inorder(a[x][0]);
    cout << char(x + 'A');
    inorder(a[x][1]);
}

void postorder(int x){
    if(x==-1) return;
    postorder(a[x][0]);
    postorder(a[x][1]);
    cout << char(x + 'A');
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        char x, y, z;
        cin >> x >> y >> z;

        if(y == '.'){
            a[x-'A'][0] = -1;
        }else{
            a[x-'A'][0] = y-'A';
        }

        if(z == '.'){
            a[x-'A'][1] = -1;
        }else{
            a[x-'A'][1] = z-'A';
        }
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
    return 0;
}