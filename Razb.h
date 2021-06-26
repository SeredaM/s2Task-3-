#ifndef RAZB_H_INCLUDED
#define RAZB_H_INCLUDED
struct R
{
    char name[10];
    int alive, hrs,swrd,gems,nk,wf,coins,wealth;

};
void add(struct R *band);
void kill (struct R *band);
void create (struct R *band);
void showrb(int i, struct R *band);
void showall(struct R *band);
void showsurv(struct R *band);
void showrich(struct R *band);
void showinfo(struct R *band);
void gr1(struct R *band);
void gr2(struct R *band);
void menu(struct R *band);
#endif // RAZB_H_INCLUDED
