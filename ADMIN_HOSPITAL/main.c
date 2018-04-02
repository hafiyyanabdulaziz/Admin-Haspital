#include <stdio.h>
#include <stdlib.h>

//DEKLARASi
int life=4,i=0;
char user[9999],pass[9999],n,aa[5]="a0";
struct pasien{
        char nama[30],ayah[30],ibu[30],darah[5],hp[30],alamat[40],jns_kelamin,tempat_lahir[30];
        int tinggi,berat,tanggal,bulan,tahun;
}p[900];
FILE *pasien;
/*===========KETERANGAN==========
    life: untuk membuat coundown ketika username dan password tidak sesuai
    user: menyimpan data username
    pass: menyimpan data password
    struct pasien: menyimpan semua data pasien
    i: melakukan penjumlahan perhitungan
    n: untuk menyimpan data y/t ketika input data pasien
    FILE pasien: menyimpan data pasien di file
===============================*/

//PLAY
int main()
{
    system("color a0");
    intro();
    login:
        printf("\t\t\t\t\t\t  Username: ");gets(user);
        printf("\t\t\t\t\t\t  Password: ");readPass(pass);
        if ((strcmp(user,"admin")==0)&&(strcmp(pass,"admin")==0)){
            main_menu();
        }
        else{
            intro();
            printf("\t\t\t\t\tUSERNAME DAN PASSWORD TIDAK SESUAI\n");
            if(life>1) printf("\t\t\t\t\t\t    %dx lagi\n",life-1);
            life=life-1;
            if(life>0) goto login;
            else{
                printf("\t\t\t\t\t  ANDA SUDAH MELEBIHI BATAS LOGIN");
                getch();
                keluar();
            }
        }
}

void isi_data_pasien() //Input data pasien
{
    pasien=fopen("data_pasien.txt", "a");
    do{
        intro();
        i++;
        printf("\t\t\t\t\t\t     PASIEN %d\n",i);
        printf("\t\t\t\t\t     Masukkan Nama Lengkap: ");gets(p[i].nama);
        printf("\t\t\t\t\t     Masukkan Tempat Lahir: ");gets(p[i].tempat_lahir);
        printf("\t\t\t\t\t              Tanggal Lahir: ");scanf("%d",&p[i].tanggal);fflush(stdin);
        printf("\t\t\t\t\t              Bulan Lahir: ");scanf("%d",&p[i].bulan);fflush(stdin);
        printf("\t\t\t\t\t              Tahun Lahir: ");scanf("%d",&p[i].tahun);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Jenis Kelamin(L/P)? ");scanf("%c",&p[i].jns_kelamin);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Golongan Darah (A/B/AB/O)? ");scanf("%s",&p[i].darah);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Tinggi Badan (cm)= ");scanf("%d",&p[i].tinggi);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Berat Badan (kg)= ");scanf("%d",&p[i].berat);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Alamat: ");gets(p[i].alamat);
        printf("\t\t\t\tAPAKAH INGIN MEMASUKKAN DATA PASIEN LAGI (y/t)? ");scanf("%c",&n);fflush(stdin);
        fprintf(pasien,"nama:%s  tempat:%s  tanggal:%d  bulan:%d tahun:%d  jns_kelamin:%c  darah:%s  tinggi:%d  berat:%d  alamat:%s\n",p[i].nama,p[i].tempat_lahir,p[i].tanggal,p[i].bulan,p[i].tahun,p[i].jns_kelamin,p[i].darah,p[i].tinggi,p[i].berat,p[i].alamat);
    } while (n=='y'||n=='Y');
    fclose(pasien);
    main_menu();
}

