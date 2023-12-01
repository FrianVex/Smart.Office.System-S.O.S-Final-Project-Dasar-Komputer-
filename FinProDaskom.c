#include <stdio.h>
#include <stdlib.h>

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

void login(logindata){
	char decoyuser;
	int decoypass;
	while (logindata.username != decoyuser){
		puts("Masukan Username");
		scanf("%s", &decoyuser);
		if (logindata.password != decoypass) puts("Invalid Username");
	}
	while (logindata.password != decoypass){
		puts("Masukan Password");
		scanf("%s", &decoypass);
		if (logindata.password != decoypass) puts("Invalid Password");
	}
}

int buletinboard(struct ruangan *control){
	int pilihan;
	printf("1. Kontrol Elektronik\n2. Perubahan Status Elektronik\n3. Ubah Username dan Password\n4. Bantuan\n5.Log Out\n");
	scanf("%d", &pilihan);
	switch (pilihan){
		case (1):
			ctos(struct ruangan *control);
			break;
		case(2):
			//
			break;
		case(3):
			//
			break;
		case(4):
			//
			break;
		default:
			puts("INVALID MENU");
			exit(1);
			break;
	}
}

void ctos(struct ruangan *control){
	puts("")
}

int main(){
	struct user logindata;
	login(logindata);

	struct ruangan *control = (struct ruangan*)malloc(sizeof(int) * sizeof(struct ruangan));
	buletinboard(control);
	
}
