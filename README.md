# CG-Final-Project
O projeto precisa ter:
1) objetos distintos; OK
2) múltiplos materiais; -Diego OK
3) múltiplas fontes de luz (pontual, spot, direcional, ambiente); -Marcus -Josue -Diego
4) sombra;
5) cluster para aceleração do ray casting;
6) demonstrar o uso das matrizes de transformação na composição do cenário (escala ok, translação ok, rotação -Diego, cisalhamento -Josue, reflexão ok);
7) capacidade de "fotografar" o cenário de qualquer posição; -Marcus

A pontuação será baseada no cumprimento dos seguintes requisitos:
1) Objetos compondo o cenário (pelo menos um de cada): Cubo, Esfera, Cone, Cilindro, malha;
2) Materiais dos objetos: usar pelo menos dois materiais distintos;
3) Transformações para montagem do cenário: Translação, Escala, Rotação, Cisalhamento, Reflexão (Espelho);
4) Transformações de câmera: Mudar a posição do fotógrafo e os parâmetros da câmera;
5) Fontes luminosas: Pontual, Direcional, Spot e Ambiente;
6) Projeções: Perspectiva e Ortográfica;
7) Aceleração do Ray Casting: Hierarquia de Clusters;
8) Mudança do campo de visão: Alterar tamanho da janela no plano bloqueador (Plano de projeção) mantendo a distância d fixa ou Fixar o tamanho da janela e aumentar ou diminuir o valor de d;
9) Pontos extras:
     - Implementação de picking;
     - Criatividade e complexidade do cenário.

linux:
sudo apt install make freeglut3 libglew-dev libglfw3

Windows:
mingw32-make.exe