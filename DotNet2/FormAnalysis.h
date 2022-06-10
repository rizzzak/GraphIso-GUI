#include <vector>
#include "supervisor.h"
#include "FormResults.h"
#pragma once
namespace DotNet2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormAnalysis
	/// </summary>
	public ref class FormAnalysis : public System::Windows::Forms::Form
	{
	public:
		FormAnalysis(std::vector<std::vector<std::vector<int>> >& sampleGraphBig2,
			std::vector<std::vector<std::vector<int>> >& sampleGraphSmall2,
			std::vector<int>* methodsFlags, int _iterationLimit, int isomorphsCntr):
			sampleGraphBig(sampleGraphBig2), sampleGraphSmall(sampleGraphSmall2)
		{
			InitializeComponent();
			RW_d_parameter = 0.3;
			methodsEnableFlags = methodsFlags;
			isomorphsFoundGoal = isomorphsCntr;
			pairNumber = 0;
			iterationLimit = _iterationLimit;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormAnalysis()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::DataGridView^ dataGridView5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		std::vector<std::vector<std::vector<int>> >& sampleGraphBig;
		std::vector<std::vector<std::vector<int>> >& sampleGraphSmall;
		int isomorphsFoundGoal = 0;
		std::vector<int>* methodsEnableFlags;
		double RW_d_parameter = 0;
		supervisor* o_supervisor;
		int pairNumber;
		int iterationLimit;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView6;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
		   

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(12, 41);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(151, 124);
			this->dataGridView1->TabIndex = 0;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->ColumnHeadersVisible = false;
			this->dataGridView2->Location = System::Drawing::Point(193, 57);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->Size = System::Drawing::Size(151, 124);
			this->dataGridView2->TabIndex = 1;
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView3->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->ColumnHeadersVisible = false;
			this->dataGridView3->Location = System::Drawing::Point(380, 57);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->ReadOnly = true;
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->Size = System::Drawing::Size(151, 124);
			this->dataGridView3->TabIndex = 2;
			// 
			// dataGridView4
			// 
			this->dataGridView4->AllowUserToAddRows = false;
			this->dataGridView4->AllowUserToDeleteRows = false;
			this->dataGridView4->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView4->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->ColumnHeadersVisible = false;
			this->dataGridView4->Location = System::Drawing::Point(193, 242);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->ReadOnly = true;
			this->dataGridView4->RowHeadersVisible = false;
			this->dataGridView4->Size = System::Drawing::Size(151, 124);
			this->dataGridView4->TabIndex = 3;
			// 
			// dataGridView5
			// 
			this->dataGridView5->AllowUserToAddRows = false;
			this->dataGridView5->AllowUserToDeleteRows = false;
			this->dataGridView5->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView5->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView5->ColumnHeadersVisible = false;
			this->dataGridView5->Location = System::Drawing::Point(380, 242);
			this->dataGridView5->Name = L"dataGridView5";
			this->dataGridView5->ReadOnly = true;
			this->dataGridView5->RowHeadersVisible = false;
			this->dataGridView5->Size = System::Drawing::Size(151, 124);
			this->dataGridView5->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Граф В (эталон)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(208, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Полный П.";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(234, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"p={0,1,2,3,4}";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(314, 41);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"#";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(377, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Случайный П.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(426, 184);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"p={0,1,2,3,4}";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(517, 41);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(14, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"#";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(208, 226);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(74, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Жадный Алг.";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(234, 369);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(69, 13);
			this->label9->TabIndex = 13;
			this->label9->Text = L"p={0,1,2,3,4}";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(314, 226);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(14, 13);
			this->label10->TabIndex = 14;
			this->label10->Text = L"#";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(377, 226);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(101, 13);
			this->label11->TabIndex = 15;
			this->label11->Text = L"Случайный Взв. П.";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(426, 369);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(69, 13);
			this->label12->TabIndex = 16;
			this->label12->Text = L"p={0,1,2,3,4}";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(517, 226);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(14, 13);
			this->label13->TabIndex = 17;
			this->label13->Text = L"#";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->выходToolStripMenuItem,
					this->оПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(755, 24);
			this->menuStrip1->TabIndex = 18;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormAnalysis::выходToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			// 
			// dataGridView6
			// 
			this->dataGridView6->AllowUserToAddRows = false;
			this->dataGridView6->AllowUserToDeleteRows = false;
			this->dataGridView6->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView6->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView6->ColumnHeadersVisible = false;
			this->dataGridView6->Location = System::Drawing::Point(552, 57);
			this->dataGridView6->Name = L"dataGridView6";
			this->dataGridView6->ReadOnly = true;
			this->dataGridView6->RowHeadersVisible = false;
			this->dataGridView6->Size = System::Drawing::Size(202, 195);
			this->dataGridView6->TabIndex = 19;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(586, 41);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(101, 13);
			this->label14->TabIndex = 20;
			this->label14->Text = L"Граф A (исходный)";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(34, 200);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 21;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormAnalysis::listBox1_SelectedIndexChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(9, 184);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(171, 13);
			this->label15->TabIndex = 22;
			this->label15->Text = L"Выбор пары графов из выборки";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(37, 356);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(117, 49);
			this->button10->TabIndex = 30;
			this->button10->Text = L"вывод выборки SampleBig";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Visible = false;
			this->button10->Click += gcnew System::EventHandler(this, &FormAnalysis::button10_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(37, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 49);
			this->button1->TabIndex = 31;
			this->button1->Text = L"вывод выборки SampleSmall";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormAnalysis::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(552, 299);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(182, 44);
			this->button2->TabIndex = 32;
			this->button2->Text = L"Результаты";
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FormAnalysis::button2_Click);
			// 
			// FormAnalysis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(755, 411);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->dataGridView6);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView5);
			this->Controls->Add(this->dataGridView4);
			this->Controls->Add(this->dataGridView3);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormAnalysis";
			this->Text = L"Поиск изоморфного подграфа - анализ";
			this->Load += gcnew System::EventHandler(this, &FormAnalysis::FormAnalysis_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
		private: 
			long double fact(int N)
			{
				if (N < 0) // если пользователь ввел отрицательное число
					return 0; // возвращаем ноль
				if (N == 0) // если пользователь ввел ноль,
					return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
				else // Во всех остальных случаях
					return N * fact(N - 1); // делаем рекурсию.
			}
			void testInput()
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
		private: System::Void FormAnalysis_Load(System::Object^ sender, System::EventArgs^ e) {
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
				listBox1->Items->Add("Пара " + (i+1));

				//o_supervisor.MetaoptimizationAll(graphBig, graphSmall);

				// 3. решение задачи методами
				o_supervisor->InitAll(smallSize, bigSize, isomorphsFoundGoal);
				while (!o_supervisor->IterationAll(graphBig, graphSmall)) { 
					//Repaint(*o_supervisor, pairNumber);
				}
				Repaint(*o_supervisor, pairNumber);
				o_supervisor->FindLocalStatsAll();
			}
			// 4. сбор глобальной статистики - результатов работы методов по выборке
			o_supervisor->FindGlobalStatsAll(sizeOfSample); //incl. DocAll

		}
		private: System::Void PrintMatrixInDataGridView(System::Windows::Forms::DataGridView^ _dataGridView, std::vector<std::vector<int>>& matrix)
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
		private: std::vector<int> getEmptyVector(int size)
		{
			std::vector<int> graphString;
			for (int j = 0; j < size; j++)
			{
				graphString.push_back(0);
			}
			return graphString;
		}
		private: std::vector<std::vector<int> > getEmptyGraph(int size)
		{
			std::vector<std::vector<int>> graph;

			for (int i = 0; i < size; i++)
			{
				graph.push_back(getEmptyVector(size));
			}
			return graph;
		}
		private: System::Void PrintMethodResults(supervisor& super, System::Windows::Forms::Label^ labelP,
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
		private: System::Void Repaint(supervisor& super, int graphPairIndex)
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
		private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			if (this->listBox1->SelectedIndex < 0) return;
			pairNumber = this->listBox1->SelectedIndex;
			std::vector<std::vector<int>> graphBig = this->sampleGraphBig[pairNumber];
			PrintMatrixInDataGridView(this->dataGridView6, graphBig);
			std::vector<std::vector<int>> graphSmall = this->sampleGraphSmall[pairNumber];
			PrintMatrixInDataGridView(this->dataGridView1, graphSmall);
			Repaint(*o_supervisor, pairNumber);
		}
		private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
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
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
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
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			FormResults^ formResults = gcnew FormResults(*o_supervisor, *methodsEnableFlags);
			this->Hide();
			formResults->Show();
		}
};
}
