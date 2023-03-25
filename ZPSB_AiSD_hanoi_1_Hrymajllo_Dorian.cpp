#include <bits/stdc++.h>
#include <iostream>
#include <tchar.h>

using namespace std;

template<class T> class MojStack
{
    T *m_data;
    int m_numElements;

public:

    MojStack() : m_data(NULL), m_numElements(0) { }

    ~MojStack()
    {
        free(m_data);
        m_data = NULL;
        m_numElements = 0;
    }

    bool empty()
    {
        free(m_data);
        m_data = NULL;
        m_numElements = 0;
        return true;
    }

    bool push(T data)
    {
        if(m_data == NULL)
        {
            m_numElements = 1;
            m_data = (T*) malloc(sizeof(T));
        }
        else
        {
            m_numElements++;
            m_data = (T*) realloc(m_data, m_numElements * sizeof(T));
            memmove(&m_data[1], m_data, (m_numElements - 1) * sizeof(T));
        }
        m_data[0] = data;
        return true;
    }



    int pop()
    {
        int wynik = -1;
        if(m_data == NULL)
        {
            m_numElements = 0;
            return -1;
        }
        else
        {
            wynik = top();
            if(m_numElements == 1)
            {
                m_numElements = 0;
                free(m_data);
                m_data = NULL;
            }
            else
            {
                m_numElements--;
                memmove(m_data, &m_data[1], m_numElements * sizeof(T));
                m_data = (T*) realloc(m_data, m_numElements * sizeof(T));
            }
        }
        return wynik;
    }

    T top()
    {
        if(m_numElements > 0)
            return m_data[0];
    }

    int size()
    {
        return m_numElements;
    }

    void DrukujStack()
    {
        int i = 0;
        cout << "[";
        for(i = m_numElements - 1; i >= 0; i--)
        {
            cout << "|" << m_data[i] << "|";
        }
        cout << "]";
    }
};

static int iloscRuchow = 0;
static int licznikA = 0;
static int licznikB = 0;
static int licznikC = 0;

static MojStack<int> *A = 0;
static MojStack<int> *B = 0;
static MojStack<int> *C = 0;

void DrukujStacks()
{
    if (licznikA != A->size() ||
        licznikB != B->size() ||
        licznikC != C->size())
    {
        int inneA = A->size() - licznikA;
        int inneB = B->size() - licznikB;
        int inneC = C->size() - licznikC;
        if (inneA == 1)
        {
            if (inneB == -1)
                cout << "Przesuniecie " <<  A->top() << " z B do A";
            else
                cout << "Przesuniecie " << A->top() << " z C do A";
        }
        else if (inneB == 1)
        {
            if (inneA == -1)
                cout << "Przesuniecie " << B->top() << " z A do B";
            else
                cout << "Przesuniecie " << B->top() << " z C do B";
        }
        else
        {
            if (inneA == -1)
                cout << "Przesuniecie " << C->top() << " z A do C";
            else
                cout << "Przesuniecie " << C->top() << " z B do C";
        }
        licznikA = A->size();
        licznikB = B->size();
        licznikC = C->size();
        cout << endl;
    }

    A->DrukujStack();
    cout << " , ";
    B->DrukujStack();
    cout << " , ";
    C->DrukujStack();
    cout << " , ";
}

void Rozwiaz2DiscsTOH(MojStack<int> *zrodlo, MojStack<int> *temp, MojStack<int> *docelowo)
{
    temp->push(zrodlo->pop());
    iloscRuchow++;
    DrukujStacks();

    docelowo->push(zrodlo->pop());
    iloscRuchow++;
    DrukujStacks();

    docelowo->push(temp->pop());
    iloscRuchow++;
    DrukujStacks();
}

int RozwiazTOH(int nDyski, MojStack<int> *zrodlo, MojStack<int> *temp, MojStack<int> *docelowo)
{
    if (nDyski <= 4)
    {
        if ((nDyski % 2) == 0)
        {
            Rozwiaz2DiscsTOH(zrodlo, temp, docelowo);
            nDyski = nDyski - 1;
            if (nDyski == 1)
                return 1;

            temp->push(zrodlo->pop());
            iloscRuchow++;
            DrukujStacks();

            Rozwiaz2DiscsTOH(docelowo, zrodlo, temp);

            docelowo->push(zrodlo->pop());
            iloscRuchow++;
            DrukujStacks();

            RozwiazTOH(nDyski, temp, zrodlo, docelowo);
        }
        else
        {
            if (nDyski == 1)
                return 0;
            Rozwiaz2DiscsTOH(zrodlo, docelowo, temp);
            nDyski = nDyski - 1;
            docelowo->push(zrodlo->pop());
            iloscRuchow++;
            DrukujStacks();
            Rozwiaz2DiscsTOH(temp, zrodlo, docelowo);
        }
        return 1;
    }
    else if (nDyski >= 5)
    {
        RozwiazTOH(nDyski - 2, zrodlo, temp, docelowo);
        temp->push(zrodlo->pop());
        iloscRuchow++;
        DrukujStacks();
        RozwiazTOH(nDyski - 2, docelowo, zrodlo, temp);
        docelowo->push(zrodlo->pop());
        iloscRuchow++;
        DrukujStacks();
        RozwiazTOH(nDyski - 1, temp, zrodlo, docelowo);
    }
    return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int sz, i, iloscDyskow;
        cout << "Wpisz ilosc dyskow: " << endl;
        cout << "ilosc: ";
        cin >> iloscDyskow;
        while(iloscDyskow < 2){
                cout << "Ilosc Dyskow nie moze byc mniejsza niz 2 !!!\nilosc: ";
                cin >> iloscDyskow;
        }
        cout << endl;
    A = (MojStack<int>*) malloc(sizeof(MojStack<int>));
    B = (MojStack<int>*) malloc(sizeof(MojStack<int>));
    C = (MojStack<int>*) malloc(sizeof(MojStack<int>));

        iloscRuchow = 0;
        memset((void*)A, 0, sizeof(MojStack<int>));
        memset((void*)B, 0, sizeof(MojStack<int>));
        memset((void*)C, 0, sizeof(MojStack<int>));
        for (i = iloscDyskow; i >= 1; i--){
            A->push(i-1);
        }
        licznikA = A->size();
        licznikB = B->size();
        licznikC = C->size();
        DrukujStacks();
        RozwiazTOH(iloscDyskow, A, B, C);
        cout << "Ilosc ruchow = " << iloscRuchow;
        A->empty();
        B->empty();
        C->empty();
    cout << endl;
    return 0;
}
