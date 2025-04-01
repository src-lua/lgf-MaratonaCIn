# LOG DO CONTEST DE COMBINATÓRIA DIV.3

### A. Running for Gold
|| Se tiver uma resposta, a função check, que verifica se a >= b para pelo menos 3 maratonas, é true para todos os casos. Portanto, Se eu passar essa função linearmente do começo ao fim do array, eu chego em um candidato de vencedor, porquê eu tenho certeza que, o valor que ficou salvo depois disso é pelo menos superior à todo mundo na frente dele. Além disso, eu sei que ele é o melhor candidato a vencedor, porq se tivesse alguém pra traz que fosse candidato a vencedor e ganhasse dele, ele ganharia dele. Então, pra trás, só podem ter pessoas que com certeza não são vencedores, mas, podem tirar o posto de vencedor dele. Dessa forma, é só passar denovo no array até ele, verificando se ele é mesmo o vencedor. Além disso, só tem que tomar cuidado com um caso onde tem dois vencedores, porque, em nenhum momento ele fala que Rij é exclusivo, isto é que Ria != Rib, por isso, o caso onde tem um atleta (1,1,1,2,2) e outro atleta (2,2,1,1,1) é, teoricamente possível, então, na hora de verificar se de alguém ganha do vencedor, tem verificar ser quem ganhou do vencedor também perde pro vencedor, por que, se for esse o caso, os dois são vencedores, aí, pode printar qualquer coisa, então, você mantém o seu cadidato à melhor vencedor.

Possíveis otimizações:
 - Como você já tem certeza que, do vecedor pra frente tá tudo safe, pode parar a verificação no índice do vencedor;
 - Assim que você achar que ganha do candidato à vecedor, já é garantido que não tem respota, então, pode dar break na verificação. ||



### D. Two Arrays
|| Essa questão parece muito complicada, mas ela é só questão de interpretar direito os dados e conectar eles.

Sabendo que Ai <= Bi, então An <= Bn.

Sabendo que B é não crescente, então Bi >= Bi+1  =>  bn <= bn-1 <= bn-2 <= ... <= b1

Além disso, como A é não decrescente, então A1 <= A2 <= B2 <= ... <= An.

Juntando isso tudo, você forma:

A1 <= A2 <= A3 <= ... <= An <= Bn <+ Bn-1 <= Bn-2 <= ... <= B2 <= B1

Ou seja, você simplificou a questão inteira pra fazer um array só de tamanho 2m e esse array precisa ser não decresente.
Sendo assim, é só aplicar combinação com repetição:

Combinação com repetição de n tomado k = (n+k-1)! / (k!(n-1)!)

Logo, Crep(n, 2m) = (n+2m-1)! / (2m!(n-1)!)