void lihat_data_pasien() //melihat data pasien dari file
{
    system("cls");
    pasien=fopen("data_pasien.txt","r");
    if(!pasien){  //cek apakah filenya ada atau tidak
        printf("FILE TIDAK DITEMUKAN");
    }
    else{
        intro();
        printf("\t\t\t\t\t\t   DATA PASIEN\n");
        printf("   ________________________________________________________________________________________________________\n");
        printf("  |%-3s|%-20s|%-12s|%-9 %s|%-11s|%-3s|%-5s|%-5s|%-20s|\n","NO.","        NAMA","TEMPAT LAHIR","TGL LAHIR","JNS KELAMIN","GOL DARAH","TINGGI","BERAT","        ALAMAT");
        printf("   --------------------------------------------------------------------------------------------------------\n");
        while(!feof(pasien)){
            i++;
            fscanf(pasien,"nama:%s  tempat:%s  tanggal:%d  bulan:%d tahun:%d  jns_kelamin:%c  darah:%s  tinggi:%d  berat:%d  alamat:%s\n",&p[i].nama,&p[i].tempat_lahir,&p[i].tanggal,&p[i].bulan,&p[i].tahun,&p[i].jns_kelamin,&p[i].darah,&p[i].tinggi,&p[i].berat,&p[i].alamat);
            printf("  |%-3d| %-19s| %-11s|%-1 %d/%d/%d| %-10c| %-8s| %-5d| %-4d| %-19s|\n",i,p[i].nama,p[i].tempat_lahir,p[i].tanggal,p[i].bulan,p[i].tahun,p[i].jns_kelamin,p[i].darah,p[i].tinggi,p[i].berat,p[i].alamat);
        }
        printf("   --------------------------------------------------------------------------------------------------------\n");
        fclose(pasien);
        printf("Press any key to Main Menu.");
        getch();
        main_menu();
    }
}

void intro() //kop rumah sakit
{
    system("cls");
    printf("\t\t\t\t\t\t       ____\n");
    printf("\t\t\t\t\t\t      |    |\n");
    printf("\t\t\t\t\t\t   ___|    |___\n");
    printf("\t\t\t\t\t\t  |            |\n");
    printf("\t\t\t\t\t\t  |___      ___|\n");
    printf("\t\t\t\t\t\t      |    |\n");
    printf("\t\t\t\t\t\t      |____|\n\n");
    printf("\t\t\t\t\t\tSK 41-01 Hospital\n\n");
}


void readPass(char *temp) //Menyamarkan Password
{
    int key=0,index=0;
    do{
        key=getch();
        switch (key){
            case 0:
            case 224:
                getch();
                break;
            case '\b':
                if(index>0){
                    index=index-1;
                    temp[index] = 0;
                    printf("\b \b");
                }
                break;
            default:
                if(key>31&&key<127){
                    temp[index]=key;
                    index = index + 1;
                    printf("*");
                }
        }
    } while(key!=13);
    temp[index]='\0';
}

void main_menu() //menu setelah login
{
    int pil=0;
    menu:
        intro();
        printf("\t\t\t\t\t\t    MAIN MENU\n");
        printf("\t\t\t\t\t    ________________________\n");
        printf("\t\t\t\t\t   | No |       Pilihan     |\n");
        printf("\t\t\t\t\t   |------------------------|\n");
        printf("\t\t\t\t\t   | 1  |  Isi Data Pasien  |\n");
        printf("\t\t\t\t\t   | 2  | Lihat Data Pasien |\n");
        printf("\t\t\t\t\t   | 3  |      Log Out      |\n");
        printf("\t\t\t\t\t   | 4  |      Keluar       |\n");
        printf("\t\t\t\t\t    ---- -------------------\n");
        if(pil>4) printf("\t\t\t\tNOMOR YANG ANDA INGINKAN TIDAK ADA DALAM DAFTAR\n\n");
        printf("Masukkan No. Pilihan= ");scanf("%d",&pil);fflush(stdin);
        switch(pil){
            case 1 : isi_data_pasien();break;
            case 2 : lihat_data_pasien();break;
            case 3 : main();break;
            case 4 : keluar();break;
            default : goto menu;
        }
}

void keluar()
{
    system("cls");
    printf("THANKS FOR USING\n");
    printf("Created By:\n");
    printf("1. Hafiyyan Abdul Aziz\n");
    printf("2. Taufiq Mulya Wijaya\n");
    printf("3. Muhammad Stefani");
    return 0;
}
