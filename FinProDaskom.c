/* 	Final Project : Smart Office System
	Radhitya Gibran Prasetianto, 2206062522
	Raffly Putera Wibowo, 2206062693
	Selasa, 05 Desember 2023
	Versi 3.3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
	char username[50];
	char password[50]; 
};

struct ruangan{
	int door;
	int ac;
	int lights;
	int fan;
};

void loading(){
	int i;
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM\n\n");
	sleep(1);
	//Menggunakan referensi Code page 437 (CCISD 437) Standard IBM untuk DOS untuk deklarasi char kosong dengan ASCII value 176 dan char terisi ASCII value 219
	char kosong = 176;
	char terisi = 219;

	printf("\n\n  ");
    printf("Tunggu Sebentar ...\n\n");
	printf("  ");

	//Print Bar Kosong
	for (i = 0; i < 30; i++)
		printf("%c", kosong);

	//Agar Bar terisi overlap dengan bar kosong
	printf("\r");
	printf("  ");

	//Print bar terisi
	for (i = 0; i < 30; i++) {
		printf("%c", terisi);
		
		// Cepat lambatnya loading bar
		Sleep(60);
	}
}

void displayroom(){
	int i;
	printf("Tampilan Ruangan\n");
	for (i = 0; i < 3; i++){
		printf("A%d		A%d		A%d\n", i+1, i+4, i+7);
	}
}

//Menu sebelum melakukan Login
int prelogin(struct ruangan *control, struct user *logindata){
	
	//input pilihan login
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM");
	char pilihan[10];
	printf("\n\nLOGIN\nSHUTDOWN\n: ");
	scanf("%s", &pilihan);
	
	//check nilai pada pilihan
	if (strcmp(pilihan, "login") == 0){
		login(control, logindata);
	}
	else if (strcmp(pilihan, "shutdown") == 0){
		
	}
	else {
		printf("\nINVALID MENU");
		sleep(1);
		return prelogin(control, logindata);
	}
}

//Inteface saat login
int login(struct ruangan *control, struct user *logindata){
	
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM");
	//input username
	printf("\n\nMasukan Username : ");
	scanf("%s", &logindata[1].username);
	
	//input password
	printf("Masukan Password : ");
	scanf("%s", &logindata[1].password);
	
	//check username dan password 
	if (strcmp(logindata[1].username, logindata[0].username) == 0 && strcmp(logindata[1].password, logindata[0].password) == 0){
		printf("\nSelamat Datang %s", logindata[1].username);
		sleep(3);
		buletinboard(control, logindata);
	}
	else {
		printf("\nUsername atau Password salah");
		sleep(1);
		return login(control, logindata);	
	}
}

//inisialisasi nilai array structure
int start(struct ruangan *control, struct user *logindata){
	int i, indeks;
	for (i = 0; i < 9;i++){
		control[i].ac = 0;
		control[i].door = 0;
		control[i].fan = 0;
		control[i].lights = 0;
	}
	strcpy(logindata[0].username, "admin");
	strcpy(logindata[0].password, "12345");
}

//Function untuk Kontrol Elektronik
int ctos(struct ruangan *control, struct user *logindata){
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM\n\n");
	int indeks;
	char pilihan[10], con[10];
	printf("RUANGAN\nMENU\n: ");
	scanf("%s", &pilihan);
	if (strcmp(pilihan, "ruangan") == 0){
		system("cls");
		printf("\n\nSMART OFFICE SYSTEM\n\n");
		displayroom(control);
			
		printf("\nPILIH RUANGAN : ");
		scanf("%d", &indeks);
			
		pilihelektronik:
			system("cls");
			printf("\n\nSMART OFFICE SYSTEM\n\n");
			printf("PINTU\nAC\nLAMPU\nKIPAS\n\nKELUAR\n");
			printf("\nPILIH ELEKTRONIK : ");
			scanf("%s", &con);
			if (strcmp(con, "pintu") == 0){
				if (control[indeks - 1].door == 0) {
					printf("\nMenyalakan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n  Elektronik Berhasil Dinyalakan\n");
					control[indeks - 1].door = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else if (control[indeks - 1].door == 1){
					printf("\nMematikan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n  Elektronik Berhasil Dimatikan\n");
					control[indeks - 1].door = 0;
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("Elektronik Sedang Rusak/Maintenance\n");
					sleep(2);
					goto pilihelektronik;
				}
			}
			else if (strcmp(con, "ac") == 0){
				if (control[indeks - 1].ac == 0) {
					printf("\nMenyalakan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n  Elektronik Berhasil Dinyalakan\n");
					control[indeks - 1].ac = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else if (control[indeks - 1].ac == 1){
					printf("\nMematikan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n  Elektronik Berhasil Dimatikan\n");
					control[indeks - 1].ac = 0;
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("Elektronik Sedang Rusak/Maintenance\n");
					sleep(2);
					goto pilihelektronik;
				}
			}
			else if (strcmp(con, "lampu") == 0){
				if (control[indeks - 1].lights == 0) {
					printf("\nMenyalakan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n  Elektronik Berhasil Dinyalakan\n");
					control[indeks - 1].lights = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else if (control[indeks - 1].lights == 1){
					printf("\nMematikan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n  Elektronik Berhasil Dimatikan\n");
					control[indeks - 1].lights = 0;
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("Elektronik Sedang Rusak/Maintenance\n");
					sleep(2);
					goto pilihelektronik;
				}
			}
			else if (strcmp(con, "kipas") == 0){
				if (control[indeks - 1].fan == 0) {
					printf("\nMenyalakan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n  Elektronik Berhasil Dinyalakan\n");
					control[indeks - 1].fan = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else if (control[indeks - 1].fan == 1){
					printf("\nMematikan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n  Elektronik Berhasil Dimatikan\n");
					control[indeks - 1].fan = 0;
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("\nElektronik Sedang Rusak/Maintenance\n");
					sleep(2);
					goto pilihelektronik;
				}
			}
			else if (strcmp(con, "keluar") == 0){
				return ctos(control, logindata);
			}
			else {
				printf("INVALID MENU");
				goto pilihelektronik;
			}
	}
	else if (strcmp(pilihan, "menu") == 0){
		return buletinboard(control, logindata);
	}
	else {
		printf("INVALID MENU");
		sleep(2);
		return ctos(control, logindata);
	}
}

/* 	Wikipedia Status Elektronik
	0 = Mati
	1 = Nyala
	2 = Rusak
	3 = Maintenance
*/

