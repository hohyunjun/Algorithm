#include <cstdio>
#include <vector>
using namespace std;

int BT[26][2];

void preorder(int root){
    
    printf("%c", root+'A');
    if(BT[root][0] == -1){
        return;    
    }else{
        preorder(BT[root][0]);
    }
    if(BT[root][1] == -1){
        return;
    }else{
        preorder(BT[root][1]);
    }
}



int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        char parent, lc, rc;
        scanf("%c %c %c", &parent, &lc, &rc);
        if(lc == '.'){
            BT[parent-'A'][0] = -1;
        }else{
            BT[parent - 'A'][0] = lc - 'A';
        }
        if(rc == '.'){
            BT[parent-'A'][1] = -1;
        }else{
            BT[parent - 'A'][1] = rc - 'A';
        }
    }

    preorder(0);
    printf("\n");
    // inorder(0);
    // printf("\n");
    // postorder(0);

    return 0;
}