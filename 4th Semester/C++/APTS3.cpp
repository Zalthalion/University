#include <iostream>
using namespace std;


struct Marsietis
{
    int numurs;

    Marsietis* pa_kreisi;
    Marsietis* pa_labi;
    Marsietis* vecaks;

    Marsietis() : numurs(0), pa_kreisi(nullptr), pa_labi(nullptr), vecaks(nullptr) {};

    Marsietis(int numurs, Marsietis* pa_kreisi, Marsietis* pa_labi, Marsietis* vecaks)
    {
        this->numurs = numurs;
        this->pa_kreisi = pa_kreisi;
        this->pa_labi = pa_labi;
        this->vecaks = vecaks;
    }
};



struct Koks
{
    int senca_Numurs;
    Marsietis* marsiesi;


    Koks(int sencis)
    {
        this->marsiesi = new Marsietis[10001];
        this->senca_Numurs = sencis;
        this->marsiesi[senca_Numurs] = Marsietis(senca_Numurs, nullptr, nullptr, nullptr);
    }


    void pievieno_Mars(char& puse, int& vecaks, int& berns)
    {
        this->marsiesi[berns] = Marsietis(berns, nullptr, nullptr, &marsiesi[vecaks]);

        if (puse == 'R')
        {
            this->marsiesi[vecaks].pa_labi = &marsiesi[berns];

        }
        else if (puse == 'L')
        {
            this->marsiesi[vecaks].pa_kreisi = &marsiesi[berns];
        }
    }



    int mekle_pa_kreisi(Marsietis* n)
    {
        while (n->pa_kreisi != nullptr)
        {
            n = n->pa_kreisi;
        }
        return n->numurs;
    }

    int mekle_pa_labi(Marsietis* n)
    {
        while (n->pa_labi != nullptr)
        {
            n = n->pa_labi;
        }
        return n->numurs;
    }



    int mekle_nakamo(int numurs)
    {
        Marsietis* it = &this->marsiesi[numurs];

        if (it->pa_labi != nullptr)
        {
            return mekle_pa_kreisi(it->pa_labi);
        }

        Marsietis* vecaks = it->vecaks;

        while (vecaks != nullptr && it == vecaks->pa_labi)
        {
            it = vecaks;
            vecaks = vecaks->vecaks;
        }

        if (vecaks == nullptr)
        {
            return 0;
        }

        else
        {
            return vecaks->numurs;
        }
    }


    int mekle_ieprieksejo(int numurs)
    {
        Marsietis* it = &this->marsiesi[numurs];

        if (it->pa_kreisi != nullptr)
        {
            return mekle_pa_labi(it->pa_kreisi);
        }

        Marsietis* vecaks = it->vecaks;

        while (vecaks != nullptr && it == vecaks->pa_kreisi)
        {
            it = vecaks;
            vecaks = vecaks->vecaks;
        }

        if (vecaks == nullptr)
        {
            return 0;
        }

        else
        {
            return vecaks->numurs;
        }
    }
};

int main()
{
    freopen("aliens.in", "r", stdin);
    freopen("aliens.out", "w", stdout);

    int sencis;
    int vecaks;
    int child;
    char simbols;

    scanf("%d\n", &sencis);

    fprintf(stderr, "%d\n", sencis);

    Koks koks(sencis);
    bool error = false;

    while (scanf("%c %d %d\n", &simbols, &vecaks, &child))
    {
        fprintf(stderr, "%c %d %d\n", simbols, vecaks, child);

        if (simbols == 'F')
        {
            break;
        }

        if (simbols == '?')
        {
            if (koks.marsiesi[vecaks].numurs == 0)
            {
                printf("%s\n", "error0");
                continue;
            }

            printf("%d %d\n", koks.mekle_ieprieksejo(vecaks), koks.mekle_nakamo(vecaks));
        }
        else
        {
            if (vecaks == child)
            {
                printf("%s\n", "error1");
                continue;
            }

            if (koks.marsiesi[vecaks].numurs == 0)
            {
                printf("%s\n", "error2");
                continue;
            }

            if (koks.marsiesi[child].numurs != 0)
            {
                printf("%s\n", "error3");
                continue;
            }

            if (simbols == 'L' && koks.marsiesi[vecaks].pa_kreisi != nullptr)
            {
                printf("%s\n", "error4");
                continue;
            }
            if (simbols == 'R' && koks.marsiesi[vecaks].pa_labi != nullptr)
            {
                printf("%s\n", "error5");
                continue;
            }

            koks.pievieno_Mars(simbols, vecaks, child);
        }
    }
    return 0;
}