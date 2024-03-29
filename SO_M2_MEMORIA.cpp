
#include"stdafx.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>
#include<iostream>
using namespace std;


#define MEMORIA 1024 // Tamanho do Vetor = MEMORIA RAM DE 1MB


int comeco() {
	int  opcao;

	cout << " GERENCIAMENTO DE MEMORIA" << endl;
	cout << "1-Preenchimento automático" << endl;
	cout << "2- Preenchimento manual" << endl;
	cout << "3- Sair" << endl;
	cout << "Sua escolha:";
	
	do {
		cin >> opcao;
		if (opcao != 1) while (getchar() != '\n');
	} while (opcao != 1);
	
	return opcao;
	
}


int* preencheLacunaAutomatico(int*vetor, int*tam) {
	int i;
	vetor = new int(MEMORIA);
	if (vetor == NULL) {
		cout << "Espaco nao esta alocado" << endl;
		return NULL;
	}
	int aux[MEMORIA];
	for (int j = 0;j < MEMORIA;j++)//USAR RAND AQUI DPS
		aux[j]=rand()%100+1;

	*tam = MEMORIA;
	for (i = 0;i < MEMORIA;i++)
		vetor[i] = aux[i];
	return vetor;
}

int* preencheRequisicaoAutomatico(int *vetor, int *tam) {
	
	vetor = new int(3);
	if (vetor == NULL) {
		cout << "este esoaco nao esta alocado" << endl;
		return NULL;
	}
	int aux[3] = { 3,5,10 };
	*tam = 3;
	for (int i = 0;i < 3;i++)
		vetor[i] = aux[i];
	return vetor;
}

int* preencheLacunaManual(int *vetor, int*tam) {
	int qtd, teste=0;
	cout << "Numero de lacunas: ";
	cin >> qtd;

	vetor = new int(qtd);
	if (vetor = NULL) {
		cout << "nao alocado";
		return NULL;
	}
	*tam = qtd;
	for (int i = 0;i < qtd;i++) {
		do {
			cout << "Lacuna: ", i + 1;
			vetor[i] = teste;
			if (teste != 1)
				cout << "erro, tente novamente";
			while (getchar() != '\n');
		} while (teste != 1);
		
	}
	return vetor;
}


int* preencheRequisicaoManual(int *vetor, int*tam) {
	int qtd,teste;
	cout << "numero de requisicoes:";
	cin >> qtd;

	vetor = new int(qtd);
	if (vetor == NULL) {
		cout << "espaco nao esta alocado" << endl;
		return NULL;
	}
	*tam = qtd;
	for (int i = 0;i < qtd;i++){
		do {
			cout << "Requisicao:", i + 1;
			teste = vetor[i];
			if (teste != 1)
				cout << "erro, tente novamente";
			while (getchar() != '\n');
		} while (teste != 1);

	}
	return vetor;

}
int bestFit(int*lacunas, int *requisicoes, int qtdLac, int qtdReq) {
	int menor;

	for (int i = 0;i < qtdLac;i++)
		cout << lacunas[i];
	for (int i = 0;i < qtdReq;i++) {
		menor = 0;
		for (int j = 0;j < qtdLac;j++) {
			if ((lacunas[j] - requisicoes[i]) >= 0) {
				menor = j;
				break;
			}
		}


		for (int j=0; j < qtdLac;j++) {
			if (lacunas[j] >= requisicoes[i] && lacunas[j] < lacunas[menor])
				menor = j;
		}
		if (lacunas[menor] >= requisicoes[i]) {
			lacunas[menor] -= requisicoes[i];

			for (int k = 0;k < qtdLac;k++) {
				if (k == menor) {
					cout << lacunas[k];
				}
				else
					cout << lacunas[k];
			}
		}
		else
			cout << "a requisicao nao foi atendida:  "<<requisicoes[i];

	}
	return 0;
}

int worstFit(int*lacunas, int*requisicoes, int qtdLac, int qtdReq) {
	int maior;
	for (int i = 0;i < qtdLac;i++) {
		cout << lacunas[i] << endl;
	}

	for (int i = 0;i < qtdReq;i++) {
		maior = 0;
		for (int j = 0;j < qtdLac;j++) {
			if (lacunas[j] > lacunas[maior])
				maior = j;
		}
		if (lacunas[maior] >= requisicoes[i]) {
			lacunas[maior] -= requisicoes[i];
			for (int k = 0;k < qtdLac;k++) {
				if (k == maior) {
					cout << lacunas[k];
				}
				else
					cout << lacunas[k];
			}
		}
		else
			cout << "a requisicao nao foi atendida: "<<requisicoes[i];
	}
	return 0;
}

int imprime(int *vetorLacuna, int *vetorRequisicao, int qtdLac, int qtdReq) {
	
	for (int i = 0; i < qtdLac; i++) {
		cout<< vetorLacuna[i];	//LACUNAS
	}
	for (int i= 0; i < qtdReq; i++) {
		cout<< vetorRequisicao[i];
	}
	cout << endl;
	return 0;
}


int main (){
	int i, teste = 0;
	int *lacunas = nullptr;
		int *requisicao = nullptr;
		int opcao, qtdLac, qtdReq;
	
	do {
		opcao = comeco();

		switch (opcao) {
		case 1:
			lacunas = preencheLacunaAutomatico(lacunas, &qtdLac);
			requisicao = preencheRequisicaoAutomatico(requisicao, &qtdReq);
			break;

		case 2:
			lacunas = preencheLacunaManual(lacunas, &qtdLac);
			requisicao = preencheRequisicaoManual(requisicao, &qtdReq);
			break;

		case 3:
			return 0;
			break;
		default:
			cout << "opcao invalida" << endl;

		}
		cout << "Escolha um dos metodos:" << endl;
		cout << "1- Best Fit" << endl;
		cout << "2-Worst Fit" << endl;
		do
		{
			cin >> opcao;
			if (opcao != 1)
				cout << "erro! Tente novamente";
		} while (getchar()!='\n');
		//csl
		switch (opcao)
		{
		case 1:
			bestFit(lacunas, requisicao, qtdLac, qtdReq);
			break;
		case 2:
			worstFit(lacunas, requisicao, qtdLac, qtdReq);
		default:
			cout << "opcao invalida";
			break;
		}
	} while (opcao == 1);
}