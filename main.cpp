#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h>

using namespace std;



class Money{
	public:
	bool p_m_money;			//true -p, false -m
	string type;
	int sum;
	
	Money() {
		p_m_money=false;
		type="";
		sum=0;
	}
	
	Money (bool _p_m_money,string _type, int _sum){
		p_m_money=_p_m_money;
		type=_type;
		sum=_sum;
	}
}; 

class Functional{
	public:
		Functional(){
        	cout << "Введите ваше имя" << endl;
        	getline(cin,name);
        	filename=name+".txt";
        	ifstream fin(filename.c_str());
        	if (!fin.is_open()) {
				ofstream fout(filename.c_str());
				balance=0;
				fout.close();
				fin.close();
			}else{
				string buff="";
				getline(fin, buff, '\n');
              	int i=0;
              	balance=0;
              	balance=atoi(&buff[0]);
				while (!fin.eof()){
					getline(fin, buff, '\n');
					i=0;
					Money mn;
			        int space=0;
			        while(buff[i]!=';'){
				    	if (buff[i]==' '){
							space++;
				           	i++;
						}
						if (space==0){
							if(buff[i]=='p')
                        		mn.p_m_money=true;
		       		    	else 
								mn.p_m_money=false;
						}
						if (space==1)
							mn.type+=buff[i];
						if (space==2){
							mn.sum=mn.sum*10+to_int(buff[i]);
						}	
						i++;
					}
					bool duplicate=false;
					for(int i=0; i<types.size(); i++){
						if(mn.type==types[i])
							duplicate=true;
					}
					if(!duplicate)
						types.push_back(mn.type);
					money.push_back(mn);
				}
				fin.close();
			}
    	}
        int to_int(char c){
        	switch (c){
        		case '1':
        			return 1;
        			break;
        		case '2':
        			return 2;
        			break;
				case '3':
        			return 3;
        			break;
				case '4':
        			return 4;
        			break;
				case '5':
        			return 5;
        			break;
				case '6':
        			return 6;
        			break;
				case '7':
        			return 7;
        			break;
				case '8':
        			return 8;
        			break;
				case '9':
        			return 9;
        			break;
				case '0':
        			return 0;
        			break;	
			}
		}
          
        void change_balance(){
        system("cls");
        cout << "Введите ваш текущий баланс" << endl;
        cin >> balance;
        }

        
        void plus_balance(){
        	system("cls");
        	cout << "Выбрать старый источник дохода или добавить новый?" << endl;
        	cout <<"1.Выбрать старый" << endl;
			cout <<"2.Добавить новый" << endl;
			cout << "0.Отмена" << endl;
			string control="";
			cin >> control;
			system("cls");
			if(control=="1"){
				for(int i=0; i<types.size(); i++)
					cout << i+1 << "." << types[i] << endl;
				cin >> control;
				int point=0;
				for(int i=0; i<control.size(); i++)
					point=point*10+to_int(control[i]);
				system("cls");
				cout << types[point-1] << endl;
				cout << "Введите сумму, которую вы получили" << endl;
				int _sum;
				cin >> _sum;
				add_new(true, types[point-1], _sum);
				balance+=_sum;
			}else{
				if(control=="2"){
					system("cls");
					cout << "Введите название нового типа" << endl;
					cin >> control;
					types.push_back(control);
					cout << "Введите сумму, которую вы получили" << endl;
					int _sum;
					cin >> _sum;
					add_new(true, control, _sum);
					balance+=_sum;
				}else{
					return;
				}
			}
		}
	
		void minus_balance(){
			system("cls");
        	cout << "Выбрать старые расходы или добавить новые?" << endl;
        	cout <<"1.Выбрать старый" << endl;
			cout <<"2.Добавить новый" << endl;
			cout << "0.Отмена" << endl;
			string control="";
			cin >> control;
			system("cls");
			if(control=="1"){
				for(int i=0; i<types.size(); i++)
					cout << i+1 << "." << types[i] << endl;
				cin >> control;
				int point=0;
				for(int i=0; i<control.size(); i++)
					point=point*10+to_int(control[i]);
				system("cls");
				cout << types[point-1] << endl;
				cout << "Введите сумму, которую вы потратили" << endl;
				int _sum;
				cin >> _sum;
				add_new(false, types[point-1], _sum);
				balance-=_sum;
			}else{
				if(control=="2"){
					system("cls");
					cout << "Введите название нового типа" << endl;
					cin >> control;
					types.push_back(control);
					cout << "Введите сумму, которую вы потратили" << endl;
					int _sum;
					cin >> _sum;
					add_new(false, control, _sum);
					balance-=_sum;
				}else{
					return;
				}
			}
		}

        
        void stats(){
        	system("cls");
			for (int i=0; i<types.size(); i++){
				int total=0;
				for(int z=0; z<money.size(); z++){
					if(types[i]==money[z].type)
						if(money[i].p_m_money)
							total+=money[i].sum;
						else
							total-=money[i].sum;
				}
				if(total<0)
					cout << "На " << types[i] << " было потрачено " << abs(total) << endl;
				else
					cout << "С " << types[i] << " было получено " << total << endl;
			}
			system("pause");
		}
        
        void show_history(){
        	system("cls");
        	for(int i=0; i<money.size(); i++){
        		if(money[i].p_m_money)
        			cout << "Получено ";
        		else
        			cout << "Потрачено ";
        		cout << money[i].sum << "р на " << money[i].type << endl;
			}
			system("pause");
		}
          
        void add_new(bool _p_m_money, string _type, int _sum){
        	Money mn(_p_m_money, _type, _sum);
        	money.push_back(mn);
        }

        int get_balance(){
            return(balance);
        }

        string get_name(){
            return(name);
        }
   
        ~Functional(){
            ofstream fout(filename.c_str());
			fout << balance << ';';
            for(int i=0; i<money.size(); i++){
              	fout << '\n';
                if(money[i].p_m_money)
                    fout << "p ";
                else
                   	fout << "m ";
               	fout << money[i].type << ' ' << money[i].sum << ';';
            }
			fout.close();
        }
	private:
    	int balance;
    	vector<Money> money;
    	string name;
    	string filename;
    	vector<string> types;
};

int main () {
	char control;
	Functional func;
	do{
		cout << "Здравствуйте " << func.get_name() << endl;
		cout << "Текущий баланс: " << func.get_balance() << endl;
		cout << "Выберите дальнейшее действие:" << endl;
		cout << "1.Изменить баланс" << endl;
		cout << "2.Доходы" << endl;
		cout << "3.Расходы" << endl;
		cout << "4.Узнать статистику" << endl;
		cout << "5.Показать историю" << endl;
		cout << "0.Выход" << endl;
		cin >> control;
		switch (control){
			case '1':
				func.change_balance();
				break;
			case '2':
				func.plus_balance();
				break;
			case '3':
				func.minus_balance();
				break;	
			case '4':
				func.stats();
				break;
			case '5':
				func.show_history();
				break;
			case '0':
				return 0;
				break;
		}
		system("cls");
	}while(control!='0');
}