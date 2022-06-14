#include "FormAnalysis.h"

System::Void DotNet2::FormAnalysis::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

long double DotNet2::FormAnalysis::fact(int N)
{
	if (N < 0) // если пользователь ввел отрицательное число
		return 0; // возвращаем ноль
	if (N == 0) // если пользователь ввел ноль,
		return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
	else // Во всех остальных случаях
		return N * fact(N - 1); // делаем рекурсию.
}
void DotNet2::FormAnalysis::testInput()
{
	this->sampleGraphBig.clear();
	this->sampleGraphSmall.clear();
	std::vector<std::vector<int>> graphBig;
	std::vector<std::vector<int>> graphSmall;
	graphBig = {
		{ 0,0,1,1,1,1 },
		{ 0,0,0,0,1,1 },
		{ 1,0,0,0,1,0 },
		{ 1,0,0,0,0,1 },
		{ 1,1,1,0,0,1 },
		{ 1,1,0,1,1,0 } }; //big Graph
	graphSmall = {
		{ 0,1,1,0,0 },
		{ 1,0,1,0,1 },
		{ 1,1,0,1,1 },
		{ 0,0,1,0,1 },
		{ 0,1,1,1,0 } };
	this->sampleGraphBig.push_back(graphBig);
	this->sampleGraphSmall.push_back(graphSmall);
	graphBig = {
		{ 0,1,0,0,1 },
		{ 1,0,1,1,1 },
		{ 0,1,0,0,1 },
		{ 0,1,0,0,0 },
		{ 1,1,1,0,0 } };
	graphSmall = {
		{ 0,0,1,0 },
		{ 0,0,1,1 },
		{ 1,1,0,1 },
		{ 0,1,1,0 } };
	this->sampleGraphBig.push_back(graphBig);
	this->sampleGraphSmall.push_back(graphSmall);
	graphBig = {
		{ 0,1,0,0,0,0,1,0,0 },
		{ 1,0,1,0,0,0,1,0,1 },
		{ 0,1,0,1,1,0,0,1,0 },
		{ 0,0,1,0,0,1,1,0,1 },
		{ 0,0,1,0,0,1,1,1,0 },
		{ 0,0,0,1,1,0,1,0,0 },
		{ 1,0,0,1,1,1,0,0,0 },
		{ 0,0,1,0,1,0,0,0,0 },
		{ 0,1,0,1,0,0,0,0,0 } };
	graphSmall = {
		{ 0,1,1,0,0,0 },
		{ 1,0,0,0,0,0 },
		{ 1,0,0,1,1,0 },
		{ 0,0,1,0,0,1 },
		{ 0,0,1,0,0,1 },
		{ 0,0,0,1,1,0 } };
	this->sampleGraphBig.push_back(graphBig);
	this->sampleGraphSmall.push_back(graphSmall);
}
System::Void DotNet2::FormAnalysis::FormAnalysis_Load(System::Object^ sender, System::EventArgs^ e) {
	String^ x = this->sampleGraphBig.size().ToString();
	x = x + " " + this->sampleGraphSmall.size().ToString() + " " + isomorphsFoundGoal + " " + this->methodsEnableFlags->size().ToString();
	MessageBox::Show(x);

	//testInput();

	int sizeOfSample = this->sampleGraphBig.size();
	o_supervisor = new supervisor(*methodsEnableFlags, isomorphsFoundGoal, iterationLimit);
	o_supervisor->fillSolutionsContainers(this->sampleGraphSmall);
	//sizeOfSample = 1;
	for (int i = 0; i < sizeOfSample; i++)
	{
		int iterationCounter = 0;
		int bigSize = this->sampleGraphBig[i].size();
		int smallSize = this->sampleGraphSmall[i].size();

		std::vector<std::vector<int>> graphBig = this->sampleGraphBig[i];
		std::vector<std::vector<int>> graphSmall = this->sampleGraphSmall[i];

		PrintMatrixInDataGridView(this->dataGridView1, graphSmall);
		PrintMatrixInDataGridView(this->dataGridView6, graphBig);
		listBox1->Items->Add("Пара " + (i + 1));

		//o_supervisor.MetaoptimizationAll(graphBig, graphSmall);

		// 3. решение задачи методами
		o_supervisor->InitAll(smallSize, bigSize, isomorphsFoundGoal);
		while (!o_supervisor->IterationAll(graphBig, graphSmall)) {
			//Repaint(*o_supervisor, pairNumber);
		}

		o_supervisor->FindLocalStatsAll();
	}
	// 4. сбор глобальной статистики - результатов работы методов по выборке
	o_supervisor->FindGlobalStatsAll(sizeOfSample); //incl. DocAll
	Repaint(*o_supervisor, pairNumber);
}
System::Void DotNet2::FormAnalysis::PrintMatrixInDataGridView(System::Windows::Forms::DataGridView^ _dataGridView, std::vector<std::vector<int>>& matrix)
{
	_dataGridView->ColumnCount = matrix.size();
	_dataGridView->RowCount = matrix[0].size();

	//отображение выборки
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			_dataGridView->Rows[i]->Cells[j]->Value = matrix[i][j].ToString();
		}
	}

}
std::vector<int> DotNet2::FormAnalysis::getEmptyVector(int size)
{
	std::vector<int> graphString;
	for (int j = 0; j < size; j++)
	{
		graphString.push_back(0);
	}
	return graphString;
}
std::vector<std::vector<int> > DotNet2::FormAnalysis::getEmptyGraph(int size)
{
	std::vector<std::vector<int>> graph;

	for (int i = 0; i < size; i++)
	{
		graph.push_back(getEmptyVector(size));
	}
	return graph;
}
System::Void DotNet2::FormAnalysis::PrintMethodResults(supervisor& super, System::Windows::Forms::Label^ labelP,
	System::Windows::Forms::Label^ labelIters,
	System::Windows::Forms::DataGridView^ _dataGridView, int methodNumber)
{
	labelIters->Text = super.getIterationCounter(pairNumber, methodNumber).ToString();
	if (super.getFinishFlag(methodNumber) && super.getIsomorphP(pairNumber, methodNumber) != getEmptyVector(sampleGraphSmall[pairNumber].size()))
	{
		///отображение перестановки-изоморфа
		String^ strBuf;
		std::vector<int> isoP = super.getIsomorphP(pairNumber, methodNumber);
		for (int k = 0; k < isoP.size(); k++)
		{
			strBuf += isoP[k].ToString();
			strBuf += " ";
		}
		labelP->Text = strBuf;

		//отображение изоморфа
		std::vector<std::vector<int>> isoMatr = super.getIsomoph(pairNumber, methodNumber);
		PrintMatrixInDataGridView(_dataGridView, isoMatr);
	}
	else
	{
		_dataGridView->RowCount = 1;
		_dataGridView->ColumnCount = 0;
		labelP->Text = "No iso found";
	}
}
System::Void DotNet2::FormAnalysis::Repaint(supervisor& super, int graphPairIndex)
{
	//отрисовка числа итераций
	//отображение изоморфа, если он найден
	//отображение перестановки-решения, если она найдена
	int j = -1; // локальный индекс считающий только включенные методы
	for (int i = 0; i < this->methodsEnableFlags->size(); i++)
	{
		if ((*methodsEnableFlags)[i] == 1)
			j++;
		if (i == 0 && (*methodsEnableFlags)[i] == 1)
		{
			//Full
			PrintMethodResults(super, label3, label4, dataGridView2, j);
		}
		else if (i == 1 && (*methodsEnableFlags)[i] == 1)
		{
			//RandomMethod* rm = new RandomMethod();
			PrintMethodResults(super, label6, label7, dataGridView3, j);
		}
		else if (i == 2 && (*methodsEnableFlags)[i] == 1)
		{
			//GreedMethod
			PrintMethodResults(super, label9, label10, dataGridView4, j);
		}
		else if (i == 3 && (*methodsEnableFlags)[i] == 1)
		{
			//RW
			PrintMethodResults(super, label12, label13, dataGridView5, j);
		}
		else if (i == 4 && (*methodsEnableFlags)[i] == 1)
		{
			//SAMethod* sam = new SAMethod();

		}
	}


}
System::Void DotNet2::FormAnalysis::listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->listBox1->SelectedIndex < 0) return;
	pairNumber = this->listBox1->SelectedIndex;
	std::vector<std::vector<int>> graphBig = this->sampleGraphBig[pairNumber];
	PrintMatrixInDataGridView(this->dataGridView6, graphBig);
	std::vector<std::vector<int>> graphSmall = this->sampleGraphSmall[pairNumber];
	PrintMatrixInDataGridView(this->dataGridView1, graphSmall);
	Repaint(*o_supervisor, pairNumber);
}
System::Void DotNet2::FormAnalysis::button10_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ strBuf;
	for (int k = 0; k < (sampleGraphBig).size(); k++)
	{
		strBuf += k;
		strBuf += "\n";
		for (int i = 0; i < (sampleGraphBig)[k].size(); i++)
		{
			for (int j = 0; j < (sampleGraphBig)[k][i].size(); j++)
			{
				strBuf += (sampleGraphBig)[k][i][j].ToString();
			}
			strBuf += "\n";
		}
	}
	MessageBox::Show(strBuf);
}
System::Void DotNet2::FormAnalysis::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ strBuf;
	for (int k = 0; k < (sampleGraphSmall).size(); k++)
	{
		strBuf += k;
		strBuf += "\n";
		for (int i = 0; i < (sampleGraphSmall)[k].size(); i++)
		{
			for (int j = 0; j < (sampleGraphSmall)[k][i].size(); j++)
			{
				strBuf += (sampleGraphSmall)[k][i][j].ToString();
			}
			strBuf += "\n";
		}
	}
	MessageBox::Show(strBuf);
}
System::Void DotNet2::FormAnalysis::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	FormResults^ formResults = gcnew FormResults(*o_supervisor, *methodsEnableFlags);
	this->Hide();
	formResults->Show();
}