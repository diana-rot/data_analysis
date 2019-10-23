# data_analysis
Data Analysis using lists in c
Rotila Diana-Andreea 
Corectie,eliminarea exceptiilor si completarea datelor secventiale

Pentru inceput, am implemntat niste functii de baza cu care o sa lucrez pe 
tot parcursul temei. Am folosit liste simplu inlantuite. Functiile:
-  add_tail(adaug la coada listei un nou nod)
-  freel(eliberez lista)
-  init(initializez lista)
-  sterge_1(sterg un nod din lista)
-  add_node(adaug un nod in mijlocul listei, unde aux=valoarea dupa care
 trebuie 
   sa adaug, naux valoarea inaintea careia trebuie sa aduag)
-  print(afisez lista)


Pentru exercitii am utilizat functiile:
1.1	eliminareE
1.2.1 mediana
1.2.2 ma
1.3 uniformizare
1.4 w
	C
	f
	ex4
1.5(bonus) delta


Explicatie: 

exercitiul 1.1	Pentrul primul exercitiu am folosit functia eliminareE.
 Parcurg toata lista, si pentru fiecare fereastra de 5 noduri calculez intai 
 suma lor(s), pentru a calcula media(med), apoi le mai parcurg o data pentu 
 a calcula sum(din formula deviatiei), iar dupa ce le-am parcurs pe cele 5,
 calculez deviatia. verific daca nodul din mijloc se afla in intervalul
 (med+dev,med-dev), iar daca nu, ii setez campul to_del la 1. La sfarsit
 parcurg lista si sterg nodurile cu to_del=1, scad numarul de noduri.


exercitiul 1.2.1	In functia mediana: am initializat o lista s, de sortari.
 Parcurg toata lista si adaug fiecare 5 noduri in lista de sortari, apoi o 
sortez cu 2 pointeri, si iau  valoarea din mijloc pe care o adaug in lista 
rezultata.

exercitiul 1.2.2	In functia ma, parcurg toata lista si pentru fiecare 
fereastra de 5 noduri calculez media lor aritmetica si adaug rezultatul
la lista rez, pe care o voi returna. Daca nu am niciu nod in lista
o initializez si cresc numarul de noduri(nr3).

exercitiul 1.3	Pentru acest exercitiu folosesc functia uniformizare.
Parcurg lista si fac diferenta dintre nodul curent si cel anterior, retinut
de doi pointeri. Daca se afla in intervalul [100,1000] atunci nodul ia valoarea
medie dintre nodul curent si cel anterior. Returnez lista.

exercitiul 1.4 Pentru acest exercitiu calzulez intai in functia w, w-ul, 
conform formulei, astfel n1 va fi numaratorul, apoi parcurg suma de la o la k,
 si aflu numitorul, la final impartindu-le, returnez q. De asemenea calculez
 si C-ul,in functia C, conform formulei. La fel si pentru f, utilizez doua 
 foruri pentru a afla suma1(s1) si suma1(s2), apoi in rez le inmultesc cu
 (1-c),respectiv cu c si aflu rezultatul functiei, pe care il returnez.
 In ex4 initializez intai listele stanga sreapta. Apoi parcurg cu un for
 3 noduri pentru a putea compara timpestampurilelor, il retin pe al 3-lea
 si pe al 4-lea. Fac diferenta timpestampurilor lor si daca e >1000, 
 pun in lista din stanga si in lista din dreapta valori. Cat e mai mic 
 timpestampul lui dk fata de lk, adaug noduri conform forumulelor. 
 Scad contorul, pentru a nu lua in considerare ultimele 2 noduri. 
 Daca nu indeplineste conditia ma misc in continuare prin lista.

exercitiul 1.5	In functia delta, parcurg intai lista gasesc minimul
si maximul in functie de care calculez capetele intervalurilor.
Impart in doua cazuri cand sunt negative si cand sunt pozitive
si le tratez pe amandoua. Vad ca diferenta dintre doua valori
sa nu fie intr-un interbal de eroare de 0,01 si 1, pentru a alege
potrivt capetele. Apoi parcurg lista si daca se alfa in interval, adun
in nri numarul nodurilor. Retin in p capul de lista si apoi urmatoarele
inceputuri de intervale, pentru a ma putea intoarce sa afisez lista.
cresc apoi in c1 si c2, intervalul ales, in functie de delta.

Main In main initializez lista si parcurg cu un for numarul de argumente
date. O iau pe cazuri, daca e  e1, e2, e3,u sau c, si mai apoi st. Daca
e st oke-ul e 1, pentru a trece peste acest caz atunci cand afisez lista.
La ex4 mai fac o verificarea a listei in cazul in care diferenta nodurilor 
adaugate e mai mare decat unele noduri.
