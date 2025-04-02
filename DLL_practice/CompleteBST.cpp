#include "CompleteBST.h"

// left = 2*i+1, right = 2*i+2



void CompleteBST::insert(int value) {
	tree.push_back(value);
    sort();
}

void CompleteBST::sort() {
    int n = tree.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapsort( n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(tree[0], tree[i]);
        heapsort(i, 0);         
    }
}

void CompleteBST::heapsort(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && tree[left] > tree[largest]) {
        largest = left;
    }
    if (right < n && tree[right] > tree[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(tree[i], tree[largest]);
        heapsort(n, largest);
    }
}

void CompleteBST::remove(int value) {
    int tar = search(value);
    if (tar == -1) {
        return;
    }
    swap(tree[tar], tree[tree.size() - 1]);
    tree.pop_back();
    sort();
}

int CompleteBST::search(int value) {
    
    int i = 0;
    while (i < tree.size()) {
        if (tree[i] == value) {
            return i;
        }
        i++;
    }
    return -1;
}

void CompleteBST::print() {
    for (int val : tree) {
        cout << val << " ";
    }
    cout << endl;
}

int CompleteBST::size() {
    return tree.size();
}


void CompleteBST::realSort() {
    int idx = size() / 2 + 1;

}

vector<int> CompleteBST::partSort(vector<int> subt) {

}