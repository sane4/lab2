#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//только тире и пробелы
bool isTirOnly(const string& s){
	for(int i = 0; i < s.size() -1; ++i){
		if(s[i] != '-' && s[i] != ' '){
			return false;
		}
	}
	return true;
}
				
//на разных строках
bool isDiffLines(const string& s){
	for(int i = 0; i < s.size() - 1; ++i){
		if(s[i] == '\n'){
			return true;
		}
	}
	return false;
}

int main(){
	setlocale(LC_ALL, "");
	int files;//количество файлов
	cout << "Введите количество файлов: ";
	cin >> files;
	string *names = new string[files];
	for(int i = 0; i < files; ++i){
		cout << "Введите название файла [" << i + 1 << "] = ";
		cin >> names[i];
	}
	for(int i = 0; i < files; ++i){
		try{
			cout << '\n' << names[i] << '\n';
			ifstream in(names[i]);
			string line;//предложение
			stringstream ss;//строковый поток
			int cnt = 0;
			while(getline(in, line, '.')){//считываем по предложению
				++cnt;
				bool ff = false, space = true;
				int i;

				for(i = 0; i < line.size(); ++i){
					
					if(line[i] == '-'){
						ff = true && space;
						break;
					}
					if(line[i] != ' '){
						 space = false;
					}
				
				}
				if(ff){
					ss << line << '\n';
					if(isDiffLines(line)){
					   	cnt = -2;
						break;
					}
				}
				if(isTirOnly(line)){
					cnt = -1;
					break;
				}
			}
			if(cnt == -1){
			    cout << "Имеется предложение только с одним тире";
			}
			else if(cnt == -2){
				cout << "Имеется предложение с тире в разных строках";
			}
			else if (cnt == 0) {
				cout << "Файла не существует, либо файл пустой";
			}

			
			else{
				cout << ss.str();
			}
			in.close();//закрываем файл
		}
		catch(...){
			cout << "Исключение";
		}
	}
	system("pause>>void");

}
