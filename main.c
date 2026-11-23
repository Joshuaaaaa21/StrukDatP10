/* File : main.c */
/* Deskripsi : Driver aplikasi ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060125120048 & Joshua Briliant Suryana */
/* Tanggal : 20 November 2026 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"

/* Procedure UjiPohon (input P:bintree, input nama:string, input cari:infotype)
   { Proses: Menguji fungsi-fungsi dasar, predikat, metrik, level, vokal/konsonan, dan modus pada pohon P } */
void UjiPohon(bintree P, char *nama, infotype cari){
    //kamus lokal
    int i, t;
    bintree kiri, kanan;
    //algoritma
    printf("====================================================================\n");
    printf("  PENGUJIAN %s\n", nama);
    printf("====================================================================\n");

    /* 1. Penelusuran Prefix */
    printf("[1] Penelusuran Prefix:\n");
    printf("  PrintPrefix        : ");
    PrintPrefix(P);
    printf("\n");
    printf("  PrintPrefixRingkas : ");
    PrintPrefixRingkas(P);
    printf("\n\n");

    /* 2. Selektor GetLeft & GetRight */
    printf("[2] Selektor Akar, GetLeft & GetRight:\n");
    if(!IsEmptyTree(P)){
        printf("  Akar               : %c\n", akar(P));
        kiri = GetLeft(P);
        kanan = GetRight(P);
        if(kiri != NIL){
            printf("  Info GetLeft       : %c\n", info(kiri));
        } else {
            printf("  Info GetLeft       : NIL\n");
        }
        if(kanan != NIL){
            printf("  Info GetRight      : %c\n", info(kanan));
        } else {
            printf("  Info GetRight      : NIL\n");
        }
    } else {
        printf("  Pohon kosong (NIL)\n");
    }
    printf("\n");

    /* 3. Predikat Pohon */
    printf("[3] Predikat Pohon:\n");
    printf("  IsEmptyTree        : %s\n", IsEmptyTree(P) ? "TRUE" : "FALSE");
    printf("  IsDaun             : %s\n", IsDaun(P) ? "TRUE" : "FALSE");
    printf("  IsBiner            : %s\n", IsBiner(P) ? "TRUE" : "FALSE");
    printf("  IsUnerLeft         : %s\n", IsUnerLeft(P) ? "TRUE" : "FALSE");
    printf("  IsUnerRight        : %s\n", IsUnerRight(P) ? "TRUE" : "FALSE");
    printf("  IsSkewLeft         : %s\n", IsSkewLeft(P) ? "TRUE" : "FALSE");
    printf("  IsSkewRight        : %s\n\n", IsSkewRight(P) ? "TRUE" : "FALSE");

    /* 4. Metrik & Karakteristik */
    t = Tinggi(P);
    printf("[4] Metrik & Karakteristik:\n");
    printf("  NbElm              : %d\n", NbElm(P));
    printf("  NbDaun             : %d\n", NbDaun(P));
    printf("  Tinggi             : %d\n", t);
    printf("  GetDaunTerkiri     : %c\n", GetDaunTerkiri(P));
    printf("  Modus              : %c\n\n", Modus(P));

    /* 5. Pencarian, Frekuensi, & Level */
    printf("[5] Pencarian, Frekuensi & Level:\n");
    printf("  SearchX('%c')       : %s\n", cari, SearchX(P, cari) ? "TRUE (Ditemukan)" : "FALSE (Tidak ada)");
    printf("  SearchX('Z')       : %s\n", SearchX(P, 'Z') ? "TRUE (Ditemukan)" : "FALSE (Tidak ada)");
    printf("  CountX('%c')        : %d\n", cari, CountX(P, cari));
    printf("  FrekuensiX('%c')    : %.2f\n", cari, FrekuensiX(P, cari));
    printf("  LevelX('%c')        : %d\n", cari, LevelX(P, cari));
    printf("  LevelX('Z')        : %d\n", LevelX(P, 'Z'));

    if(t >= 0){
        printf("  Isi per Level (CountLevel & PrintLevel):\n");
        for(i = 1; i <= t + 1; i++){
            printf("    Level %d (%d node) : ", i, CountLevel(P, i));
            PrintLevel(P, i);
            printf("\n");
        }
    }
    printf("\n");

    /* 6. Vokal & Konsonan */
    printf("[6] Vokal & Konsonan:\n");
    printf("  CountVocal         : %d\n", CountVocal(P));
    printf("  PrintVocal         :");
    PrintVocal(P);
    printf("\n");
    printf("  CountConsonant     : %d\n", CountConsonant(P));
    printf("  PrintConsonant     :");
    PrintConsonant(P);
    printf("\n\n");
}

