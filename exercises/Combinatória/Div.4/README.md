# LOG DO CONTEST DE COMBINATÓRIA DIV.4

### A. Ski Resort
|| Pensei a questão como se fosse uma P.A. de passo 1. A resposta é a soma para  cada grupo que eu consigo montar, sendo que um grupo é um subarray contínuo em que todas as temperaturas são aceitas. Para pegar a resposta para cada grupo, eu descobri a resposta como se k = 1 e subtrai pela resposta começando de size-k+2, desse jeito, eu desconsidero as possibilidade que tem k < que o que eu quero|| 
|| Tomei alguns W.A. de besta por causa por causa de ll na soma da P.A..  É sempre bom lembrar de guardar a soma da P.A. em ll.||

### B. Pasha and Stick
|| Montei uma fórmula O(1) para a questão. Se for ímpar, não tem solução. Se for par, divide por 2 para achar o meio e tira 2, por que, no pior caso, começa com  1 1 e n/2-1 n/2-1. Dessa valor, você tira 1 para desconsiderar o caso que tem 4  n/4 e divide por 2 denovo para desconsiderar que a a b b == b b a a||

### C. Combinatorics Homework
|| Nessa questão, a primeira coisa que pensei foi no limite superior. Só existe resposta se a + b + c - 3 for pelo menos m, visto que dá pra fazer a-1 pares com a letra a, b-1 pares com a letra b e c-1 pares com a letra c. Isso sózinho ainda não é suficiente para passar a questão, tem que pensar,  também, no limite pro outro lado, porque a questão fala que tem que ser  EXATAMENTE m pares. Então, se você pegar a letra com mais ocorrências e for emparelhando as outras entre elas impedindo de formar pares, você tem que o mínimo de pares que forma é (assuma c >= b >= b) c - (b + a + 1), logo, m deve ser maior igual a essa fórmula. ||

### D. Counting Orders
|| Sabendo para cada posição de B quantos elementos em A são maiores que ele, é só fazer um produto e a questão tá pronta. Dessa forma, você pode sortar A e fazer busca binária pra achar o índice do upperbound e subtrair isso do total de elementos, assim, você chega na quantidade de elementos maiores que cada posição de b. Depois disso, é só sortar o array com as respostas disso e, a partir do menor, a resposta começa em 1 e a cada passo você multiplica por arr[i]-i, é tipo aquele principio dos quadradinhos e possibilidades, que você tirando 1 a  mais a cada passo. Só isso com o MOD direitinho já passa a questão ||

### E. AND 0, Sum Big
|| Essa questão só tem um texto chato pra assustar, mas, se você pensar nos num em binário, a melhor possibiidade é que para um bit K, tenham n-1 bits 1 e 1 bit 0 . Sendo assim, o que você tem que fazer é permutar esse bit 0 pra cada uma das n posições. Em outras palavras:

CADA K BIT 0 PODE ESTAR EM N POSIÇÕES 
N*N*N*N...*N (K vezes) 
N^K

Ou seja, um fast exponentiation (do python mesmo) já passa ||

### F. Forming Triangles
|| Pra mim, essa foi a questão mais chatinha do contest. O pulo do gato dela é perceber que, se os lados do triangulo são 2^i, então o que o realmente importa é a grandeza de cada lado. Sabendo que, pela desigualdade triangular, a < b + c etc , para satisfazer todas as três desigualdades, obrigatoriamente dois valores tem que ter a mesma grandeza e o outro tem que ter a grandez menor ou igual a ela. Sendo assim, a questão vira contar quantos elementos no array são <= a K para cada k. Pra fazer isso é fácil, só sortar o array e usar o próprio indice do for na iteração ao contráiro pelo array como marcador, ou seja, i já vai naturalmente ser quantos elementos são menores iguais à K.

A partir disso, pra conseguir o valor da questão, é só fazer uma P.A., partindo do número de elementos estritamente menores até o número de elementos menores iguais, isso na combinatória chega no valor que você quer calcular, porq basicamente ele tá permutando os iguais na segunda posição e permutando os menores ou iguais na terceira posição.

