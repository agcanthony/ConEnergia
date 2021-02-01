#include <iostream>
#include <locale.h>
#include <fstream>
#include <Windows.h>
using namespace std;

class Relogio{
	private:
		
		
	public:
		
		void cadastro(){
			cout<<"Calculadora de Consumo de ENERGIA: \n";
			cout<<"Informe o numero de serie do Relogio: \n";
			cin>>serie_rel;
		}
		void mostrarrel(){
			cout<<"Numero de serie: "<<serie_rel<<endl;
	
		}
	protected:
		double total, sub;
		float rel_cont_ant;
		float rel_cont_new ;
		string serie_rel;	
};
class Contador : public Relogio{		
	public:
		Relogio obj1;
		
		void calculo(){
			total;
			sub;
			rel_cont_ant;
			rel_cont_new;
		
			
			cout<<"Calcular Conta de luz\n";
			cout<<"Contador Do Relogio\n";
			cout<<"Informe Numero Anterior:\n";
			cin>>rel_cont_ant;
			cout<<"Informe Numero Atual:\n";
			cin>>rel_cont_new;
			
			sub=rel_cont_new - rel_cont_ant;
			total= sub*74/100;
			
		}
		
		void mostracont(){
			
		ofstream fout("impressao.txt");
			if(sub<=100)
				{
					cout<<"Bandeira Verde"<<endl;
					cout<<"Total de: "<<sub<<"KWH"<<endl;
					cout<<"Total A Pagar R$: "<<total<<endl;
					cout<<" | ICMS 12% |"<<" PIS 0,97% "<<"| CONFIS 4,51% |"<<endl;
					cout<<" | "<<total*12/100<<"   | "<<total*0.97/100<<"  |  "<<total*4.51/100<<"     |";

					fout<<"Bandeira Verde"<<endl;
					fout<<"Total de: "<<sub<<"KWH"<<endl;
					fout<<"Total A Pagar R$: "<<total<<endl;
					fout<<" | ICMS 12% |"<<" PIS 0,97% "<<"| CONFIS 4,51% |"<<endl;
					fout<<" | "<<total*12/100<<"   | "<<total*0.97/100<<"  |  "<<total*4.51/100<<"     |";
				}
			if(sub>=101 && sub<=150)
				{
					cout<<"Bandeira amarela"<<endl;
					cout<<"Total de: "<<sub<<"KWH"<<endl;
					cout<<"Total A Pagar R$: "<<total+3<<" - Acrescimo de R$: 3,00"<<endl;
					cout<<" | ICMS 12% |"<<" PIS 0,97% "<<"| CONFIS 4,51% |"<<endl;
					cout<<" | "<<total*12/100<<"   | "<<total*0.97/100<<"  |  "<<total*4.51/100<<"     |";
					
					fout<<"Bandeira amarela"<<endl;
					fout<<"Total de: "<<sub<<"KWH"<<endl;
					fout<<"Total A Pagar R$: "<<total+3<<" - Acrescimo de R$: 3,00"<<endl;
					fout<<" | ICMS 12% |"<<" PIS 0,97% "<<"| CONFIS 4,51% |"<<endl;
					fout<<" | "<<total*12/100<<"   | "<<total*0.97/100<<"  |  "<<total*4.51/100<<"     |";
				}
			if(sub>=151)
				{
					
					cout<<"Bandeira vermelha"<<endl;
					cout<<"Total de: "<<sub<<"KWH"<<endl;
					cout<<"Total A Pagar R$: "<<total+5<<" - Acrescimo de R$: 5,00"<<endl;
					cout<<" | ICMS 12% |"<<" PIS 0,97% "<<"| CONFIS 4,51% |"<<endl;
					cout<<" | "<<total*12/100<<"   | "<<total*0.97/100<<"  |  "<<total*4.51/100<<"     |";
					
					fout<<"Bandeira vermelha"<<endl;
					fout<<"Total de: "<<sub<<"KWH"<<endl;
					fout<<"Total A Pagar R$: "<<total+5<<"- Acrescimo de R$: 5,00"<<endl;
					fout<<" | ICMS 12% |"<<" PIS 0,97% "<<"| CONFIS 4,51% |"<<endl;
					fout<<" | "<<total*12/100<<"   | "<<total*0.97/100<<"  |  "<<total*4.51/100<<"     |";
				}	
						
			}
};
class imprimirarq:public Contador{
	public:
		
		ofstream file;
	void imprimir(){
		
    	system("notepad /p impressao.txt");
    	
	}	
};
class Documento:public Relogio{
	private:
	
	public:
		void doc(){
			cout<<"Em 2018, a tarifa de energia na CPFL Paulista foi reajustada pela revisão tarifária,\n uma correção de status que ocorre a cada 4 anos e faz uma revisão de todos os componentes \n que compõem o preço da energia. \n subiu meaning. A tarifa média é de 14,06% para grandes consumidores e 15,77% para \n consumidores residenciais e pequenos consumidores comerciais. \n O custo médio aumentado de 0,62 reais por KWh para 0,74 reais por KWh. \n Apesar do alto percentual de reajuste para 2018,\n uma avaliação do valor da taxa nos últimos 10 anos mostrou, se o reajuste da inflação (IGPM ou IPCA) foi anulado,\n o custo de energia seria ainda maior, o que leva a ANEEL a reafirmar o modelo atual \n de correção aplicado. Como resultado, temos de consultar com um esforço futuro \n os custos de acesso a uma conta de energia.\n";
			cout<<"\n\n\n Sistema criado SEM calculo de Taxas ou Bandeiras por Modificarem constantemente.";
		}
};

int main() {
	setlocale(LC_ALL,"Portuguese");
	Relogio obj1;
	Contador obj2;
	Documento obj3;
	imprimirarq obj4;
	int resp;
	char x;
		ofstream file;
	obj1.cadastro();

	do{
	
	system("cls");
	
	cout<<"Informe o setor de acesso: \n";
	cout<<"[1]- Calcular\n";
	cout<<"[2]- Imprimir\n";
	cout<<"[3]- Consultar Documentação\n";
	cin>>resp;
	switch(resp){
		case 1:
			obj2.calculo();
			obj1.mostrarrel();
			obj2.mostracont();
		break;
		case 2:
			obj4.imprimir();
		break;	
		case 3:
			obj3.doc();
		break;
	}
	cout<<"\n\n\nDeseja Retornar[s]-sim ou [n]-nao"<<endl;
	cin>>x;
	}while(x!='n');
	return 0;
}
