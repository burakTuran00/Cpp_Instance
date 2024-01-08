#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>   // getch icin
#include <windows.h> // sleep icin
int buyukluk;
void mayinlar(int buyukluk, char tarla[buyukluk][buyukluk])
{
    srand(time(NULL));

    int satir, sutun, etkiSatir, etkiSutun;
    int mayinSayisi = (buyukluk * buyukluk) * 0.05;
    int yerlesenMayin = 0;

    while (yerlesenMayin < mayinSayisi)
    {
        satir = rand() % buyukluk;
        sutun = rand() % buyukluk;

        if (tarla[satir][sutun] != 'o')
        {
            tarla[satir][sutun] = 'o';
        }

        for (etkiSatir = satir - 1; etkiSatir <= satir + 1; etkiSatir++)
        {
            if (0 <= etkiSatir && etkiSatir < buyukluk)
            {
                if (tarla[etkiSatir][sutun] != 'o')
                {
                    tarla[etkiSatir][sutun] = 'x';
                }
            }
        }

        for (etkiSutun = sutun - 1; etkiSutun <= sutun + 1; etkiSutun++)
        {
            if (0 <= etkiSutun && etkiSutun < buyukluk)
            {
                if (tarla[satir][etkiSutun] != 'o')
                {
                    tarla[satir][etkiSutun] = 'x';
                }
            }
        }
        yerlesenMayin++;
    }
}

void mayinTarlasi(int buyukluk, char tarla[buyukluk][buyukluk], char gorunenTarla[buyukluk][buyukluk])
{
    int i, j, x, y;
    tarla[buyukluk - 1][buyukluk - 1] = 'B';

    for (i = 0; i < buyukluk; i++)
    {
        for (j = 0; j < buyukluk; j++)
        {
            tarla[i][j] = '-';
        }
    }

    mayinlar(buyukluk, tarla);

    if (tarla[buyukluk - 1][buyukluk - 1] == 'o')
    {
        tarla[buyukluk - 1][buyukluk - 1] = 'B';
        tarla[buyukluk - 2][buyukluk - 1] = '-';
        tarla[buyukluk - 1][buyukluk - 2] = '-';
    }

    if (tarla[0][0] == 'o')
    {
        tarla[0][1] = '-';
        tarla[1][0] = '-';
    }

    for (i = 0; i < buyukluk; i++)
    {
        for (j = 0; j < buyukluk; j++)
        {
            gorunenTarla[i][j] = '-';
        }
    }

    for (x = 0; x < buyukluk; x++)
    {
        for (y = 0; y < buyukluk; y++)
        {
            printf("%c ", gorunenTarla[x][y]);
        }

        printf("\n");
    }
}

