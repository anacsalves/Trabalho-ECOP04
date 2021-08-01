# Elevador

![2021-07-31 (28)](https://user-images.githubusercontent.com/88052180/127776245-de2dd116-b8da-4939-8857-45a7e2421716.png)


## Como usar

Após a inicialização do elevador, você terá as seguintes opções:

**Teclas de 1 a 5**: escolha de andar

**Tecla 0**: chama ajuda

**Tecla "*"**: abre a porta

**Tecla #**: fecha a porta

Como todo elevador, sua função principal é mudar de andar. Para isso você pode escolher o andar pelas teclas e a partir disso, ele irá "se movimentar" com o cooler e você poderá acompanha o andar atual pelos LEDs. Ele também simula a abertura e fechamento da porta, através do relé. Por fim, ele apresenta uma funcionalidade muito comum nos elevadores, a funçãode chamar ajuda, que é simulada pelo buzzer. Todas essas funções também são comunicadas pelo display LCD.


## Como usar o código

O principal método é utilizar o [MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide) com o compilador XC8, após isso é apenas baixar o arquivo compactado "trabalho" e importar tudo para o programa MPLab. Além disso, para poder executar e testar os códigos é necessário do [PICSimLab](https://github.com/lcgamboa/picsimlab). A placa utilizada é a PICGENIOS e o microcontrolador é o PI18F4520. Após isso vá na barra superior e clique em _Files_ -> _Load Hex_, o arquivo que será colocado está nesta pasta `trabalho.X\dist\default\production\trabalho.X.productions.hex`.


## Créditos

Projeto feito na Universidade Federal de Itajubá para as disciplinas de ECOP04 e ECOP14. Avaliação e supervisão dos professores Otávio Gomes e Rodrigo Almeida.
