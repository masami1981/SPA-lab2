3. Laboratorijska vježba

Dictionary - nastavak


Potrebno je dodati funkciju koja će „filtrirati“ listu:

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w));

Funkcija prima rječnik (lista ispunjena sa abecedno poredanim riječima
i brojem pojavljivanja u tekstu iz prethodne vježbe) i pokazivač na
funkciju:

int filter(Word *w);

Funkcija filterDictionary() vraća izmijenjenu indict listu koja sadrži
samo riječi za koje je filter() funkcija vratila 1 (sve druge riječi
se oslobađaju). Funkcija filter() vraća 1 ako je broj pojavljivanja
riječi između 5 i 10 i ako je riječ duža od 3 znaka.

Kôd je na stranicama kolegija.