void printGuvenliYol(int buyukluk, char guvenliYol[buyukluk][buyukluk])
{
    int i, j;
    for (i = 0; i < buyukluk; i++)
    {
        for (j = 0; j < buyukluk; j++)
        {
            if (guvenliYol[i][j] == '+')
            {
                printf("+ ");
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int oyuncuHareketleri(int buyukluk, char tarla[buyukluk][buyukluk], char gorunenTarla[buyukluk][buyukluk])
{
    char gorulenOyuncu = 'P';
    char oyuncu = 'H';
    int hareket;
    char gorulenBitis = 'B';
    char bitis = 'E';
    int i, j;
    int baslangicSatir = 0, baslangicSutun = 0;
    int oyuncuSatir = baslangicSatir, oyuncuSutun = baslangicSutun;
    char guvenliYol[buyukluk][buyukluk];

    do
    {
        gorunenTarla[oyuncuSatir][oyuncuSutun] = 'P';
        tarla[oyuncuSatir][oyuncuSutun] = 'H';

        gorunenTarla[buyukluk - 1][buyukluk - 1] = gorulenBitis;
        tarla[buyukluk - 1][buyukluk - 1] = bitis;

        guvenliYol[baslangicSatir][baslangicSutun] = '+';

        system("cls"); // Ekran temizleme (Windows için)
        printf("Hareket yonu seciniz: (w:yukari, s:asagi, a:sol, d:sag, r:restart)\n", hareket);

        // Oyun alanını görüntüleme
        for (i = 0; i < buyukluk; i++)
        {
            for (j = 0; j < buyukluk; j++)
            {
                printf("%c ", gorunenTarla[i][j]);
            }
            printf("\n");
        }

        hareket = getch();

        switch (hareket)
        {
        case 'w':

            if (0 < oyuncuSatir)
            {
                gorunenTarla[oyuncuSatir][oyuncuSutun] = '-';
                tarla[oyuncuSatir][oyuncuSutun] = '-';

                oyuncuSatir--;

                gorulenOyuncu = gorunenTarla[oyuncuSatir][oyuncuSutun];
                oyuncu = tarla[oyuncuSatir][oyuncuSutun];

                gorunenTarla[oyuncuSatir][oyuncuSutun] = 'P';
                tarla[oyuncuSatir][oyuncuSutun] = 'H';

                guvenliYol[oyuncuSatir][oyuncuSutun] = '+';
            }

            break;

        case 's':

            if (oyuncuSatir < buyukluk - 1)
            {
                gorunenTarla[oyuncuSatir][oyuncuSutun] = '-';
                tarla[oyuncuSatir][oyuncuSutun] = '-';

                oyuncuSatir++;

                gorulenOyuncu = gorunenTarla[oyuncuSatir][oyuncuSutun];
                oyuncu = tarla[oyuncuSatir][oyuncuSutun];

                gorunenTarla[oyuncuSatir][oyuncuSutun] = 'P';
                tarla[oyuncuSatir][oyuncuSutun] = 'H';

                guvenliYol[oyuncuSatir][oyuncuSutun] = '+';
            }

            break;

        case 'a':

            if (0 < oyuncuSutun)
            {
                gorunenTarla[oyuncuSatir][oyuncuSutun] = '-';
                tarla[oyuncuSatir][oyuncuSutun] = '-';

                oyuncuSutun--;

                gorulenOyuncu = gorunenTarla[oyuncuSatir][oyuncuSutun];
                oyuncu = tarla[oyuncuSatir][oyuncuSutun];

                gorunenTarla[oyuncuSatir][oyuncuSutun] = 'P';
                tarla[oyuncuSatir][oyuncuSutun] = 'H';

                guvenliYol[oyuncuSatir][oyuncuSutun] = '+';
            }

            break;

        case 'd':

            if (oyuncuSutun < buyukluk - 1)
            {
                gorunenTarla[oyuncuSatir][oyuncuSutun] = '-';
                tarla[oyuncuSatir][oyuncuSutun] = '-';

                oyuncuSutun++;

                gorulenOyuncu = gorunenTarla[oyuncuSatir][oyuncuSutun];
                oyuncu = tarla[oyuncuSatir][oyuncuSutun];

                gorunenTarla[oyuncuSatir][oyuncuSutun] = 'P';
                tarla[oyuncuSatir][oyuncuSutun] = 'H';

                guvenliYol[oyuncuSatir][oyuncuSutun] = '+';
            }

            break;

        case 'r':

            printf("Oyun resetleniyor...\n");

            Sleep(1000);

            mayinTarlasi(buyukluk, tarla, gorunenTarla);
            oyuncuSatir = baslangicSatir;
            oyuncuSutun = baslangicSutun;

            gorulenOyuncu = gorunenTarla[oyuncuSatir][oyuncuSutun];
            oyuncu = tarla[oyuncuSatir][oyuncuSutun];

            gorunenTarla[oyuncuSatir][oyuncuSutun] = 'P';
            tarla[oyuncuSatir][oyuncuSutun] = 'H';

            // guvenliYolu temizlemek icin
            for (i = 0; i < buyukluk; i++)
            {
                for (j = 0; j < buyukluk; j++)
                {
                    if (guvenliYol[i][j] == '+')
                    {
                        guvenliYol[i][j] = ' ';
                    }
                }

                printf("\n");
            }

            break;

        default:

            printf("Yanlis tus kullandiniz.");
        }

        // Oyuncu "x" konumuna geldiğinde başlangıç noktasına dön
        if (oyuncu == 'x')
        {
            gorunenTarla[oyuncuSatir][oyuncuSutun] = '-';
            tarla[oyuncuSatir][oyuncuSutun] = 'x';

            oyuncuSatir = baslangicSatir;
            oyuncuSutun = baslangicSutun;

            gorunenTarla[oyuncuSatir][oyuncuSutun] = 'P';
            tarla[oyuncuSatir][oyuncuSutun] = 'H';

            // guvenliYolu temizlemek icin
            for (i = 0; i < buyukluk; i++)
            {
                for (j = 0; j < buyukluk; j++)
                {
                    if (guvenliYol[i][j] == '+')
                    {
                        guvenliYol[i][j] = ' ';
                    }
                }

                printf("\n");
            }
        }

    } while (oyuncu != bitis);

    printf("Oyunu kazandiniz.\nIlerlediginiz guvenli yol:\n");
    printGuvenliYol(buyukluk, guvenliYol);

    return 0;
}

int main()
{
    printf("Mayin tarlasinin buyuklugunu giriniz:");
    scanf("%d", &buyukluk);

    char tarla[buyukluk][buyukluk];
    char gorunenTarla[buyukluk][buyukluk];

    mayinTarlasi(buyukluk, tarla, gorunenTarla);
    oyuncuHareketleri(buyukluk, tarla, gorunenTarla);

    return 0;
}
