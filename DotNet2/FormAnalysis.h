#include <vector>
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
		FormAnalysis(std::vector<std::vector<std::vector<int>> >& sampleGraphBig,
			std::vector<std::vector<std::vector<int>> >& sampleGraphSmall):
			sampleGraphBig2(sampleGraphBig), sampleGraphSmall2(sampleGraphSmall)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			
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
		std::vector<std::vector<std::vector<int>> >& sampleGraphBig2;
		std::vector<std::vector<std::vector<int>> >& sampleGraphSmall2;

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(23, 28);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(151, 124);
			this->dataGridView1->TabIndex = 0;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(237, 57);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->Size = System::Drawing::Size(151, 124);
			this->dataGridView2->TabIndex = 1;
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(433, 57);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->ReadOnly = true;
			this->dataGridView3->Size = System::Drawing::Size(151, 124);
			this->dataGridView3->TabIndex = 2;
			// 
			// dataGridView4
			// 
			this->dataGridView4->AllowUserToAddRows = false;
			this->dataGridView4->AllowUserToDeleteRows = false;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Location = System::Drawing::Point(237, 242);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->ReadOnly = true;
			this->dataGridView4->Size = System::Drawing::Size(151, 124);
			this->dataGridView4->TabIndex = 3;
			// 
			// dataGridView5
			// 
			this->dataGridView5->AllowUserToAddRows = false;
			this->dataGridView5->AllowUserToDeleteRows = false;
			this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView5->Location = System::Drawing::Point(433, 242);
			this->dataGridView5->Name = L"dataGridView5";
			this->dataGridView5->ReadOnly = true;
			this->dataGridView5->Size = System::Drawing::Size(151, 124);
			this->dataGridView5->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(44, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Граф В (эталон)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(234, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Полный П.";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(275, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"p={0,1,2,3,4}";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(374, 41);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"#";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(430, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Случайный П.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(477, 184);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"p={0,1,2,3,4}";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(570, 41);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(14, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"#";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(234, 226);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(74, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Жадный Алг.";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(275, 369);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(69, 13);
			this->label9->TabIndex = 13;
			this->label9->Text = L"p={0,1,2,3,4}";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(374, 226);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(14, 13);
			this->label10->TabIndex = 14;
			this->label10->Text = L"#";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(430, 226);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(101, 13);
			this->label11->TabIndex = 15;
			this->label11->Text = L"Случайный Взв. П.";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(468, 369);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(69, 13);
			this->label12->TabIndex = 16;
			this->label12->Text = L"p={0,1,2,3,4}";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(570, 226);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(14, 13);
			this->label13->TabIndex = 17;
			this->label13->Text = L"#";
			// 
			// FormAnalysis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(679, 446);
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
			this->Name = L"FormAnalysis";
			this->Text = L"FormAnalysis";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
