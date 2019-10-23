#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct list{
	double data;
	int timestamp;
	int to_del;//camp pentru exercitiul 1
	struct list *next;
} *List;

//functiile de baza
List add_tail(List l, double data,int tmp);
List init(double data,int tmp);
void freel(List l);
List sterge_1(List l, List n);
List add_node(List l,int aux,int naux,double val,int tmp,int *nr);
void print(List lst, int nr);
//functiile pe care le folosesc in exercitii
List eliminareE(List lst, int nr, int *nounr);
List mediana(List lst,int nr,int *nrm);
List ma(List l,int nrm, int *nr3);
List uniformizare(List l, int nr);
double w(double i,double k );
double C(double tmp,double ltmp, double rtmp);
double f(List st, List dr, int tmp, double ce);
List ex4(List l,int *nr);
void delta(List l, double d, int nr);


List add_tail(List l, double data,int tmp)
{	
	//adaug la sfarsitul listei un nou element
	List nou=malloc(sizeof( struct list));
	List q;
	q=l;
		nou->data=data; //initializez toate campurile
		nou->to_del=0;
		nou->timestamp=tmp;
	while(l->next!=NULL)
		{l=l->next;
		}//se opreste pe ultimul
	nou->next=NULL;
	l->next=nou;//fac legatura
	
	return q;

	
}

void freel(List l)
{
	//eliberez lista
	List p;
	while(l!=NULL){
		p=l;//retin capul de lista de fiecare data
		l=l->next;//ma deplasez
		free(p);//eliberez nodul acum anterior
	
	}
	free(l);
}
	
List init(double data,int tmp)
{	
	//initializez o lista
	List n1,lst=malloc(sizeof(struct list));//aloc memorie pentru noua lista
	lst->data=data;//initializez campurile
	lst->to_del=0;
	lst->timestamp=tmp;
	lst->next=NULL;
	n1=lst;//un pointer pointeaza spre capul de lista
	lst=NULL;
	freel(lst);
	return n1;
}


List sterge_1(List l, List n)
{	
	//sterg un nod din lista
	List q,r;
	q = l;//retin capul de lista
	if(q->data == n->data){ 
		//cazul in care trebuie sa sterg primul nod
		r = q;
		q = q->next;
		free(r);
		return q;
	}

	while(q->next != NULL){
		r = q->next;//ma deplasez prin lista
		if(r != NULL && r->data == n->data){//trebuie sa retin nodul de dinainte
			if(r->next == NULL)
				q->next = NULL;//daca ajung cumva pe NULL
			else
				q->next = r->next;
			free(r);
			return l;
		}
		q = q->next;
	}
	return l;
}

List add_node(List l,int aux,int naux,double val,int tmp,int *nr)
{
	//adaug un nou nod in interiorul listei
	//aux=valoarea dupa care trebuie sa adaug, naux valoarea inaintea careia trebuie sa aduag
	List p,q;	
	p=l;//pointer spre capul de lista
	List nou=malloc(sizeof(struct list));//aloc memorie pentru noul nod

	while(p->next!=NULL){
		if(p->timestamp==naux){
			q=p;//gasesc locul unde trebuie sa aduag, dupa naux
		}
			p=p->next;
	}
	p=l;//ii dau din nou capul de lista pentru a ma putea deplasa prin ea
	while(p->next!=NULL){
		if(p->timestamp==aux){
			nou->data=val;//completez campurile noului nod
			nou->next=q;
			p->next=nou;
			nou->timestamp=tmp;
			(*nr)++;
					
 		}
			
	p=p->next;
			
	}
	return l;
		
}

void print(List lst, int nr)
{
	//afisarea listei
	List p;
	p=lst;
	 printf("%d\n",nr);
		
		while(p!=NULL)
			{	//afisez lista
				printf("%d ",p->timestamp);
				printf("%0.2lf\n",p->data);
				p=p->next;
			

		}

}


