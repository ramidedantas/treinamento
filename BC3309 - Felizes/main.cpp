#include <stdio.h>
#include <set>

// Solução C + C++ baseada em código de Marcos

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int soma = 0;
    while (n--) {
        int num;
        scanf("%d", &num);

        set<int> passados;

        while(1) {
            passados.insert(num);
            int novo=0;

            while(num) {
                int dig = num%10;
                novo += dig*dig;
                num /= 10;
            }

            num = novo;
            //printf("%d\n", tran);

            if (num==1) { // sucesso -> feliz
                soma++;
                break;
            }

            if (passados.find(num) != passados.end()) {
                break;
            }

//            if (num==4) {
//                break;
//            }
        }

    }

    printf("%d\n", soma);

    return 0;
}
