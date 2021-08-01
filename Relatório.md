
## Step 1 Passos iniciais
A linguagem utilizada foi C. Os softwares usados foram MPLAB X IDE v5.30 juntamente com o compilador XC8 v2.32 e o simulador PICSimLab v0.8.6 para a PICGenios com PIC18F4520.

Minha ideia era projetar um programa que simulasse um _elevador_ em um prédio de 5 andares, e, principalmente, o painel do elevador. Para isso tive que pensar em quais funcionalidades são utilizadas em um elevador. Inicialmente, pensei em utilizar o Display LCD 16x2 para escrever mensagens, as teclas para o usuário escolher o andar, chamar ajuda e abrir e fechar a porta, os LEDs ou o display de 7 segmentos para mostrar o andar em que o elevador está no momento, o buzzer para simular um alarme, e o relé para simular as portas abertas/fechadas. Mais tarde, acabei optando pelos LEDs na representação do andar atual, devido a facilidade e ao design, e decidi adicionar também o cooler/ventoinha para simular o movimento do elevador.

## Step 2 Bibliotecas e defines

As bliotecas utilizadas foram: "config.h", que possui algumas configurações do PICSimLab; "bits.h", a qual possui: bitTst, bitSet e bitClr, que serão utilizados durante o projeto; "lcd.c" e "lcd.h", que possibilitam utilizar o display LCD; e "keypad.c" e "keypad.h", que permitem utilizar as teclas. 

Os quatro primeiros #defines, definem os PORTs e TRISs, de acordo com o que é expresso no datasheet do PIC18F4520. Já os outros três #defines determinam os códigos das linhas 1 e 2 do display LCD e também o código para limpar o display; esses códigos serão lidos pelo lcdCommand() durante o programa.

![2021-08-01 (1)](https://user-images.githubusercontent.com/88052180/127773012-f07cca91-5099-4f6b-9e63-0aeef1c5e760.png)


## Step 3 Criando variáveis

A partir de agora estamos na função main. Nela, primeiramente foi atríbuido ao TRISB e ao TRISC o valor hexadecimal 0x00.

Logo depois, vemos os auxs, sendo que o "aux" será utilizado para alterar o andar, e começará no andar 1. Já o "auxa" é utilizado para marcar o status do alarme, se ele estiver desligado auxa=0, e se estiver ligado, auxa=1; o alarme começa desligado.


A variável "i" é utilizada para passar "quadradinho" por "quadradinho" para o LCD e as variáveis "s" e "k" são usadas pelos LEDs.
As variavéis andarx (1<=x<=5), definem o código binário de cada LED, que representará os andares.

![2021-07-31 (30)](https://user-images.githubusercontent.com/88052180/127773298-66942fbb-af05-438e-8761-5f5302852333.png)

As variáveis do tipo char que estão entre aspas representam mensagens que serão apresentadas no display LCD, e as que estão entre colchetes são imagens que serão mostradas no mesmo display.

![2021-07-31 (31)](https://user-images.githubusercontent.com/88052180/127773871-a69faad4-5580-4371-8a2e-acd9c13efe39.png)
![2021-08-01 (2)](https://user-images.githubusercontent.com/88052180/127773989-86253ce6-2f77-4a24-883f-6a0ee9401680.png)
![2021-07-31 (32)](https://user-images.githubusercontent.com/88052180/127773995-bd0d7831-096f-4861-80fb-9ac02d73315b.png)


## Step 4 Iniciando o elevador

Para isso, foram chamadas as funções _lcdInit()_ e _kpInit()_, que ligam o display LCD e o teclado, respectivamente. Através do _for_ com a função _lcdData_, é apresentada no LCD a mensagem de boas vindas no elevador. Com a função _bitSet(PORTC, 0);_ o relé é "aceso", o que significa que a porta está aberta. Além disso, é iniciado o _for(;;)_, dentro dele estão todas as leituras de teclas, o que faz com que as teclas sejam lidas para sempre. Dentro do loop infinito, também está o kpDebounce para evitar o bouncing do teclado, e um _if_ que define que a tecla só será lida se o valor dela for diferente do anterior, ou seja, se ela for clicada.
![2021-08-01 (4)](https://user-images.githubusercontent.com/88052180/127774393-d5de5bca-c206-4587-a00d-e79be304c299.png)


## Step 5 Andares

É realizado a leitura da tecla, através do _bitTst_, e se, por exemplo, você aperta a tecla 2 o elevador irá para o segundo andar. Em cada andar uma série de funções é acionada: primeiramente, a mensagem antiga é apagada, e uma nova, dizendo para qual andar o usuário está indo é apresentada; depois o relé é desligado( _bitClr(PORTC, 0);_ ), simulando porta fechada, e o cooler é ligado ( _bitSet(PORTC, 2);_), aparentando que o elevador está em movimento.
![2021-07-31 (36)](https://user-images.githubusercontent.com/88052180/127775410-bf288bd4-8fea-4974-a24c-fda8360b4196.png)


Depois, de acordo com o andar anterior, que estava salvo no _aux_, os LEDs irão acender, se movendo a partir do andar anterior até o andar selecionado e parando de mover no andar escolhido. Também há um _if_ para que a pessoa seja avisada, caso escolha o andar em que ela já estava.
![2021-07-31 (35)](https://user-images.githubusercontent.com/88052180/127775325-7c9ba723-b8a4-4524-ab8c-36384307c55c.png)


Ao final do processo, o cooler é desligado ( _bitClr(PORTC, 2);_), a porta é aberta(_bitSet(PORTC, 0);_), e o andar atual é salvo no _aux_. O processo é o mesmo em todos os andares.
![2021-07-31 (37)](https://user-images.githubusercontent.com/88052180/127775484-3fa5ab3f-4c30-4e71-b165-db821c642426.png)


## Step 6 Botões de ajuda e de abrir e fechar porta

Estas são algumas funcionalidades extras. Se acontecer algum problema, o usuário poderá pressionar o botão "0" e então o buzzer será acionado e a mensagem "Chamando ajuda" com um símbolo de alarme ligado aparecerão no display LCD; _auxa_ terá seu valor alterado para 1. Para desligar o alarme basta pressionar novamente a tecla "0" e o buzzer irá parar de tocar e o valor do _auxa_ irá para 0. 
![2021-07-31 (38)](https://user-images.githubusercontent.com/88052180/127775823-0efbf0af-c3dd-4e45-b7c8-2ddc0a92640c.png)
![2021-07-31 (39)](https://user-images.githubusercontent.com/88052180/127775906-825fbb2d-865e-4982-afde-c8c453e27e34.png)

Enquanto isso, se o _bitTst_ for realizado e a tecla " * " for pressionada, abrirá a porta, acendendo o relé e mostrando mensagem no display, com imagem, e se o _bitTst_ for realizado e a tecla " # " for clicada, a porta fechará, apagando o relé e mostrando nova mensagem também com imagem.
![2021-07-31 (40)](https://user-images.githubusercontent.com/88052180/127775965-9b859064-d811-435a-a9d6-c5faeacf1bfa.png)


## Conclusão

No início apresentei alguns problemas, inclusive de entendimento da matéria, devido ao fato de estarmos tendo aula à distáncia e também às peculiaridades do MPLAB e da placa utilizada. Porém, com o tempo e com as video-aulas dos professores Otávio e Rodrigo, pude aprender melhor e resolver as questões enfrentadas.

Assim, pude concluir meu projeto final, realizando todas as funções desejadas e criando um programa que, ao meu ver, se assemelha bastante ao funcionamento de um elevador real.


