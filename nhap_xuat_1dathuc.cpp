
#include <iostream>
#include <math.h>
#include <iomanip>

#define MAX 100
using namespace std;

struct DONTHUC
{
    double n1;
    int n2;
};
struct DATHUC
{
    int n;
    DONTHUC *d;
};

DATHUC* Nhap()
{
    DATHUC *a;
    a = new DATHUC;
    cin >> a->n;
    a->d = new DONTHUC[MAX];
    for (int i=0; i<a->n; i++)
    {
        cin >> a->d[i].n1 >> a->d[i].n2;
    }
    return a;
}

void Xuat(DATHUC a)
{
    int l=0, m=0;
    for (int i=0; i<a.n; i++)
    {
        if (a.d[i].n1!=0){
      for (int t=0; t<i; t++)
      {
          if (a.d[t].n1==0) m++;
      }
      break;
        }

    }
    for (int i=0; i<a.n; i++)
    {
        if (a.d[i].n1>0)
        {
           if (a.d[i].n2!=0)
           {
               if (a.d[i].n2!=1)
               {
                   if (a.d[i].n1!=1)
                   {
                           if (m==i)
                        {
                           m+=101;
                           cout <<  a.d[i].n1 << "x^" << a.d[i].n2;
                        }
                        else cout <<"+" << a.d[i].n1 << "x^" << a.d[i].n2;
                   }
                    else
                        {
                           if (m==i)
                            {
                                m+=101;
                                cout << "x^" << a.d[i].n2;
                            }
                            else cout <<"+" << "x^" << a.d[i].n2;
                       }
               }

               else
               {
                   if (a.d[i].n1!=1)
                   {
                       if (m==i)
                       {
                           m+=101;
                           cout <<  a.d[i].n1 << "x";
                       }
                        else cout << "+" <<a.d[i].n1 << "x";
                   }
                   else
                   {
                       if (m==i)
                       {
                           m+=101;
                           cout << "x";
                       }
                       else cout << "+x";
                   }

               }
           }
           else
           {
               if (a.d[i].n1!=1)
                   {
                       if (m==i)
               {
                   m+=101;
                   cout << a.d[i].n1;
               }
               else cout << "+" << a.d[i].n1;
                   }
                else
                {
                    if (m==i)
                    {
                        m+=101;
                        cout << "1";
                    }

                    else cout << "+1";
                }

           }
        }

        else if (a.d[i].n1<0)
        {
            if (a.d[i].n2!=0)
            {
                if (a.d[i].n2!=1)
                {
                    if (a.d[i].n1!=-1)
                    {
                        cout << a.d[i].n1 << "x^" << a.d[i].n2;
                    }
                    else cout << "-x^" << a.d[i].n2;
                }
                else if (a.d[i].n2==1)
                {
                    if (a.d[i].n1!=-1)
                    {
                        cout << a.d[i].n1 << "x";
                    }
                    else cout << "-x";

                }
            }
            else
            {
                if (a.d[i].n1!=-1)
                    {
                        cout << a.d[i].n1;
                    }
                else cout << "-1";
            }

        }
    else l++;
    }
    if (l==a.n) cout << "0";

}

double TinhDaThuc(DATHUC &a, double &x)
{
    double s=0;
    for (int i=0; i<a.n;i++)
    {
        s+=a.d[i].n1*pow(x,a.d[i].n2);
    }
    return s;
}


int main() {
    DATHUC *B; B = Nhap();
    cout << "Da thuc vua nhap la: "; Xuat(*B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "<< setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}
