#include <stdio.h>
#include <stdlib.h>

//DEKLARASi
int life=4,i=0,warna,pil,x,y,Imax;
char user[9999],pass[9999],n,pengguna[999],sandi[999],o;
struct pasien{
        char nama[30],darah[5],hp[30],alamat[40],jns_kelamin,tempat_lahir[30];
        int tinggi,berat,tanggal,bulan,tahun;
}p[900],simpan;
struct dokter{
    char nama[30],lulusan[30],hp[30],alamat[40],spesialis[50],tempat_lahir[30],jns_kelamin;
    int tinggi,berat,tanggal,bulan,tahun;
}d[100],tempat;
FILE *pasien, *userpass, *color, *dokter;

//PLAY
int main()
{
    start();
    switch(warna){
            case 1 : system("color a0");break;
            case 2 : system("color b0");break;
            case 3 : system("color c0");break;
            case 4 : system("color d0");break;
            case 5 : system("color e0");break;
            case 6 : system("color f0");break;
    }
    intro();
    login:
        printf("\t\t\t\t\t\t  Username: ");gets(user);
        printf("\t\t\t\t\t\t  Password: ");readPass(pass);
        if ((strcmp(user,pengguna)==0)&&(strcmp(pass,sandi)==0)){
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

void isi_data_dokter()
{
    dokter=fopen("data_dokter.txt", "a");
    i=0;
    do{
        intro();
        i++;
        printf("\t\t\t\t\t\t     Dokter %d\n",i);
        printf("\t\t\t\t\t     Masukkan Nama Lengkap: ");gets(d[i].nama);
        printf("\t\t\t\t\t     Masukkan Tempat Lahir: ");gets(d[i].tempat_lahir);
        printf("\t\t\t\t\t              Tanggal Lahir: ");scanf("%d",&d[i].tanggal);fflush(stdin);
        printf("\t\t\t\t\t              Bulan Lahir: ");scanf("%d",&d[i].bulan);fflush(stdin);
        printf("\t\t\t\t\t              Tahun Lahir: ");scanf("%d",&d[i].tahun);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Jenis Kelamin(L/P)? ");scanf("%c",&d[i].jns_kelamin);fflush(stdin);
        printf("\t\t\t\t\t     Spesialisasi: ");gets(d[i].spesialis);
        printf("\t\t\t\t\t     Lulusan: ");gets(d[i].lulusan);
        printf("\t\t\t\t\t     Masukkan Alamat: ");gets(d[i].alamat);
        printf("\t\t\t\tAPAKAH INGIN MEMASUKKAN DATA DOKTER LAGI (y/t)? ");scanf("%c",&n);fflush(stdin);
        fprintf(dokter,"%s#%s#%d#%d#%d#%c#%s#%s#%s#\n",d[i].nama,d[i].tempat_lahir,d[i].tanggal,d[i].bulan,d[i].tahun,d[i].jns_kelamin,d[i].spesialis,d[i].lulusan,d[i].alamat);
    } while (n=='y'||n=='Y');
    fclose(dokter);
    urut_dokter();
    menu_dokter();
}

void start()
{
    userpass=fopen("userpass.txt","r");
    color=fopen("colour.txt","r");
    if(!userpass){  //cek apakah filenya ada atau tidak
        fscanf(color,"%d",&warna);
        printf("===SELAMAT DATANG===\nSILAHKAN REGISTRASI TERLEBIH DAHULU!\nUsername: ");gets(pengguna);
        printf("Password: ");gets(sandi);
        userpass=fopen("userpass.txt", "w");
        fprintf(userpass,"%s %s",pengguna,sandi);
        printf("PENDAFTARAN BERHASI\nPress any key to Login.");
        getch();
    }
    else{
        fscanf(userpass,"%s %s",&pengguna,&sandi);
        fscanf(color,"%d",&warna);
    }
    fclose(userpass);
    fclose(color);
}

void isi_data_pasien() //Input data pasien
{
    pasien=fopen("data_pasien.txt", "a");
    i=0;
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
        fprintf(pasien,"%s#%s#%d#%d#%d#%c#%s#%d#%d#%s#\n",p[i].nama,p[i].tempat_lahir,p[i].tanggal,p[i].bulan,p[i].tahun,p[i].jns_kelamin,p[i].darah,p[i].tinggi,p[i].berat,p[i].alamat);
    } while (n=='y'||n=='Y');
    fclose(pasien);
    urut_pasien();
    menu_pasien();
}

void lihat_data_dokter()
{
    i=0;
    system("cls");
    dokter=fopen("data_dokter.txt","r");
    if(!dokter){  //cek apakah filenya ada atau tidak
        printf("FILE TIDAK DITEMUKAN\n");
        printf("Apakah Anda Ingin Memasukkan Data (y/t)? ");scanf("%c",&o);fflush(stdin);
        if(o=='y'||o=='Y')isi_data_dokter();
        else main_menu();
    }
    else{
        intro();
        printf("\t\t\t\t\t\t   DATA DOKTER\n");
        printf("   ____________________________________________________________________________________________________________\n");
        printf("  |%-3s|%-22s|%-12s|%-9 %s|%-11s|%-11s|%-16s|%-16s|\n","NO.","        NAMA","TEMPAT LAHIR","TGL LAHIR","JNS KELAMIN"," SPESIALIS","     LULUSAN","     ALAMAT");
        printf("   ------------------------------------------------------------------------------------------------------------\n");
        while(!feof(dokter)){
            i++;
            fscanf(dokter,"%[^#]#%[^#]#%d#%d#%d#%c#%[^#]#%[^#]#%[^#]#\n",&d[i].nama,&d[i].tempat_lahir,&d[i].tanggal,&d[i].bulan,&d[i].tahun,&d[i].jns_kelamin,&d[i].spesialis,&d[i].lulusan,&d[i].alamat);
            printf("  |%-3d| Dr. %-17s| %-11s|%-1 %d/%d/%d| %-10c| %-10s| %-15s| %-15s|\n",i,d[i].nama,d[i].tempat_lahir,d[i].tanggal,d[i].bulan,d[i].tahun,d[i].jns_kelamin,d[i].spesialis,d[i].lulusan,d[i].alamat);
        }
        printf("   ------------------------------------------------------------------------------------------------------------\n");
        fclose(dokter);
        printf("Press any key to Menu Dokter.");
        getch();
        menu_dokter();
    }
}

void ganti_dokter()
{
    int g,a;
    i=0;
    system("cls");
    dokter=fopen("data_dokter.txt","r");
    if(!dokter){  //cek apakah filenya ada atau tidak
        printf("FILE TIDAK DITEMUKAN\n");
        printf("Apakah Anda Ingin Memasukkan Data (y/t)? ");scanf("%c",&o);fflush(stdin);
        if(o=='y'||o=='Y')isi_data_dokter();
        else main_menu();
    }
    else{
        intro();
        printf("\t\t\t\t\t\t   DATA DOKTER\n");
        printf("   ____________________________________________________________________________________________________________\n");
        printf("  |%-3s|%-22s|%-12s|%-9 %s|%-11s|%-11s|%-16s|%-16s|\n","NO.","        NAMA","TEMPAT LAHIR","TGL LAHIR","JNS KELAMIN"," SPESIALIS","     LULUSAN","     ALAMAT");
        printf("   ------------------------------------------------------------------------------------------------------------\n");
        while(!feof(dokter)){
            i++;
            fscanf(dokter,"%[^#]#%[^#]#%d#%d#%d#%c#%[^#]#%[^#]#%[^#]#\n",&d[i].nama,&d[i].tempat_lahir,&d[i].tanggal,&d[i].bulan,&d[i].tahun,&d[i].jns_kelamin,&d[i].spesialis,&d[i].lulusan,&d[i].alamat);
            printf("  |%-3d| Dr. %-17s| %-11s|%-1 %d/%d/%d| %-10c| %-10s| %-15s| %-15s|\n",i,d[i].nama,d[i].tempat_lahir,d[i].tanggal,d[i].bulan,d[i].tahun,d[i].jns_kelamin,d[i].spesialis,d[i].lulusan,d[i].alamat);
        }
        printf("   ------------------------------------------------------------------------------------------------------------\n");
        printf("Masukkan Nomer Yang Ingin Anda Ganti= ");scanf("%d",&g);fflush(stdin);
        intro();
        printf("\t\t\t\t\t\t   DATA DOKTER\n");
        printf("   ____________________________________________________________________________________________________________\n");
        printf("  |%-3s|%-22s|%-12s|%-9 %s|%-11s|%-11s|%-16s|%-16s|\n","NO.","        NAMA","TEMPAT LAHIR","TGL LAHIR","JNS KELAMIN"," SPESIALIS","     LULUSAN","     ALAMAT");
        printf("   ------------------------------------------------------------------------------------------------------------\n");
        printf("  |%-3d| Dr. %-17s| %-11s|%-1 %d/%d/%d| %-10c| %-10s| %-15s| %-15s|\n",g,d[g].nama,d[g].tempat_lahir,d[g].tanggal,d[g].bulan,d[g].tahun,d[g].jns_kelamin,d[g].spesialis,d[g].lulusan,d[g].alamat);
        printf("   ------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t==========DATA BARU==========\n");
        printf("\t\t\t\t\t     Masukkan Nama Lengkap: ");gets(d[g].nama);
        printf("\t\t\t\t\t     Masukkan Tempat Lahir: ");gets(d[g].tempat_lahir);
        printf("\t\t\t\t\t              Tanggal Lahir: ");scanf("%d",&d[g].tanggal);fflush(stdin);
        printf("\t\t\t\t\t              Bulan Lahir: ");scanf("%d",&d[g].bulan);fflush(stdin);
        printf("\t\t\t\t\t              Tahun Lahir: ");scanf("%d",&d[g].tahun);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Jenis Kelamin(L/P)? ");scanf("%c",&d[g].jns_kelamin);fflush(stdin);
        printf("\t\t\t\t\t     Spesialisasi: ");gets(d[g].spesialis);
        printf("\t\t\t\t\t     Lulusan: ");gets(d[g].lulusan);
        printf("\t\t\t\t\t     Masukkan Alamat: ");gets(d[g].alamat);
        dokter=fopen("data_dokter.txt", "w");
        for(a=1;a<=i;a++){
            fprintf(dokter,"%s#%s#%d#%d#%d#%c#%s#%s#%s#\n",d[a].nama,d[a].tempat_lahir,d[a].tanggal,d[a].bulan,d[a].tahun,d[a].jns_kelamin,d[a].spesialis,d[a].lulusan,d[a].alamat);
        }
        fclose(dokter);
        printf("GANTI DATA BERHASIL\nPress any key to Menu Dokter.");
        getch();
        urut_dokter();
        menu_dokter();
    }
}

void ganti_pasien()
{
    int g,a;
    i=0;
    system("cls");
    pasien=fopen("data_pasien.txt","r");
    if(!pasien){  //cek apakah filenya ada atau tidak
        printf("FILE TIDAK DITEMUKAN\n");
        printf("Apakah Anda Ingin Memasukkan Data (y/t)? ");scanf("%c",&o);fflush(stdin);
        if(o=='y'||o=='Y')isi_data_pasien();
        else main_menu();
    }
    else{
        intro();
        printf("\t\t\t\t\t\t   DATA PASIEN\n");
        printf("   ________________________________________________________________________________________________________\n");
        printf("  |%-3s|%-20s|%-12s|%-9 %s|%-11s|%-3s|%-5s|%-5s|%-20s|\n","NO.","        NAMA","TEMPAT LAHIR","TGL LAHIR","JNS KELAMIN","GOL DARAH","TINGGI","BERAT","        ALAMAT");
        printf("   --------------------------------------------------------------------------------------------------------\n");
        while(!feof(pasien)){
            i++;
            fscanf(pasien,"%[^#]#%[^#]#%d#%d#%d#%c#%[^#]#%d#%d#%[^#]#\n",&p[i].nama,&p[i].tempat_lahir,&p[i].tanggal,&p[i].bulan,&p[i].tahun,&p[i].jns_kelamin,&p[i].darah,&p[i].tinggi,&p[i].berat,&p[i].alamat);
            printf("  |%-3d| %-19s| %-11s|%-1 %d/%d/%d| %-10c| %-8s| %-5d| %-4d| %-19s|\n",i,p[i].nama,p[i].tempat_lahir,p[i].tanggal,p[i].bulan,p[i].tahun,p[i].jns_kelamin,p[i].darah,p[i].tinggi,p[i].berat,p[i].alamat);
        }
        printf("   --------------------------------------------------------------------------------------------------------\n");
        printf("Masukkan Nomer Yang Ingin Anda Ganti= ");scanf("%d",&g);fflush(stdin);
        intro();
        printf("\t\t\t\t\t\t   DATA PASIEN\n");
        printf("   ________________________________________________________________________________________________________\n");
        printf("  |%-3s|%-20s|%-12s|%-9 %s|%-11s|%-3s|%-5s|%-5s|%-20s|\n","NO.","        NAMA","TEMPAT LAHIR","TGL LAHIR","JNS KELAMIN","GOL DARAH","TINGGI","BERAT","        ALAMAT");
        printf("   --------------------------------------------------------------------------------------------------------\n");
        printf("  |%-3d| %-19s| %-11s|%-1 %d/%d/%d| %-10c| %-8s| %-5d| %-4d| %-19s|\n",g,p[g].nama,p[g].tempat_lahir,p[g].tanggal,p[g].bulan,p[g].tahun,p[g].jns_kelamin,p[g].darah,p[g].tinggi,p[g].berat,p[g].alamat);
        printf("   --------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t==========DATA BARU==========\n");
        printf("\t\t\t\t\t     Masukkan Nama Lengkap: ");gets(p[g].nama);
        printf("\t\t\t\t\t     Masukkan Tempat Lahir: ");gets(p[g].tempat_lahir);
        printf("\t\t\t\t\t              Tanggal Lahir: ");scanf("%d",&p[g].tanggal);fflush(stdin);
        printf("\t\t\t\t\t              Bulan Lahir: ");scanf("%d",&p[g].bulan);fflush(stdin);
        printf("\t\t\t\t\t              Tahun Lahir: ");scanf("%d",&p[g].tahun);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Jenis Kelamin(L/P)? ");scanf("%c",&p[g].jns_kelamin);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Golongan Darah (A/B/AB/O)? ");scanf("%s",&p[g].darah);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Tinggi Badan (cm)= ");scanf("%d",&p[g].tinggi);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Berat Badan (kg)= ");scanf("%d",&p[g].berat);fflush(stdin);
        printf("\t\t\t\t\t     Masukkan Alamat: ");gets(p[g].alamat);
        pasien=fopen("data_pasien.txt", "w");
        for(a=1;a<=i;a++){
            fprintf(pasien,"%s#%s#%d#%d#%d#%c#%s#%d#%d#%s#\n",p[a].nama,p[a].tempat_lahir,p[a].tanggal,p[a].bulan,p[a].tahun,p[a].jns_kelamin,p[a].darah,p[a].tinggi,p[a].berat,p[a].alamat);
        }
        fclose(pasien);
        printf("GANTI DATA BERHASIL\nPress any key to Menu Pasien.");
        getch();
        urut_pasien();
        menu_pasien();
    }
}

