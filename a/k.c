char what_a_k_c[] = "@(#) $Id: k.c,v 1.67 1993/04/30 00:54:13 atw Exp $";
#include "f.h"
Z I MY[2001];Z struct _cx rx;CX Rx,Cx;I Xf;
I nl,sq=2,q,(*g)(),*Y,*X,*XY,*K=MY;
extern HT hti();
ki(){H("ki ");A a; X=Y=XY=(K=MY)+2000,*X=*K=0,*++K=0,Cx=Rx=&rx,
 rx.s=(S)si(""),rx.n=0,rx.ht=hti(HTSIZE),H("ki->");a=gv(Et,0),a->c=0,nl=(I)a,H("ki->");te();H("ki=> ");}
ic(a)A a;{R!QA(a)?(I)a:a->c?(++a->c,(I)a):im(a);}
dc(a)A a;{H("dc ");if(QA(a)&&a)a->c?H("dc->"),--a->c||dec(a):H("dc->"),dm(a);H("dc=> ");}
dec(a)A a;{H("dec->");
 if(a->t<Et){int res=mf(a);H("dec=> ");R res;}
 if(a->t==Et)DO(a->n,dc(a->p[i]))
 else
  if(a->t==Xt)DO(a->r,dc(a->d[i]))
  else ef(*a->p),mf(a->p[a->n+1]);
 mf(a);}

ef(a)I a;{H("ef "); E e;I n;
 if(!QE(a)){H("ef->");int res=dc(a);H("ef=> ");R res;}
 e=XE(a);
 DO(e->n,ef(e->a[i]))H("ef->"),ef(e->f),H("ef->"),mf(e);}

I *tm(n){H("tm "); Z I *ta=0; if(ta){H("tm->");mf(ta);}
 if(n){H("tm->");ta=ma(n);} else ta=0; H("tm=> ");R ta;}
mv(d,s,n)I *d,*s;{DO(n,*d++=*s++)}
C *tst(t,d,j,s,k,n)I *d,*s;{switch(t){
 CS(It,DO(n,*d=*s;d+=j;s+=k)R(C*)d;)
 CS(Et,DO(n,*d=ic(*s);d+=j;s+=k)R(C*)d;)
 CS(Ft,{F *a=(F*)d;F *b=(F*)s;DO(n,*a=*b;a+=j;b+=k)R(C*)a;})
 CS(Ct,{C *a=(C*)d;C *b=(C*)s;DO(n,*a=*b;a+=j;b+=k)R(C*)a;})}}
C *tmv(t,d,s,n)I *d,*s;{switch(t){
 CS(It,DO(n,*d++=*s++)R(C*)d;)
 CS(Et,DO(n,*d++=ic(*s++))R(C*)d;)
 CS(Ft,{F *a=(F*)d;F *b=(F*)s;DO(n,*a++=*b++)R(C*)a;})
 CS(Ct,{C *a=(C*)d;C *b=(C*)s;DO(n,*a++=*b++)R(C*)a;})}}
C *trp(t,d,s,n){R tst(t,d,1,s,0,n);}
Z F f;Z C c=' ';C *zer(t,d,n){R trp(t,d,t==Ct?&c:t==Et?(C*)&nl:(C*)&f,n);}
zr(a)A a;{zer(a->t,a->p,a->n);R(I)a;}
I tr(r,d)I r,*d;{I n,*t;if(!r)R 1;for(t=d+r,n= *d;++d<t;n*= *d);R n;}
tr1(r,d)I r,*d;{F s=1;I t;if(r<0)DO(-r,s*=*d)else DO(r,if(s*=t=*d++,t<0)R -1)R s>0x7FFFFFFF?-1:(I)s;}
#define GA(_t,_r,_n,x) {H("GA ");\
 I _f=_t==Ct;H("GA->");A z=(A)mab(_f+AH+Tt(_t,_n));z->c=1,z->t=_t,z->r=_r,z->n=_n;x;if(_f)((C*)z->p)[_n]=0;\
 H("GA=> ");R z;}
A gm(t,m,n)GA(t,2,m*n,*z->d=m;z->d[1]=n)        A gv(t,n)GA(t,1,n,*z->d=n)
A gd(t,a)A a;GA(t,a->r,a->n,mv(z->d,a->d,a->r)) A ga(t,r,n,d)GA(t,r,n,mv(z->d,d,r))
A gc(t,r,n,d,p)GA(t,r,n,mv(z->d,d,r);tmv(t,z->p,p,n))
A gi(i)I i;GA(It,0,1,*z->p=i)A gs(t)GA(t,0,1,1) A gf(f)F f;GA(Ft,0,1,*(F*)z->p=f)

#define EV(z) {H("EV ");I t;switch(M&z){CS(0,ic(z))CS(3,H("EV->");z=ee(XE(z)))\
 CS(1,ic(z=gt(XV(z))))CS(5,for(;!(t=X[U(z)]);)err(4,z);ic(z=t))}H("EV=> ");}

