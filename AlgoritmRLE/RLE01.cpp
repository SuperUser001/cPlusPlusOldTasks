/*Задачи:
1.	Написать функции чтения и записи данных в двоичный файл.
2.	Реализовать алгоритм поиска префикса в байтовом массиве.
3.	Реализовать алгоритм кодирования данных посредствам RLE кода.
4.	Предложить и реализовать алгоритм декодирования RLE кода.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#define map_size 256

char* read(const char* fname);
void writer(const char * fwrname);
int prefix(char * buf);
void code(char * buf, int prefix);
using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");
	const char* fname = "labe3.txt";
	char* buf = read(fname); //содержимое для анализа	
	int pref = prefix(buf);
	cout << pref << endl;
	code(buf, pref);
	system("pause");
	return 0;
}

void code(char * buf, int prefix){
	//кодирование
	std::ofstream file_compr("COMPRESSED_TEXT.txt");
	int sizing_l = 0;
	int str_len = strlen(buf);
	for (int i = 0; i < str_len; i++) {
		if (buf[i] != buf[i + 1]) {
			sizing_l++;
		}
	}
	int *repeating = new int[sizing_l]; //кол-во повторений
	char * lettering = new char[sizing_l]; //буква, повторяющаяся
	int j = 0; int kol = 1;

	for (int i = 0; i < str_len; i++) {
		if (buf[i] != buf[i + 1]) {
			repeating[j] = kol; lettering[j] = buf[i]; j++; kol = 0;
		}
		kol++;
	}

	int counter_one = 0;
	for (int j = 0; j < sizing_l; j++){
		if (repeating[j] <= 2) { file_compr << lettering[j] << ' '; counter_one++; }
		else { // hex << (int)
			file_compr << dec << (char)prefix << repeating[j] << lettering[j] << ' ';
		}
		cout << dec << (char)prefix << repeating[j] << lettering[j] << ' ';
	}
	double compression = 0;
	compression = 100.0*(((sizing_l - counter_one) * 3 + counter_one) / (double)str_len);
	cout << endl << " Достигнутая степень сжатия " << dec << compression << "%." << endl;

	//декодирование
	std::ofstream file_dec("DECOMPRESSED_TEXT.txt");
	for (int j = 0; j < sizing_l; j++){
		if (repeating[j] <= 2) { file_dec << lettering[j]; }
		else { // hex << (int)
			for (int i = 0; i < repeating[j]; i++) {
				file_dec << lettering[j];
				cout << lettering[j];
			}
		}
	}
	cout << endl;
}

/*
void write(const char * fwrname, char * bufwrite) {
	const char* fwrname = "labe3_writing.txt";
	FILE *mf = fopen(fwrname, "wb"); //rb+ открывает для чтения и записи
	//определяем разрмер файла
	fseek(mf, 0, SEEK_SET); //устанавливаем позицию в начало файла
	fwrite(bufwrite, sizeof(char), sizeof(bufwrite), mf); //считываем с буффера в файл
	fclose(mf);
}
*/

//ф-ия к заданию 2.1.1.
char* read(const char * fname) {
	FILE *mf = fopen(fname, "rb"); //rb
	//определяем разрмер файла
	long  lSize = 0;
	fseek(mf, +2, SEEK_END);// устанавливаем позицию в конец файла
	lSize = ftell(mf); //получаем размер в байтах
	fseek(mf, 0, SEEK_SET); //устанавливаем позицию в начало файла
	char * buffer = (char*)malloc(sizeof(char) *lSize); //выделяем память для хранения содержимого файла
	memset(buffer, 0, lSize);
	fread(buffer, sizeof(char), lSize, mf); //считываем файл в буффер
	puts(buffer);
	fclose(mf);
	//содержимое файла теперь в буфере
	return buffer;
}

//нахождение префикса - первый с конца аски реже встречающийся
int prefix(char * buf) {
	int map[map_size] = { 0 };
	int str_len = strlen(buf);
	int i = 0;
	//приведение типов
	for (i = 0; i < str_len; i++) {
		map[(unsigned char)buf[i]]++;
	}
	for (i = 0; i < map_size; i++) {
		if (map[i]) printf("'%c' => %d\n", i, map[i]);
	}
	for (i = map_size - 1 ; i > 0 ; i--) {
		if (!map[i]) {
			return i; exit;
		};
	}
}
