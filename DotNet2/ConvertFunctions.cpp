/* ���������� ������� */
#include "ConvertFunctions.h"
const std::vector < std::string > errors = {
	"������ 0",
	"������ 1: ������ �������� ����� ������. ��������� ����.",
	"������ 2: ������� ������������ ����������� ����� A. ����������� ������ ���� � ��������� �� 3 �� 99",
	"������ 3: ������� ������������ ����������� ����� B. ����������� ������ ���� � ��������� �� 3 �� 99",
	"������ 4: ������� ������������ ��������� ������������ ������. ��������� ������ ���� � ��������� �� 0.1 �� 1.0",
	"������ 5: ������ �������� ������ ������� - ������� ������ �������� �� 1-99 ������",
	"������ 6",
	"������ 7. ����������� ������ ������ ���� � ��������� �� 3 �� 99.\n",
	"������ 8. ����������� ���������� n ������ ��� ����� ����������� n2. ��������� ����.\n"
};
long double fact(int N)
{
	if (N < 0) // ���� ������������ ���� ������������� �����
		return 0; // ���������� ����
	if (N == 0) // ���� ������������ ���� ����,
		return 1; // ���������� ��������� �� ���� - �� �����������, �� ��� 1 =)
	else // �� ���� ��������� �������
		return N * fact(N - 1); // ������ ��������.
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

//������������ System::string^ � std::string
std::string& Convert_String_to_string(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}
//������������ std::string � System::string^
String^ Convert_string_to_String(std::string& os, String^ s) {
	s = gcnew System::String(os.c_str());

	return s;
}
//������������ System::string^ � std::string
std::string Convert_String_to_string(String^ s) {
	std::string os;
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}
//������������ std::string � System::string^
String^ Convert_string_to_String(std::string& os) {
	System::String^ s = gcnew System::String(os.c_str());

	return s;
}
//������������ char � System::string^
System::String^ Convert_char_to_String(char ch) {
	char* chr = new char();
	chr[0] = ch;
	System::String^ str;
	for (int i = 0; chr[i] != '\0'; i++)
		str += wchar_t(ch);
	return str;
}
//������������ System::string^ � char*
char* Convert_String_to_char(System::String^ string) {
	using namespace System::Runtime::InteropServices;
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}
//������������ char* � System::string^
System::String^ Convert_char_to_String(char* ch) {
	char* chr = new char();
	chr = ch;
	System::String^ str;
	for (int i = 0; chr[i] != '\0'; i++)
		str += wchar_t(ch[i]);
	return str;
}