#include "config.h"
#include "bits.h"
#include "lcd.h"
#include "keypad.h"
#include "ssd.h"
#include "config.h"

#define PORTB (*(volatile unsigned char*)0xF81)
#define TRISB (*(volatile unsigned char*)0xF93)
#define PORTC (*(volatile unsigned char*)0xF82)
#define TRISC (*(volatile unsigned char*)0xF94)

#define L1 0x80
#define L2 0xC0
#define CLR 0x01

void main(void) {
    TRISB = 0x00;
    TRISC = 0x00;
    int aux = 1, auxa = 0;
    char i;
    float s;
    char andar1, andar2, andar3, andar4, andar5;
    char k;
    andar1 = 0b10000000;
    andar2 = 0b01000000;
    andar3 = 0b00100000;
    andar4 = 0b00010000;
    andar5 = 0b00001000;
    unsigned int tecla = 16;

    char linha1[15] = "Edificio UNIFEI";
    char linha2[15] = "Seja bem vindo!";
    char linha4[16] = "Voce chegou";
    char esc1[16] = "Indo p/ 1° andar";
    char esc2[16] = "Indo p/ 2° andar";
    char esc3[16] = "Indo p/ 3° andar";
    char esc4[16] = "Indo p/ 4° andar";
    char esc5[16] = "Indo p/ 5° andar";
    char ajuda1[16] = "Chamando";
    char ajuda2[16] = "ajuda";
    char ajuda5[16] = "Cancelando";
    char jaesta1[16] = "Voce ja esta ai";
    char abre[] = "ABRINDO PORTA";
    char fecha[] = "FECHANDO PORTA";

    char alarmeon[48] = {
        0x00, 0x00, 0x04, 0x09, 0x11, 0x11, 0x11, 0x11,
        0x04, 0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
        0x00, 0x00, 0x04, 0x12, 0x11, 0x11, 0x11, 0x11,
        0x11, 0x11, 0x17, 0x10, 0x08, 0x04, 0x00, 0x00,
        0x1F, 0x1F, 0x1F, 0x00, 0x04, 0x0E, 0x0E, 0x04,
        0x11, 0x11, 0x1D, 0x01, 0x02, 0x04, 0x00, 0x00
    };
    char alarmeoff[48] = {
        0x10, 0x08, 0x04, 0x03, 0x03, 0x02, 0x02, 0x02,
        0x04, 0x0A, 0x11, 0x00, 0x00, 0x10, 0x08, 0x04,
        0x00, 0x00, 0x00, 0x10, 0x08, 0x08, 0x08, 0x08,
        0x02, 0x02, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x01, 0x1F, 0x00, 0x04, 0x0E, 0x0E, 0x04,
        0x08, 0x08, 0x1C, 0x08, 0x04, 0x02, 0x01, 0x00
    };
    char pabre [24] = {
        0x00, 0x00, 0x01, 0x03, 0x07, 0x03, 0x01, 0x00,
        0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x00, 0x00, 0x10, 0x18, 0x1C, 0x18, 0x10, 0x00
    };
    char pfecha[16] = {
        0x00, 0x00, 0x04, 0x06, 0x07, 0x06, 0x04, 0x00,
        0x00, 0x10, 0x12, 0x16, 0x1E, 0x16, 0x12, 0x10
    };

    lcdInit();

    bitSet(PORTC, 0);
    lcdCommand(L1);
    for (i = 0; i < 15; i++) {
        lcdData(linha1[i]);
    }
    lcdCommand(L2);
    for (i = 0; i < 15; i++) {
        lcdData(linha2[i]);
    }


    kpInit();
    for (;;) {

        kpDebounce();
        if (kpRead() != tecla) {
            tecla = kpRead();

            if (bitTst(tecla, 3)) {//andar1
                lcdCommand(CLR);
                lcdCommand(L1);
                for (i = 0; i < 16; i++) {
                    lcdData(esc1[i]);
                }
                bitClr(PORTC, 0);
                bitSet(PORTC, 2);

                if (aux == 1) {
                    lcdCommand(CLR);
                    lcdCommand(L1);
                    for (i = 0; i < 15; i++) {
                        lcdData(jaesta1[i]);
                    }
                }
                if (aux == 2) {
                    for (k = 0; k < 2; k++) {
                        PORTB = andar2 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar1;
                }
                if (aux == 3) {
                    for (k = 0; k < 3; k++) {
                        PORTB = andar3 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar1;
                }
                if (aux == 4) {
                    for (k = 0; k < 4; k++) {
                        PORTB = andar4 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar1;
                }
                if (aux == 5) {
                    for (k = 0; k < 5; k++) {
                        PORTB = andar5 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar1;
                }
                lcdCommand(L2);
                for (i = 0; i < 11; i++) {
                    lcdData(linha4[i]);
                }
                bitClr(PORTC, 2);
                bitSet(PORTC, 0);
                aux = 1;
            } else if (bitTst(tecla, 7)) {//andar2
                lcdCommand(CLR);
                lcdCommand(L1);
                for (i = 0; i < 16; i++) {
                    lcdData(esc2[i]);
                }
                bitClr(PORTC, 0);
                bitSet(PORTC, 2);

                if (aux == 1) {
                    for (k = 0; k < 2; k++) {
                        PORTB = andar1 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar2;
                }
                if (aux == 2) {
                    lcdCommand(CLR);
                    lcdCommand(L1);
                    for (i = 0; i < 15; i++) {
                        lcdData(jaesta1[i]);
                    }
                }
                if (aux == 3) {
                    for (k = 0; k < 2; k++) {
                        PORTB = andar3 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar2;
                }

                if (aux == 4) {
                    for (k = 0; k < 3; k++) {
                        PORTB = andar4 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar2;
                }

                if (aux == 5) {
                    for (k = 0; k < 4; k++) {
                        PORTB = andar5 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar2;
                }
                lcdCommand(L2);
                for (i = 0; i < 11; i++) {
                    lcdData(linha4[i]);
                }
                bitClr(PORTC, 2);
                bitSet(PORTC, 0);
                aux = 2;
            } else if (bitTst(tecla, 11)) {//andar 3
                lcdCommand(CLR);
                lcdCommand(L1);
                for (i = 0; i < 16; i++) {
                    lcdData(esc3[i]);
                }
                bitClr(PORTC, 0);
                bitSet(PORTC, 2);
                if (aux == 1) {
                    for (k = 0; k < 3; k++) {
                        PORTB = andar1 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    lcdCommand(L2);
                    for (i = 0; i < 16; i++) {
                        lcdData(linha4[i]);
                    }
                    PORTB = andar3;
                }
                if (aux == 2) {
                    for (k = 0; k < 2; k++) {
                        PORTB = andar2 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar3;
                }
                if (aux == 3) {
                    lcdCommand(CLR);
                    lcdCommand(L1);
                    for (i = 0; i < 15; i++) {
                        lcdData(jaesta1[i]);
                    }
                }
                if (aux == 4) {
                    for (k = 0; k < 2; k++) {
                        PORTB = andar4 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar3;
                }

                if (aux == 5) {
                    for (k = 0; k < 3; k++) {
                        PORTB = andar5 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar3;
                }
                lcdCommand(L2);
                for (i = 0; i < 11; i++) {
                    lcdData(linha4[i]);
                }
                bitClr(PORTC, 2);
                bitSet(PORTC, 0);
                aux = 3;

            } else if (bitTst(tecla, 2)) {//andar 4
                lcdCommand(CLR);
                lcdCommand(L1);
                for (i = 0; i < 16; i++) {
                    lcdData(esc4[i]);
                }
                bitClr(PORTC, 0);
                bitSet(PORTC, 2);

                if (aux == 1) {
                    for (k = 0; k < 4; k++) {
                        PORTB = andar1 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar4;
                }
                if (aux == 2) {
                    for (k = 0; k < 3; k++) {
                        PORTB = andar2 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar4;
                }
                if (aux == 3) {
                    for (k = 0; k < 2; k++) {
                        PORTB = andar3 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar4;
                }
                if (aux == 4) {
                    lcdCommand(CLR);
                    lcdCommand(L1);
                    for (i = 0; i < 15; i++) {
                        lcdData(jaesta1[i]);
                    }
                }
                if (aux == 5) {
                    for (k = 0; k < 2; k++) {
                        PORTB = andar5 << k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar4;
                }
                lcdCommand(L2);
                for (i = 0; i < 11; i++) {
                    lcdData(linha4[i]);
                }
                bitClr(PORTC, 2);
                bitSet(PORTC, 0);
                aux = 4;
            } else if (bitTst(tecla, 6)) {//andar 5
                lcdCommand(CLR);
                lcdCommand(L1);
                for (i = 0; i < 16; i++) {
                    lcdData(esc5[i]);
                }
                bitClr(PORTC, 0);
                bitSet(PORTC, 2);

                if (aux == 1) {
                    for (k = 0; k < 5; k++) {
                        PORTB = andar1 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar5;
                }
                if (aux == 2) {
                    for (k = 0; k < 4; k++) {
                        PORTB = andar2 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar5;
                }
                if (aux == 3) {
                    for (k = 0; k < 3; k++) {
                        PORTB = andar3 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar5;
                }
                if (aux == 4) {
                    for (k = 0; k < 2; k++) {
                        PORTB = andar4 >> k;
                        for (s = 0; s < 10000; s++);
                    }
                    PORTB = andar5;
                }
                if (aux == 5) {
                    lcdCommand(CLR);
                    lcdCommand(L1);
                    for (i = 0; i < 15; i++) {
                        lcdData(jaesta1[i]);
                    }
                }
                lcdCommand(L2);
                for (i = 0; i < 11; i++) {
                    lcdData(linha4[i]);
                }
                bitClr(PORTC, 2);
                bitSet(PORTC, 0);
                aux = 5;
            } else if ((bitTst(tecla, 4))&&(auxa == 0)) {
                // botao 0 = ajuda
                bitSet(PORTC, 1);
                lcdCommand(CLR);
                lcdCommand(L1);
                for (i = 0; i < 8; i++) {
                    lcdData(ajuda1[i]);
                }
                lcdCommand(L2);
                for (i = 0; i < 5; i++) {
                    lcdData(ajuda2[i]);
                }
                lcdCommand(0x40);
                for (i = 0; i < 48; i++) {
                    lcdData(alarmeon[i]);
                }
                lcdCommand(0x8B);
                lcdData(0);
                lcdData(1);
                lcdData(2);
                lcdCommand(0xCB);
                lcdData(3);
                lcdData(4);
                lcdData(5);

                auxa = 1;

            } else if ((bitTst(tecla, 4))&&(auxa == 1)) {

                bitClr(PORTC, 1);
                lcdCommand(CLR);
                lcdCommand(L1);
                for (i = 0; i < 10; i++) {
                    lcdData(ajuda5[i]);
                }
                lcdCommand(L2);
                for (i = 0; i < 5; i++) {
                    lcdData(ajuda2[i]);
                }
                lcdCommand(0x40);
                for (i = 0; i < 48; i++) {
                    lcdData(alarmeoff[i]);
                }
                lcdCommand(0x8B);
                lcdData(0);
                lcdData(1);
                lcdData(2);
                lcdCommand(0xCB);
                lcdData(3);
                lcdData(4);
                lcdData(5);

                auxa = 0;

            } else if (bitTst(tecla, 0)) {//abre portas
                bitSet(PORTC, 0); // liga rele 1
                lcdCommand(CLR);
                lcdCommand(L1);
                for (i = 0; i < 13; i++) {
                    lcdData(abre[i]);
                }
                lcdCommand(0x40);
                for (i = 0; i < 24; i++) {
                    lcdData(pabre[i]);
                }
                lcdCommand(0x8D);
                lcdData(0);
                lcdData(1);
                lcdData(2);

            } else if (bitTst(tecla, 8)) {//fecha portas
                bitClr(PORTC, 0); // desliga rele 1
                lcdCommand(CLR);
                lcdCommand(L1);
                for (i = 0; i < 14; i++) {
                    lcdData(fecha[i]);}
                    
                    lcdCommand(0x40);
                    for (i = 0; i < 16; i++) {
                        lcdData(pfecha[i]);
                    }
                    lcdCommand(0x8E);
                    lcdData(0);
                    lcdData(1);
                
            }

        }
    }
}