//Function untuk Service dan Maintenance
int terminal(struct ruangan *control, struct user *logindata){
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM\n\n");
	
	int indeks;
	char pilihan[10], con[10], st[10], pseudopilihan[10];
	
	printf("ELEKTRONIK\nMENU\n: ");
	scanf("%s", &pilihan);
	
	//If statement untuk menu elektronik dan menu
	if (strcmp(pilihan, "elektronik") == 0){
		pilihelektronik:
				
			system("cls");
			printf("\n\nSMART OFFICE SYSTEM\n\n");
			printf("\nMAINTENANCE MODE\n\nPINTU\nAC\nLAMPU\nKIPAS\n\nKELUAR\n: ");
			scanf("%s", &con);
			if (strcmp(con, "keluar") == 0) return terminal(control, logindata);	
			
			system("cls");
			printf("\n\nSMART OFFICE SYSTEM\n\n");
			displayroom(control);
			printf("\nPILIH RUANGAN : ");
			scanf("%d", &indeks);
			
			system("cls");
			printf("\n\nSMART OFFICE SYSTEM\n\n");
			
			if (strcmp(con, "pintu") == 0){
				if (control[indeks - 1].door < 2) {
						printf("ELEKTRONIK SEDANG BERFUNGSI\n\n");
				}
				else {
						printf("ELEKTRONIK SEDANG TIDAK BERFUNGSI\n\n");
				}
				printf("MENU MAINTENANCE ELEKTRONIK:\n\nENABLE\nDISABLE\nTROUBLESHOOT\n\nKELUAR\n: ");
				scanf("%s", &st);
				
				if (strcmp(st, "enable") == 0){
					if (control[indeks - 1].door == 2) {
						printf("\nELEKTRONIK SEDANG RUSAK, TIDAK BISA DIAKTIFKAN\n");
					}
					else if (control[indeks - 1].door < 2){
						printf("\nELEKTRONIK SUDAH AKTIF\n");
					}
					else {
						printf("\nMENGAKTIFKAN ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\n  ELEKTRONIK BERHASIL DIAKTIFKAN\n");
						control[indeks - 1].door = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "disable") == 0){
					if (control[indeks - 1].door  == 2) {
						printf("\nELEKTRONIK SUDAH RUSAK\n");
					}
					else if (control[indeks - 1].door == 3){
						printf("\nELEKTRONIK SUDAH DINONAKTIFKAN\n");
					}
					else {						
						printf("\nMENONAKTIFKAN ELEKTRONIK . . .\n");
						sleep(1);
						printf("\nMENGAPA ELEKTRONIK DINONAKTIFKAN\nRUSAK\nMAINTENANCE\n: ");
						
						disdoor:
						scanf("%s", &pseudopilihan);
						if (strcmp(pseudopilihan, "rusak") == 0){
							printf("\n\nELEKTRONIK DINYATAKAN RUSAK\n");
							sleep(1);
							loading();
							printf("\n\n  STATUS TELAH BERUBAH\n");
							control[indeks - 1].door = 2;
						}
						else if (strcmp(pseudopilihan, "maintenance") == 0){
							printf("\n\nELEKTRONIK PERLU MAINTENANCE\n");
							sleep(1);
							loading();
							printf("\n\n  STATUS TELAH DIUBAH\n");
							control[indeks - 1].door = 3;
						}
						else {
							printf("INVALID MENU");
							system("cls");
							goto disdoor;
						}
				
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "troubleshoot") == 0){
					if (control[indeks - 1].door < 2) {
						printf("\nELEKTRONIK SEDANG BERFUNGSI, TROUBLESHOOT TIDAK BISA DIJALANKAN\n");
					}
					else if (control[indeks - 1].door == 2){
						printf("\nELEKTRONIK RUSAK, LAKUKAN PERBAIKAN MANUAL\n");
					}
					else {
						printf("\nMENCOBA MEMPERBAIKI ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\n\n  PERBAIKAN BERHASIL\n");
						control[indeks - 1].door = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "keluar") == 0){
					goto pilihelektronik;
				}
				else {
					printf("INVALID MENU");
					sleep(1);
					goto pilihelektronik;
				}			
			}
			else if (strcmp(con, "ac") == 0){
				if (control[indeks - 1].ac < 2) {
					printf("ELEKTRONIK SEDANG BERFUNGSI\n\n");
				}
				else {
					printf("ELEKTRONIK SEDANG TIDAK BERFUNGSI\n\n");
				}
				printf("MENU MAINTENANCE ELEKTRONIK:\n\nENABLE\nDISABLE\nTROUBLESHOOT\n\nKELUAR\n: ");
				scanf("%s", &st);
				if (strcmp(st, "enable") == 0){
					if (control[indeks - 1].ac == 2) {
						printf("\nELEKTRONIK SEDANG RUSAK, TIDAK BISA DIAKTIFKAN\n");
					}
					else if (control[indeks - 1].ac < 2){
						printf("\nELEKTRONIK SUDAH AKTIF\n");
					}
					else {
						printf("\nMENGAKTIFKAN ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\n  ELEKTRONIK BERHASIL DIAKTIFKAN\n");
						control[indeks - 1].ac = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "disable") == 0){
					if (control[indeks - 1].ac == 2) {
						printf("\nELEKTRONIK SUDAH RUSAK\n");
					}
					else if (control[indeks - 1].ac == 3){
						printf("\nELEKTRONIK SUDAH DINONAKTIFKAN\n");
					}
					else {
						printf("\nMENONAKTIFKAN ELEKTRONIK . . .\n");
						sleep(1);
						printf("\nMENGAPA ELEKTRONIK DINONAKTIFKAN\nRUSAK\nMAINTENANCE\n: ");
						
						disac:
						scanf("%s", &pseudopilihan);
						if (strcmp(pseudopilihan, "rusak") == 0){
							printf("\n\nELEKTRONIK DINYATAKAN RUSAK\n");
							sleep(1);
							loading();
							printf("\n\n  STATUS TELAH BERUBAH\n");
							control[indeks - 1].ac = 2;
						}
						else if (strcmp(pseudopilihan, "maintenance") == 0){
							printf("\n\nELEKTRONIK PERLU MAINTENANCE\n");
							sleep(1);
							loading();
							printf("\n\n  STATUS TELAH DIUBAH\n");
							control[indeks - 1].ac = 3;
						}
						else {
							printf("INVALID MENU");
							system("cls");
							goto disac;
						}
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "troubleshoot") == 0){
					if (control[indeks - 1].ac < 2) {
						printf("\nELEKTRONIK SEDANG BERFUNGSI, TROUBLESHOOT TIDAK BISA DIJALANKAN\n");
					}
					else if (control[indeks - 1].ac == 2){
						printf("\nELEKTRONIK RUSAK, LAKUKAN PERBAIKAN MANUAL\n");
					}
					else {
						printf("\nMENCOBA MEMPERBAIKI ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\n\n  PERBAIKAN BERHASIL\n");
						control[indeks - 1].ac = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "keluar") == 0){
					goto pilihelektronik;
				}
				else {
					printf("INVALID MENU");
					sleep(1);
					goto pilihelektronik;
				}			
			}
			else if (strcmp(con, "lampu") == 0){
				if (control[indeks - 1].lights < 2) {
						printf("ELEKTRONIK SEDANG BERFUNGSI\n\n");
				}
				else {
						printf("ELEKTRONIK SEDANG TIDAK BERFUNGSI\n\n");
				}
				printf("MENU MAINTENANCE ELEKTRONIK:\n\nENABLE\nDISABLE\nTROUBLESHOOT\n\nKELUAR\n: ");
				scanf("%s", &st);
				if (strcmp(st, "enable") == 0){
					if (control[indeks - 1].lights == 2) {
						printf("\nELEKTRONIK SEDANG RUSAK, TIDAK BISA DIAKTIFKAN\n");
					}
					else if (control[indeks - 1].lights < 2){
						printf("\nELEKTRONIK SUDAH AKTIF\n");
					}
					else {
						printf("\nMENGAKTIFKAN ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\n  ELEKTRONIK BERHASIL DIAKTIFKAN\n");
						control[indeks - 1].lights = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "disable") == 0){
					if (control[indeks - 1].lights == 2) {
						printf("\nELEKTRONIK SUDAH RUSAK\n");
					}
					else if (control[indeks - 1].lights == 3){
						printf("\nELEKTRONIK SUDAH DINONAKTIFKAN\n");
					}
					else {
						
						printf("\nMENONAKTIFKAN ELEKTRONIK . . .\n");
						sleep(1);
						printf("\nMENGAPA ELEKTRONIK DINONAKTIFKAN\nRUSAK\nMAINTENANCE\n: ");
						
						dislights:
						scanf("%s", &pseudopilihan);
						if (strcmp(pseudopilihan, "rusak") == 0){
							printf("\n\nELEKTRONIK DINYATAKAN RUSAK\n");
							sleep(1);
							loading();
							printf("\n\n  STATUS TELAH BERUBAH\n");
							control[indeks - 1].lights = 2;
						}
						else if (strcmp(pseudopilihan, "maintenance") == 0){
							printf("\n\nELEKTRONIK PERLU MAINTENANCE\n");
							sleep(1);
							loading();
							printf("\n\n  STATUS TELAH DIUBAH\n");
							control[indeks - 1].lights = 3;
						}
						else {
							printf("INVALID MENU");
							system("cls");
							goto dislights;
						}
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "troubleshoot") == 0){
					if (control[indeks - 1].lights < 2) {
						printf("\nELEKTRONIK SEDANG BERFUNGSI, TROUBLESHOOT TIDAK BISA DIJALANKAN\n");
					}
					else if (control[indeks - 1].lights == 2){
						printf("\nELEKTRONIK RUSAK, LAKUKAN PERBAIKAN MANUAL\n");
					}
					else {
						printf("\nMENCOBA MEMPERBAIKI ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\n\n  PERBAIKAN BERHASIL\n");
						control[indeks - 1].lights = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "keluar") == 0){
					goto pilihelektronik;
				}
				else {
					printf("INVALID MENU");
					sleep(1);
					goto pilihelektronik;
				}			
			}
			else if (strcmp(con, "kipas") == 0){
				if (control[indeks - 1].fan < 2) {
					printf("ELEKTRONIK SEDANG BERFUNGSI\n\n");
				}
				else {
					printf("ELEKTRONIK SEDANG TIDAK BERFUNGSI\n\n");
				}
				printf("MENU MAINTENANCE ELEKTRONIK:\n\nENABLE\nDISABLE\nTROUBLESHOOT\n\nKELUAR\n: ");
				scanf("%s", &st);
				if (strcmp(st, "enable") == 0){
					if (control[indeks - 1].fan == 2) {
						printf("\nELEKTRONIK SEDANG RUSAK, TIDAK BISA DIAKTIFKAN\n");
					}
					else if (control[indeks - 1].fan < 2){
						printf("\nELEKTRONIK SUDAH AKTIF\n");
					}
					else {
						printf("\nMENGAKTIFKAN ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\n  ELEKTRONIK BERHASIL DIAKTIFKAN\n");
						control[indeks - 1].fan = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "disable") == 0){
					if (control[indeks - 1].fan == 2) {
						printf("\nELEKTRONIK SUDAH RUSAK\n");
					}
					else if (control[indeks - 1].fan == 3){
						printf("\nELEKTRONIK SUDAH DINONAKTIFKAN\n");
					}
					else {
						
						printf("\nMENONAKTIFKAN ELEKTRONIK . . .\n");
						sleep(1);
						printf("\nMENGAPA ELEKTRONIK DINONAKTIFKAN\nRUSAK\nMAINTENANCE\n: ");
						
						disfan:
						scanf("%s", &pseudopilihan);
						if (strcmp(pseudopilihan, "rusak") == 0){
							printf("\n\nELEKTRONIK DINYATAKAN RUSAK\n");
							sleep(1);
							loading();
							printf("\n\n  STATUS TELAH BERUBAH\n");
							control[indeks - 1].fan = 2;
						}
						else if (strcmp(pseudopilihan, "maintenance") == 0){
							printf("\n\nELEKTRONIK PERLU MAINTENANCE\n");
							sleep(1);
							loading();
							printf("\n\n  STATUS TELAH DIUBAH\n");
							control[indeks - 1].fan = 3;
						}
						else {
							printf("INVALID MENU");
							system("cls");
							goto disfan;
						}
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "troubleshoot") == 0){
					if (control[indeks - 1].fan < 2) {
						printf("\nELEKTRONIK SEDANG BERFUNGSI, TROUBLESHOOT TIDAK BISA DIJALANKAN\n");
					}
					else if (control[indeks - 1].fan == 2){
						printf("\nELEKTRONIK RUSAK, LAKUKAN PERBAIKAN MANUAL\n");
					}
					else {
						printf("\nMENCOBA MEMPERBAIKI ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\n\n  PERBAIKAN BERHASIL\n");
						control[indeks - 1].fan = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "keluar") == 0){
					goto pilihelektronik;
				}
				else {
					printf("INVALID MENU");
					sleep(1);
					goto pilihelektronik;
				}			
			}
			else if (strcmp(con, "keluar") == 0){
				return terminal(control, logindata);
			}
			else {
				printf("INVALID MENU");
				goto pilihelektronik;
			}
	}
	else if (strcmp(pilihan, "menu") == 0){
		return buletinboard(control, logindata);
	}
	else {
		printf("INVALID MENU");
		sleep(2);
		return terminal(control, logindata);
	}
}