I ev(z){H("ev ");
  if(q)err(q,QE(z)?XE(z)->f:z);
  H("ev->");EV(z) 
  H("z:%d ev=> ",z);R z;}

extern PX(),(*PN[])(),(*P1[])(),(*P2[])();

I ee(e)E e;{H("ee ");I z,i,n,f=e->f;
 if(QN(f)){H("ee=> ");R(*PN[U(f)])(e);}
 for(i=n=e->n;i;*--Y=z){z=e->a[--i];H("ee->");EV(z)}H("ee->");EV(f)
 if(QA(f)){++n;*--Y=f;if(((A)f)->t>Xt+1)z=(I)ga(Xt,n,0L,Y),Y+=n,z;z=af(n);H("ee=> ");R z;}
 else{i=U(f);
  EQ(0,QX(f)?(i?PX(i,n):xin(*Y,n-1,0)):n==2?(*P2[i])(*Y,Y[1],i):(*P1[i])(*Y,i))}
 DO(n,H("ee->");dc(*Y++))H("ee=> ");R z;}

I fa(f,a,w){I z,i,n=w?2:1;if(w)*--Y=w;*--Y=a;if(QA(f))ic(*--Y=f),z=af(++n);
 else{i=U(f);EQ(0,QX(f)?PX(i,n):n==2?(*P2[i])(*Y,Y[1],i):(*P1[i])(*Y,i))}
 DO(n,dc(*Y++))R z;}

Z es(e,n,a)E e;{e->a[n]=a?a:(I)nl;}Z ms(s){A z=gs(Et);R *z->p=MS(s),(I)z;}
A af4(f,a,b,c,d,v)A f;V v;{I z=b?0:3,x=0,y=0,n=QA(f)&&f->t==Xt+1&&f->r-1<7-z?f->r-1:0;
 E e=(E)ma(2+n);e->n=n,e->f=(I)f;if(n>4-z)if(y=ms(v->s),x=ms(v->cx->s),z)b=x,c=y;
 switch(n){case 6:es(e,5,y);case 5:es(e,4,x);case 4:es(e,3,d);
           case 3:es(e,2,c);case 2:es(e,1,b);case 1:es(e,0,a);}
 R a=ez(ME(e)),xrr(),mf(e),dc(x),dc(y),(A)a;}
A un(v)A *v;{A a=*v;if(a->c>1||!a->c&&!wr(a))*v=gc(a->t,a->r,a->n,a->d,a->p),dc(a);R *v;}
extern MZ[]; extern I Sf;
Z app(z,w)A *z,w;{A a=un(z);Q(!a->r,7){XA;XW,h=wr==ar,m=(h?*wd:1)+*ad,n=m*tr(--ar,++ad);Q(!a->r,7)
 Q(wr!=ar+h,7)Q(cm(ad,wd+h,ar),8) if(!a->c)Q(m>a->i,16)else
  if(AH+Tt(at,n)+(at==Ct)+4>4*MZ[255&((I*)a)[-1]])*z=ga(at,ar+1,n,ad-1),
    tmv(at,(*z)->p,a->p,an),dc(a),a=*z;
 tmv(at,((C*)a->p)+Tt(at,an),w->p,wn);R a->n=n,*a->d=m,(I)w;}}
Z in(z,a,w,r)A*z,a,w;{H("in\n");
 A v;I j=(*z)->t;
 if(j!=w->t&&(!(w=j==Ft?ep_cf(2):j==It?ci(2):(q=6,(A)0))))R 0;
 if(!a)R app(z,w);v=un(z); if(!r)R xr(v,a,w);
 if(j=w->n!=1){Q(w->r!=a->r,7)Q(cm(w->d,a->d,w->r),8)}
 I1{I *ap=a->p,t=w->t,n=a->n;P p;C *wp=(C*)w->p;p.i=v->p;j=T(j);
  DO(n,Q((unsigned)(n=*ap++)>=v->n,10)switch(t){
   CS(It,p.i[n]=*(I*)wp)        CS(Ft,p.f[n]=*(F*)wp)  CS(Ct,p.c[n]=*wp)
   CS(Et,dc(p.a[n]);p.i[n]=ic(*(A*)wp))}wp+=j)  R 1;}}
pcb(v,d,i,p)V v;{I a;R Sf&&v->p?(a=(I)af4(v->p,v->q,d,i,p,v),dc(d),a):d;}
prcb(v,d,i,p)V v;{I a;R Sf&&v->rpf?(a=(I)af4(v->rpf,v->rpc,d,i,p,v),dc(d),a):d;}
Z enc(a){A z=gs(Et);R *z->p=a,(I)z;}
Z gap(a,w)A a,w;{I v=a->r==w->r,n=v?*w->d:1;A z=v?gv(It,n):gs(It);
 DO(z->n,z->p[i]=*a->d+i)R enc(z);}
