#pragma once

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
		FormMeta(void)
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
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
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
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
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
			this->label2->Size = System::Drawing::Size(152, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Оптимальное значение: 0,8\\";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(30, 263);
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
			this->label4->Size = System::Drawing::Size(20, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"T=";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(191, 301);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Gamma=";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(307, 301);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"param3=";
			this->label6->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(78, 298);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(35, 20);
			this->textBox1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(246, 298);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(35, 20);
			this->textBox2->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(361, 298);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(35, 20);
			this->textBox3->TabIndex = 8;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(45, 335);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(370, 46);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Выбор параметра для оптимизации";
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
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(164, 15);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(60, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"param2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(280, 15);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(60, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"param3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(486, 322);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 59);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Начать метаоптимизацию";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(533, 68);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 59);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Analysis";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(136, 32);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(358, 228);
			this->chart1->TabIndex = 12;
			this->chart1->Text = L"chart1";
			title1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			title1->Name = L"OY";
			title1->Position->Auto = false;
			title1->Position->Height = 85;
			title1->Position->X = 3;
			title1->Position->Y = 4;
			title1->Text = L"Вероятность нахождения решения";
			title1->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
			title2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			title2->Name = L"OX";
			title2->Position->Auto = false;
			title2->Position->Width = 30;
			title2->Position->X = 39;
			title2->Position->Y = 97;
			title2->Text = L"Param1";
			this->chart1->Titles->Add(title1);
			this->chart1->Titles->Add(title2);
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
			// FormMeta
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 446);
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
			this->Name = L"FormMeta";
			this->Text = L"FormMeta";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
