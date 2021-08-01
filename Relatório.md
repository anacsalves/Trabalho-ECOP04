
## Step 1 Passos iniciais

Minha ideia era projetar um programa que simulasse um _elevador_, e, principalmente, seu painel. Para isso tive que pensar em quais funcionalidades são utilizadas em um elevador. Inicialmente, pensei em utilizar o Display LCD para escrever mensagens, as teclas para o usuário escolher o andar e chamar ajuda, os LEDs ou o display de 7 segmentos para mostrar o andar em que o elevador está no momento, o buzzer para simular um alarme, e o relé para simular as portas abertas/fechadas. Mais tarde, acabei optando pelos LEDs, devido a facilidade e ao design, e decidindo adicionar também o cooler para simular o movimento do elevador.

## Step 2 Bibliotecas e defines

As bliotecas utilizadas foram: "config.h", que possui algumas configurações do PICSimLab; "bits.h", a qual possui: bitTst, bitSet e bitClr, que serão utilizados durante o projeto; "lcd.c" e "lcd.h", que possibilitam utilizar o display LCD; e "keypad.c" e "keypad.h", que permitem utilizar as teclas. 

Os quatro primeiros #defines, definem os PORTs e TRISs, de acordo com o que é expresso no datasheet do PIC18F4520. Já os outros três #defines determinam os códigos das linhas 1 e 2 do display LCD e também o código para limpar o display; esses códigos serão lidos pelo lcdCommand().

![2021-08-01 (1)](https://user-images.githubusercontent.com/88052180/127773012-f07cca91-5099-4f6b-9e63-0aeef1c5e760.png)


## Step 3 Criando variáveis

A partir de agora estamos na função main. Nela, primeiramente foi atríbuido ao TRISB e ao TRISC o valor hexadecimal 0x00.

Logo depois, vemos os "auxs", sendo que o "aux" será utilizado para alterar o andar, e começará no andar 1. Já o "auxa" é utilizado para marcar o status do alarme, se ele estiver desligado auxa=0, e se estiver ligado, auxa=1; o alarme começa desligado.


A variável "i" é utilizada para passar "quadradinho' por "quadradinho" para o LCD e as variáveis "s" e "k" são usadas pelos LEDs.
As variavéis andarx (1<=x<=5), definem o código binário de cada LED, que representará os andares.

![2021-07-31 (30)](https://user-images.githubusercontent.com/88052180/127773298-66942fbb-af05-438e-8761-5f5302852333.png)

As variáveis do tipo char que estão entre aspas representam mensagens que serão apresentadas no display LCD, e as que estão entre colchetes são imagens que serão mostradas no mesmo display.

![2021-07-31 (31)](https://user-images.githubusercontent.com/88052180/127773871-a69faad4-5580-4371-8a2e-acd9c13efe39.png)
![2021-08-01 (2)](https://user-images.githubusercontent.com/88052180/127773989-86253ce6-2f77-4a24-883f-6a0ee9401680.png)
![2021-07-31 (32)](https://user-images.githubusercontent.com/88052180/127773995-bd0d7831-096f-4861-80fb-9ac02d73315b.png)


## Step 4 Iniciando o elevador

Para isso, foram chamadas as funções _lcdInit()_ e _kpInit()_, que ligam o display LCD e o teclado, respectivamente. É apresentada no LCD a mensagem de boas vindas do elevador. Com a função _bitSet(PORTC, 0);_ o relé é "aceso", o que significa que a porta está aberta. Além disso, é iniciado o _for(;;)_, dentro dele estão todas as leituras de teclas, o que faz com que as teclas sejam lidas para sempre. Dentro do for(;;), também está o kpDebounce para evitar o bouncing das teclas, e um _if_ que define que a tecla só será lida se o valor dela for diferente do anterior, ou seja, se ela for clicada.
![2021-08-01 (4)](https://user-images.githubusercontent.com/88052180/127774393-d5de5bca-c206-4587-a00d-e79be304c299.png)


## Step 5 Andares

É realizado a leitura da tecla e se, por exemplo, você aperta a tecla 2 o elevador irá para o segundo andar. Em cada andar uma série de funções é acionada: primeiramente, a mensagem antiga é apagada, e uma nova, dizendo para qual andar o usuário está indo é apresentada; depois o relé é desligado, simulando porta fechada, e o cooler é ligado, aparentando que o elevador está em movimento.
![2021-07-31 (34)](https://user-images.githubusercontent.com/88052180/127774651-7326752e-6811-4f75-8993-80a3ab98e6a9.png)


