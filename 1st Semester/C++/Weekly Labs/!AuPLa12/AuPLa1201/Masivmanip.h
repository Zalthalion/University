//Masivmanip.h
/*********************************************************************************************************************
Realizç klasi „Masivmanip”, kurâ tiek glabâts veselu skaitïu masîvs ar n komponentiem. Klasei izveidot ðâdas metodes:
(1) konstruktors, kas aizpilda masîva n komponentu vçrtîbas ar nullçm,
(2) destruktors, kurð paziòo par objekta likvidçðanu,
(3) metode "mainit" ar 2 parametriem – indeksu un vçrtîbu, kas izmaina masîva doto komponentu,
(4) metode "drukat", kas izdrukâ uz ekrâna masîva komponentus.
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
