#pragma once
#include "supervisor.h"
#include "vector"
#include "ConvertFunctions.h"
namespace DotNet2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormResults
	/// </summary>
	public ref class FormResults : public System::Windows::Forms::Form
	{
	public:
		FormResults(supervisor& _super, std::vector<int>& _mEF):super(_super), methodsEnableFlags(_mEF)
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
		~FormResults()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		
		supervisor& super;
	private: System::Windows::Forms::Button^ button1;
		   std::vector<int>& methodsEnableFlags;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 48);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(1007, 199);
			this->dataGridView1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(255, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Результаты работы методов:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(536, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"DEBUG";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormResults::button1_Click);
			// 
			// FormResults
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1025, 260);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"FormResults";
			this->Text = L"FormResults";
			this->Load += gcnew System::EventHandler(this, &FormResults::FormResults_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FormResults_Load(System::Object^ sender, System::EventArgs^ e) {		
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
						dataGridView1->Rows[i]->Cells[0]->Value = "!Полный перебор ";
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
			dataGridView1->Rows[i]->Cells[2]->Value = doubleToString(prob,5);
			dataGridView1->Rows[i]->Cells[3]->Value = doubleToString(disp,5);
			dataGridView1->Rows[i]->Cells[4]->Value = doubleToString(sigma,5);
			dataGridView1->Rows[i]->Cells[5]->Value = doubleToString(dQ,5);

		}
		super.ClearingTotalAll();
	}
	private: String^ doubleToString(double src, int precision)
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

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (true)
			;
	}
};
}
