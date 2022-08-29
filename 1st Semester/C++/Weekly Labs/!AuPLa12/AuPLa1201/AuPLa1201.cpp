//AuPLa1201.cpp
#include <iostream>
#include "lvfriendly.h"
using namespace std;
#include "Masivmanip.h"

int main(){

Masivmanip m1(3);
Masivmanip* dm;

m1.drukat();
m1.mainit(1, 17);
m1.drukat();
m1.mainit(12, 25);
m1.drukat();

dm = new Masivmanip(3);
dm->drukat();
dm->mainit(1, 17);
dm->drukat();
dm->mainit(12, 25);
dm->drukat();

delete dm;
return 0;

}
