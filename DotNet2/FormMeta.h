#pragma once
#include "supervisor.h"
#include "FormAnalysis.h"
namespace DotNet2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormMeta
	/// </summary>
	public ref class FormMeta : public System::Windows::Forms::Form
	{
	public:
		FormMeta(std::vector<std::vector<std::vector<int>> >& _sampleGraphBig, 
			std::vector<std::vector<std::vector<int>> >& _sampleGraphSmall, 
			std::vector<int>* _methodsFlags, int _iterationLimit, int _isomorphCount):
			sampleGraphBig(_sampleGraphBig), sampleGraphSmall(_sampleGraphSmall)
		{
			InitializeComponent();
			selectedMethodIndex = 0;
			selectedParameterIndex = 0;
			iterationLimit = _iterationLimit;
			methodsEnableList = _methodsFlags;
			isomorphCount = _isomorphCount;
			parametersCounts = new std::vector<int>({ 1,2,4,4 });
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormMeta()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label7;

	private:
		System::ComponentModel::Container ^components;
		std::vector<std::vector<std::vector<int>> >& sampleGraphBig;
		std::vector<std::vector<std::vector<int>> >& sampleGraphSmall;
		int selectedMethodIndex;
		int selectedParameterIndex;
		std::vector<int>* methodsEnableList;
		int iterationLimit;
		int isomorphCount;
		supervisor* super;
		std::vector<int>* parametersCounts;
		int metaSizeOfSample;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::Button^ button3;
		



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^ title6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Метод:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(511, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(138, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Оптимальное значение: \?";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(30, 278);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(178, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Настроечные параметры метода:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(52, 301);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"T";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(191, 301);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Gamma";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(317, 301);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(42, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"param3";
			this->label6->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(45, 317);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(35, 20);
			this->textBox1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(194, 317);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(35, 20);
			this->textBox2->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(320, 317);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(35, 20);
			this->textBox3->TabIndex = 8;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(45, 372);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(370, 46);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Выбор параметра для оптимизации";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(280, 19);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(60, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"param3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Visible = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(149, 19);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(60, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"param2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(10, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(60, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"param1";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(548, 375);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 59);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Начать метаоптимизацию";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormMeta::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(548, 106);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 59);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Поиск";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FormMeta::button2_Click);
			// 
			// chart1
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			this->chart1->Location = System::Drawing::Point(136, 32);
			this->chart1->Name = L"chart1";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Color = System::Drawing::Color::Blue;
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(358, 228);
			this->chart1->TabIndex = 12;
			this->chart1->Text = L"chart1";
			title5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			title5->Name = L"OY";
			title5->Position->Auto = false;
			title5->Position->Height = 85;
			title5->Position->X = 3;
			title5->Position->Y = 4;
			title5->Text = L"Сигнатура";
			title5->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
			title6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			title6->Name = L"OX";
			title6->Position->Auto = false;
			title6->Position->Width = 30;
			title6->Position->X = 39;
			title6->Position->Y = 97;
			title6->Text = L"Параметр";
			this->chart1->Titles->Add(title5);
			this->chart1->Titles->Add(title6);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Случайный Взв. П.", L"Имитация Отж.", L"Пчелиной Кол.",
					L"Муравьиной Кол.", L"Генетический Алг."
			});
			this->listBox1->Location = System::Drawing::Point(12, 39);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(103, 108);
			this->listBox1->TabIndex = 13;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMeta::listBox1_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(231, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(154, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Результат метаоптимизации";
			this->label7->Visible = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(548, 297);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 59);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Задать параметры";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FormMeta::button3_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(459, 414);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(35, 20);
			this->textBox4->TabIndex = 16;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &FormMeta::textBox4_TextChanged);
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(421, 369);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(123, 39);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Размер выборки для метаоптимизации";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(548, 217);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 59);
			this->button4->TabIndex = 18;
			this->button4->Text = L"Debug";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &FormMeta::button4_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->выходToolStripMenuItem,
					this->оПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(670, 24);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMeta::выходToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			// 
			// FormMeta
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 446);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormMeta";
			this->Text = L"Поиск изоморфного подграфа - метаоптимизация";
			this->Load += gcnew System::EventHandler(this, &FormMeta::FormMeta_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FormMeta_Load(System::Object^ sender, System::EventArgs^ e) {
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
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		FormAnalysis^ formAnalysis = gcnew FormAnalysis(sampleGraphBig, sampleGraphSmall, methodsEnableList, isomorphCount, iterationLimit);
		this->Hide();
		formAnalysis->Show();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//начать метаоптимизацию
		if (radioButton1->Checked)
			selectedParameterIndex = 0;
		else if (radioButton2->Checked)
			selectedParameterIndex = 1;
		else if (radioButton3->Checked)
			selectedParameterIndex = 2;
		std::vector<double> sigs;
		double param_val_init, param_val_step;
		std::vector<std::vector<std::vector<int>> > sampleGraphBigMeta;
		std::vector<std::vector<std::vector<int>> > sampleGraphSmallMeta;
		for (int i = 0; i < metaSizeOfSample; i++)
		{
			sampleGraphBigMeta.push_back(sampleGraphBig[i]);
			sampleGraphSmallMeta.push_back(sampleGraphSmall[i]);
		}
		sigs = super->Metaoptimization(selectedMethodIndex, sampleGraphBigMeta, sampleGraphSmallMeta, param_val_init, param_val_step, selectedParameterIndex);
		String^ seriesName = Convert_string_to_String(super->getMetaMethodName(selectedMethodIndex) + " " + std::to_string(selectedParameterIndex));
		chart1->Series->Clear();
		chart1->Series->Add(seriesName);
		int maxSigIndex = 0;
		double maxSig = 0;
		for (int i = 0; i < sigs.size(); i++)
		{
			chart1->Series[0]->Points->AddXY(param_val_init + i * param_val_step, sigs[i]);
			if (sigs[i] > maxSig)
			{
				maxSig = sigs[i];
				maxSigIndex = i;
			}
		}
		double param_optimal = param_val_init + maxSigIndex * param_val_step;

		label2->Text = "Оптимальное значение : " + param_optimal;//+param(maxSig)
		chart1->Series[0]->ChartType = DataVisualization::Charting::SeriesChartType::Line;
		chart1->Series[0]->Color = Color::Navy;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
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
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
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
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		metaSizeOfSample += std::stoi(Convert_String_to_string(textBox4->Text));
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (super != nullptr) {}
	}
	private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
};
}