List eliminareE(List l,int nr, int *nrn)
{	
	//exercitiul 1
	List nod,q,r,aux;
	int i,j; 
	double s,med,sum=0,dev;
	*nrn=nr;//numarul nodurilor din urmatoarea lista(nrn)
	q=l;
	r=l;//retin capul de lista
	nod=l->next->next;//retin nodul din mijlocul ferestrei

	for(i=0;i<(*nrn)-4;i++){
		//parcurg lista
		s=0;med=0,sum=0;
		//pentru fiecare fereastra de 5 noduri
		for(j=0;j<5;j++){
			s=s+q->data;//calculez suma lor
			q=q->next;
		}
		//apoi fac media
		med=s/5;
		q=r;//ma intorc la primul nod din fereastra
		for(j=0;j<5;j++){
			//parcurg fereastra de 5 noduri pentru a afla sum din formula deviatiei
			sum=sum+pow(q->data-med,2);
			q=q->next;
	
		}
		dev=sqrt(sum/5);//aflu deviatia
		
		if(nod->data>(med+dev)||nod->data<(med-dev)){
			//verific daca valoarea nodului se afla in intervalul dorit
			nod->to_del=1;
			//daca nu setez campul de sters
			}

		r=r->next;
		nod=r->next->next;
		q=r;
		
	}
	q=l;
	r=l;
	nod=l->next->next;
	//parcurg lista intreaga pentru a sterse nodurile cu campul to_del=1
	while(nod->next!=NULL){
		if(nod->to_del==1){
			aux=nod;

			l = sterge_1(l,aux);
			(*nrn)--;//scad numarul de noduri
			q=r;
			nod=r->next->next;
		}

		else{ 
			r=r->next;
			q=r;
			nod=r->next->next;

		}

	}
	return l;


}
List mediana(List l,int nr,int *nrm)
{	
	//exercitiul 1.2.1
	List q,r,s,rez,z,x;
	int i,j;
	double aux,t;
	(*nrm)=0;
	s=init(1,0);//am initializat lista noua;
	for(i=0;i<4;i++){
		t=3;//valoare random de adaugat in nod
	s=add_tail(s,t,0);//am adaugat 5 noduri la lista de sortare
	t++;
	}
	q=l;//prin lista initiala
	r=l;
	z=s;//ma misc prin lista de sortari
	
	for(i=0;i<nr-4;i++){
		//parcurg lista
		for(j=0;j<5;j++){
			aux=q->data;
			z->data=aux;//adaug in lista de sortari
			z->timestamp=q->timestamp;
			z=z->next;
			q=q->next;
		}
	
		//acum o sortam
		for(z=s;z!=NULL;z=z->next){
			for(x=z->next;x!=NULL;x=x->next){
				if(z->data>x->data){
					aux=z->data;
					z->data=x->data;
					x->data=aux;
		
					}
			}
		}
		
		z=s;

		for(j=0;j<5;j++){//verificarea si adaugarea in lista
			if(j==2){
				//daca am ajuns in mijlocul listei de sortari
				if((*nrm)==0){
					//daca nu avem niciun element
					rez=init(z->data,z->timestamp);
					(*nrm)++;
					//e primul element, initalizam lista

				}
				else{
					rez=add_tail(rez,z->data,z->timestamp);
					(*nrm)++;
				}

			}

			z=z->next;
		}

		r=r->next;//pentru urmatoarea fereastra de 5 noduri
		q=r;
		z=s;
	}
	
	//eliberel listele
	freel(s);
	freel(l);
	//returnez lista rezultata
	return rez;
	

}

List ma(List l,int nrm, int *nr3)
{
	//1.2.2
	int i,j,auxi;
	List rez,q,r;
	double media,s;
	q=l;
	r=l;
	for(i=0;i<nrm-4;i++){
		//parcurg lista
		media=0;
		s=0;
		//pentru fiecare 5 noduri
		for(j=0;j<5;j++){
			s=s+q->data;
			if(j==2){
				auxi=q->timestamp;
			}
			q=q->next;
			
		}
	
		media=s/5;//fac media nodurilor din fereastra
		//o adaug la lista
		if((*nr3)==0){
			//daca nu am inca niciun element o initializez
			rez=init(media,auxi);
			(*nr3)++;
			
		}
		else{
			add_tail(rez,media,auxi);
			(*nr3)++;
		}
		r=r->next;
		q=r;
	}
	freel(l);
	//returnez lista rezultata
	return rez;

}
List uniformizare(List l, int nr)
{
	//1.3
	List p,q;
	double dif;
	int i;
	q=l;//capul de lista
	p=l->next;//un nod inainte
	for(i=0;i<nr-1;i++){
		//parcurg lista
		dif=p->timestamp-q->timestamp;//diferenta dintre nodul anterior si cel curent
		if(dif>=100 && dif<= 1000){
			//daca df lor e mai mare ca 100, <1000 atunci nodul ia valoarea medie 
			p->timestamp=(p->timestamp+q->timestamp)/2;
			p->data=(p->data+q->data)/2;
		}
		p=p->next;
		q=q->next;

	}
	return l;
}



