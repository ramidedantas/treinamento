#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class pilha {
private:
    int topo = -1;
    long * arr_min;
//    stack<long> mins;

public:

    pilha()
//    : mins()
    {
        arr_min = new long[1000000];
    }

    ~pilha() {
        delete arr_min;
    }

    void push(long v) {
//        long m = (mins.empty())? v : std::min(v, mins.top());
        long m = (topo < 0)? v : std::min(v, arr_min[topo]);
        topo++;
        arr_min[topo] = m;
//        mins.push(m);
    }

    void pop() {
//        mins.pop();
        topo--;
    }

    int min() {
//        long m = arr_val[0];
//        for (int i = 0; i <= topo; i++) m = std::min(arr_val[i], m);
//        return m;
        return arr_min[topo];
//        return mins.top();
    }

    bool empty() const {
//        return mins.empty();
        return topo < 0;
    }
};

int main() {
    // Disable synchronization with C standard I/O
    std::ios_base::sync_with_stdio(false);
    // Untie cin from cout
    std::cin.tie(NULL);

    int n;
//    cin >> n;
    scanf("%d", &n);

    pilha p;

    while (n--) {
        char command[10];
        scanf("%s", command);
        string op(command);

        if (op == "PUSH") {
            long v;
            scanf("%ld", &v);
            p.push(v);
        } else if (p.empty()) {
            cout << "EMPTY" << endl;
        } else if (op == "POP") {
            p.pop();
        } else {
            cout << p.min() << endl;
        }
    }

    return 0;
}
