#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Razb.h"


void main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   struct R band[41];
   create(band);
   menu(band);
}
