const int hrs$=100,swrd$=50,gems$=200,nk$=100,wf$=200;
#include <graphics.h>
struct R
{
    char name[10];
    int alive, hrs,swrd,gems,nk,wf,coins,wealth;

};
void add(struct R *band)
{
 int i=0;
 while (strcmp(band[i].name,"0")!=0)
    i++;
    printf("Введите в следующем порядке: Имя,скакуны,сабли,рубины,рубины,жёны,монеты\n");
    scanf("%s %d %d %d %d %d %d",&band[i].name, &band[i].hrs, &band[i].swrd, &band[i].gems, &band[i].nk, &band[i].wf, &band[i].coins);
    band[i].alive=1;
    band[i].wealth=band[i].hrs*hrs$ + band[i].swrd*swrd$ + band[i].gems*gems$ + band[i].nk*nk$ + band[i].coins - band[i].wf*wf$;
    band[40].alive++;
    band[40].hrs+=band[i].hrs;
    band[40].swrd+=band[i].swrd;
    band[40].gems+=band[i].gems;
    band[40].nk+=band[i].nk;
    band[40].wf+=band[i].wf;
    band[40].coins+=band[i].coins;
    band[40].wealth+=band[i].wealth;
}
void kill (struct R *band)
{
 int i=0;
    char nm[10];
    printf("Введите имя разбойника:\n");
    scanf("%s",&nm);
    while ((i<40)&&(strcmp(band[i].name,nm)!=0))
           i++;
    band[i].alive=0;
    band[40].alive--;
    band[40].hrs-=band[i].hrs;
    band[40].swrd-=band[i].swrd;
    band[40].gems-=band[i].gems;
    band[40].nk-=band[i].nk;
    band[40].wf-=band[i].wf;
    band[40].coins-=band[i].coins;
    band[40].wealth-=band[i].wealth;
}
void create (struct R *band)
{

    int c;
     printf("Введите начальное количество разбойников и их имена \n");
   scanf("%d",&c);
    for (int i=0;i<41;i++)
   {


     band[i].alive=0;
     strcpy(band[i].name,"0");
     band[i].hrs=0;
     band[i].swrd=0;
     band[i].gems=0;
     band[i].nk=0;
     band[i].wf=0;
     band[i].coins=0;
     band[i].wealth = 0;
   }
    strcpy(band[40].name,"Итого");
   for (int i=0;i<c;i++)
    {
    scanf("%s",&band[i].name);
    band[i].hrs=rand()%10;
    band[i].swrd= rand()%10;
    band[i].gems= rand()%20;
    band[i].nk=rand()%10;
    band[i].wf=rand()%4;
    band[i].coins=rand()%3000;
    band[i].alive=1;
    band[i].wealth=band[i].hrs*hrs$ + band[i].swrd*swrd$ + band[i].gems*gems$ + band[i].nk*nk$ + band[i].coins - band[i].wf*wf$;
    band[40].alive++;
    band[40].hrs+=band[i].hrs;
    band[40].swrd+=band[i].swrd;
    band[40].gems+=band[i].gems;
    band[40].nk+=band[i].nk;
    band[40].wf+=band[i].wf;
    band[40].coins+=band[i].coins;
    band[40].wealth+=band[i].wealth;
    }


}
void showrb(int i, struct R *band)
{
  printf("%s ",&band[i].name);
        if (band[i].alive==0)
            printf("нет ");
            else printf("да ");
        printf("%d %d %d %d %d %d %d\n",band[i].hrs, band[i].swrd, band[i].gems, band[i].nk, band[i].wf, band[i].coins,band[i].wealth);
}
void showall(struct R *band)
{
  int i=0;
  printf("Имя Живой Скакуны Рубины Ожерелья Монеты Жёны Богатство\n");
    while ((i<40)&&(strcmp(band[i].name,"0")!=0))
    {
        showrb(i,band);
        i++;
    }

printf("%s %d %d %d %d %d %d %d %d\n",band[40].name,band[40].alive,band[40].hrs, band[40].swrd, band[40].gems, band[40].nk, band[40].wf, band[40].coins, band[40].wealth);
}
void showsurv(struct R *band)
{
    int i=0;
  printf("Имя Живой Скакуны Рубины Ожерелья Монеты Жёны Богатство\n");
    while ((i<40)&&(strcmp(band[i].name,"0")!=0))
    {
        if (band[i].alive==1)
        {
            showrb(i,band);
        }
        i++;
    }

printf("%s %d %d %d %d %d %d %d %d\n",band[40].name,band[40].alive,band[40].hrs, band[40].swrd, band[40].gems, band[40].nk, band[40].wf, band[40].coins, band[40].wealth);
}
void showrich(struct R *band)
{
    int max=0,i=0;
    while ((i<40)&&(strcmp(band[i].name,"0")!=0))
    {
       if ((band[i].wealth>max)&&(band[i].alive=1))
            max=band[i].wealth;
       i++;
    }
    i=0;
    while ((i<40)&&(strcmp(band[i].name,"0")!=0))
    {
       if ((band[i].wealth==max)&&(band[i].alive=1))
            showrb(i,band);
       i++;
    }
}
void showinfo(struct R *band)
{
    int i=0;
    char nm[10];
    printf("Введите имя разбойника:\n");
    scanf("%s",&nm);
    printf("Имя Живой Скакуны Рубины Ожерелья Монеты Жёны Богатство\n");
  while ((i<40)&&(strcmp(band[i].name,"0")!=0))
  {
     if (strcmp(band[i].name,nm)==0)
        showrb(i,band);
        i++;
  }
}
void gr1(struct R *band)
{
    int a;
    float start,end;
int driver, mode,i=0,clr=1;
driver = DETECT;
mode = 0;
initgraph(&driver, &mode,"");
while ((i<40)&&(strcmp(band[i].name,"0")!=0))
    {
        if (band[i].alive==1)
        {
         setcolor(clr);
         clr++;
         end=start+360*band[i].wealth/band[40].wealth;
         pieslice (300, 200, start, end, 150);
         start=end;
        }
        i++;
    }
getch ();
}
void gr2(struct R *band)
{
    int a;
    float x1=100,y1=200, h=50;
int driver, mode,i=0,clr=1;
driver = DETECT;
mode = 0;
initgraph(&driver, &mode,"");
while ((i<40)&&(strcmp(band[i].name,"0")!=0))
    {
        if (band[i].alive==1)
        {
         setcolor(clr);
         rectangle (x1,y1,x1+h,y1-200*band[i].wealth/band[40].wealth);
         setfillstyle(HATCH_FILL,clr);
         floodfill(x1+20,y1-20,clr);
         x1+=h+1;
         clr++;
        }
        i++;
    }
getch ();
}

void menu(struct R *band)
{
    int a;
  printf("Выберите действие:\n 1.Вывести полный состав банды \n 2.Вывести актуальный состав банды \n 3.Показать самого богатого \n 4.Убить разбойника\n 5.Добавить разбойника\n 6.Показать информацию о разбойнике \n 7.Вывести круговую диаграмму \n 8. Вывести столбчатую диаграмму \n 9. Распустить банду(закрыть) \n");
   scanf("%d",&a);
   switch(a)
   {
    case 1:
        showall(band);
        break;
    case 2:
        showsurv(band);
        break;
    case 3:
        showrich(band);
        break;
    case 4:
        kill(band);
        break;
    case 5:
        add(band);
        break;
    case 6:
        showinfo(band);
        break;
    case 7:
        gr1(band);
        break;
    case 8:
        gr2(band);
        break;
    case 9:
        return;
   }
   menu(band);
}
