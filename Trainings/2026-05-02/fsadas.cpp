#include <bits/stdc++.h>

using namespace std;

#define br '\n'

typedef tuple<string,int> strint;
string INPUT;
int N;

int readWS(int i)
{
    while(INPUT[i] == ' ' ||INPUT[i] == '\t' ||INPUT[i] == '\n' ) i++;
    return i;
}

bool isIN(int i)
{
    i = readWS(i);
    while(i < N && INPUT[i] != ' '){
        i++;
    }
    return (i+1 < N && INPUT[i+1] == '=');
}

bool isOUT(int i){
    i = readWS(i);
    if (!(i+5 < N)){
        return false;
    }
    //cout << "substr: " << " " << INPUT.substr(i,6) << endl;
    if (INPUT.substr(i,6) == "print("){
        return true;
    }
    return false;
}

bool isIO(int i)
{
    i = readWS(i);
    return (isIN(i) || isOUT(i));
}

bool isIF(int i)
{
    i = readWS(i);
    // heuristica good enough
    return (i < N - 1 && INPUT.substr(i,2) == "if");
}

bool isWH(int i)
{
    i = readWS(i);
    return (i+4 < N && INPUT.substr(i,5) == "while"); // while 
}

// <id> | <num> | <str> | <E> <op> <E>

strint E(int i)
{
    i = readWS(i);
    string e;
    if (INPUT[i] == '\'' || INPUT[i] == '"')
    {
        char delim = INPUT[i];
        e+= delim;
        i++;
        while(i < N && INPUT[i] != delim){
            e += INPUT[i];
            i++;
        }
        e+= delim;
        i++;
    }
    else {
        while(i < N && (INPUT[i] != ' ' && INPUT[i] != ')' && INPUT[i] != ':')){
            e += INPUT[i];
            i++;
        }
    }
    return strint(e,i);
}

strint Econd(int i)
{
    i = readWS(i);
    string e;
    while(i < N && INPUT[i] != ':'){
        // cout << "e: " << e << endl;
        // cout << "input[i]: " << INPUT[i] << endl;
        e += INPUT[i];
        i++;
    }
    // cout << "INPUT[I] FINAL: " << INPUT[i] << endl;
    // cout << "i: " << i << " N: " << N << endl;
    return strint(e,i);
}

int IN(int i)
{
    i = readWS(i);
    auto [e, j] = E(i);
    i = j;
    i += 10; // "= input()*", retorna primeiro caracter fora
    cout << "LEIA " << e << " ";
    return i;
}

int OUT(int i)
{
    i = readWS(i);
    i += 6; // "print("
    auto [e, j] = E(i);
    i = j;
    i++; // )
    cout << "APRESENTE " << e << " ";
    return i;
}

int WH(int i)
{
    i = readWS(i);
    i += 6; // "while "
    auto [e, j] = Econd(i);
    i = j;
    i++; // ':'
    cout << "ENQUANTO " << e << " ";
    if (isOUT(i)){
        return OUT(i);
    }
    else{
        return IN(i);
    }
}

int IF(int i)
{
    i = readWS(i);
    i += 3; // "if "
    auto [e, j] = Econd(i);
    i = j;
    i++; // ':'
    cout << "SE " << e << " ENTAO ";
    if (isOUT(i)){
        return OUT(i);
    }
    else{
        return IN(i);
    }
}

//   <P> ::= <IO> | <IF> | <WH>
//  <IF> ::= if <E>: <IO>
//  <WH> ::= while <E>: <IO>
//  <IO> ::= <IN> | <OUT>
//  <IN> ::= <id> = input()
// <OUT> ::= print(<E>)
//   <E> ::= <id> | <num> | <str> | 

// Para a versão em Português temos a seguinte gramática:

//   <P> ::= <IO> | <IF> | <WH>
//  <IF> ::= SE <E> ENTAO <IO>
//  <WH> ::= ENQUANTO <E> <IO>
//  <IO> ::= <IN> | <OUT>
//  <IN> ::= LEIA <id>
// <OUT> ::= APRESENTE <E>
//   <E> ::= <id> | <num> | <str> | <E> <op> <E>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    getline(cin,INPUT);
    string line2;
    if (getline(cin,line2)){
        string line;

        int sz = line2.size();
        int i = 0;
        while(line2[i] == ' ' || line2[i] == '\t' || line2[i] == '\n' && i < sz){
            i++;
        }
        line = line2.substr(i);

        //cout << "line: " << line << endl;

        INPUT += " " + line;
    }
    N = INPUT.size();

    //cout << "INPUT: " << INPUT << endl;
    
    if (isIF(0)){
        IF(0);
    }
    else if (isWH(0)){
        WH(0);
    }
    else {
        if (isOUT(0)){
            OUT(0);
        }
        else{
            IN(0);
        }
    }
    cout << br;
 
    return 0;
}