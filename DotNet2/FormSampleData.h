#include "FormMeta.h"
#include "FormAnalysis.h"
#include "ConvertFunctions.h"
#include <string>
#pragma once

namespace DotNet2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class FormSampleData : public System::Windows::Forms::Form
	{
	public:
		FormSampleData(void)
		{
			InitializeComponent();
			customerInEdit = nullptr;
			customerInEdit2 = nullptr;
			sampleGraphBig = new std::vector<std::vector<std::vector<int>> >();
			sampleGraphSmall = new std::vector<std::vector<std::vector<int>> >();
			graphBig = new std::vector<std::vector<int>>();
			graphSmall = new std::vector<std::vector<int>>();
			methodsEnableList = new std::vector<int>();
			density = 0.;
		}

	protected:
		~FormSampleData()
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
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::ListBox^ listBox1;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::Button^ button3;
		private: System::Windows::Forms::Button^ button4;
		private: System::Windows::Forms::Button^ button5;
		private: System::Windows::Forms::Button^ button6;
		private: System::Windows::Forms::Button^ button7;
		private: System::Windows::Forms::Button^ button8;
		private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::TextBox^ textBox2;
		private: System::Windows::Forms::TextBox^ textBox3;
		private: System::Windows::Forms::DataGridView^ dataGridView1;
		private: System::Windows::Forms::DataGridView^ dataGridView2;
		private: System::Windows::Forms::Label^ label8;
		private: System::Windows::Forms::TextBox^ textBox4;
		private: System::Windows::Forms::Label^ label9;
		private: System::Windows::Forms::TextBox^ textBox5;
		private: System::Windows::Forms::Button^ button9;
		private: System::Windows::Forms::Button^ button10;

		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
		private: System::Windows::Forms::Button^ button11;
		private: System::Windows::Forms::Button^ button12;
		private: System::Windows::Forms::Button^ button13;
		private: System::Windows::Forms::Button^ button14;
		private: System::Windows::Forms::Button^ button15;
		private: System::Windows::Forms::MenuStrip^ menuStrip1;
		private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
		private: System::Windows::Forms::TextBox^ textBox6;
		private: System::Windows::Forms::Label^ label10;




	private:
	
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		std::vector<std::vector<std::vector<int>> >* sampleGraphBig;
		std::vector<std::vector<std::vector<int>> >* sampleGraphSmall;
		std::vector<std::vector<int>>* graphBig;
		std::vector<std::vector<int>>* graphSmall;
		int selectedGraphPair = 0;
		int isomorphCount = 0;
		int rowInEdit = -1;
		int rowInEdit2 = -1;
		std::vector<int>* customerInEdit;
		std::vector<int>* customerInEdit2;
		std::vector<int>* methodsEnableList;
		double density;
		int iterationLimit;
	

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выборка";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(239, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Граф А";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(506, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Граф В";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(715, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Методы";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(133, 342);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"size(a)=";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(133, 374);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"size(b)=";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(146, 408);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"D=";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(15, 51);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(94, 82);
			this->listBox1->TabIndex = 8;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormSampleData::listBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 163);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormSampleData::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 199);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Сохранить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FormSampleData::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(15, 238);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FormSampleData::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(15, 349);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 62);
			this->button4->TabIndex = 12;
			this->button4->Text = L"Генерация выборки";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &FormSampleData::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(364, 471);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 28);
			this->button5->TabIndex = 13;
			this->button5->Text = L"import";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &FormSampleData::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(524, 471);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(100, 28);
			this->button6->TabIndex = 14;
			this->button6->Text = L"export";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &FormSampleData::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(684, 414);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(124, 28);
			this->button7->TabIndex = 15;
			this->button7->Text = L"Метаоптимизация";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &FormSampleData::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(695, 471);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(100, 28);
			this->button8->TabIndex = 16;
			this->button8->Text = L"Поиск";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &FormSampleData::button8_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->CheckOnClick = true;
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Полный П.", L"Случайный П.", L"Жадный Алг.",
					L"Случайный Взв. П.", L"Имитация Отж.", L"Муравьиной Кол.", L"Пчелиной Кол."
			});
			this->checkedListBox1->Location = System::Drawing::Point(677, 51);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(131, 124);
			this->checkedListBox1->TabIndex = 17;
			this->checkedListBox1->Leave += gcnew System::EventHandler(this, &FormSampleData::checkedListBox1_Leave);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(172, 339);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(30, 20);
			this->textBox1->TabIndex = 18;
			this->textBox1->Text = L"5";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(172, 371);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(30, 20);
			this->textBox2->TabIndex = 19;
			this->textBox2->Text = L"4";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(172, 405);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(30, 20);
			this->textBox3->TabIndex = 20;
			this->textBox3->Text = L"0.8";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGridView1->Location = System::Drawing::Point(115, 51);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(271, 282);
			this->dataGridView1->TabIndex = 21;
			this->dataGridView1->VirtualMode = true;
			this->dataGridView1->CancelRowEdit += gcnew System::Windows::Forms::QuestionEventHandler(this, &FormSampleData::dataGridView1_CancelRowEdit);
			this->dataGridView1->CellValueNeeded += gcnew System::Windows::Forms::DataGridViewCellValueEventHandler(this, &FormSampleData::dataGridView1_CellValueNeeded);
			this->dataGridView1->CellValuePushed += gcnew System::Windows::Forms::DataGridViewCellValueEventHandler(this, &FormSampleData::dataGridView1_CellValuePushed);
			this->dataGridView1->NewRowNeeded += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &FormSampleData::dataGridView1_NewRowNeeded);
			this->dataGridView1->RowValidated += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormSampleData::dataGridView1_RowValidated);
			this->dataGridView1->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &FormSampleData::dataGridView1_UserDeletingRow);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 21;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToOrderColumns = true;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->ColumnHeadersVisible = false;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column2 });
			this->dataGridView2->Location = System::Drawing::Point(392, 51);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(271, 282);
			this->dataGridView2->TabIndex = 30;
			this->dataGridView2->VirtualMode = true;
			this->dataGridView2->CancelRowEdit += gcnew System::Windows::Forms::QuestionEventHandler(this, &FormSampleData::dataGridView2_CancelRowEdit);
			this->dataGridView2->CellValueNeeded += gcnew System::Windows::Forms::DataGridViewCellValueEventHandler(this, &FormSampleData::dataGridView2_CellValueNeeded);
			this->dataGridView2->CellValuePushed += gcnew System::Windows::Forms::DataGridViewCellValueEventHandler(this, &FormSampleData::dataGridView2_CellValuePushed);
			this->dataGridView2->NewRowNeeded += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &FormSampleData::dataGridView2_NewRowNeeded);
			this->dataGridView2->RowValidated += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormSampleData::dataGridView2_RowValidated);
			this->dataGridView2->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &FormSampleData::dataGridView2_UserDeletingRow);
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 21;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(68, 440);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(99, 13);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Размер выборки=";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(172, 439);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(30, 20);
			this->textBox4->TabIndex = 24;
			this->textBox4->Text = L"4";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 486);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(213, 13);
			this->label9->TabIndex = 25;
			this->label9->Text = L"Сколько изоморфов необходимо найти\?";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(252, 471);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(30, 20);
			this->textBox5->TabIndex = 26;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &FormSampleData::textBox5_TextChanged);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(230, 342);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(117, 45);
			this->button9->TabIndex = 28;
			this->button9->Text = L"Вывод GraphBig";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &FormSampleData::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(230, 393);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(117, 49);
			this->button10->TabIndex = 29;
			this->button10->Text = L"вывод выборки SampleBig";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Visible = false;
			this->button10->Click += gcnew System::EventHandler(this, &FormSampleData::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(467, 346);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(117, 45);
			this->button11->TabIndex = 31;
			this->button11->Text = L"Вывод GraphSmall";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Visible = false;
			this->button11->Click += gcnew System::EventHandler(this, &FormSampleData::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(467, 397);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(117, 45);
			this->button12->TabIndex = 32;
			this->button12->Text = L"вывод выборки SampleSmall";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Visible = false;
			this->button12->Click += gcnew System::EventHandler(this, &FormSampleData::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(347, 339);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(117, 77);
			this->button13->TabIndex = 33;
			this->button13->Text = L"DEBUG";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Visible = false;
			this->button13->Click += gcnew System::EventHandler(this, &FormSampleData::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(353, 425);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(100, 28);
			this->button14->TabIndex = 34;
			this->button14->Text = L"IsoCnt\?";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Visible = false;
			this->button14->Click += gcnew System::EventHandler(this, &FormSampleData::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(695, 289);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(100, 28);
			this->button15->TabIndex = 35;
			this->button15->Text = L"binary Vect\?";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Visible = false;
			this->button15->Click += gcnew System::EventHandler(this, &FormSampleData::button15_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->выходToolStripMenuItem,
					this->оПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(820, 24);
			this->menuStrip1->TabIndex = 36;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormSampleData::выходToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(732, 241);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(30, 20);
			this->textBox6->TabIndex = 37;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &FormSampleData::textBox6_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(705, 225);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(90, 13);
			this->label10->TabIndex = 38;
			this->label10->Text = L"Лимит итераций";
			// 
			// FormSampleData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(820, 525);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormSampleData";
			this->Text = L"Поиск изоморфного подграфа - данные выборки";
			this->Load += gcnew System::EventHandler(this, &FormSampleData::FormSampleData_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
	
	
	
		private: System::Void FormSampleData_Load(System::Object^ sender, System::EventArgs^ e) {
			
			this->dataGridView1->AutoSizeColumnsMode =
				DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView2->AutoSizeColumnsMode =
				DataGridViewAutoSizeColumnsMode::AllCells;

			this->dataGridView1->RowCount = 1;
			this->dataGridView2->RowCount = 1;

			for (int i = 0; i < this->checkedListBox1->Items->Count; i++)
			{
				this->methodsEnableList->push_back(0);
			}
		}
		
		private: System::Void dataGridView1_CellValueNeeded(System::Object^ sender, System::Windows::Forms::DataGridViewCellValueEventArgs^ e) {
			if (e->RowIndex == this->dataGridView1->RowCount) return;
			if (e->RowIndex == rowInEdit)
			{
				e->Value = (*this->customerInEdit)[e->ColumnIndex];
			}
			else if(this->graphBig->size() > e->RowIndex && (*this->graphBig)[0].size() > e->ColumnIndex)
			{ 
				e->Value = (*this->graphBig)[e->RowIndex][e->ColumnIndex];
			}
		}
		private: System::Void dataGridView1_CellValuePushed(System::Object^ sender, System::Windows::Forms::DataGridViewCellValueEventArgs^ e) {
			//считывание ряда customers[row] в customerInEdit, изменение ячейки customerInEdit[col]
			if (e->RowIndex < this->graphBig->size())
			{
				// new row
				if (this->customerInEdit == nullptr)
				{
					customerInEdit = new std::vector<int>();
					for (int i = 0; i < (*this->graphBig)[0].size(); i++)
					{
						customerInEdit->push_back((*(this->graphBig))[e->RowIndex][i]);
					}
				}
				this->rowInEdit = e->RowIndex;
			}
			String^ buff2 = e->Value->ToString();
			std::string buff1 = Convert_String_to_string(buff2);
			int newValue = std::stoi(buff1);;
			(*this->customerInEdit)[e->ColumnIndex] = newValue;
		}
		private: System::Void dataGridView1_NewRowNeeded(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e) {
		
			// добавление новой вершины
			this->customerInEdit = new std::vector<int>();
			for (int i = 0; i < (*this->graphBig)[0].size() + 1; i++)
				this->customerInEdit->push_back(0);
			for (int i = 0; i < (*this->graphBig).size(); i++)
				(*this->graphBig)[i].push_back(0);
			this->rowInEdit = this->dataGridView1->Rows->Count - 1;
			this->dataGridView1->ColumnCount++;
			this->dataGridView1->RowCount++;
			this->dataGridView1->Update();
		}
		private: System::Void dataGridView1_RowValidated(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			// Save row changes if any were made and release the edited
			// Customer object if there is one.
			if (e->RowIndex >= this->graphBig->size() &&
				e->RowIndex != this->dataGridView1->Rows->Count - 1)
			{
				if (this->customerInEdit == nullptr)
					customerInEdit = new std::vector<int>({ 0 });
				// Add the new Customer object to the data store.
				this->graphBig->push_back(*(this->customerInEdit));
			}
			else if (this->customerInEdit != nullptr &&
				e->RowIndex < this->graphBig->size())
			{
				// Save the modified Customer object in the data store.
				(*(this->graphBig))[e->RowIndex] = *(this->customerInEdit);
			}
			else if (this->dataGridView1->ContainsFocus) {}
			else return;
			delete this->customerInEdit;
			this->customerInEdit = nullptr;
			this->rowInEdit = -1;
		}
		private: System::Void dataGridView1_CancelRowEdit(System::Object^ sender, System::Windows::Forms::QuestionEventArgs^ e) {
			if (this->rowInEdit == this->dataGridView1->Rows->Count - 2 &&
				this->rowInEdit == this->graphBig->size())
			{
				// If the user has canceled the edit of a newly created row,
				// replace the corresponding Customer object with a new, empty one.
				this->customerInEdit = new std::vector<int>();
				for (int i = 0; i < this->dataGridView1->Columns->Count; i++)
				{
					this->customerInEdit->push_back(0);
				}
			}
			else
			{
				// If the user has canceled the edit of an existing row,
				// release the corresponding Customer object.
				delete this->customerInEdit;
				this->customerInEdit = nullptr;
				this->rowInEdit = -1;
			}
		}
		private: System::Void dataGridView1_UserDeletingRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e) {
			this->dataGridView1->ColumnCount--;
			if (e->Row->Index < this->graphBig->size())
			{
				// удаление существующей вершины
				for (int i = 0; i < this->graphBig->size(); i++)
				{
					(*this->graphBig)[i].erase((*this->graphBig)[i].begin() + e->Row->Index);
				}
				this->graphBig->erase(this->graphBig->begin() + e->Row->Index);
			
			}
			if (e->Row->Index == this->rowInEdit)
			{
				// удаление созданной строки
				this->rowInEdit = -1;
				delete this->customerInEdit;
				this->customerInEdit = nullptr;
				return;
			}
			this->dataGridView1->Update();
		}
		   
		private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			if (this->listBox1->SelectedIndex < 0) return;
			if (this->sampleGraphBig->size() > this->selectedGraphPair)
				(*this->sampleGraphBig)[this->selectedGraphPair] = (*this->graphBig);
			if (this->sampleGraphSmall->size() > this->selectedGraphPair)
				(*this->sampleGraphSmall)[this->selectedGraphPair] = (*this->graphSmall);
			this->selectedGraphPair = this->listBox1->SelectedIndex;
			graphBig = &((*this->sampleGraphBig)[selectedGraphPair]);
			this->dataGridView1->RowCount = graphBig->size() + 1;
			this->dataGridView1->ColumnCount = graphBig->size();
			dataGridView1->Refresh();
			graphSmall = &((*this->sampleGraphSmall)[selectedGraphPair]);
			this->dataGridView2->RowCount = graphSmall->size() + 1;
			this->dataGridView2->ColumnCount = graphSmall->size();
			dataGridView2->Refresh();
	
		}

		private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			this->isomorphCount = std::stoi(Convert_String_to_string(this->textBox5->Text));
		}
		private: System::Void checkedListBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
			for (int i = 0; i < this->checkedListBox1->CheckedIndices->Count; i++)
			{
				(*this->methodsEnableList)[this->checkedListBox1->CheckedIndices[i]] = 1;
			}
		}


		//data grid view 2
		private: System::Void dataGridView2_CellValueNeeded(System::Object^ sender, System::Windows::Forms::DataGridViewCellValueEventArgs^ e) {
			if (e->RowIndex == this->dataGridView2->RowCount) return;
			if (e->RowIndex == rowInEdit2)
			{
				e->Value = (*this->customerInEdit2)[e->ColumnIndex];
			}
			else if (this->graphSmall->size() > e->RowIndex && (*this->graphSmall)[0].size() > e->ColumnIndex)
			{
				e->Value = (*this->graphSmall)[e->RowIndex][e->ColumnIndex];
			}
		}
		private: System::Void dataGridView2_CellValuePushed(System::Object^ sender, System::Windows::Forms::DataGridViewCellValueEventArgs^ e) {
			//считывание ряда customers[row] в customerInEdit, изменение ячейки customerInEdit[col]
			if (e->RowIndex < this->graphSmall->size())
			{
				// new row
				if (this->customerInEdit2 == nullptr)
				{
					customerInEdit2 = new std::vector<int>();
					for (int i = 0; i < (*this->graphSmall)[0].size(); i++)
					{
						customerInEdit2->push_back((*(this->graphSmall))[e->RowIndex][i]);
					}
				}
				this->rowInEdit2 = e->RowIndex;
			}
			String^ buff2 = e->Value->ToString();
			std::string buff1 = Convert_String_to_string(buff2);
			int newValue = std::stoi(buff1);;
			(*this->customerInEdit2)[e->ColumnIndex] = newValue;
		}
		private: System::Void dataGridView2_NewRowNeeded(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e) {

			// добавление новой вершины
			this->customerInEdit2 = new std::vector<int>();
			for (int i = 0; i < (*this->graphSmall)[0].size() + 1; i++)
				this->customerInEdit2->push_back(0);
			for (int i = 0; i < (*this->graphSmall).size(); i++)
				(*this->graphSmall)[i].push_back(0);
			this->rowInEdit2 = this->dataGridView2->Rows->Count - 1;
			this->dataGridView2->ColumnCount++;
			this->dataGridView2->RowCount++;
			this->dataGridView2->Update();
		}
		private: std::vector<std::vector<int>> buildGraphFromP(std::vector<int> p, std::vector<std::vector<int>> source)
		{
			std::vector<std::vector<int>> graph;
			std::vector<int> graphVertix;
			for (int i = 0; i < p.size(); i++)
			{
				graphVertix.push_back(0);
			}
			for (int i = 0; i < p.size(); i++)
			{
				for (int j = 0; j < p.size(); j++)
				{
					graphVertix[j] = source[p[i]][p[j]];
				}
				graph.push_back(graphVertix);
			}
			return graph;
		}
		private: std::vector<std::vector<int>> shuffleVertixes(std::vector<std::vector<int>>& smallGraph) {
			std::vector<int> perestanovka, availableVertixes;
			int r;
			
			//получить случайную перестановку +
			for (int i = 0; i < smallGraph.size(); i++) availableVertixes.push_back(i);
			while (availableVertixes.size() != 0)
			{
				r = rand() % availableVertixes.size();
				perestanovka.push_back(availableVertixes[r]);
				availableVertixes.erase(availableVertixes.begin() + r);
			}
			//построить матрицу по перестановке
			return buildGraphFromP(perestanovka, smallGraph);

			
		}
		private: std::vector<std::vector<int>> buildBigGraphIsomorph(std::vector<std::vector<int>>& smallGraph, int bigSize)
		{

			std::vector<std::vector<int>> bigGraph = shuffleVertixes(smallGraph);
			std::vector<int> bigGraphNewRow;
			
			//вставить необходимое число вершин на случайные места
			int deltaSize = bigSize - smallGraph.size();
			for (int i = 0; i < deltaSize; i++)
			{
				int randPos = rand() % smallGraph.size();
				for (int j = 0; j < smallGraph.size()+i+1; j++)
					if (j != randPos)
						bigGraphNewRow.push_back(rand() % 2);
					else
						bigGraphNewRow.push_back(0);
				for (int j = 0; j < bigGraphNewRow.size(); j++)
				{
					if (j > randPos)
						bigGraph[j - 1].insert(bigGraph[j - 1].begin() + randPos, bigGraphNewRow[j]);
					else if (j < randPos)
						bigGraph[j].insert(bigGraph[j].begin() + randPos, bigGraphNewRow[j]);
				}
				bigGraph.insert(bigGraph.begin() + randPos, bigGraphNewRow);
				bigGraphNewRow.clear();
			}
			return bigGraph;
		}
		private: System::Void dataGridView2_RowValidated(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			// Save row changes if any were made and release the edited
			// Customer object if there is one.
			if (e->RowIndex >= this->graphSmall->size() &&
				e->RowIndex != this->dataGridView2->Rows->Count - 1)
			{
				if (this->customerInEdit2 == nullptr)
					customerInEdit2 = new std::vector<int>({ 0 });
				// Add the new Customer object to the data store.
				this->graphSmall->push_back(*(this->customerInEdit2));
			}
			else if (this->customerInEdit2 != nullptr &&
				e->RowIndex < this->graphSmall->size())
			{
				// Save the modified Customer object in the data store.
				(*(this->graphSmall))[e->RowIndex] = *(this->customerInEdit2);
			}
			else if (this->dataGridView2->ContainsFocus) {}
			else return;
			delete this->customerInEdit2;
			this->customerInEdit2 = nullptr;
			this->rowInEdit2 = -1;
		}
		private: System::Void dataGridView2_CancelRowEdit(System::Object^ sender, System::Windows::Forms::QuestionEventArgs^ e) {
			if (this->rowInEdit2 == this->dataGridView2->Rows->Count - 2 &&
				this->rowInEdit2 == this->graphSmall->size())
			{
				// If the user has canceled the edit of a newly created row,
				// replace the corresponding Customer object with a new, empty one.
				this->customerInEdit2 = new std::vector<int>();
				for (int i = 0; i < this->dataGridView2->Columns->Count; i++)
				{
					this->customerInEdit2->push_back(0);
				}

			}
			else
			{
				// If the user has canceled the edit of an existing row,
				// release the corresponding Customer object.
				delete this->customerInEdit2;
				this->customerInEdit2 = nullptr;
				this->rowInEdit2 = -1;
			}
		}
		private: System::Void dataGridView2_UserDeletingRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e) {
			this->dataGridView2->ColumnCount--;
			if (e->Row->Index < this->graphSmall->size())
			{
				// удаление существующей вершины
				for (int i = 0; i < this->graphSmall->size(); i++)
				{
					(*this->graphSmall)[i].erase((*this->graphSmall)[i].begin() + e->Row->Index);
				}
				this->graphSmall->erase(this->graphSmall->begin() + e->Row->Index);

			}
			if (e->Row->Index == this->rowInEdit2)
			{
				// удаление созданной строки
				this->rowInEdit2 = -1;
				delete this->customerInEdit2;
				this->customerInEdit2 = nullptr;
				return;
			}

			this->dataGridView2->Update();
		}
	
		private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

		//DEBUG
		private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
			return System::Void();
		}
		private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show(this->isomorphCount.ToString());
		}
		private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ strBuf;
			for (int j = 0; j < (*this->methodsEnableList).size(); j++)
			{
				strBuf += (*this->methodsEnableList)[j].ToString();
				strBuf += " ";
			}
			MessageBox::Show(strBuf);
		}
		private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ strBuf;
			for (int i = 0; i < this->graphBig->size(); i++)
			{
				for (int j = 0; j < (*this->graphBig)[i].size(); j++)
				{
					strBuf += (*this->graphBig)[i][j].ToString();
				}
				strBuf += "\n";
			}
			MessageBox::Show(strBuf);
		}
		private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ strBuf;
			for (int k = 0; k < (*sampleGraphBig).size(); k++)
			{
				strBuf += k;
				strBuf += "\n";
				for (int i = 0; i < (*sampleGraphBig)[k].size(); i++)
				{
					for (int j = 0; j < (*sampleGraphBig)[k][i].size(); j++)
					{
						strBuf += (*sampleGraphBig)[k][i][j].ToString();
					}
					strBuf += "\n";
				}
			}
			MessageBox::Show(strBuf);
		}
		private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ strBuf;
			for (int i = 0; i < this->graphSmall->size(); i++)
			{
				for (int j = 0; j < (*this->graphSmall)[i].size(); j++)
				{
					strBuf += (*this->graphSmall)[i][j].ToString();
				}
				strBuf += "\n";
			}
			MessageBox::Show(strBuf);
		}
		private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ strBuf;
			for (int k = 0; k < (*sampleGraphSmall).size(); k++)
			{
				strBuf += k;
				strBuf += "\n";
				for (int i = 0; i < (*sampleGraphSmall)[k].size(); i++)
				{
					for (int j = 0; j < (*sampleGraphSmall)[k][i].size(); j++)
					{
						strBuf += (*sampleGraphSmall)[k][i][j].ToString();
					}
					strBuf += "\n";
				}
			}
			MessageBox::Show(strBuf);
		}
		
		private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			this->iterationLimit = std::stoi(Convert_String_to_string(this->textBox6->Text)) - 1;
		}
};
}