//Function untuk Reset username dan password
int changer(struct ruangan *control, struct user *logindata){
	char pilihan;
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM\n\n");
	printf("Apakah ingin melakukan reset akun?(y/n)\n: ");
	scanf(" %c", &pilihan);
	if (pilihan == 'y'){
		
		//mengganti username
		username:
			system("cls");
			printf("\n\nSMART OFFICE SYSTEM\n\n");
			printf("Masukkan Username Baru: ");
        	scanf("%s", &logindata[0].username);
        	printf("\nKonfirmasi Username Baru: ");
        	scanf("%s", &logindata[2].username);
        	if (strcmp(logindata[0].username, logindata[2].username) == 0){
        		printf("\n\nUSERNAME BERHASIL DIUBAH!\n");
			}
        	else {
        		printf("\n\nUSERNAME TIDAK COCOK\n");
        		sleep(3);
        		goto username;
			}
       		sleep(3);
        
        //mengganti password
        password:
        	system("cls");
        	printf("\n\nSMART OFFICE SYSTEM\n\n");
        	printf("Masukkan password baru: ");
        	scanf("%s", &logindata[0].password);
        	printf("\nKonfirmasi password baru: ");
        	scanf("%s", &logindata[2].password);
        	if (strcmp(logindata[0].password, logindata[2].password) == 0){
        		printf("\n\nPASSWORD BERHASIL DIUBAH!\n");
			}
       		else {
        		printf("\n\nPASSWORD TIDAK COCOK\n");
        		sleep(3);
        		goto password;
			}
        	sleep(3);
        	return prelogin(control, logindata);
	}
	else if (pilihan == 'n') {
		printf("\nPROSES DIBATALKAN, MENGEMBALIKAN KE MENU");
		sleep(3);
		return buletinboard(control, logindata);
	}
	else {
		printf("\nINVALID MENU");
		return changer(control, logindata);
	}
}

