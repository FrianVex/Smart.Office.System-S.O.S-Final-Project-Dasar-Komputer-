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
	sleep(1);
	//Menggunakan ASCII Code 437 Standard IBM untuk DOS untuk deklarasi char kosong dengan ASCII value 177 dan char terisi ASCII value 219
	char kosong = 177;
	char terisi = 219;

	printf("\n\n\n\n\t");
    printf("Loading...\n\n");
	printf("\t");

	// Print initial loading bar (loading bar kosong)
	for (i = 0; i < 50; i++)
		printf("%c", kosong);

	// Set the cursor again at starting point of loading bar
	printf("\r");
	printf("\t");

	// Print loading bar progress
	for (i = 0; i < 50; i++) {
		printf("%c", terisi);

		// Cepat lambatnya loading bar
		Sleep(90);
	}
}

int prelogin(struct ruangan *control, struct user *logindata){
	
	//input pilihan login
	system("cls");
	int pilihan;
	printf("\n\n\n1.Login\n2.Shutdown\n: ");
	scanf("%d", &pilihan);
	fflush(stdin);
	
	//check nilai pada pilihan
	switch (pilihan){
		case(1):
			system("cls");
			login(control, logindata);			
			break;
		case(2):
			break;
		default:
			printf("\nINVALID MENU");
			sleep(1);
			fflush(stdin);
			return prelogin(control, logindata);
			break;
	}
}

