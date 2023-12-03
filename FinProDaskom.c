#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
	//Menggunakan ASCII Code 437 Standard IBM untuk DOS untuk deklarasi char kosong dengan ASCII value 177 dan char terisi ASCII value 219
	char kosong = 177;
	char terisi = 219;

	printf("\n\n\t");
    printf("Loading...\n\n");
	printf("\t");

	//Print Bar Kosong
	for (i = 0; i < 30; i++)
		printf("%c", kosong);

	//Buat Bar Isi overlap dengan bar kosong
	printf("\r");
	printf("\t");

	//Print bar terisi
	for (i = 0; i < 30; i++) {
		printf("%c", terisi);

		// Cepat lambatnya loading bar
		Sleep(150);
	}
}

void displayroom(){
	int i;
	printf("Tampilan Ruangan\n");
	for (i = 0; i < 3; i++){
		printf("A%d		A%d		A%d\n", i+1, i+4, i+7);
	}
}

int prelogin(struct ruangan *control, struct user *logindata){
	
	//input pilihan login
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM");
	char pilihan[10];
	printf("\n\nLOGIN\nSHUTDOWN\n: ");
	scanf("%s", &pilihan);
	fflush(stdin);
	
	//check nilai pada pilihan
	if (strcmp(pilihan, "login") == 0){
		login(control, logindata);
	}
	else if (strcmp(pilihan, "shutdown") == 0){
		
	}
	else {
		printf("\nINVALID MENU");
		sleep(1);
		fflush(stdin);
		return prelogin(control, logindata);
	}
}

