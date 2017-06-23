/*
Projeto e Análise de Algoritmos I
Programa: Células
*/

#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

bool celula(char *imagem, int posicao){
	return (imagem[posicao]=='#');
}

bool naoDescoberta(char *imagem, int l, int c,int w){
	int posicao=l*w+c;
	if(c==w-1){
		if(imagem[posicao+w]!='*'&&imagem[posicao-w]!='*'&&imagem[posicao-1]!='*')
			return 1;
	}
	if(c==0){
		if(imagem[posicao+w]!='*'&&imagem[posicao-w]!='*'&&imagem[posicao+1]!='*')
			return 1;
	}
	if(imagem[posicao+w]!='*'&&imagem[posicao-w]!='*'&&imagem[posicao-1]!='*'&&imagem[posicao+1]!='*')
		return 1;
	return 0;
}

int contagem(char *imagem, int h, int w, int l, int c, int &n){
	int posicao;
	for(int i=l;i<h;i++){
		for(int j=c;j<w;j++){
			posicao=i*w+j;
			if(celula(imagem,posicao)){
				if(naoDescoberta(imagem,i,j,w))
					n++;
				imagem[posicao]='*';
				contagem(imagem,h,w,l,c+1,n);
				contagem(imagem,h,w,l,c-1,n);
				contagem(imagem,h,w,l-1,c,n);
				contagem(imagem,h,w,l+1,c,n);
			}
		}
	}
	return n;
}

int main(int argc, char *argv[]){
	int w, h, k, n;
	std::ifstream arquivo;
	std::string linha;
	
	arquivo.open(argv[1],ios::in);

	cout<<"Imagens: ";
	getline(arquivo,linha);
	stringstream imagem(linha);
	imagem>>k;
	cout<<k;
	
	while(k!=0){
		cout<<"\nLargura da imagem: ";
		getline(arquivo,linha);
		stringstream largura(linha);
		largura>>w;
		cout<<w;
		cout<<"\nAltura da imagem: ";
		getline(arquivo,linha);
		stringstream altura(linha);
		altura>>h;
		cout<<h;
		
		char imagem[h*w];
		
		cout<<"\n\nImagem:\n";
		for(int i=0;i<h;i++){
			getline(arquivo,linha);
			for(int j=0;j<w;j++)
				imagem[(i*w)+j]=linha.at(j);
		}
		
		for(int i=0;i<h*w;i++){
			if(i%w==0)
				cout<<"\n";
			cout<<imagem[i];
		}
		
		n=0;
		cout<<"\n\nContagem: "<<contagem(imagem,h,w,0,0,n)<<endl;
		
		cout<<"\n\nSaida:\n";
		for(int i=0;i<h*w;i++){
			if(i%w==0)
				cout<<"\n";
			cout<<imagem[i];
		}
		cout<<"\n";
		
		k--;
	}
	
}
