#include "FormMeta.h"

System::Void DotNet2::FormMeta::FormMeta_Load(System::Object^ sender, System::EventArgs^ e) {
	super = new supervisor(*methodsEnableList, 1, iterationLimit);
	int index = 0;
	listBox1->Items->Clear();
	for (int i = 0; i < methodsEnableList->size(); i++)
	{
		if ((i > 2) && ((*methodsEnableList)[i] == 1))
		{

			listBox1->Items->Add(Convert_string_to_String(super->getMetaMethodName(index)));
			index++;
		}
	}
	this->textBox5->Text = Convert_string_to_String(std::to_string(super->getIterationLimit() + 1));
}
System::Void DotNet2::FormMeta::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	FormAnalysis^ formAnalysis = gcnew FormAnalysis(sampleGraphBig, sampleGraphSmall, methodsEnableList, iterationLimit, isomorphCount);
	this->Hide();
	formAnalysis->Show();
}
System::Void DotNet2::FormMeta::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//начать метаоптимизацию
	if (radioButton1->Checked)
		selectedParameterIndex = 0;
	else if (radioButton2->Checked)
		selectedParameterIndex = 1;
	else if (radioButton3->Checked)
		selectedParameterIndex = 2;
	super->setIterationLimit(std::stoi(Convert_String_to_string(this->textBox5->Text)));
	std::vector<double> sigs, probability;
	double param_val_init, param_val_step;
	std::vector<std::vector<std::vector<int>> > sampleGraphBigMeta;
	std::vector<std::vector<std::vector<int>> > sampleGraphSmallMeta;
	for (int i = 0; i < metaSizeOfSample; i++)
	{
		sampleGraphBigMeta.push_back(sampleGraphBig[i]);
		sampleGraphSmallMeta.push_back(sampleGraphSmall[i]);
	}
	
	sigs = super->Metaoptimization(selectedMethodIndex, sampleGraphBigMeta, sampleGraphSmallMeta, param_val_init, param_val_step, probability, selectedParameterIndex);
	String^ seriesName = Convert_string_to_String(super->getMetaMethodName(selectedMethodIndex) + " " + std::to_string(selectedParameterIndex));
	chart1->Series->Clear();
	chart1->Series->Add(seriesName);
	seriesName = Convert_string_to_String(super->getMetaMethodName(selectedMethodIndex) + " probability");
	chart1->Series->Add(seriesName);
	int maxSigIndex = 0;
	double maxSig = 0;
	for (int i = 0; i < sigs.size(); i++)
	{
		chart1->Series[0]->Points->AddXY(param_val_init + i * param_val_step, std::round(sigs[i]*100)/100);
		chart1->Series[1]->Points->AddXY(param_val_init + i * param_val_step, std::round(probability[i]*100)/100);
		if (sigs[i] > maxSig)
		{
			maxSig = sigs[i];
			maxSigIndex = i;
		}
	}
	double param_optimal = param_val_init + maxSigIndex * param_val_step;

	label2->Text = "Оптимальное значение : " + param_optimal;//+param(maxSig)
	chart1->Series[0]->ChartType = DataVisualization::Charting::SeriesChartType::Line;
	chart1->Series[1]->ChartType = DataVisualization::Charting::SeriesChartType::Line;
	chart1->Series[0]->Color = Color::Navy;
	chart1->Series[1]->Color = Color::Red;
	chart1->ChartAreas[0]->Axes[0]->Minimum = 0;
	chart1->ChartAreas[0]->Axes[0]->Maximum = param_val_init + (sigs.size()) * param_val_step;
	chart1->ChartAreas[0]->Axes[1]->Minimum = 0;
	chart1->ChartAreas[0]->Axes[1]->Maximum = 1.5;
	if (selectedParameterIndex == 0)
		textBox1->Text = Convert_string_to_String(std::to_string(super->getParameterInMethod(selectedMethodIndex, selectedParameterIndex)));
	else if (selectedParameterIndex == 1)
		textBox2->Text = Convert_string_to_String(std::to_string(super->getParameterInMethod(selectedMethodIndex, selectedParameterIndex)));
}
System::Void DotNet2::FormMeta::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//задать параметры
	int methodNumber = selectedMethodIndex;
	std::vector<double> parameterList;
	if (textBox1->Text != "")
		parameterList.push_back(std::stod(Convert_String_to_string(textBox1->Text)));
	if (textBox2->Text != "")
		parameterList.push_back(std::stod(Convert_String_to_string(textBox2->Text)));
	if (textBox3->Text != "")
		parameterList.push_back(std::stod(Convert_String_to_string(textBox3->Text)));

	for (int parameterNumber = 0; parameterNumber < parameterList.size(); parameterNumber++)
	{
		super->setParameterInMethod(methodNumber, parameterNumber, parameterList[parameterNumber]);
	}


}
System::Void DotNet2::FormMeta::listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->listBox1->SelectedIndex < 0) return;
	selectedMethodIndex = this->listBox1->SelectedIndex;
	if ((*parametersCounts)[selectedMethodIndex] == 1)
	{
		label5->Enabled = false;
		label6->Enabled = false;
		textBox2->Enabled = false;
		textBox3->Enabled = false;
		label5->Visible = false;
		label6->Visible = false;
		textBox2->Visible = false;
		textBox3->Visible = false;

	}
	else if ((*parametersCounts)[selectedMethodIndex] == 2)
	{
		label5->Enabled = true;
		label6->Enabled = false;
		textBox2->Enabled = true;
		textBox3->Enabled = false;
		label5->Visible = true;
		label6->Visible = false;
		textBox2->Visible = true;
		textBox3->Visible = false;
	}
	else if ((*parametersCounts)[selectedMethodIndex] == 3)
	{
		label5->Enabled = true;
		label6->Enabled = true;
		textBox2->Enabled = true;
		textBox3->Enabled = true;
		label5->Visible = true;
		label6->Visible = true;
		textBox2->Visible = true;
		textBox3->Visible = true;
	}
	if (selectedMethodIndex == 0)
	{
		label4->Text = "D=";
		label5->Text = "None";
		label6->Text = "None";
		textBox1->Clear();
		textBox2->Clear();
		textBox3->Clear();
		radioButton1->Text = "D";
		radioButton2->Text = "None";
		radioButton3->Text = "None";
		radioButton2->Enabled = false;
		radioButton3->Enabled = false;
		radioButton1->Checked = false;

	}
	else if (selectedMethodIndex == 1)
	{
		label4->Text = "Tstart=";
		label5->Text = "Gamma=";
		label6->Text = "None";
		textBox1->Clear();
		textBox2->Clear();
		textBox3->Clear();
		radioButton1->Text = "Tstart";
		radioButton2->Text = "Gamma";
		radioButton3->Text = "None";
		radioButton2->Enabled = true;
		radioButton3->Enabled = false;
		radioButton1->Checked = false;
		radioButton2->Checked = false;
	}
}
System::Void DotNet2::FormMeta::textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	metaSizeOfSample = std::stoi(Convert_String_to_string(textBox4->Text));
}
System::Void DotNet2::FormMeta::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (super != nullptr) {}
}
System::Void DotNet2::FormMeta::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}