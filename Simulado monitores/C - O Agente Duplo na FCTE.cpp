/*
A FCTE (Força Central de Táticas de Espionagem) declarou estado de emergência! A divisão de contra-inteligência descobriu que existe um Agente Duplo infiltrado na organização, repassando segredos para o inimigo.

A agência possui N agentes operantes, numerados de 1 a N. Para encontrar o traidor, os analistas examinaram os fluxos de “confiança” (compartilhamento de informações sensíveis) entre os agentes.

O perfil psicológico do Agente Duplo revela dois comportamentos padrão de quem está apenas fingindo lealdade:

Paranoia do Traidor: O Agente Duplo não confia em nenhum outro agente da FCTE (ele não envia seus relatórios verdadeiros para ninguém dentro da agência, apenas para o inimigo externo).
Manipulação Perfeita: O Agente Duplo enganou a todos; portanto, todos os outros agentes da FCTE confiam nele (enviam seus relatórios para ele, achando que ele é um oficial leal).
Você recebeu a lista completa de quem confia em quem. Sua missão é identificar o número identificador do Agente Duplo.

Se ninguém se encaixar nesse perfil exato (ou se houver múltiplos suspeitos inconsistentes), retorne -1, indicando que a contra-inteligência falhou em isolar o alvo.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX { 1000 };

using ii = pair<int, int>;

int find_suspect( vector<int>& in_degree, vector<int>& out_degree, int N ) {
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == N - 1 && out_degree[i] == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    vector<int> in_degree(N + 1, 0);
    vector<int> out_degree(N + 1, 0);

    for (int i = 0; i < T; ++i) {
        int u, v;
        cin >> u >> v;
        out_degree[u]++;
        in_degree[v]++;
    }   

    int suspect = find_suspect(in_degree, out_degree, N);
    cout << suspect << '\n';

    
    return 0;
}