int main(){
    //kamus
    bintree B1, B2, B3, Pkosong, Pdaun;
    bintree subF, subI;
    //algoritma
    printf("====================================================================\n");
    printf("         DRIVER ADT POHON BINER 1 (POINTER) - BINTREE               \n");
    printf("====================================================================\n\n");

    /* --- PERSIAPAN 3 POHON UJI + POHON KOSONG & DAUN TUNGGAL --- */
    Pkosong = NIL;
    Pdaun = AlokasiTree('X');

    /* Pohon 1 (B1): Pohon Biner Umum (T-I-N-F-O-R-M-A-T-I-K-A) */
    B1 = Tree('T',
              Tree('I',
                   Tree('N', NIL, NIL),
                   Tree('F',
                        Tree('O', NIL, NIL),
                        NIL)),
              Tree('R',
                   Tree('M',
                        Tree('A', NIL, NIL),
                        Tree('T', NIL, NIL)),
                   Tree('I',
                        NIL,
                        Tree('K',
                             NIL,
                             Tree('A', NIL, NIL))))
             );

    /* Pohon 2 (B2): Pohon Condong Kiri / Skew Left (S -> A -> K -> A) */
    B2 = Tree('S',
              Tree('A',
                   Tree('K',
                        Tree('A', NIL, NIL),
                        NIL),
                   NIL),
              NIL);

    /* Pohon 3 (B3): Pohon Condong Kanan / Skew Right (B -> I -> N -> I) */
    B3 = Tree('B',
              NIL,
              Tree('I',
                   NIL,
                   Tree('N',
                        NIL,
                        Tree('I', NIL, NIL))));

    /* --- 1. UJI POHON 1 (BINER UMUM) --- */
    UjiPohon(B1, "POHON 1 (B1 - Biner Umum: TINFORMATIKA)", 'A');

    /* --- 2. UJI POHON 2 (SKEW LEFT) --- */
    UjiPohon(B2, "POHON 2 (B2 - Condong Kiri / Skew Left: SAKA)", 'A');

    /* --- 3. UJI POHON 3 (SKEW RIGHT) --- */
    UjiPohon(B3, "POHON 3 (B3 - Condong Kanan / Skew Right: BINI)", 'I');

    /* --- 4. PENGUJIAN TAMBAHAN (KOSONG, DAUN, SUBPOHON, MAX2, UPDATEX, DEALOKASI) --- */
    printf("====================================================================\n");
    printf("  PENGUJIAN TAMBAHAN (KOSONG, DAUN, MAX2, UPDATEX, DEALOKASI)\n");
    printf("====================================================================\n");

    /* Uji Pohon Kosong & Daun Tunggal */
    printf("[A] Pohon Kosong & Daun Tunggal:\n");
    printf("  IsEmptyTree(Pkosong) : %s\n", IsEmptyTree(Pkosong) ? "TRUE" : "FALSE");
    printf("  NbElm(Pkosong)       : %d\n", NbElm(Pkosong));
    printf("  Tinggi(Pkosong)      : %d\n", Tinggi(Pkosong));
    printf("  GetDaunTerkiri(Pkos) : %c\n", GetDaunTerkiri(Pkosong));
    printf("  Modus(Pkosong)       : %c\n", Modus(Pkosong));
    printf("  IsDaun(Pdaun 'X')    : %s (Tinggi = %d)\n\n", IsDaun(Pdaun) ? "TRUE" : "FALSE", Tinggi(Pdaun));

    /* Uji Predikat UnerLeft & UnerRight pada subpohon B1 */
    printf("[B] Predikat Subpohon B1 (UnerLeft & UnerRight):\n");
    subF = GetRight(GetLeft(B1)); // node 'F' (anak kiri 'O', anak kanan NIL)
    subI = GetRight(GetRight(B1)); // node 'I' (anak kiri NIL, anak kanan 'K')
    if(subF != NIL){
        printf("  Subpohon '%c' -> IsUnerLeft  : %s\n", info(subF), IsUnerLeft(subF) ? "TRUE" : "FALSE");
    }
    if(subI != NIL){
        printf("  Subpohon '%c' -> IsUnerRight : %s\n", info(subI), IsUnerRight(subI) ? "TRUE" : "FALSE");
    }
    printf("\n");

    /* Uji Fungsi max2 */
    printf("[C] Fungsi max2:\n");
    printf("  max2(12, 25)         : %d\n", max2(12, 25));
    printf("  max2(40, 15)         : %d\n\n", max2(40, 15));

    /* Uji UpdateX pada B2 */
    printf("[D] Manipulasi UpdateX pada Pohon B2:\n");
    printf("  B2 sebelum UpdateX('A', 'O') : ");
    PrintPrefixRingkas(B2);
    printf("\n");
    UpdateX(&B2, 'A', 'O');
    printf("  B2 setelah UpdateX('A', 'O') : ");
    PrintPrefixRingkas(B2);
    printf("\n");
    printf("  CountX(B2, 'A') = %d, CountX(B2, 'O') = %d\n\n", CountX(B2, 'A'), CountX(B2, 'O'));

    /* Uji DealokasiTree pada Pdaun */
    printf("[E] Manajemen Memori (DealokasiTree):\n");
    DealokasiTree(&Pdaun);
    printf("  Pdaun setelah DealokasiTree  : %s\n\n", (Pdaun == NIL) ? "NIL (Berhasil didealokasi)" : "Belum NIL");

    printf("====================================================================\n");
    printf("                       PENGUJIAN SELESAI                            \n");
    printf("====================================================================\n");

    return 0;
}
