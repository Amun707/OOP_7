#include <iostream>
#include <string>

//static - относительно элементов класса
//в стаических методах нельзя пользоваться и обращаться к нестатическим элементам

class SequencesGenerator {
public:
	void Moo()const{}
	static void mo1(){}
	//позволяет создавать вызовы метода без создания объекта класса
	static int NextNum() {
		static int n{};

		//Moo(); - нет доступа тк нет указателя на себя
		mo1();
		return SequencesGenerator::n++;
	}

private:
	static int n;//переместили переменную в глобальную память программы
	//неконстантные статические поля нельзя использовать без инициализации
	//и их определение должно происходить вне класса

	//константные статические поля допустимо определять в теле класса

	
};

//определение статических полей всегда выносим в файлы кода
int SequencesGenerator::n{ 10 };


//такая функция будет запрещена для вызова в других кодовых файлах программы
static int NumSequense() {
	static int n{};//переместили переменную в глобальнуюпамять программы
	return n++;
}

void CatDemo();

int main() {
	system("chcp 1251>nul");

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << NumSequense() << '\n';
	}

	//SequencesGenerator obj;
	for (size_t i = 0; i < 5; i++)
	{
		std::cout <<SequencesGenerator::NextNum() << '\n';
	}

	CatDemo();

	return 0;
}

//нужно создать класс который без создания объектов мог бы сообщать
//своё название, данный класс сделать на примере животного(кошка)
//включить в класс методы которые бы пользовались статическим методом для формирования сообщений на экране

class Cat {
public:

	static void Name() {
		std::cout << name;
	}

	void Say()const {
		Name();
		std::cout << "Няшечка)\n";
	}

	void Feed(std::string feed)const {
		Name();
		std::cout << " Кушает \n"<<feed<<'\n';
	}

private:
	static std::string name;//объявление
};

 std::string Cat::name{ " Cat " };//определение и установка

 void CatDemo() {
	 std::cout << "У нас есть -> ";
	 Cat::Name();
	 std::cout << '\n';
	 Cat cat;//создали объект класса
	 cat.Feed(" мясо ");
	 cat.Say();
 }