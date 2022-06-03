/* Реализация функций */
#include "ConvertFunctions.h"
const std::vector < std::string > errors = {
	"Ошибка 0",
	"Ошибка 1: Введен неверный режим работы. Повторите ввод.",
	"Ошибка 2: Введена неправильная размерность графа A. Размерность должна быть в диапазоне от 3 до 99",
	"Ошибка 3: Введена неправильная размерность графа B. Размерность должна быть в диапазоне от 3 до 99",
	"Ошибка 4: Введена неправильная плотность генерируемых графов. Плотность должна быть в диапазоне от 0.1 до 1.0",
	"Ошибка 5: Введен неверный размер выборки - выборка должна состоять из 1-99 графов",
	"Ошибка 6",
	"Ошибка 7. Размерности графов должны быть в диапазоне от 3 до 99.\n",
	"Ошибка 8. Размерность переменной n больше или равна размерности n2. Повторите ввод.\n"
};
long double fact(int N)
{
	if (N < 0) // если пользователь ввел отрицательное число
		return 0; // возвращаем ноль
	if (N == 0) // если пользователь ввел ноль,
		return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
	else // Во всех остальных случаях
		return N * fact(N - 1); // делаем рекурсию.
}
bool isInputValid(int var, int leftBorder, int rightBorder, int errorNum)
{
	if (errorNum > errors.size())
	{
		MessageBox::Show("Wrong Error Num <debug error>");
		return false;
	}
	if (!((var >= leftBorder) && (var <= rightBorder)))
	{
		std::string buf = errors[errorNum];
		MessageBox::Show(Convert_string_to_String(buf));
		return false;
	}
	return true;
}
bool isInputValid(double var, double leftBorder, double rightBorder, int errorNum)
{
	if (errorNum > errors.size())
	{
		MessageBox::Show("Wrong Error Num <debug error>");
		return false;
	}
	if (!((var >= leftBorder) && (var <= rightBorder)))
	{
		std::string buf = errors[errorNum];
		MessageBox::Show(Convert_string_to_String(buf));
		return false;
	}
	return true;
}
std::string getVectorInt(std::vector<int> vec, std::string name = "")
{
	std::string ret = "";
	for (int i = 0; i < vec.size(); i++)
		ret = ret + std::to_string(vec[i]) + " ";
	return ret;
}

//конвертируем System::string^ в std::string
std::string& Convert_String_to_string(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}
//конвертируем std::string в System::string^
String^ Convert_string_to_String(std::string& os, String^ s) {
	s = gcnew System::String(os.c_str());

	return s;
}
//конвертируем System::string^ в std::string
std::string Convert_String_to_string(String^ s) {
	std::string os;
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}
//конвертируем std::string в System::string^
String^ Convert_string_to_String(std::string& os) {
	System::String^ s = gcnew System::String(os.c_str());

	return s;
}
//конвертируем char в System::string^
System::String^ Convert_char_to_String(char ch) {
	char* chr = new char();
	chr[0] = ch;
	System::String^ str;
	for (int i = 0; chr[i] != '\0'; i++)
		str += wchar_t(ch);
	return str;
}
//конвертируем System::string^ в char*
char* Convert_String_to_char(System::String^ string) {
	using namespace System::Runtime::InteropServices;
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}
//конвертируем char* в System::string^
System::String^ Convert_char_to_String(char* ch) {
	char* chr = new char();
	chr = ch;
	System::String^ str;
	for (int i = 0; chr[i] != '\0'; i++)
		str += wchar_t(ch[i]);
	return str;
}