//Function untuk Manual
int help(struct ruangan *control, struct user *logindata){
	char pilihan[10];
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM\n\n");
	printf("Gunakan 'Kontrol Elektronik' untuk melakukan Kendali ON/OFF Elektronik \npada Ruangan dengan ketik 'kontrol'\n\n");
	printf("Gunakan 'Service dan Maintenance' untuk melakukan Check, Aktivasi/Deaktivasi dan Perbaikan \npada Elektronik dengan ketik 'service'\n\n");
	printf("Gunakan 'Reset Akun' untuk Melakukan penggantian username dan password yang digunakan \nuntuk login Smart Office System dengan ketik 'reset'\n");
	
	printf("\n\nKeluar\n: ");
	scanf("%s", &pilihan);
	if (strcmp(pilihan, "keluar") == 0){
		return buletinboard(control, logindata);
	}
	else {
		printf("INVALID MENU");
		return help(control, logindata);
	}
}

//Function untuk About
int credits(struct ruangan *control, struct user *logindata){
	char pilihan[10];
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM");
	printf("\n\nKelompok 07 - Daskom 02\n");
	printf("Raffly Putera Wibowo, 2206062693");
	printf("\nRadhitya Gibran Prasentianto, 2206062522");
	printf("\n\nVersi 3.2");
	
	printf("\n\nKeluar\n: ");
	scanf("%s", &pilihan);
	if (strcmp(pilihan, "keluar") == 0){
		return buletinboard(control, logindata);
	}
	else {
		printf("INVALID MENU");
		return credits(control, logindata);
	}
}