void lihat_data_pasien() //melihat data pasien dari file
{
    i=0;
    system("cls");
    pasien=fopen("data_pasien.txt","r");
    if(!pasien){  //cek apakah filenya ada atau tidak
        printf("FILE TIDAK DITEMUKAN\n");
        printf("Apakah Anda Ingin Memasukkan Data (y/t)? ");scanf("%c",&o);fflush(stdin);
        if(o=='y'||o=='Y')isi_data_pasien();
        else main_menu();
    }
    else{
        intro();
        printf("\t\t\t\t\t\t   DATA PASIEN\n");
        printf("   ________________________________________________________________________________________________________\n");
        printf("  |%-3s|%-20s|%-12s|%-9 %s|%-11s|%-3s|%-5s|%-5s|%-20s|\n","NO.","        NAMA","TEMPAT LAHIR","TGL LAHIR","JNS KELAMIN","GOL DARAH","TINGGI","BERAT","        ALAMAT");
        printf("   --------------------------------------------------------------------------------------------------------\n");
        while(!feof(pasien)){
            i++;
            fscanf(pasien,"%[^#]#%[^#]#%d#%d#%d#%c#%[^#]#%d#%d#%[^#]#\n",&p[i].nama,&p[i].tempat_lahir,&p[i].tanggal,&p[i].bulan,&p[i].tahun,&p[i].jns_kelamin,&p[i].darah,&p[i].tinggi,&p[i].berat,&p[i].alamat);
            printf("  |%-3d| %-19s| %-11s|%-1 %d/%d/%d| %-10c| %-8s| %-5d| %-4d| %-19s|\n",i,p[i].nama,p[i].tempat_lahir,p[i].tanggal,p[i].bulan,p[i].tahun,p[i].jns_kelamin,p[i].darah,p[i].tinggi,p[i].berat,p[i].alamat);
        }
        printf("   --------------------------------------------------------------------------------------------------------\n");
        fclose(pasien);
        printf("Press any key to Menu Pasien.");
        getch();
        menu_pasien();
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

void urut_pasien()
{
    i=0;
    pasien=fopen("data_pasien.txt","r");
    while(!feof(pasien)){
            i++;
            fscanf(pasien,"%[^#]#%[^#]#%d#%d#%d#%c#%[^#]#%d#%d#%[^#]#\n",&p[i].nama,&p[i].tempat_lahir,&p[i].tanggal,&p[i].bulan,&p[i].tahun,&p[i].jns_kelamin,&p[i].darah,&p[i].tinggi,&p[i].berat,&p[i].alamat);
    }
    for(x=1;x<=i;x++){
        Imax=x;
        for(y=x+1;y<=i;y++)
            if(strcmp(p[Imax].nama,p[y].nama)>0)
                Imax=y;
        simpan=p[Imax];
        p[Imax]=p[x];
        p[x]=simpan;
     }
     pasien=fopen("data_pasien.txt", "w");
    for(x=1;x<=i;x++){
        fprintf(pasien,"%s#%s#%d#%d#%d#%c#%s#%d#%d#%s#\n",p[x].nama,p[x].tempat_lahir,p[x].tanggal,p[x].bulan,p[x].tahun,p[x].jns_kelamin,p[x].darah,p[x].tinggi,p[x].berat,p[x].alamat);
    }
    fclose(pasien);
}

void urut_dokter()
{
    i=0;
    dokter=fopen("data_dokter.txt","r");
    while(!feof(dokter)){
            i++;
            fscanf(dokter,"%[^#]#%[^#]#%d#%d#%d#%c#%[^#]#%[^#]#%[^#]#\n",&d[i].nama,&d[i].tempat_lahir,&d[i].tanggal,&d[i].bulan,&d[i].tahun,&d[i].jns_kelamin,&d[i].spesialis,&d[i].lulusan,&d[i].alamat);
    }
    for(x=1;x<=i;x++){
        Imax=x;
        for(y=x+1;y<=i;y++)
            if(strcmp(d[Imax].nama,d[y].nama)>0)
                Imax=y;
        tempat=d[Imax];
        d[Imax]=d[x];
        d[x]=tempat;
     }
     dokter=fopen("data_dokter.txt", "w");
    for(x=1;x<=i;x++){
        fprintf(dokter,"%s#%s#%d#%d#%d#%c#%s#%s#%s#\n",d[x].nama,d[x].tempat_lahir,d[x].tanggal,d[x].bulan,d[x].tahun,d[x].jns_kelamin,d[x].spesialis,d[x].lulusan,d[x].alamat);
    }
    fclose(dokter);
}

void menu_pasien()
{
    pil=0;
    menu:
        intro();
        printf("\t\t\t\t\t\t    MENU PASIEN\n");
        printf("\t\t\t\t\t    ___________________________\n");
        printf("\t\t\t\t\t   | No |        Pilihan       |\n");
        printf("\t\t\t\t\t   |---------------------------|\n");
        printf("\t\t\t\t\t   | 1  |    Isi Data Pasien   |\n");
        printf("\t\t\t\t\t   | 2  |   Lihat Data Pasien  |\n");
        printf("\t\t\t\t\t   | 3  |   Ganti Data Pasien  |\n");
        printf("\t\t\t\t\t   | 4  | kembali ke Main Menu |\n");
        printf("\t\t\t\t\t    ---- ----------------------\n");
        if(pil>3) printf("\t\t\t\tNOMOR YANG ANDA INGINKAN TIDAK ADA DALAM DAFTAR\n\n");
        printf("Masukkan No. Pilihan= ");scanf("%d",&pil);fflush(stdin);
        switch(pil){
            case 1 : isi_data_pasien();break;
            case 2 : lihat_data_pasien();break;
            case 3 : ganti_pasien();break;
            case 4 : main_menu();break;
            default : goto menu;
        }
}

void menu_dokter()
{
    pil=0;
    menu:
        intro();
        printf("\t\t\t\t\t\t    MENU DOKTER\n");
        printf("\t\t\t\t\t    ___________________________\n");
        printf("\t\t\t\t\t   | No |        Pilihan       |\n");
        printf("\t\t\t\t\t   |---------------------------|\n");
        printf("\t\t\t\t\t   | 1  |    Isi Data Dokter   |\n");
        printf("\t\t\t\t\t   | 2  |   Lihat Data Dokter  |\n");
        printf("\t\t\t\t\t   | 3  |   Ganti Data Dokter  |\n");
        printf("\t\t\t\t\t   | 4  | kembali ke Main Menu |\n");
        printf("\t\t\t\t\t    ---- ----------------------\n");
        if(pil>3) printf("\t\t\t\tNOMOR YANG ANDA INGINKAN TIDAK ADA DALAM DAFTAR\n\n");
        printf("Masukkan No. Pilihan= ");scanf("%d",&pil);fflush(stdin);
        switch(pil){
            case 1 : isi_data_dokter();break;
            case 2 : lihat_data_dokter();break;
            case 3 : ganti_dokter();break;
            case 4 : main_menu();break;
            default : goto menu;
        }
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
    pil=0;
    menu:
        intro();
        printf("\t\t\t\t\t\t    MAIN MENU\n");
        printf("\t\t\t\t\t    ________________________\n");
        printf("\t\t\t\t\t   | No |       Pilihan     |\n");
        printf("\t\t\t\t\t   |------------------------|\n");
        printf("\t\t\t\t\t   | 1  |       Pasien      |\n");
        printf("\t\t\t\t\t   | 2  |       Dokter      |\n");
        printf("\t\t\t\t\t   | 3  |      Log Out      |\n");
        printf("\t\t\t\t\t   | 4  |      Keluar       |\n");
        printf("\t\t\t\t\t   | 5  |    Pengaturan     |\n");
        printf("\t\t\t\t\t   | 6  |     Cek Kamar     |\n");
        printf("\t\t\t\t\t    ---- -------------------\n");
        if(pil>6) printf("\t\t\t\tNOMOR YANG ANDA INGINKAN TIDAK ADA DALAM DAFTAR\n\n");
        printf("Masukkan No. Pilihan= ");scanf("%d",&pil);fflush(stdin);
        switch(pil){
            case 1 : menu_pasien();break;
            case 2 : menu_dokter();break;
            case 3 : main();break;
            case 4 : keluar();break;
            case 5 : pengaturan();break;
            case 6 : cek_kamar();break;
            default : goto menu;
        }
}

void pengaturan()
{
    pil=0;
    menu:
        intro();
        printf("\t\t\t\t\t\t    PENGATURAN\n");
        printf("\t\t\t\t\t    ___________________________\n");
        printf("\t\t\t\t\t   | No |        Pilihan       |\n");
        printf("\t\t\t\t\t   |---------------------------|\n");
        printf("\t\t\t\t\t   | 1  |   Ganti Background   |\n");
        printf("\t\t\t\t\t   | 2  |   Ganti User & Pass  |\n");
        printf("\t\t\t\t\t   | 3  | kembali ke Main Menu |\n");
        printf("\t\t\t\t\t    ---- ----------------------\n");
        if(pil>3) printf("\t\t\t\tNOMOR YANG ANDA INGINKAN TIDAK ADA DALAM DAFTAR\n\n");
        printf("Masukkan No. Pilihan= ");scanf("%d",&pil);fflush(stdin);
        switch(pil){
            case 1 : background();break;
            case 2 : gantiup();break;
            case 3 : main_menu();break;
            default : goto menu;
        }
}

void gantiup()
{
    userpass=fopen("userpass.txt", "w");
    fscanf(userpass,"%s %s",&pengguna,&sandi);
    intro();
    printf("\t\t\t\tUsername Lama: %s | Password Lama: %s\n",pengguna,sandi);
    printf("\t\t\t\t===========================================\n");
    printf("\t\t\t\tMasukkan Username Baru: ");gets(pengguna);
    printf("\t\t\t\tMasukkan Password Baru: ");gets(sandi);
    fprintf(userpass,"%s %s",pengguna,sandi);
    fclose(userpass);
    printf("\t\t\t\tGANTI USERNAME DAN PASSWORD BERHASIL\nPress any key to Login.");
    getch();
    main();
}

void background()
{
    pil=0;
    menu:
        intro();
        printf("\t\t\t\t\t\t    GANTI BACKGROUND\n");
        printf("\t\t\t\t\t    ______________________\n");
        printf("\t\t\t\t\t   | No |     Pilihan     |\n");
        printf("\t\t\t\t\t   |----------------------|\n");
        printf("\t\t\t\t\t   | 1  |      Hijau      |\n");
        printf("\t\t\t\t\t   | 2  |      Aqua       |\n");
        printf("\t\t\t\t\t   | 3  |      Merah      |\n");
        printf("\t\t\t\t\t   | 4  |      Ungu       |\n");
        printf("\t\t\t\t\t   | 5  |     Kuning      |\n");
        printf("\t\t\t\t\t   | 6  |      Putih      |\n");
        printf("\t\t\t\t\t   | 7  |     Kembali     |\n");
        printf("\t\t\t\t\t    ---- -----------------\n");
        if(pil>7) printf("\t\t\t\tNOMOR YANG ANDA INGINKAN TIDAK ADA DALAM DAFTAR\n\n");
        printf("Masukkan No. Pilihan= ");scanf("%d",&pil);fflush(stdin);
        switch(pil){
            case 1 : warna=1;break;
            case 2 : warna=2;break;
            case 3 : warna=3;break;
            case 4 : warna=4;break;
            case 5 : warna=5;break;
            case 6 : warna=6;break;
            case 7 : pengaturan();break;
            default : goto menu;
        }
        color=fopen("colour.txt", "w");
        fprintf(color,"%d",warna);
        fclose(color);
        printf("\nGANTI BACKGROUND BERHASIL\nPress any key to Login.");
        getch();
        main();
}

int keluar()
{
    system("cls");
    printf("THANKS FOR USING\n");
    printf("Created By:\n");
    printf("1. Hafiyyan Abdul Aziz\n");
    printf("2. Taufiq Mulya Wijaya\n");
    printf("3. Muhammad Stefani");
    return 0;
}

void cek_kamar()
{
    system("cls");
    int Y,I,j,A;
    for(Y=1;Y<=10;Y++){
        printf("\t\t\t\t\t\t");
        for(I=9;I>=Y;I--)printf(" ");
        for(j=1;j<=Y;j++)printf("*");
        for(j=1;j<Y;j++)printf("*");
        printf("\n");
    }
    for(Y=1;Y<=8;Y++){
        printf("\t\t\t\t\t\t");
        for(A=1;A<=19;A++)printf("*");
        printf("\n");
    }
    printf("\t\t\t\t\tMOHON MAAF, SEMUA KAMAR SUDAH PENUH\n");
    printf("Press any key to Main Menu.");
    getch();
    main_menu();
}

/*  CARI PASIEN
void cari_pasien()
{
    int cari_angka;
    char cari_huruf[100];
    i=0;
    system("cls");
    pasien=fopen("data_pasien.txt","r");
    if(!pasien){  //cek apakah filenya ada atau tidak
        printf("FILE TIDAK DITEMUKAN\n");
        printf("Apakah Anda Ingin Memasukkan Data (y/t)? ");scanf("%c",&o);fflush(stdin);
        if(o=='y'||o=='Y')isi_data_pasien();
        else main_menu();
    }
    else{
        intro();
        printf("Masukkan Data Yang Ingin Dicari: ");scanf("%d",&cari_angka);gets(cari_huruf);
        printf("\t\t\t\t\t\t   DATA PASIEN\n");
        printf("   ________________________________________________________________________________________________________\n");
        printf("  |%-3s|%-20s|%-12s|%-9 %s|%-11s|%-3s|%-5s|%-5s|%-20s|\n","NO.","        NAMA","TEMPAT LAHIR","TGL LAHIR","JNS KELAMIN","GOL DARAH","TINGGI","BERAT","        ALAMAT");
        printf("   --------------------------------------------------------------------------------------------------------\n");
        while(!feof(pasien)){
            i++;
            fscanf(pasien,"%[^#]#%[^#]#%d#%d#%d#%c#%[^#]#%d#%d#%[^#]#\n",&p[i].nama,&p[i].tempat_lahir,&p[i].tanggal,&p[i].bulan,&p[i].tahun,&p[i].jns_kelamin,&p[i].darah,&p[i].tinggi,&p[i].berat,&p[i].alamat);
            if(p[i].nama,p[i].tempat_lahir,p[i].tanggal,p[i].bulan,p[i].tahun,p[i].jns_kelamin,p[i].darah,p[i].tinggi,p[i].berat,p[i].alamat);
            printf("  |%-3d| %-19s| %-11s|%-1 %d/%d/%d| %-10c| %-8s| %-5d| %-4d| %-19s|\n",i,p[i].nama,p[i].tempat_lahir,p[i].tanggal,p[i].bulan,p[i].tahun,p[i].jns_kelamin,p[i].darah,p[i].tinggi,p[i].berat,p[i].alamat);
        }
        printf("   --------------------------------------------------------------------------------------------------------\n");
        fclose(pasien);
        printf("Press any key to Main Menu.");
        getch();
        main_menu();
    }
}
*/
