#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define N 3

int A[N] = {1, 2, 3};

/*
class Node{
    public:
    Node* next;
    char *data;

    Node(){
        next = NULL;
        data = NULL;
    }

    void setData(char d[]){
        data = d;
    }

    char* getData(){
        return data;
    }

    void concatData(char* a){
        data = strcat(data, a);
    }
};
*/

class Node
{
public:
    Node *next;
    int *data;
    int size;

    Node(int n = 0) : size(n)
    {
        next = NULL;
        data = new int[n]{-1};
    }

    ~Node()
    {
        delete[] data;
    }

    void setData(int d[])
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = d[i];
        }
    }
};

class LinkedList
{
public:
    Node *head = NULL;

    LinkedList()
    {
        head = NULL;
    }

    void append(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            return;
        }
        Node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = n;

        log();
    }

    void log()
    {
        Node *t = head;
        while (t != NULL)
        {
            cout << "[";
            for (int i = 0; i < t->size; i++)
            {
                cout << t->data[i] << " ";
            }
            cout << "], ";
            t = t->next;
        }

        cout << endl;
    }
};

bool exist(int sums[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        if (sums[i] == sum)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "Begin" << endl;

    LinkedList *list = new LinkedList();
    // l.head = new Node(1);
    // l.head->setData(new int{9});

    // Node *n = new Node(2);
    // n->setData(new int[2]{1,2});

    // l.append(n);
    // l.log();

    int noOfSubSets = pow(2, N);
    noOfSubSets = noOfSubSets - 1;
    int sums[noOfSubSets] = {-1};
    int sumsIndex = 0;

    for (int i = 0; i < N; i++)
    {
        int aaja = 0;
        for (int j = i; j < N; j++)
        {
            int n = N - j;
            int a[n];
            int sum = 0;
            int index = 0;
            
            cout << "PRE - i: " << i << "N: " << 3 << "j: " << j << endl; 
            for (int k = i; k < N - aaja; k++)
            {
                a[index] = A[k];
                cout << "A[" << k << "]: " << A[k] << endl;
                sum += A[k];
                index++;
            }

            // Check if exist?
            bool doesExist = exist(sums, noOfSubSets, sum);

            if (!doesExist)
            {
                sums[sumsIndex] = sum;
                sumsIndex++;

                cout << "******** NEW ENTRY **********" << endl;
                for (int p = 0; p < n; p++)
                {
                    cout << "a[" << p << "]: " << a[p] << ", ";
                }
                
                cout << endl << "********************" << endl;
                Node *node = new Node(n);
                node->setData(a);

                list->append(node);

                Node *t = list->head;
                while (t != NULL)
                {
                    int n2 = 0;
                    int sum2 = 0;

                    bool isUnique = true;

                    for (int r = 0; r < n; r++)
                    {
                        for (int l = 0; l < t->size; l++)
                        {   
                            cout << "a[" << r << "]: " << a[r] << " == t[" << l << "]: " << t->data[l] << " ... " << endl;
                            if (a[r] == t->data[l])
                            {
                                isUnique = false;
                                break;
                            }
                            sum2 += t->data[l];
                        }
                        if (!isUnique)
                            break;
                    }

                    cout << "**********************" << endl;

                    if (!isUnique)
                    {
                        t = t->next;
                        continue;
                    }

                    sum2 += sum;
                    cout << "sum: " << sum << ", sum2: " << sum2 << endl;
                    n2 = t->size + n;

                    cout << "n: " << n << ", n2: " << n2 << endl;

                    // bool doesExist2 = exist(sums, sumsIndex, sum2);

                    for (int q = 0; q <= sumsIndex; q++)
                    {
                        cout << "[" << q << "]: " << sums[q] << endl;
                    }

                    sumsIndex++;
                    sums[sumsIndex] = sum2;

                    int *a2 = new int[n2];
                    int index2 = 0;
                    for (int m = 0; m < n; m++)
                    {
                        if (m < n)
                            a2[m] = a[m];
                    }

                    for (int o = 0; o < t->size; o++)
                    {
                        a2[n + o] = t->data[o];
                    }

                    Node *node2 = new Node(n2);
                    node2->setData(a2);

                    list->append(node2);

                    t = t->next;
                }
            }

            aaja++;
        }
    }

    for (int p = 0; p < noOfSubSets; p++)
    {
        /* code */

        cout << sums[p] << ", ";
    }

    cout << endl;

    return 0;
}

/*
int main(){

    char c1[2] = {a[0] + '0', '\0'};
    char c2[2] = {a[1] + '0', '\0'};
    std::cout << "Hello World " << c1 << " " << c2 << endl;

    Node *head = new Node();
    head->setData(c1);

    Node *newNode = new Node();
    newNode->setData(c2);
    head->next = newNode;

    Node *newNode2 = new Node();
    char c3[3] = {c1[0], c2[0], '\0'};
    newNode2->setData(c3);
    newNode->next = newNode2;

    Node *t = head;
    while(t != NULL){
        char *c = t->getData();
        cout << c << ", " << endl;
        t = t->next;
    }

    return 0;
}
*/