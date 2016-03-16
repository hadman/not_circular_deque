#include <iostream>

using namespace std;
struct elem
{
    char info;
    elem* pointer;
};
class cdequeue
{
private:
    int pointerL; // указатель на голову
    int pointerR; // указатель на хвост
    int n; // размер вектора
    int* arr; // указатель

public:
    cdequeue(int size = 10 ) // дек состоит хотя бы из двух элементов. Создаем массив размерности 2
    {
        if (size >= 2 )
        {
            n = size;
        } else{
            size = 10;
            n = size; //7
        }
        arr = new int[n]; // выделение памяти для массива
        pointerL = 1;
        pointerR = 0;
    }
    ~cdequeue() // Деструктор
    {
        delete[] arr; // очистка памяти
    }

    int ahead(int num) // добавление головы // ПРОБЛЕМЫ -> ВРОДЬ ПОЧИНИЛ
    {

        if (pointerR - pointerL  != n-1) // если дек не полность заполнен
        {
            if(pointerL == 0) // если голова на первом элементе, а в хвосте есть место
            {
                for (int i = pointerR; i >= pointerL; --i) {
                    arr[i+1]=arr[i];
                }
                pointerR++;
                arr[pointerL] = num;
            } else
            {
                pointerL = (pointerL - 1);
                arr[pointerL] = num;
            }
            return 1;
        } else
        {
            cout << "full! " << num << endl;
            return NULL;
        }
    }
    int atail(int num) // добавление хвоста
    {

        if (pointerR - pointerL  != n-1) // если дек не полность заполнен
        {
            if(pointerR == n) // если хвост на последнем элементе, а в голове есть место
            {
                for (int i = pointerL; i <= pointerR; ++i) {
                    arr[i-1]=arr[i];
                }
                pointerL--;
                arr[pointerR] = num;
            } else
            {
                pointerR = (pointerR + 1);
                arr[pointerR] = num;
            }
            return 1;
        } else
        {
            cout << "full! " << num << endl;
            return NULL;
        }
    }

    int dhead() // вывод и удаление головы
    {
        if (pointerL != (pointerR+1)) // если дек не пустой
        {
            int temp = arr[pointerL];
            pointerL = (pointerL + 1);
            return temp;
        } else
        {
            cout << " empty! " << endl;
            return NULL;
        }
    }
    int dtail() // вывод и удаление хвоста
    {
        if (pointerL != (pointerR+1))// если дек не пустой
        {
            int temp = arr[pointerR];
            pointerR = pointerR - 1;
            return temp;
        } else
        {
            cout << " empty! " << endl;
            return NULL;
        }
    }

    int  phead() // печать от головы до хвоста
    {
        if (pointerL != (pointerR+1))
        {
            cout << "pointerL = " << pointerL << endl;
            cout << "pointerR = " << pointerR << endl;
            cout << "size = " << n << endl;
//            for (int i = 0; i < n; ++i) {
//                cout << i << " " << arr[i] << endl;
//            }

            cout << endl << "****************" << endl;



            for (int i = pointerL; i < pointerR+1; ++i)
            {
                cout << i << " : " << arr[i];
                if (i == pointerL)
                {
                    cout << " head " ;
                }
                if (i == pointerR)
                {
                    cout << " tail " ;
                }
                cout  << endl;
            }
            return 1;

        }else
        {
            cout << " EMpty ! " << endl;
            return NULL;
        }
        cout << endl << "****************" << endl;
    }
    int ptail() // печать хвоста
    {
        if (pointerL != (pointerR+1))
        {
            cout << "pointerL = " << pointerL << endl;
            cout << "pointerR = " << pointerR << endl;
            cout << endl << "****************" << endl;


            for (int i = pointerR; i > pointerL-1; --i)
            {
                cout << i << " : " << arr[i];
                if (i == pointerL)
                {
                    cout << " head " ;
                }
                if (i == pointerR)
                {
                    cout << " tail " ;
                }
                cout  << endl;
            }
            return 1;

        }else
        {
            cout << " EMpty ! " << endl;
            return NULL;
        }
        cout << endl << "****************" << endl;
    }

    int length() // количество непустых ячеек
    {
        if (pointerL != (pointerR+1)) // если дек не пустой
        {
            return pointerR - pointerL + 1;

        } else
        {
            return 0;
        }
    }

    cdequeue (cdequeue &another) // конструктор копирования
    {
        n = another.n;
        pointerL = another.pointerL;
        pointerR = another.pointerR;
        arr = new int[n];

        for (int i = pointerL; i <= pointerR; ++i) {
            arr[i] = another.arr[i];
        }
        cout<<endl<<"COPY"<<endl;
    }

    cdequeue operator = (cdequeue &another) // перегрузка присваивания. если размер меньше, переписать и оставить место
    {
        if(&another != this)
        {
            if (another.length() > n) // если элемменты не влезут
            {

                pointerL = 0;
                pointerR = n;
                int tmp;
                tmp = another.pointerL;

                for (int i = pointerL; i <= pointerR; ++i) // переносим все элементы от головы до хвоста
                {
                    arr[i] = another.arr[tmp]; // копируем вектор
                    tmp++;
                }
            }else
            {
                pointerL = 0;
                pointerR = another.length()-1;
                int tmp;
                tmp = another.pointerL;
                for (int i = pointerL; i <= pointerR; ++i)
                {
                    arr[i] = another.arr[tmp]; // копируем вектор
                    tmp++;
                }
            }

        }
        return *this;
    }
};

int main()
{
    cdequeue a(7);



    for (int i=1;i<10;i++) {
        a.ahead(i);
        a.atail(i*10);
    }
    a.phead();
    cdequeue b;
    b=a;
    b.phead();
    cout << "length = " << b.length() << endl;

    return 0;
}