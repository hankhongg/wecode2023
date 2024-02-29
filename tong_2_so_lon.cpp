/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cstring>
#define MAX 200

struct SOLON {
    int *so;
    int n;
};
//###INSERT CODE HERE -
void input (SOLON &a)
{
    a.so = new int[MAX];
    char s[MAX]; std::cin>>s;
    a.n = strlen(s);
    for (int i=0; i<a.n; i++)
    {
        a.so[i] = (int) s[i] - 48;
    }
}
SOLON* input()
{
    char s[MAX]; std::cin >> s;
    SOLON *a = new SOLON;
    a->so = new int[MAX];
    a->n = strlen(s);
    for (int i=0; i<a->n; i++)
    {
        a->so[i] = (int) s[i] - 48;
    }
    return a;

}
SOLON Cong(SOLON &a, SOLON &b)
{
    SOLON S;
    S.so = new int[MAX];
    int i=a.n-1;
    int j=b.n-1;
    S.n = (a.n>b.n) ? a.n:b.n;
    int tam1=0, tam2=0, nho=0, k=S.n;
    for (int m=0; m<S.n; m++) S.so[m] = 0;
    while (i>=0 && j>=0)
    {
        tam1 = a.so[i] + b.so[j] + nho;
        tam2=tam1;
        S.so[k--] = tam1%10;
        nho = tam2/10;
        i--;
        j--;
    }
    tam1=0, tam2=0;
    while (i>=0)
    {
        tam1 = nho + a.so[i--];
        tam2 = tam1;
        S.so[k--] = tam1%10;
        nho = tam2/10;
    }
    tam1=0, tam2=0;
    while (j>=0)
    {
        tam1 = nho + b.so[j--];
        tam2 = tam1;
        S.so[k--] = tam1%10;
        nho = tam2/10;
    }
    int t;
    int m=0;
    if (nho>0)
    {
    S.n=S.n+1;
    t=S.n+1;
    S.so[k]=nho;

    S.so[t]='\0';
    }
    else{
    for (t=0; t<S.n+1; t++)
    {
        S.so[t] = S.so[t+1];
    }

    S.so[t] = '\0'; }
    return S;
}

void output(SOLON *a)
{
    for (int i=0; i<a->n;i++) std::cout << a->so[i];
    std::cout << std::endl;
}


int main() {
    SOLON a, *b, S;
    input(a);
    b=input();
    S=Cong(a, *b);
    output(&a);
    output(b);
    output(&S);
    return 0;
}
