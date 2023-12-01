#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
	char username[50] = {'admin'};
	long int password = 12345; 
};

struct ruangan{
	int door;
	int ac;
	int lights;
	int fan;
};

void loading(){
	int i;
	// ASCII buat loading bar
	// a = loading bar kosong || b = loading bar progress
	char a = 177, b = 219;

	printf("\n\n\n\n\t");
    printf("Loading...\n\n");
	printf("\t");

	// Print initial loading bar (loading bar kosong)
	for (i = 0; i < 50; i++)
		printf("%c", a);

	// Set the cursor again at starting point of loading bar
	printf("\r");
	printf("\t");

	// Print loading bar progress
	for (i = 0; i < 50; i++) {
		printf("%c", b);

		// Cepat lambatnya loading bar
		Sleep(150);
	}
}

void prelogin(){
	int pilihan;
	printf("\n\n\n1.Login\n2.Shutdown\n: ");
	scanf("%d", &pilihan);
	fflush(stdin);
	switch (pilihan){
		case(1):
		system("cls");			
		break;
		case(2):
		exit(0);	
	}
}

void login(struct user logindata){
	char decoyuser[] = "admin";
	long int decoypass = 12345;
	printf("Masukan Username : ");
	scanf("%[^\n]s", &logindata.username);
	fflush(stdin);
	printf("Masukan Password : ");
	scanf("%ld", &logindata.password);
	fflush(stdin);
	if (strcmp(logindata.username, decoyuser) == 0 && logindata.password == decoypass){
		printf("\nSelamat Datang %s :3", decoyuser);
		sleep(3);
		system("cls");
		loading();
	}
	else {
		printf("\nUsername atau Password salah");
		sleep(1);
		system("cls");
		return login(logindata);	
	}
}

void displayroom(struct ruangan *control){
	int i;
	printf("Tampilan Ruangan\n");
	for (i = 0; i < 3; i++){
		printf("A%d		A%d		A%d\n", i+1, i+4, i+7);
	}
}

int ctos(struct ruangan *control){
	system("cls");
	int pilihan;
	int lantai = sizeof(int);
	display(control);
	printf("Pilih Ruangan : ");
	scanf("%d", &pilihan);
	printf("1. Pintu\n2. AC\n3. Lampu\n4. Kipas\n: ");
	printf
	return buletinboard(control);
}

int terminal(struct ruangan *control){
	printf("Asvial");
	return buletinboard(control);
}

int changer(struct ruangan *control){
	printf("Noa");
	return buletinboard(control);
}

int help(struct ruangan *control){
	printf("Rendy");
	return buletinboard(control);
}

int credits(struct ruangan *control){
	printf("Darksoulist");
	return buletinboard(control);
}

int buletinboard(struct ruangan *control){
	sleep(3);
	system("cls");
	int pilihan;
	printf("1. Kontrol Elektronik\n2. Perubahan Status Elektronik\n3. Ubah Username dan Password\n4. Bantuan\n5. Credits\n6. Shutdown\n: ");
	scanf("%d", &pilihan);
	switch (pilihan){
		case (1):
			ctos(control);
			break;
		case(2):
			terminal(control);
			break;
		case(3):
			changer(control);
			break;
		case(4):
			help(control);
			break;
		case(5):
			credits(control);
			break;
		case(6):
			exit(0);
			break;
		default:
			puts("INVALID MENU");
			sleep(1);
			return buletinboard(control);
			break;
	}
}

int main(){
	struct user logindata;
	prelogin();
	login(logindata);

	struct ruangan *control = (struct ruangan*)malloc(sizeof(int) * sizeof(struct ruangan));
	buletinboard(control);
	
}
