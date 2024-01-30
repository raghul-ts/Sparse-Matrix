#include <iostream>
using namespace std;
struct elements {
    int i, j, x;
};
struct sparse {
    int m, n, num;
    elements* arrEle;
};
void create(sparse* A) {
    cout << "Enter m, n, num: ";
    cin >> A -> m;
    cin >> A -> n;
    cin >> A -> num;
    A -> arrEle = new elements[A->num];
    cout << "Enter " << A->num << " array elements: (i, j, value)" << endl;
    for (int x = 0; x < A->num; x++) {
        cin >> A -> arrEle[x].i;
        cin >> A -> arrEle[x].j;
        cin >> A -> arrEle[x].x;
    }
}
void display(sparse* s) {
    for (int i = 0; i < s -> num; i++) {
        cout << "i, j, x = " << s->arrEle[i].i << " " << s->arrEle[i].j << " " << s->arrEle[i].x << endl;
    }
    // print matrix;
    int k = 0;
    for (int a = 0; a < s->m; a++) {
        for (int b = 0; b < s->n; b++) {
            if (a == s->arrEle[k].i-1 && b == s->arrEle[k].j-1) {
                cout << s->arrEle[k++].x << " ";
            } else cout << 0 << " ";
        }
        cout << endl;
    }
}
void add(sparse* a, sparse* b, sparse* c) {
    int i = 0, j = 0, k = 0;
    c -> m = a -> m; c -> n = a -> n; c -> num = (a->num * 2);
    c -> arrEle = new elements[c->num];
    
    while (i < a -> num && j < b -> num) {
        int x1 = a->arrEle[i].i, x2 = b->arrEle[j].i, y1 = a->arrEle[i].j, y2 = b->arrEle[j].j;
        int sum = 0;
        if (x1 == x2 && y1 == y2) {
            sum += a->arrEle[i].x + b->arrEle[j].x;
            c->arrEle[k].i = x1; c->arrEle[k].j = y1;
            c->arrEle[k].x = sum; k++;
            i++; j++;
        } else if (x1 < x2 || (x1 == x2 && y1 < y2)) {
            c->arrEle[k] = a->arrEle[i];
            k++;
            i++;
        } else if (x2 < x1 || (x1 == x2 && y2 < y1)) {
            c->arrEle[k] = b->arrEle[j];
            k++;
            j++;
        }
    }
    for (int g = i; g < a->num; g++) {
        c->arrEle[k++] = a->arrEle[g];
    }
    for (int g = j; g < b->num; g++) {
        c->arrEle[k++] = b->arrEle[g];
    }
}


int main() {
    sparse A;
    create(&A);
    sparse B;
    create(&B);
    sparse C;
    add(&A, &B, &C);
    display(&C);
}
