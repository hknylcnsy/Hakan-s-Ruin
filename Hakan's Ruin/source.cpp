#include "stdio.h"
#include "conio.h"
#include <time.h>
#include <stdlib.h>

int main() {
	srand(time(NULL)); //seed

	double kazanmaOrani = 0.56;  // 0 - 1 arasýnda deðer alýr
	double bahisYuzdesi = 0.6;  // 0 - 100 arasýnda deðer alýr

	double anaPara = 10000;
	double hedef = 55000;
	double bahis = 100;

	double denemeSayisi = 365; // hedefe ulaþmak için oynanacak oyun
	double paralelEvrenSayisi = 5000; // oyuna sýfýrdan baþlama sayýsý 

	int kazanmaSayisi = 0;

	for (unsigned long n = 0; n < paralelEvrenSayisi; n++) {
		double anaParadurumu = anaPara;
		for (int m = 0; m < denemeSayisi; m++) {
			double oyun = (rand() / (float)(RAND_MAX)) * (rand() / (float)(RAND_MAX)); // float random sayý
			if (oyun < kazanmaOrani) {
				anaParadurumu += anaParadurumu*(bahisYuzdesi / 100);
			}
			else {
				anaParadurumu -= anaParadurumu*(bahisYuzdesi / 150);
			}
			if (anaParadurumu >= hedef) {
				kazanmaSayisi++;
				break;
			}
			if (anaParadurumu <= 0) {
				break;
			}
		}
	}

	printf("Hedefe ulasma olasiligi: %%%lf \n",((double)kazanmaSayisi / paralelEvrenSayisi) * 100);
	
	return 0;

}

