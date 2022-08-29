//Masivmanip.h
/*********************************************************************************************************************
Realiz� klasi �Masivmanip�, kur� tiek glab�ts veselu skait�u mas�vs ar n komponentiem. Klasei izveidot ��das metodes:
(1) konstruktors, kas aizpilda mas�va n komponentu v�rt�bas ar null�m,
(2) destruktors, kur� pazi�o par objekta likvid��anu,
(3) metode "mainit" ar 2 parametriem � indeksu un v�rt�bu, kas izmaina mas�va doto komponentu,
(4) metode "drukat", kas izdruk� uz ekr�na mas�va komponentus.
**********************************************************************************************************************/
class Masivmanip
{
private:
    int n;              // n >= 1
    int* mas;
public:
    Masivmanip(int n);   // n >= 1
    ~Masivmanip();
    void mainit(int index, int vertiba); // 0 <= i <= n-1
    void drukat();


};
