É a probabilidade de um ponto estar na "coroa" exatamente do k-ésimo polígono.

Polígono 1 tem área 1, polígono 2 tem área $r$, polígono k tem área $r^{k-1}$
P(ponto cair dentro do polígono k) = $r^{k-1}$
P(ponto cair exatamente na coroa entre polígono k e k+1) = $r^{k-1} - r^k$
Se o ponto está nessa coroa, ele acertou exatamente k tipos de nuts.

Então:

$$E = \sum_{k=1}^{\infty} k \cdot \underbrace{(r^{k-1} - r^k)}_{\text{P(estar na k-ésima coroa)}}$$

Dá pra simplificar usando o truque de linearity of expectation também: em vez de somar por coroa, soma por polígono — um ponto no k-ésimo polígono "conta 1" para cada um dos k polígonos que o contém:

$$E = \sum_{k=1}^{\infty} P(\text{ponto dentro do k-ésimo}) = \sum_{k=1}^{\infty} r^{k-1} = \frac{1}{1-r}$$

Esse segundo jeito é mais direto.