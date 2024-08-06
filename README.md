# Base Defense - Projeto Final LP1

Um [Shoot'em-up](https://pt.wikipedia.org/wiki/Shoot_%27em_up) escrito em C++ usando SFML Graphics. Desenvolvido como projeto final da disciplina de Linguagem de Programação 1.

## Dependências
- SFML v.2.6.1
- GCC
- GNU Make
- Git

## Para Compilar

1. Clone o repositório
````
git clone https://github.com/lucasarruda12/lp1-base-defense.git
````

2. Execute o makefile com make
````
cd lp1-base-defense && make
````
> Se o SFML está instalado em um local específico, passe o caminho como argumento para o makefile `make SFML={SEU_CAMINHO_PERSONALIZADO}`


## Para jogar

Dentro do diretório do jogo, use `make run` para iniciar uma partida

## Especificação do Trabalho

- [x] O herói tem vida limitada a 100

- [x] O herói tem uma quantidade limitada de projéteis

- [x] O herói pode se mover em qualquer direção controlado pelo clique do mouse em um local “destino”. Quando se clicar com o botão direito do mouse em um ponto do mapa, o herói tem esse local setado como “destino” e deve caminhar nessa direção. 

- [x] O herói pode sair livremente da base.

- [x] O herói pode disparar projéteis pressionando a tecla “Q”. O projétil deve ter um alcance máximo e deve ter a direção apontando para o cursor do mouse no momento do disparo.

- [x] Os inimigos surgem nas bordas do mapa aleatoriamente em um intervalo fixo de tempo (que pode ir diminuindo para aumentar a dificuldade do jogo)

- [x] O inimigo caminha em direção ao centro da base, ou ao herói (livre escolha do programador)

- [x] O inimigo dispara os projéteis sempre em direção ao herói.

- [ ] Os projéteis podem colidir com o herói, outro inimigo, ou com a base.

- [x] A base deve resistir até um número limitado de tiros, podendo regenerar sua estrutura com o tempo

- [ ] Quando abatido, o inimigo deixa no mapa uma quantidade aleatória limitada de projéteis que pode ser coletada pelo herói se o mesmo passar sobre o item ou esse item desaparece após um determinado tempo caso o herói não o colete.

- [ ] O jogo deve finalizar se a base conseguir ser protegida por um determinado período de tempo ou se ela for destruída.