double w(double i,double k )
{
	k=3;//mereu va avea valoarea 3
	double s1,p1,p,p3;
	double n1=0,rez=0,n3=0,s3;
	double q;
	s1=i/(k-1);
	p1=pow(s1,2);
	n1=p1*0.9+0.1; //calculez numaratorul

	//calzulez numitorul
	for(p=0;p<k;p++){
		//pentru suma de la 0, la k
		s3=p/(k-1);
		p3=pow(s3,2);
		n3= n3+ p3*0.9+0.1;
	
	}
	
	rez=rez+n3;
	q=n1/rez;//rezultatul functiei
	return q;

}

double C(double tmp,double ltmp, double rtmp)
{
	double a,b,rez;
	a=tmp-ltmp;
	b=rtmp-ltmp;
	rez=a/b;
	
	return rez;

}


double f(List st, List dr, int tmp, double ce)
{
	int i,j;
	List q,p;
	double s1=0,s2=0,rez=0;
	double da=0;
	double po=0,pi=0;
	p=st;
	//s1 prima suma
	for(i=0;i<3;i++){
		da=w(i,3);
		po=p->data;
		s1=s1+po*da;
		p=p->next;
	}		
	q=dr;
	j=2;
	//s2 a doua suma
	for(i=0;i<3;i++){
		da=w(j,3);
		pi=q->data;
		s2=s2+pi*da;
		q=q->next;
		j--;
		}
	//le unesc in formula si rezulta rez
	rez=(1-ce)*s1+ce*s2;
			

	return rez;

}



List ex4(List l,int *nr)
{
	List p,q,r,st,dr;
	List lk,dk,go;
	List x,o;
	List t;
	List nodulet;
	double ce,fe,te;
	double aux;
	double x1=0,x2=0;
	int tmp;
	int j;
	int i, numi=0;
	double sup=0,supi=0;
	p=l;
	r=l;
	q=l;
	t=l;
	go=l;
	numi=(*nr);
	for(i=0;i<(*nr)-1;i++){
		t=t->next;
	}

	st=init(1,0);//am initializat lista noua;
	for(i=0;i<4;i++){
		sup=3;
	st=add_tail(st,sup,0);//am adaugat 5 noduri la lista stanga
	sup++;
	}

	dr=init(1,0);//am initializat lista noua;
	for(i=0;i<4;i++){
		supi=3;
	dr=add_tail(dr,supi,0);//am adaugat 5 noduri la lista dreapta
	supi++;
	}

	while(q->timestamp!=t->timestamp){	

		p=r;//retin nodul de unde plec
		for(j=0;j<2;j++){
			p=p->next;//parcurg 3 noduri

		}
		q=p->next;//si il retin si pe al 4-lea
		aux=q->timestamp-p->timestamp;//diferenta timpestampurilor lor
		if(aux>1000){
			p=r;
			x=dr;//retin capurile de lista stg si dreapta
			o=st;
			//adaug in lista din stanga
			for(i=0;i<3;i++){
				o->data=p->data;
				o->timestamp=p->timestamp;
				numi--;//scad contorul
				lk=p;
				p=p->next;
				o=o->next;

			
			}
			nodulet=p;//retin unde va trebui sa ma intorc ca sa continui cu verificarea
			go=go->next;
			go=go->next;// ma mut doua noduri, pe care le-am parcurs
			dk=q;//retin dk

			//adaug in lista din dreapta
			for(i=0;i<3;i++){
				x->data=q->data;
				x->timestamp=q->timestamp;
				q=q->next;
				x=x->next;

			}

			te=lk->timestamp;//pentru a calcula C ul

			while(dk->timestamp >lk->timestamp+200){

					//cat timp ma aflu aici generez noi noduri pe care le adaug in lista
					tmp=lk->timestamp+200;
					x2=dk->timestamp;
					x1=tmp;//noul timpestamp
					fe=0;
					ce=C(x1,te,x2);
					fe=f(st, dr, tmp, ce);//calzulez valoarea ce trebuie adaugata
					l=add_node(l,lk->timestamp,nodulet->timestamp,fe,tmp,nr);//adaug nodul
					go=go->next;//ma misc prin lista
					lk=go;//continui

				}
				r=nodulet;//pentru a verifica de acolo de unde am ramas
				numi--;//scad contorul
				go=go->next;

			if(numi>2){//contor pentru a nu ajunge pe ultimele 2 noduri
				q=q->next;
			}
		}
				

		else{
				r=r->next;
				numi--;
				go=go->next;
				if(numi>2){
				q=q->next;
				}
					
			}
	}

		freel(st);
		freel(dr);
		return l;

}

