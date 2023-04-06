# Labs 4º Edição

<h2> Aplicação de Análise e Compressão de dados </h2>

<h3> Sobre o Programa </h3>

A aplicação Encoder recebe um ou mais arquivos de texto e comprime o dado utilizando o Algoritmo de Huffman. Uma outra aplicação, a Decoder, descomprime o arquivo criado pela Encoder, também utilizando o Algoritmo de Huffman e envia o dado descomprimido juntamente com outras informações (tamanho do dado e tempo de descompressão). Por fim, o Encoder gera um arquivo com o dado descomprimido, e imprime o dado no terminal, juntamente com outras informações (tamanho do arquivo original, tamanho do arquivo comprimido, razão de compressão e tempo de descompressão).

<h3> Representação Visual do Funcionamento da Aplicação </h3>

Um fluxograma com o funcionamento do código pode ser encontrado no link abaixo:

[Fluxograma do Projeto](https://miro.com/app/board/uXjVPybpEtg=/?share_link_id=715994620742) (Miro)

<h3> Sobre o Algoritmo de Huffman </h3>

O algoritmo de Huffman é amplamente utilizado para comprimir textos e outros tipos de arquivo em que a compressão deve ocorrer sem perda de informação.
Seu funcionamento consiste em avaliar todo o conteúdo do arquivo a ser comprimido e em seguida codificá-lo de forma que caracteres que aparecem com maior frequência sejam representados por um número menor de bits do que caracteres que aparecem com menor frequência. (No arquivo original, todos os caracteres são representados por 8 bits).
Para fazer a codificação, após percorrer todo o texto e registrar a frequência de cada caractere, é necessário construir uma Árvore de Huffman, uma árvore binária em que cada caractere ocupará uma folha, e sua posição na árvore dependerá da sua frequência no texto (quanto mais frequente, mais perto da raiz).

Abaixo um exemplo de uma Árvore de Huffman para um texto que possui incidência de 16 caracteres:

![exemplo de Huffman Tree para 16 caracteres](https://aquarchitect.github.io/swift-algorithm-club/Huffman%20Coding/Images/Tree.png "Exemplo Huffman Tree")

<br>

<h3> Setup do Programa </h3>

1. Clonar este repositório em seu repositório local:
        
        git clone git@github.com:42sp/42labs-selection-process-v4-renatainacio.git compressor_de_dados
2. Acessar o repositório do projeto:

        cd compressor_de_dados

3.  Compilar as aplicações:

        make
3. Executar o encoder colocando os arquivos que deseja comprimir separados por espaço como no exemplo abaixo:

        ./encoder arquivo1 arquivo2 arquivo2


<h1> Enunciado Completo do Desafio </h1>

## Desafio

O desafio consiste no desenvolvimento de uma aplicação de análise e compressão de dados. Essa aplicação utilizará o algoritmo de compressão Huffman e poderá receber múltiplos dados onde, uma vez que comprimido deve ser descomprimido e coletar informações pertinentes para a análise do processo e dado.

Para isso, você criará dois programas: `encoder` e `decoder`. O encoder receberá o dado a ser comprimido e exibirá suas informações vindas do decoder. Já, o decoder descomprimirá o dado e irá enviá-lo ao encoder com suas informações, onde será exibido. Os programas devem se comunicar utilizando *shared memory operations*.

A linguagem C será utilizada para o desenvolvimento e não há bibliotecas externas permitidas.

## É necessário

- Que existam dois programas `encoder` e `decoder` que se comuniquem via memória compartilhada.
- Que o `encoder` possa receber, no mínimo, múltiplos textos como dado e comprimi-lo. Caso mais de um texto seja enviado, devem ser comprimidos juntos, resultando em apenas um único dado.
- Que o algoritmo de Huffman seja implementando em sua totalidade e que o processo de compressão e descompressão ocorram utilizando-o.
-  Que o `decoder` possa descomprimir e enviar as seguintes informações ao `encoder`: dado descomprimido, quantidade de bits ou bytes totais, quantidade de bits ou bytes comprimidos e o tempo da operação de descompressão.
- O `encoder` exibir as informações recebidas pelo `decoder`.

### O que será avaliado

- Código bem escrito e limpo.
- A documentação do seu código.
- Ferramentas que foram utilizadas e por quê.
- Sua criatividade e capacidade de lidar com problemas diferentes.
- Alinhamento do seu projeto com a proposta.

### O mínimo necessário

- README.md com a documentação contendo informações do projeto.

### Bônus

Os itens a seguir não são obrigatórios, mas são funcionalidades que darão mais valor ao seu desafio.

- Compressão de múltiplos arquivos binários.
- Criptografia do dado comprimido, utilizando senha fornecida pelo usuário.
- Verificação de integridade do arquivo comprimido.
- Opção para escolher mais outro algoritmo de compressão a ser utilizado.
- Tempo de descompressão (`decoder`) abaixo da média dos candidatos.
- Cuidados especiais com otimização e padrões de código.
- Uso de ferramentas externas para planejamento nas etapas de desenvolvimento.

<sub><sup>[Importante](https://xkcd.com/1381/)</sup></sub>