Enfim, pra saber de forma rápida quantos são menores, você pode usar um map para guardar quantos são iguais, então, a quantidade de menores vai ser i-map[arr[i]]. Daí, só ir pra resposta.

OBs. Lembrar de só somar quando tiver pelo menos um igual (dá pra olhar pelo próprio mapa que tu já criou) e diminuir um do mapa toda vez que você passar por um valor, pq, dali pra frente, aquele valor não pode ser mais ser usado, todas as permutações com ele já tão calculadas.
OBS2. Lembrar que, como você tá somando várias P.A. provavelmente a reposta estoura um int, então faz isso tudo com ll. ||

### G. Chocolate
|| Essa questão é bem divertida. Basicamente, o pulo do gato é pensar que os 0  que vem antes do primeiro 1 e os que vem depois do ultimo 1 são desconsiderados. Além disso, para os 0 que estão entre 1s formam grupos. Cada grupo tem tamanho número de zeros + 1. A resposta é só multiplicar o tamanho desses grupos, que é equivalente a colocar uma barra antes do grupo ou depois de algum zero do grupo. ||

### H. Ice Cream Balls
|| Como o n é muito grande, a gente tá procurando uma solução LOG para o problema. Como dá pra calcular em O(1) se um valor é suficiente ou não, (n tomado 2), podemos pensar em busca binária na resposta. Se você achar o lower bound e somar a ele uma bola repetida pra cada bola que
faltou, você chega na resposta.
O único problema são os limites da busca binária, por que, como o N vai até  10^18 e a sua fórmula de evaluação tem um produto (aproximadamente n^2), se você usar 10^18 como limite você pode tomar um overflow que vai gerar um pico errado na sua função, que, deixando de ser monotônica, não vai funcionar para a busca binária. A minha solução pra isso foi usar 1e9 como limite da busca binária, porque 1e9^2 == 10^18, então mesmo se chegar na borda, não estoura. Eu não  chegar a provar que a solução tem que estar de fato entre 0 e 1e9, mas considerando que o produto daria overflow de outro jeito, foi o que me pareceu mais lógico. ||

### I. Battling with Numbers

|| A chave dessa questão é saber que:

LCM => máximo dos expoentes dos primos. 
GCD => mínimo dos expoentes dos primos. 

Sabendo disso, se o expoente do LCM for menor que o do GCD, não tem resposta. Se o expoente for igual, a resposta é multiplicada por 1, pois só existe uma possibilidade: p e q tem expoente igual.
Se o expoente do LCM for maior que o do GCD, então a resposta é multiplicada por
2, pois p pode ter o expoente maior ou o menor. 

Dessa forma, é só fazer um map com as frequências dos primos em X e Y e um set com todos os primos e iterar no set verificando as frequências de p em X e Y. 

Eu otimizei somando um para cada  vez que freqX > freqY e depois rodei um fexpll em (2,answ).||

### J. AND Sequences
|| Sabendo que a & b <= min(a,b), o primeiro e último elemento do array de permutações tem que obrigatoriamente ser o menor elemento do array. Além disso, como o & de todo mundo tem que ser igual ao primeiro e ao último, por que a primeira é codição é v1 = v2 & ... & vn e a última condição é vc1 & v2 & ...& vn-1 = vn, todos os elementos tem que ter 1 em todas as posições que o menor elemento, isto é, pra cada elemento e, e & min = min. Sabendo de todas as condições você só tem que encontrar o mínimo, ver se o mínimo se repete pelo menos uma vez e verificar essa condição pra todo mundo. Depois disso, a resposta é n-2 (o array sem as duas bordas que já estão definidas) fatorial, porq são todas as permutações do meio. Além disso, só tem que tomar cuidado que se o mínimo tiver mais que duas ocorrências, tem que multiplicar por 2 * número de ocorrência tomado 2, que são as permutações das possíveis bordas. ||