void delta(List l, double d, int nr)
{
	//1.5 bonus
	List p,q,r;
	int nri=0,i,c1,c2;
	int c=0;
	double maxi=-100000000,mini=10000000; //minim si maxim
	int mani;
	double ce;
	q=l;//retin capul de lista
	while(q!=NULL) {
		//il retin pe cel mai mic
	    if(q->data<mini) {
	        mini=q->data;
	    }
	    q=q->next;
	}
	r=l;
	while(r!=NULL) {
	    if(r->data>maxi) {
	    	//il retin pe cel mai mare
	        maxi=r->data;
	    }
	    r=r->next;
	}
	
	
	//calculez capetele intervalurilor
	if(mini<0){
		//daca e negativ minimul,calculez diferit capul de interval
		mani=mini-1;
		ce=mani-mini;
	
		if(ce<-0.01&& ce>-1){

			c1=mani;
			c2=mani+d;
		}
		else{
			c1=mini;
			c2=mini+d;
		}
		

	}

	
	else {
		//daca e poztiv
		mani=mini+1;
		ce=mani-mini;
		//daca diferenta dintre cele doua valori se afla in acest interval
		if(ce>0.01&&ce<1){
		
			c1=mani;
			c2=mani+d;
		}
		else{
			c1=mini;
			c2=mini+d;
		}
	

	}
	
	p=l;

	while(c!=nr){
		//cat timp nu am parcurs toate nodurile
		nri=0;
		for(i=0;i<nr;i++){
			if(p->data>=c1 && p->data<=c2){
				nri++;//daca se afla in interval cresc numarul ne numere din interval nri
				
			}
			p=p->next;
		}
			p=l;//ma intorc pentru a le afisa
			c=c+nri;
	
			if(nri!=0){

			printf("[%d, %d] %d\n",c1,c2,nri);
		}
			//iau urmatoarele intervale
			c1=c2;
			c2=c2+d;
			

		}
	

}

int main(int argc, char const *argv[])

{
	List lst,p,t;
	double n=0;
	
	int tmp,nr=0,i,nrn=0,nrm=0,nr3=0,oke=0,numr=0,de=0;
	int ok=1;
	nrn=nr;	
	numr=nr;
	//citesc lista
	scanf("%d",&nr);
	//alcatuire lista
	for(i=0;i<nr;i++){
		scanf("%d",&tmp); //pentru a pastra formatul testelor
		scanf("%lf",&n);
		if(i==0){
			lst=init(n,tmp);
			p=lst;
		}
		else
		{	
			
			lst=add_tail(lst,n,tmp);
		}
		
	}
//e1
	for(i=1;i<argc;i++){
		//parcurg numarul de argumente date
		if(strcmp(argv[i],"--e1")==0){
			lst=eliminareE(lst,nr,&nrn);
			nr=nrn;
			
		}
		//e2
		if(strcmp(argv[i],"--e2")==0){
			lst=mediana(lst,nr,&nrm);
			nr=nrm;

			}

		if(strcmp(argv[i],"--e3")==0){
			lst=ma(lst,nr,&nr3);
			nr=nr3;
			
			}
		if(strcmp(argv[i],"--u")==0){
			lst=uniformizare(lst,nr);

		}
		if(strcmp(argv[i],"--c")==0){
			numr=nr;
			lst=ex4(lst,&numr);
			nr=numr;
			while(p->next!=NULL&&p->next->next!=NULL&&ok==1){
				p=p->next;
				t=p->next;
				//mai fac o verificare
				if(t->timestamp-p->timestamp>200){
					lst=ex4(lst,&numr);
					nr=numr;
					ok=0;
				}
			}
			
			}

		if((strncmp(argv[i],"--st",4)==0)){
			de=atoi(argv[1]+4);
			delta(lst,de,nr);
			oke=1;//caz special pentu delta, pentru ca functia afiseaza direct
			

		}


	}
			if(oke!=1){
			print(lst,nr);}

		freel(lst);


	
	return 0;}