int login(struct ruangan *control, struct user *logindata){
	
	//input username
	printf("\n\n\nMasukan Username : ");
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

void displayroom(){
	int i;
	printf("Tampilan Ruangan\n");
	for (i = 0; i < 3; i++){
		printf("A%d		A%d		A%d\n", i+1, i+4, i+7);
	}
}

int ctos(struct ruangan *control, struct user *logindata){
	system("cls");
	int pilihan, indeks, con;
	printf("Pilih Ruangan(1) atau Balik Ke Menu(2): ");
	scanf("%d", &pilihan);
	switch (pilihan){
		case(1):
			system("cls");
			displayroom(control);
			
			printf("Pilih Ruangan : ");
			scanf("%d", &indeks);
			
			pilihelektronik:
			system("cls");
			printf("1. Pintu\n2. AC\n3. Lampu\n4. Kipas\n5. Keluar\n");
			printf("\nPilih Elektronik : ");
			scanf("%d", &con);
			switch (con){
				case(1):
					if (control[indeks].door == 0) {
						printf("Menyalakan Elektronik . . .\n");
						sleep(1);
						loading();
						printf("\n\n	Elektronik Berhasil Dinyalakan\n");
						control[indeks].door = 1;
						sleep(2);
						goto pilihelektronik;
					}
					else if (control[indeks].door == 1){
						printf("Memematikan Elektronik . . .\n");
						sleep(1);
						loading();
						printf("\n\n	Elektronik Berhasil Dimatikan\n");
						control[indeks].door = 1;
						sleep(2);
						goto pilihelektronik;
					}
					else {
						printf("Elektronik Sedang Rusak/Tidak Ada\n");
						sleep(2);
						goto pilihelektronik;
					}
					break;
				case(2):
					if (control[indeks].ac == 0) {
						printf("Menyalakan Elektronik . . .\n");
						sleep(1);
						loading();
						printf("\n\n	Elektronik Berhasil Dinyalakan\n");
						control[indeks].ac = 1;
						sleep(2);
						goto pilihelektronik;
					}
					else if (control[indeks].ac == 1){
						printf("Mematikan Elektronik . . .\n");
						sleep(1);
						loading();
						printf("\n\n	Elektronik Berhasil Dimatikan\n");
						control[indeks].ac = 1;
						sleep(2);
						goto pilihelektronik;
					}
					else {
						printf("Elektronik Sedang Rusak/Tidak Ada\n");
						sleep(2);
						goto pilihelektronik;
					}
					break;
				case(3):
					if (control[indeks].lights == 0) {
						printf("Menyalakan Elektronik . . .\n");
						sleep(1);
						loading();
						printf("\n\n	Elektronik Berhasil Dinyalakan\n");
						control[indeks].lights = 1;
						sleep(2);
						goto pilihelektronik;
					}
					else if (control[indeks].lights == 1){
						printf("Mematikan Elektronik . . .\n");
						sleep(1);
						loading();
						printf("\n\n	Elektronik Berhasil Dimatikan\n");
						control[indeks].lights = 1;
						sleep(2);
						goto pilihelektronik;
					}
					else {
						printf("Elektronik Sedang Rusak/Tidak Ada\n");
						sleep(2);
						goto pilihelektronik;
					}
					break;
				case(4):
					if (control[indeks].fan == 0) {
						printf("Menyalakan Elektronik . . .\n");
						sleep(1);
						loading();
						printf("\n\n	Elektronik Berhasil Dinyalakan\n");
						control[indeks].fan = 1;
						sleep(2);
						goto pilihelektronik;
					}
					else if (control[indeks].fan == 1){
						printf("Mematikan Elektronik . . .\n");
						sleep(1);
						loading();
						printf("\n\n	Elektronik Berhasil Dimatikan\n");
						control[indeks].fan = 1;
						sleep(2);
						goto pilihelektronik;
					}
					else {
						printf("Elektronik Sedang Rusak/Tidak Ada\n");
						sleep(2);
						goto pilihelektronik;
					}
					break;
				case(5):
					return ctos(control, logindata);
					break;
				default:
					printf("INVALID MENU");
					fflush(stdin);
					goto pilihelektronik;
					break;
			}
			break;
		case(2):
			return buletinboard(control);
			break;
		default:
			printf("INVALID MENU");
			fflush(stdin);
			return ctos(control, logindata);
			break;
	}
}

/* 	Wikipedia Status Elektronik
	0 = Mati
	1 = Nyala
	2 = Rusak
	3 = Maintenance/Dimatikan Sistem
	4 = Tidak ada
*/

int terminal(struct ruangan *control, struct user *logindata){
	system("cls");
	
	int pilihan, indeks, con, st, pseudopilihan;
	time_t t;
	srand((unsigned) time(&t));
	
	printf("Pilih Elektronik(1) atau Balik Ke Menu(2): ");
	scanf("%d", &pilihan);
	switch (pilihan){
		case(1):
			pilihelektronik:
				
			system("cls");
			
			printf("Pilih Elektronik untuk dilihat\n1. Pintu\n2. AC\n3. Lampu\n4. Kipas\n5. Keluar\n: ");
			scanf("%d", &con);
			if (con == 5) return terminal(control, logindata);
			fflush(stdin);
			
			system("cls");
			displayroom(control);
			printf("\nPilih Ruangan : ");
			scanf("%d", &indeks);
			
			system("cls");
			
			switch (con){
				case(1):
					if (control[indeks].door < 2) {
						printf("\nElektronik sedang berfungsi dengan baik\n\n");
					}
					else {
						printf("\nElektronik sedang dalam Maintenance\n\n");
					}
					printf("Lakukan Perubahan Status:\n1. Enable\n2. Disable\n3. Troubleshoot\n4. Maintenance\n5. Keluar\n: ");
					scanf("%d", &st);
					switch (st){
						case(1):
							if (control[indeks].door % 2 == 0) {
								printf("Elektronik sedang Rusak/Tidak Ada, Tidak Bisa dinyalakan\n");
							}
							else if (control[indeks].door < 2){
								printf("Elektronik Sudah Menyala\n");
							}
							else {
								printf("Menyalakan Elektronik\n");
								sleep(1);
								loading();
								printf("Elektronik Berhasil Dinyalakan\n");
								control[indeks].door = 0;
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(2):
							printf("Mematikan Elektronik\n\nMasukkan Status Elektronik\n1. Rusak\n2. Maintenance: ");
							scanf("%d", &pseudopilihan);
							switch(pseudopilihan){
								case(1):
									printf("Mematikan Elektronik\n");
									sleep(1);
									printf("Mengubah Status menjadi Rusak\n");
									sleep(1);
									loading();
									printf("\n\n	Status Elektronik Berhasil diubah\n");
									control[indeks].door = 2;
								case(2):
									printf("Mematikan Elektronik\n");
									sleep(1);
									printf("Mengubah Status menjadi Maintenance\n");
									sleep(1);
									loading();
									printf("\n\n	Status Elektronik Berhasil diubah\n");
									control[indeks].door = 3;
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(3):
							printf("Melakukan cek pada Elektronik\n");
							if (control[indeks].door < 2) {
								printf("\n\nElektronik sedang berfungsi dengan baik\n");
							}
							else if (control[indeks].door % 2 == 0){
								printf("\n\nElektronik Rusak/Tidak Ada\n");
							}
							else {
								printf("\n\nElektronik dalam Maintenance\n");
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case (4):
							if (control[indeks].door < 2) {
								printf("Elektronik dalam kondisi baik, Maintenance Tidak Bisa dilakukan\n");
							}
							else if (control[indeks].door == 4){
								printf("Maintenance Tidak bisa dilakukan Elektronik Tidak Ada\n");
							}
							else {
								printf("Mencoba Melakukan Maintenance pada Elektronik\n");
								sleep(1);
								loading();
								int random = rand() % 100;
								if (random < 70){
									printf("\n\n	Elektronik Gagal Diperbaiki\n	Silahkan Coba lagi\n");
								}
								else {
									printf("\n\n	Elektronik Berhasil DiPerbaiki\n");
									control[indeks].door = 0;
								}
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(5):
							goto pilihelektronik;
							break;
						default:
							printf("INVALID MENU");
							fflush(stdin);
							break;
					}
					break;
				case(2):
					if (control[indeks].ac < 2) {
						printf("\nElektronik sedang berfungsi dengan baik\n\n");
					}
					else {
						printf("\nElektronik sedang dalam Maintenance\n\n");
					}
					printf("Lakukan Perubahan Status:\n1. Enable\n2. Disable\n3. Troubleshoot\n4. Maintenance\n5. Keluar\n: ");
					scanf("%d", &st);
					switch (st){
						case(1):
							if (control[indeks].ac % 2 == 0) {
								printf("Elektronik sedang Rusak/Tidak Ada, Tidak Bisa dinyalakan\n");
							}
							else if (control[indeks].ac < 2){
								printf("Elektronik Sudah Menyala\n");
							}
							else {
								printf("Menyalakan Elektronik\n");
								control[indeks].ac = 0;
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(2):
							printf("Mematikan Elektronik\n\nMasukkan Status Elektronik\n1. Rusak\n2. Maintenance: ");
							scanf("%d", &pseudopilihan);
							switch(pseudopilihan){
								case(1):
									printf("Mematikan Elektronik\n");
									sleep(1);
									printf("Mengubah Status menjadi Rusak\n");
									sleep(1);
									loading();
									printf("\n\n	Status Elektronik Berhasil diubah\n");
									control[indeks].ac = 2;
								case(2):
									printf("Mematikan Elektronik\n");
									sleep(1);
									printf("Mengubah Status menjadi Maintenance\n");
									sleep(1);
									loading();
									printf("\n\n	Status Elektronik Berhasil diubah\n");
									control[indeks].ac = 3;
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(3):
							printf("Melakukan cek pada Elektronik\n");
							if (control[indeks].ac < 2) {
								printf("\n\nElektronik sedang berfungsi dengan baik\n");
							}
							else if (control[indeks].ac % 2 == 0){
								printf("\n\nElektronik Rusak/Tidak Ada\n");
							}
							else {
								printf("\n\nElektronik dalam Maintenance\n");
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case (4):
							if (control[indeks].ac < 2) {
								printf("Elektronik dalam kondisi baik, Maintenance Tidak Bisa dilakukan\n");
							}
							else if (control[indeks].ac == 4){
								printf("Maintenance Tidak bisa dilakukan Elektronik Tidak Ada\n");
							}
							else {
								printf("Mencoba Melakukan Maintenance pada Elektronik\n");
								sleep(1);
								loading();
								int random = rand() % 100;
								if (random < 70){
									printf("\n\n	Elektronik Gagal Diperbaiki\n	Silahkan Coba lagi\n");
								}
								else {
									printf("\n\n	Elektronik Berhasil DiPerbaiki\n");
									control[indeks].ac = 0;
								}
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(5):
							goto pilihelektronik;
							break;
						default:
							printf("INVALID MENU");
							fflush(stdin);
							break;
					}
					break;
				case(3):
					if (control[indeks].lights < 2) {
						printf("\nElektronik sedang berfungsi dengan baik\n\n");
					}
					else {
						printf("\nElektronik sedang dalam Maintenance\n\n");
					}
					printf("Lakukan Perubahan Status:\n1. Enable\n2. Disable\n3. Troubleshoot\n4. Maintenance\n5. Keluar\n: ");
					scanf("%d", &st);
					switch (st){
						case(1):
							if (control[indeks].lights % 2 == 0) {
								printf("Elektronik sedang Rusak/Tidak Ada, Tidak Bisa dinyalakan\n");
							}
							else if (control[indeks].lights < 2){
								printf("Elektronik Sudah Menyala\n");
							}
							else {
								printf("Menyalakan Elektronik\n");
								control[indeks].lights = 0;
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(2):
							printf("Mematikan Elektronik\n\nMasukkan Status Elektronik\n1. Rusak\n2. Maintenance: ");
							scanf("%d", &pseudopilihan);
							switch(pseudopilihan){
								case(1):
									printf("Mematikan Elektronik\n");
									sleep(1);
									printf("Mengubah Status menjadi Rusak\n");
									sleep(1);
									loading();
									printf("\n\n	Status Elektronik Berhasil diubah\n");
									control[indeks].lights = 2;
								case(2):
									printf("Mematikan Elektronik\n");
									sleep(1);
									printf("Mengubah Status menjadi Maintenance\n");
									sleep(1);
									loading();
									printf("\n\n	Status Elektronik Berhasil diubah\n");
									control[indeks].lights = 3;
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(3):
							printf("Melakukan cek pada Elektronik\n");
							if (control[indeks].lights < 2) {
								printf("\n\nElektronik sedang berfungsi dengan baik\n");
							}
							else if (control[indeks].lights % 2 == 0){
								printf("\n\nElektronik Rusak/Tidak Ada\n");
							}
							else {
								printf("\n\nElektronik dalam Maintenance\n");
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case (4):
							if (control[indeks].lights < 2) {
								printf("Elektronik dalam kondisi baik, Maintenance Tidak Bisa dilakukan\n");
							}
							else if (control[indeks].lights == 4){
								printf("Maintenance Tidak bisa dilakukan Elektronik Tidak Ada\n");
							}
							else {
								printf("Mencoba Melakukan Maintenance pada Elektronik\n");
								sleep(1);
								loading();
								int random = rand() % 100;
								if (random < 70){
									printf("\n\n	Elektronik Gagal Diperbaiki\n		Silahkan Coba lagi\n");
								}
								else {
									printf("\n\n	Elektronik Berhasil DiPerbaiki\n");
									control[indeks].lights = 0;
								}
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(5):
							goto pilihelektronik;
							break;
						default:
							printf("INVALID MENU");
							fflush(stdin);
							break;
					}
					break;
				case(4):
					if (control[indeks].fan < 2) {
						printf("\nElektronik sedang berfungsi dengan baik\n\n");
					}
					else {
						printf("\nElektronik sedang dalam Maintenance\n\n");
					}
					printf("Lakukan Perubahan Status:\n1. Enable\n2. Disable\n3. Troubleshoot\n4. Maintenance\n5. Keluar\n: ");
					scanf("%d", &st);
					switch (st){
						case(1):
							if (control[indeks].fan % 2 == 0) {
								printf("Elektronik sedang Rusak/Tidak Ada, Tidak Bisa dinyalakan\n");
							}
							else if (control[indeks].fan < 2){
								printf("Elektronik Sudah Menyala\n");
							}
							else {
								printf("Menyalakan Elektronik\n");
								control[indeks].fan = 0;
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(2):
							printf("Mematikan Elektronik\n\nMasukkan Status Elektronik\n1. Rusak\n2. Maintenance: ");
							scanf("%d", &pseudopilihan);
							switch(pseudopilihan){
								case(1):
									printf("Mematikan Elektronik\n");
									sleep(1);
									printf("Mengubah Status menjadi Rusak\n");
									sleep(1);
									loading();
									printf("\n\n	Status Elektronik Berhasil diubah\n");
									control[indeks].fan = 2;
								case(2):
									printf("Mematikan Elektronik\n");
									sleep(1);
									printf("Mengubah Status menjadi Maintenance\n");
									sleep(1);
									loading();
									printf("\n\n	Status Elektronik Berhasil diubah\n");
									control[indeks].fan = 3;
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(3):
							printf("Melakukan cek pada Elektronik\n");
							if (control[indeks].fan < 2) {
								printf("\n\nElektronik sedang berfungsi dengan baik\n");
							}
							else if (control[indeks].fan % 2 == 0){
								printf("\n\nElektronik Rusak/Tidak Ada\n");
							}
							else {
								printf("\n\nElektronik dalam Maintenance\n");
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case (4):
							if (control[indeks].fan < 2) {
								printf("Elektronik dalam kondisi baik, Maintenance Tidak Bisa dilakukan\n");
							}
							else if (control[indeks].fan == 4){
								printf("Maintenance Tidak bisa dilakukan Elektronik Tidak Ada\n");
							}
							else {
								printf("Mencoba Melakukan Maintenance pada Elektronik\n");
								sleep(1);
								loading();
								int random = rand() % 100;
								if (random < 70){
									printf("\n\n	Elektronik Gagal Diperbaiki\n	Silahkan Coba lagi\n");
								}
								else {
									printf("\n\n	Elektronik Berhasil DiPerbaiki\n");
									control[indeks].fan = 0;
								}
							}
							sleep(2);
							goto pilihelektronik;
							break;
						case(5):
							goto pilihelektronik;
							break;
						default:
							printf("INVALID MENU");
							fflush(stdin);
							break;
					}
					break;
				case(5):
					return ctos(control, logindata);
					break;
				default:
					printf("INVALID MENU");
					fflush(stdin);
					break;
			}
			break;
		case(2):
			return buletinboard(control);
			break;
		default:
			printf("INVALID MENU");
			fflush(stdin);
			break;
	}
}

int changer(struct ruangan *control, struct user *logindata){
	int pilihan;
	printf("1. Username\n2. Password\n3. Keluar\nPilih yang akan diganti\n: ");
	scanf("%d", &pilihan);
	switch (pilihan){
		case(1):
        	printf("Masukkan Username Baru: ");
        	scanf("%[^\n]s", &logindata[0].username);
        	printf("Username Berhasil Diubah!\n");
        	sleep(2);
        	return prelogin(control, logindata);
        	break;
        case(2):
        	printf("Masukkan Password Baru: ");
        	scanf("%[^\n]s", &logindata[0].password);
        	printf("Password Berhasil Diubah!\n");
        	sleep(2);
        	return prelogin(control, logindata);
        	break;
        case(3):
        	return buletinboard(control, logindata);
        	break;
        default:
			printf("INVALID MENU");
			fflush(stdin);
			return changer(control, logindata);
			break;
	}
}

int help(struct ruangan *control, struct user *logindata){
	printf("Fitur Belum Ditambahkan");
	return buletinboard(control);
}

int credits(struct ruangan *control, struct user *logindata){
	system("cls");
	printf("Kelompok 07 - Daskom 02\n");
	printf("Raffly Putera Wibowo, 2206062693");
	printf("\nRadhitya Gibran Prasentianto, 2206062522");
	printf("\n\nTerimakasih Kepada\n1. Five Nights at Freddy's\n2. Lethal Company\n3. Alexander Prizias\n4. Jonathan Rio Wicaksono");
	sleep(3);
	return buletinboard(control);
}

int buletinboard(struct ruangan *control, struct user *logindata){
	sleep(3);
	system("cls");
	int pilihan;
	printf("1. Kontrol Elektronik\n2. Perubahan Status Elektronik\n3. Ubah Username dan Password\n4. Bantuan\n5. Credits\n6. Exit\n: ");
	scanf("%d", &pilihan);
	switch (pilihan){
		case (1):
			ctos(control, logindata);
			break;
		case(2):
			terminal(control, logindata);
			break;
		case(3):
			changer(control, logindata);
			break;
		case(4):
			help(control, logindata);
			break;
		case(5):
			credits(control, logindata);
			break;
		case(6):
			return prelogin(control, logindata);
			break;
		default:
			puts("INVALID MENU");
			sleep(1);
			return buletinboard(control, logindata);
			break;
	}
}

int main(){
	struct user *logindata = (struct user*)malloc(2 * sizeof(struct user));
	struct ruangan *control = (struct ruangan*)malloc(9 * sizeof(struct ruangan));

	start(control, logindata);	
	prelogin(control, logindata);
	
	free(logindata);
	free(control);
	return 0;
}