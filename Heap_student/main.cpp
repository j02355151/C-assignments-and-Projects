#include <iostream>
#include <vector>
using std:: vector;
using std:: cout;
using std:: endl;

class MaxHeap {
    private:
        int _size{};
        vector<int> vect = {-1};

        int p(int i) {return i>>1;};
        int l(int i) {return i<<1;};
        int r(int i) {return (i<<1) +1;};


    public:
        bool isEmpty() const {return _size ==0;};
        int getMax() const{return vect[1];};
        void insertItem(int val);
        void shiftup(int i);
        int extractMax();
        void shiftDown(int i);

};


void MaxHeap::shiftup(int i) {

    if (i > _size) return;
    if (i ==1) return;
    if (vect[i] > vect[p(i)]) {
        std::swap(vect[p(i)], vect[i]);

    }
    shiftup(p(i));
}

void MaxHeap::insertItem(int val) {
    if (_size + 1 >= vect.size()) {
        vect.push_back(0);
    }
    vect[++_size] = val;
    shiftup(_size);
    return;
}

void MaxHeap::shiftDown(int i ) {
    if (i > _size) return;

    int swapId = i;

    if (l(i) <= _size && vect[i] < vect[l(i)]) {
        swapId = l(i);
    }

    if (r(i) <= _size && vect[swapId] < vect[r(i)]) {
        swapId = r(i);
    }

    if (swapId!= i) {
        std:: swap(vect[i], vect[swapId]);
        shiftDown(swapId);

    }
    return;
}


int MaxHeap::extractMax() {
    int maxNum = vect[1];
    std::swap(vect[1], vect[_size --]);
    shiftDown(1);
    return maxNum;
}


int main() {
    MaxHeap* priority_queue = new MaxHeap();
    if (priority_queue ->isEmpty()) {
        cout << "Yes, this is the correct answer" << endl;
    } else {
        cout << "We have a problem with our isEmpty function." << endl;
    }

    priority_queue->insertItem(10);
    priority_queue->insertItem(120);
    priority_queue->insertItem(34);
    priority_queue->insertItem(41);
    priority_queue->insertItem(5);
    cout << priority_queue->getMax() << endl;
    priority_queue->extractMax();
    cout << priority_queue->getMax() << endl;
    if (priority_queue ->isEmpty()) {
        cout << "Yes, this is the correct answer" << endl;
    } else {
        cout << "We have a problem with our isEmpty function." << endl;
    }
    return 0;

}


