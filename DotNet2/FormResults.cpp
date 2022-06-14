#include "FormResults.h"

System::Void DotNet2::FormResults::FormResults_Load(System::Object^ sender, System::EventArgs^ e) {
	int methodCount = super.getMethodCount();
	double averageQ;
	double prob, disp, sigma, dQ;
	bool findFlag = false;
	int pointer_ = 0;
	dataGridView1->ColumnCount = 6;
	dataGridView1->RowCount = methodCount;
	//dataGridView1->Columns[0]->HeaderText = 
	String^ newCell = "Метод";
	dataGridView1->Columns[0]->HeaderText = newCell;
	newCell = "Средневыборочное качество решения";
	dataGridView1->Columns[1]->HeaderText = newCell;
	newCell = "Вероятность нахождения решения";
	dataGridView1->Columns[2]->HeaderText = newCell;
	newCell = "Средневыборочная дисперсия";
	dataGridView1->Columns[3]->HeaderText = newCell;
	newCell = "Среднеквадратичное отклонение";
	dataGridView1->Columns[4]->HeaderText = newCell;
	newCell = "Ширина доверительного интервала (дельта Q)";
	dataGridView1->Columns[5]->HeaderText = newCell;

	for (int i = 0; i < methodCount; i++)
	{
		//method 0 = первая 1 в methodEnableFlags
		for (int j = pointer_; j < methodsEnableFlags.size(); j++)
		{
			pointer_++;
			if (methodsEnableFlags[j] == 1)
			{
				if (j == 0)
					dataGridView1->Rows[i]->Cells[0]->Value = "Полный перебор ";
				else if (j == 1)
					dataGridView1->Rows[i]->Cells[0]->Value = "Случайный перебор ";
				else if (j == 2)
					dataGridView1->Rows[i]->Cells[0]->Value = "Жадный алгоритм ";
				else if (j == 3)
					dataGridView1->Rows[i]->Cells[0]->Value = "Случайный-взвешенный перебор ";
				else if (j == 4)
					dataGridView1->Rows[i]->Cells[0]->Value = "Метод имитации отжига ";
				else if (j == 5)
					dataGridView1->Rows[i]->Cells[0]->Value = "!Полный перебор ";
				else if (j == 6)
					dataGridView1->Rows[i]->Cells[0]->Value = "!Полный перебор ";

				findFlag = true;
				break;
			}
		}
		findFlag = false;
		super.getMethodStats(i, averageQ, prob, disp, sigma, dQ);
		dataGridView1->Rows[i]->Cells[1]->Value = doubleToString(averageQ, 1);
		dataGridView1->Rows[i]->Cells[2]->Value = doubleToString(prob, 5);
		dataGridView1->Rows[i]->Cells[3]->Value = doubleToString(disp, 5);
		dataGridView1->Rows[i]->Cells[4]->Value = doubleToString(sigma, 5);
		dataGridView1->Rows[i]->Cells[5]->Value = doubleToString(dQ, 5);

	}
	super.ClearingTotalAll();
}
String^ DotNet2::FormResults::doubleToString(double src, int precision)
{
	std::string newStr, newStr2;
	newStr = std::to_string(src);
	int precision_counter = 0;
	bool start_counter = false;
	for (int i = 0; i < newStr.size(); i++)
	{
		if (newStr[i] == '.')
			start_counter = true;
		if (start_counter)
			precision_counter++;
		newStr2 += newStr[i];
		if (precision_counter > precision)
			break;
	}
	String^ newStr3 = Convert_string_to_String(newStr2);
	return newStr3;
}
System::Void DotNet2::FormResults::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (true)
		;
}