#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	string line;//�����������
	stringstream ss;//��������� �����
	while(getline(in, line)){//��������� �� �����������
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
		}
	}
	cout << ss.str();
	in.close();//��������� ����										   
	system("pause>>void");

}