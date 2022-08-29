// APTS2_Serveris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include<queue>
using namespace std;





struct neighbor {
    int info;
    neighbor* next;
    neighbor* prev;
    bool visited;
};

int CountEdges(int verticeStart, int verticeFinish, neighbor*& arr, int ArrSize);
int main()
{
    fstream input;
    fstream output;



    /*neighbor computers [];*/

    input.open("serveris.in");
    {
        if (input.peek() == EOF)
        {
            output.open("serveris.out", ios::out);
            output << "nothing";
            output.close();
        }

        int c;
        input >> c;
        neighbor* arr = new neighbor[c + 1];

        for (int i = 1; i <= c; i++) {
            neighbor* p = new neighbor;
            p->info = i;
            p->next = NULL;

            arr[i] = *p;
        }

        int a, b;


        //Aizpilda sarakstu
        while (input >> a >> b)
        {
            if (a == 0 || b == 0)break;
            neighbor* p = new neighbor;
            neighbor* p1 = new neighbor;

            p->info = b;
            p1->info = a;
            p->next = NULL;
            p1->next = NULL;
            p->prev = NULL;
            p1->prev = NULL;

            //cout << p->info << " p info " << a << endl;

            if (arr[a].next == NULL) {
                arr[a].next = p;
                

            }
            else {
                neighbor* q = new neighbor;
                q = arr[a].next;
                while (1) {

                    if (q->next == NULL) {
                        q->next = p; 
                        p->prev = q;
                        break;

                    }
                    q = q->next;
                }
            }

            if (arr[b].next == NULL) {
                arr[b].next = p1;

            }
            else {
                neighbor* q = new neighbor;
                q = arr[b].next;
                while (1) {

                    if (q->next == NULL) {
                        q->next = p1; 
                        p1->prev = q;
                        break;
                    }
                    q = q->next;
                }
            }



        }



        //Iziet cauri visiem kaimiòiem
        for (int i = 1; i <= c; i++) {
            if (arr[i].next == NULL)
            {
                cout << i << "- >This pc is not connected to anyone" << endl;
                continue;
            }
            neighbor* head = new neighbor;
            
            head = arr[i].next;
            cout << i << " -> ";
            
            
            while (1) {

                cout << head->info << " -> ";
                if (head->next == NULL) {
                    

                    break;
                }
                head = head->next;
                


            }
            cout << endl;
        }




        int* shorthestPath = new int[c + 1];

        for (int i = 1; i <= c; i++) {
            shorthestPath[i] = 0;
        }

        
        
        /*for (int i = 1; i <= c; i++) {
            int edgecount = arr[i].next->info;
            shorthestPath[i] = edgecount;
            int tempEdge = 0;
            for (int j = 0; j <= c; j++){
                tempEdge = CountEdges(i, j, arr);
                if (tempEdge <= edgecount) shorthestPath[i] = tempEdge;
                
            }
        }*/

        cout << CountEdges(4, 2, arr, c) << endl;

        delete[]shorthestPath;
        delete[]arr;
    
    }
    input.close();
    
    
}


int CountEdges(int verticeStart, int verticeFinish,  neighbor*& arr, int ArrSize) 
{
    for (int a = 1; a <= ArrSize; a++) {
        arr[a].visited = false;
    }

    queue <int> Queue;

    arr[verticeStart].visited = true;

    Queue.push(verticeStart);

    while (!Queue.empty())
    {
        int w = Queue.back();
        Queue.pop();

    }
   



    
}