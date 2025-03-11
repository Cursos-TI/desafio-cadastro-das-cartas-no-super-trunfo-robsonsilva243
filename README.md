# ⚠️ Importante!!!
Criamos um novo link para o primeiro desafio porque o link original apresentou problemas. Quem já completou o desafio pode continuar usando o link original para enviar seu repositório. Se você ainda não começou o desafio, utilize o novo link.

# Super Trunfo - Comparação de Cartas de Países

Este projeto é uma implementação do jogo Super Trunfo, onde os jogadores podem comparar cartas de países com base em diferentes atributos. O programa permite que o usuário escolha dois atributos para comparação e determina qual carta vence com base na soma dos valores desses atributos.

## Funcionalidades

- Cadastro de cartas de países com atributos como população, área, PIB e densidade populacional.
- Comparação de duas cartas com base em dois atributos escolhidos pelo usuário.
- Cálculo da soma dos atributos para determinar a carta vencedora.
- Tratamento de empates.
- Menus dinâmicos que garantem que o usuário não escolha o mesmo atributo duas vezes.

## Tecnologias Utilizadas

- **Linguagem de Programação**: C
- **Compilador**: GCC (GNU Compiler Collection)
- **Sistema Operacional**: O código é compatível com sistemas operacionais que suportam GCC, como Linux, macOS e Windows (com MinGW ou Cygwin).

## Estrutura do Código

O código é organizado em funções que realizam as seguintes tarefas:

- **`calcular_densidade`**: Calcula a densidade populacional de uma carta com base na população e na área.
- **`comparar_atributos`**: Compara os dois atributos escolhidos, calcula a soma dos valores e determina o vencedor ou se houve empate.
- **`main`**: Inicializa as cartas, calcula a densidade e apresenta menus para o usuário escolher os atributos a serem comparados.

## Como Usar

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/seu_usuario/super-trunfo.git
   cd super-trunfo
Compile o código: Use um compilador C, como gcc, para compilar o código:

bash
Run
Copy code
gcc -o super_trunfo super_trunfo.c
Execute o programa:

bash
Run
Copy code
./super_trunfo
Siga as instruções na tela para escolher os atributos e comparar as cartas.

Exemplo de Uso
Ao executar o programa, você verá um menu que permite escolher os atributos para comparação. Após escolher os atributos, o programa exibirá os resultados da comparação, incluindo os valores de cada atributo, a soma dos atributos e qual carta venceu.

Exemplo de Saída
Após executar o programa e escolher os atributos, a saída pode ser semelhante a:

Run
Copy code
Escolha o primeiro atributo para comparar:
1. População
2. Área
3. PIB
4. Densidade Populacional
Digite sua opção: 1

Escolha o segundo atributo para comparar (não pode ser o mesmo que o primeiro):
1. População
2. Área
3. PIB
4. Densidade Populacional
Digite sua opção: 3

Comparação de cartas:
Carta 1 - Brasil:
Atributo 1 (1): 213000000.00
Atributo 2 (3): 2100000000.00
Carta 2 - Argentina:
Atributo 1 (1): 45000000.00
Atributo 2 (3): 450000000.00
Soma dos Atributos:
Carta 1 - Brasil: 2310000000.00
Carta 2 - Argentina: 495000000.00
Resultado: Carta 1 (Brasil) venceu!

Melhorias Futuras
Adicionar mais atributos para comparação, como IDH (Índice de Desenvolvimento Humano) e taxa de desemprego.
Implementar uma interface gráfica para tornar o jogo mais interativo.
Permitir que os usuários cadastrem suas próprias cartas de países.
Adicionar um sistema de pontuação para acompanhar o desempenho dos jogadores.

Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir um issue ou enviar um pull request.

Contato
Para mais informações, entre em contato com robsonsilva243@gmail.com
Run
Copy code

### Finalizando