int login(struct ruangan *control, struct user *logindata){
	
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM");
	//input username
	printf("\n\nMasukan Username : ");
	scanf("%[^\n]s", &logindata[1].username);
	fflush(stdin);
	
	//input password
	printf("Masukan Password : ");
	scanf("%[^\n]s", &logindata[1].password);
	fflush(stdin);
	
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
			printf("PINTU\nAC\nLAMPU\nKIPAS\nKELUAR\n");
			printf("\nPILIH ELEKTRONIK : ");
			scanf("%s", &con);
			if (strcmp(con, "pintu") == 0){
				if (control[indeks - 1].door == 0) {
					printf("\nMenyalakan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n	Elektronik Berhasil Dinyalakan\n");
					control[indeks - 1].door = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else if (control[indeks - 1].door == 1){
					printf("\nMemematikan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n	Elektronik Berhasil Dimatikan\n");
					control[indeks - 1].door = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("Elektronik Sedang Rusak/Tidak Ada\n");
					sleep(2);
					goto pilihelektronik;
				}
			}
			else if (strcmp(con, "ac") == 0){
				if (control[indeks - 1].ac == 0) {
					printf("\nMenyalakan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n	Elektronik Berhasil Dinyalakan\n");
					control[indeks - 1].ac = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else if (control[indeks - 1].ac == 1){
					printf("\nMematikan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n	Elektronik Berhasil Dimatikan\n");
					control[indeks - 1].ac = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("Elektronik Sedang Rusak/Tidak Ada\n");
					sleep(2);
					goto pilihelektronik;
				}
			}
			else if (strcmp(con, "lampu") == 0){
				if (control[indeks - 1].lights == 0) {
					printf("\nMenyalakan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n	Elektronik Berhasil Dinyalakan\n");
					control[indeks - 1].lights = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else if (control[indeks - 1].lights == 1){
					printf("\nMematikan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n	Elektronik Berhasil Dimatikan\n");
					control[indeks - 1].lights = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("Elektronik Sedang Rusak/Tidak Ada\n");
					sleep(2);
					goto pilihelektronik;
				}
			}
			else if (strcmp(con, "kipas") == 0){
				if (control[indeks - 1].fan == 0) {
					printf("\nMenyalakan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n	Elektronik Berhasil Dinyalakan\n");
					control[indeks - 1].fan = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else if (control[indeks - 1].fan == 1){
					printf("\nMematikan Elektronik . . .\n");
					sleep(1);
					loading();
					printf("\n\n	Elektronik Berhasil Dimatikan\n");
					control[indeks - 1].fan = 1;
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("\nElektronik Sedang Rusak/Tidak Ada\n");
					sleep(2);
					goto pilihelektronik;
				}
			}
			else if (strcmp(con, "keluar") == 0){
				return ctos(control, logindata);
			}
			else {
				printf("INVALID MENU");
				fflush(stdin);
				goto pilihelektronik;
			}
	}
	else if (strcmp(pilihan, "menu") == 0){
		return buletinboard(control, logindata);
	}
	else {
		printf("INVALID MENU");
		fflush(stdin);
		sleep(2);
		return ctos(control, logindata);
	}
}

/* 	Wikipedia Status Elektronik
	0 = Mati
	1 = Nyala
	2 = Rusak/Tidak Ada
	3 = Maintenance/Dimatikan Sistem
*/

int terminal(struct ruangan *control, struct user *logindata){
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM\n\n");
	
	int indeks;
	char pilihan[10], con[10], st[10], pseudopilihan[10];
	time_t t;
	srand((unsigned) time(&t));
	
	printf("ELEKTRONIK\nMENU\n: ");
	scanf("%s", &pilihan);
	fflush(stdin);
	if (strcmp(pilihan, "elektronik") == 0){
		pilihelektronik:
				
			system("cls");
			printf("\n\nSMART OFFICE SYSTEM\n\n");
			printf("\nMAINTENANCE MODE\n\nPINTU\nAC\nLAMPU\nKIPAS\n\nKELUAR\n: ");
			scanf("%s", &con);
			fflush(stdin);
			if (strcmp(con, "keluar") == 0) return terminal(control, logindata);	
			
			system("cls");
			printf("\n\nSMART OFFICE SYSTEM\n\n");
			displayroom(control);
			printf("\nPILIH RUANGAN : ");
			scanf("%d", &indeks);
			fflush(stdin);
			
			system("cls");
			printf("\n\nSMART OFFICE SYSTEM\n\n");
			
			if (strcmp(con, "pintu") == 0){
				if (control[indeks - 1].door < 2) {
						printf("ELEKTRONIK SEDANG BERFUNGSI\n\n");
				}
				else {
						printf("ELEKTRONIK SEDANG TIDAK BERFUNGSI\n\n");
				}
				printf("MENU MAINTENANCE ELEKTRONIK:\nENABLE\nDISABLE\nTROUBLESHOOT\n\nKELUAR\n: ");
				scanf("%s", &st);
				
				if (strcmp(st, "enable") == 0){
					if (control[indeks - 1].door == 2) {
						printf("ELEKTRONIK SEDANG RUSAK, TIDAK BISA DIAKTIFKAN\n");
					}
					else if (control[indeks - 1].door < 2){
						printf("ELEKTRONIK SUDAH AKTIF\n");
					}
					else {
						printf("MENGAKTIFKAN ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\n	ELEKTRONIK BERHASIL DIAKTIFKAN\n");
						control[indeks - 1].door = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "disable") == 0){
					if (control[indeks - 1].door  == 2) {
						printf("ELEKTRONIK SUDAH RUSAK\n");
					}
					else if (control[indeks - 1].door == 3){
						printf("ELEKTRONIK SUDAH DINONAKTIFKAN\n");
					}
					else {						
						printf("\nMENONAKTIFKAN ELEKTRONIK . . .\n");
						sleep(1);
						printf("\nMENGAPA ELEKTRONIK DINONAKTIFKAN\nRUSAK\nMAINTENANCE\n: ");
						
						disdoor:
						scanf("%s", &pseudopilihan);
						fflush(stdin);
						if (strcmp(pseudopilihan, "rusak") == 0){
							printf("\n\nELEKTRONIK DINYATAKAN RUSAK\n");
							sleep(1);
							loading();
							printf("\n\n	STATUS TELAH BERUBAH\n");
							control[indeks - 1].door = 2;
						}
						else if (strcmp(pseudopilihan, "maintenance") == 0){
							printf("\n\nELEKTRONIK PERLU MAINTENANCE\n");
							sleep(1);
							loading();
							printf("\n\n	STATUS TELAH DIUBAH\n");
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
						printf("ELEKTRONIK BERFUNGSI, TROUBLESHOOT TIDAK BISA DIJALANKAN\n");
					}
					else if (control[indeks - 1].door == 2){
						printf("ELEKTRONIK RUSAK, LAKUKAN PERBAIKAN MANUAL\n");
					}
					else {
						printf("MENCOBA MEMPERBAIKI ELEKTRONIK\n");
						sleep(1);
						loading();
						int random = rand() % 100;
						if (random < 70){
							printf("\n\n	GAGAL DIPERBAIKI\n	SILAHKAN COBA KEMBALI\n");
						}
						else {
							printf("\n\n	PERBAIKAN BERHASIL\n");
							control[indeks - 1].door = 0;
						}
					}
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("INVALID MENU");
					fflush(stdin);
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
				printf("MENU MAINTENANCE ELEKTRONIK:\nENABLE\nDISABLE\nTROUBLESHOOT\n\nKELUAR\n: ");
				scanf("%s", &st);
				fflush(stdin);
				if (strcmp(st, "enable") == 0){
					if (control[indeks - 1].ac == 2) {
						printf("ELEKTRONIK SEDANG RUSAK, TIDAK BISA DIAKTIFKAN\n");
					}
					else if (control[indeks - 1].ac < 2){
						printf("ELEKTRONIK SUDAH AKTIF\n");
					}
					else {
						printf("MENGAKTIFKAN ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\nELEKTRONIK BERHASIL DIAKTIFKAN\n");
						control[indeks - 1].ac = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "disable") == 0){
					if (control[indeks - 1].ac == 2) {
						printf("ELEKTRONIK SUDAH RUSAK\n");
					}
					else if (control[indeks - 1].ac == 3){
						printf("ELEKTRONIK SUDAH DINONAKTIFKAN\n");
					}
					else {
						printf("\nMENONAKTIFKAN ELEKTRONIK . . .\n");
						sleep(1);
						printf("\nMENGAPA ELEKTRONIK DINONAKTIFKAN\nRUSAK\nMAINTENANCE\n: ");
						
						disac:
						scanf("%s", &pseudopilihan);
						fflush(stdin);
						if (strcmp(pseudopilihan, "rusak") == 0){
							printf("\n\nELEKTRONIK DINYATAKAN RUSAK\n");
							sleep(1);
							loading();
							printf("\n\n	STATUS TELAH BERUBAH\n");
							control[indeks - 1].ac = 2;
						}
						else if (strcmp(pseudopilihan, "maintenance") == 0){
							printf("\n\nELEKTRONIK PERLU MAINTENANCE\n");
							sleep(1);
							loading();
							printf("\n\n	STATUS TELAH DIUBAH\n");
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
						printf("ELEKTRONIK BERFUNGSI, TROUBLESHOOT TIDAK BISA DIJALANKAN\n");
					}
					else if (control[indeks - 1].ac == 2){
						printf("ELEKTRONIK RUSAK, LAKUKAN PERBAIKAN MANUAL\n");
					}
					else {
						printf("MENCOBA MEMPERBAIKI ELEKTRONIK\n");
						sleep(1);
						loading();
						int random = rand() % 100;
						if (random < 70){
							printf("\n\n	GAGAL DIPERBAIKI\n	SILAHKAN COBA KEMBALI\n");
						}
						else {
							printf("\n\n	PERBAIKAN BERHASIL\n");
							control[indeks - 1].ac = 0;
						}
					}
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("INVALID MENU");
					fflush(stdin);
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
				printf("MENU MAINTENANCE ELEKTRONIK:\nENABLE\nDISABLE\nTROUBLESHOOT\n\nKELUAR\n: ");
				scanf("%s", &st);
				fflush(stdin);
				if (strcmp(st, "enable") == 0){
					if (control[indeks - 1].lights == 2) {
						printf("ELEKTRONIK SEDANG RUSAK, TIDAK BISA DIAKTIFKAN\n");
					}
					else if (control[indeks - 1].lights < 2){
						printf("ELEKTRONIK SUDAH AKTIF\n");
					}
					else {
						printf("MENGAKTIFKAN ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\nELEKTRONIK BERHASIL DIAKTIFKAN\n");
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
						fflush(stdin);
						if (strcmp(pseudopilihan, "rusak") == 0){
							printf("\n\nELEKTRONIK DINYATAKAN RUSAK\n");
							sleep(1);
							loading();
							printf("\n\n	STATUS TELAH BERUBAH\n");
							control[indeks - 1].lights = 2;
						}
						else if (strcmp(pseudopilihan, "maintenance") == 0){
							printf("\n\nELEKTRONIK PERLU MAINTENANCE\n");
							sleep(1);
							loading();
							printf("\n\n	STATUS TELAH DIUBAH\n");
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
						printf("ELEKTRONIK BERFUNGSI, TROUBLESHOOT TIDAK BISA DIJALANKAN\n");
					}
					else if (control[indeks - 1].lights == 2){
						printf("ELEKTRONIK RUSAK, LAKUKAN PERBAIKAN MANUAL\n");
					}
					else {
						printf("MENCOBA MEMPERBAIKI ELEKTRONIK\n");
						sleep(1);
						loading();
						int random = rand() % 100;
						if (random < 70){
							printf("\n\n	GAGAL DIPERBAIKI\n	SILAHKAN COBA KEMBALI\n");
						}
						else {
							printf("\n\n	PERBAIKAN BERHASIL\n");
							control[indeks - 1].lights = 0;
						}
					}
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("INVALID MENU");
					fflush(stdin);
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
				printf("MENU MAINTENANCE ELEKTRONIK:\nENABLE\nDISABLE\nTROUBLESHOOT\n\nKELUAR\n: ");
				scanf("%s", &st);
				fflush(stdin);
				if (strcmp(st, "enable") == 0){
					if (control[indeks - 1].fan == 2) {
						printf("ELEKTRONIK SEDANG RUSAK, TIDAK BISA DIAKTIFKAN\n");
					}
					else if (control[indeks - 1].fan < 2){
						printf("ELEKTRONIK SUDAH AKTIF\n");
					}
					else {
						printf("MENGAKTIFKAN ELEKTRONIK\n");
						sleep(1);
						loading();
						printf("\nELEKTRONIK BERHASIL DIAKTIFKAN\n");
						control[indeks - 1].fan = 0;
					}
					sleep(2);
					goto pilihelektronik;
				}
				else if (strcmp(st, "disable") == 0){
					if (control[indeks - 1].fan % 2 == 0) {
						printf("ELEKTRONIK SUDAH RUSAK\n");
					}
					else if (control[indeks - 1].fan == 3){
						printf("ELEKTRONIK SUDAH DINONAKTIFKAN\n");
					}
					else {
						
						printf("\nMENONAKTIFKAN ELEKTRONIK . . .\n");
						sleep(1);
						printf("\nMENGAPA ELEKTRONIK DINONAKTIFKAN\nRUSAK\nMAINTENANCE\n: ");
						
						disfan:
						scanf("%s", &pseudopilihan);
						fflush(stdin);
						if (strcmp(pseudopilihan, "rusak") == 0){
							printf("\n\nELEKTRONIK DINYATAKAN RUSAK\n");
							sleep(1);
							loading();
							printf("\n\n	STATUS TELAH BERUBAH\n");
							control[indeks - 1].fan = 2;
						}
						else if (strcmp(pseudopilihan, "maintenance") == 0){
							printf("\n\nELEKTRONIK PERLU MAINTENANCE\n");
							sleep(1);
							loading();
							printf("\n\n	STATUS TELAH DIUBAH\n");
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
						printf("ELEKTRONIK BERFUNGSI, TROUBLESHOOT TIDAK BISA DIJALANKAN\n");
					}
					else if (control[indeks - 1].fan == 2){
						printf("ELEKTRONIK RUSAK, LAKUKAN PERBAIKAN MANUAL\n");
					}
					else {
						printf("MENCOBA MEMPERBAIKI ELEKTRONIK\n");
						sleep(1);
						loading();
						int random = rand() % 100;
						if (random < 70){
							printf("\n\n	GAGAL DIPERBAIKI\n	SILAHKAN COBA KEMBALI\n");
						}
						else {
							printf("\n\n	PERBAIKAN BERHASIL\n");
							control[indeks - 1].fan = 0;
						}
					}
					sleep(2);
					goto pilihelektronik;
				}
				else {
					printf("INVALID MENU");
					fflush(stdin);
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
		fflush(stdin);
		return changer(control, logindata);
	}
}

int help(struct ruangan *control, struct user *logindata){
	char pilihan[10];
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM\n\n");
	printf("Gunakan 'Kontrol Elektronik' untuk melakukan Kendali ON/OFF Elektronik pada Ruangan\n");
	printf("Gunakan 'Status dan Maintenance' untuk melakukan Aktivasi/Deaktivasi, Check dan Perbaikan pada Elektronik\n");
	printf("Gunakan 'Reset Akun' untuk Melakukan penggantian username dan password yang digunakan untuk login Smart Office System\n");
	
	printf("\n\nKeluar\n: ");
	if (strcmp(pilihan, "keluar") == 0){
		return buletinboard(control, logindata);
	}
	else {
		printf("INVALID MENU");
		fflush(stdin);
		return help(control, logindata);
	}
}

int credits(struct ruangan *control, struct user *logindata){
	char pilihan[10];
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM");
	printf("\n\nKelompok 07 - Daskom 02\n");
	printf("Raffly Putera Wibowo, 2206062693");
	printf("\nRadhitya Gibran Prasentianto, 2206062522");
	printf("\n\nVersi 3.0");
	printf("\n\nTerimakasih Kepada\n1. Five Nights at Freddy's\n2. Lethal Company\n3. Alexander Prizias\n4. Jonathan Rio Wicaksono\n");
	
	printf("\n\nKeluar\n: ");
	if (strcmp(pilihan, "keluar") == 0){
		return buletinboard(control, logindata);
	}
	else {
		printf("INVALID MENU");
		fflush(stdin);
		return help(control, logindata);
	}
}

int buletinboard(struct ruangan *control, struct user *logindata){
	system("cls");
	printf("\n\nSMART OFFICE SYSTEM");
	char pilihan[10];
	printf("\n\nKontrol Elektronik\nService and Maintenance\nReset Akun\nManual\nAbout\nExit\n: ");
	scanf("%s", &pilihan);
	if (strcmp(pilihan, "kontrol") == 0){
		fflush(stdin);
		ctos(control, logindata);
	}
	else if (strcmp(pilihan, "servis") == 0){
		fflush(stdin);
		terminal(control, logindata);
	}
	else if (strcmp(pilihan, "reset") == 0){
		fflush(stdin);
		changer(control, logindata);
	}
	else if (strcmp(pilihan, "manual") == 0){
		fflush(stdin);
		help(control, logindata);
	}
	else if (strcmp(pilihan, "about") == 0){
		fflush(stdin);
		credits(control, logindata);
	}
	else if (strcmp(pilihan, "exit") == 0){
		return prelogin(control, logindata);
	}
	else {
		puts("\nINVALID MENU");
		fflush(stdin);
		sleep(2);
		return buletinboard(control, logindata);
	}
}

int main(){
	int retval;
	struct user *logindata = (struct user*)malloc(3 * sizeof(struct user));
	struct ruangan *control = (struct ruangan*)malloc(9 * sizeof(struct ruangan));

	start(control, logindata);	
	prelogin(control, logindata);
	
	free(logindata);
	free(control);
	return 0;
}