Z gia(i,r)A i;{R!r&&i&&i->t<Et?enc(i):(I)i;}
Z e0(e,a)E e;{I *r=e->a+e->n-1;A z=gd(It,a);I t=*r;
 DO(z->n,z->p[i]=i)R *r=(I)z,a=ez(ME(e)),dc(z),*r=t,a;}
Z upd(x,d,i,p,r)A p;{I b[2],f=QV(x),a,*z,g=i==MP(22);V v=f?XV(x):(V)(X+U(x));
  extern I Sf;
  if(f){if(p||i)gt(v);}else Q((p||i)&&!v->a,4)z=p?(I*)pka(p,v):(I*)v;
  if(QE(i))Q(!(i=*Y=e0(XE(i),*z)),9)
  if(f){Q(g&&0==((A)(*z))->r,7);i=*Y=g?gap((A)*z,(A)d):gia((A)i,r);
   Y[2]=d=prcb(v,d,i,p);if(!d)R 0;Y[2]=d=pcb(v,d,i,p);if(!d)R 0;
   Q(!p&&!i&&v->o&&!vfy(v,d),17)}
  if(!z)R 0;a=!i?(dc(*z),*z=ic(d)):in(z,g?0:i,d,r);if(!a||!f)R a;
  i=*Y;d=Y[2];
  if(v->z!=2) {inv(v,r||g?0:i);
    if(Sf&&v->f)v->z=2,dc(af4(v->f,v->c,d,i,p,v));
    if(Sf&&v->rff)v->z=2,dc(af4(v->rff,v->rfc,d,i,p,v));
    val(v);}
  if(v->o)xup(v,d,i,p,r);R 1;}
set(x,a){I r;R *--Y=a,*--Y=0,*--Y=0;r=upd(x,a,0,0,0),dc(Y[2]),Y+=3,r;}
aset(v,d,i,p){I r;Y-=3,*Y=i?ic(i):0,r=upd(MV(v),Y[2]=d,i,p,0);dc(Y[2]),dc(*Y),Y+=3;R xrr(),r;}
Z lst(n,p,w)I *p;A w;{Q(w->r>1,7)Q(w->r&&w->n!=n,8)
 DO(n,if(!set(p[i],pck(i*w->r,w)))R 0)DO(n,if(QV(p[i]))XV(p[i])->z=1)R 1;}
#define Q1(x,n) if(x){R mf(va),q=n,0;}
Z pea(e,w)E e;A w;{I f=e->n-1,n,*va;A c=(A)(f?ev(*e->a):0),v=(A)ev(e->a[f]);
 va=ma(n=v->n),dc(c),dc(v);Q1(v->r<1,7)Q1(n&&!sym(v),9)
 if(f){Q1(c->r>1,7)Q1(c->n&&!sym(c),9)Q1(v->r&&c->r&&c->n!=n,0)if(c->r)n=c->n;}
 DO(n,va[i]=MV(sv(f?cxi(XS(c->p[i*c->r])):Cx,XS(v->p[i*v->r]))))
 R n=lst(n,va,w),mf(va),n;}
Z xli(e)E e;{A z;I n=e->n-1;W(gv(Et,n));*--Y=zr(z);for(;n--;)z->p[n]=ev(e->a[n+1]);R ++Y,(I)z;}
Z S ss(x){A a=(A)ev(x);R dc(a),!a->r&&sym(a)?XS(*a->p):0;}
Z mr0(e)E e;{I y,f=e->f,n,r=0;A a;if(f!=MP(36)&&f!=MP(74)){n=e->n-1;
  if(QE(y=f==MX(0)?*e->a:e->a[n])&&(r=XE(y)->f==MP(22)))y=*XE(y)->a;
  *Y=f==MP(20)?ev(*e->a):f!=MX(0)?(r=1,ME(e)):n==1?ev(e->a[1]):xli(e);
  if(QE(y))e=XE(y),f=e->f;}
 if(f==MP(36))if(y=e->a[1],Y[1]=ev(*e->a),QE(y=e->a[1]))e=XE(y),f=e->f;
 if(f==MP(74)){S s=ss(e->a[n=e->n-1]),c=n?ss(*e->a):0;Q(!s||n&&!c,9)
  y=MV(sv(n?cxi(c):Cx,s));} R upd(y,Y[2],*Y,Y[1],r);}
Z mrg(e){R *--Y=0,*--Y=0,e=mr0(e),dc(*Y++),dc(*Y++),e;}
xis(e)E e;{I n=e->n-1,a=*e->a,w=e->a[n];EV(w)if(!n)_longjmp(J,w);
 for(*--Y=w;!(!QE(a)?set(a,ic(w)):(e=XE(a),e->f==MN(7))?lst(e->n,e->a,w)
  :peak(e->f)?pea(e,w):mrg(e));)err(q,MN(0));R *Y++;}