//Function untuk menu utama
int buletinboard(struct ruangan *control, struct user *logindata){
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM");
	char pilihan[10];
	printf("\n\nKontrol Elektronik\nService and Maintenance\nReset Akun\nManual\nAbout\n\nLogout\n: ");
	scanf("%s", &pilihan);
	if (strcmp(pilihan, "kontrol") == 0){
		ctos(control, logindata);
	}
	else if (strcmp(pilihan, "service") == 0){
		terminal(control, logindata);
	}
	else if (strcmp(pilihan, "reset") == 0){
		changer(control, logindata);
	}
	else if (strcmp(pilihan, "manual") == 0){
		help(control, logindata);
	}
	else if (strcmp(pilihan, "about") == 0){
		credits(control, logindata);
	}
	else if (strcmp(pilihan, "logout") == 0){
		return prelogin(control, logindata);
	}
	else {
		puts("\nINVALID MENU");
		sleep(2);
		return buletinboard(control, logindata);
	}
}

int main(){
	struct user *logindata = (struct user*)malloc(3 * sizeof(struct user));
	struct ruangan *control = (struct ruangan*)malloc(9 * sizeof(struct ruangan));

	start(control, logindata);	
	prelogin(control, logindata);
	
	free(logindata);
	free(control);
	return 0;
}
