#pragma once
#include <cmath>

namespace лз6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(67, 58);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1122, 107);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(338, 261);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(112, 264);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введіть елементи масиву:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(218, 498);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(339, 92);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Обрахувати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(594, 215);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(488, 189);
			this->dataGridView1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(757, 534);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1337, 759);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. Зчитуємо текст і розбиваємо його на окремі числа (розділені пробілом)
		array<System::String^>^ strArr = textBox1->Text->Split(gcnew array<System::Char>{' '}, System::StringSplitOptions::RemoveEmptyEntries);
		int n = strArr->Length;

		if (n == 0) {
			label2->Text = "Помилка: введіть числа!";
			return;
		}

		// Створюємо масиви (один для сортування, інший для збереження початкового стану)
		array<double>^ arr = gcnew array<double>(n);
		array<double>^ origArr = gcnew array<double>(n);
		double sum = 0;

		// 2. Заповнюємо масиви і паралельно рахуємо суму
		for (int i = 0; i < n; i++) {
			// Перетворюємо рядок у число (замінюємо крапку на кому для правильності)
			arr[i] = System::Convert::ToDouble(strArr[i]->Replace(".", ","));
			origArr[i] = arr[i];
			sum += arr[i];
		}

		// 3. Обчислюємо та виводимо середнє арифметичне
		double avg = sum / n;
		label2->Text = "Середнє арифметичне = " + System::Math::Round(avg, 4).ToString();

		// 4. Сортування за спаданням (Метод екстремальних елементів / вибору максимального)
		for (int i = 0; i < n - 1; i++) {
			int maxIndex = i; // Припускаємо, що найбільший елемент - поточний

			// Шукаємо максимальний елемент у залишку масиву
			for (int j = i + 1; j < n; j++) {
				if (arr[j] > arr[maxIndex]) {
					maxIndex = j;
				}
			}

			// Міняємо місцями поточний елемент із знайденим максимальним
			double temp = arr[i];
			arr[i] = arr[maxIndex];
			arr[maxIndex] = temp;
		}

		// 5. --- ВИВЕДЕННЯ РЕЗУЛЬТАТІВ У DATAGRIDVIEW ---
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		dataGridView1->ColumnCount = n;

		// Налаштовуємо ширину стовпців та заголовків
		for (int i = 0; i < n; i++) {
			dataGridView1->Columns[i]->Width = 45; // Робимо комірки квадратними
		}
		dataGridView1->RowHeadersWidth = 110; // Робимо ліву колонку ширшою для тексту

		// Додаємо перший рядок (Початковий масив)
		dataGridView1->Rows->Add();
		dataGridView1->Rows[0]->HeaderCell->Value = "Початковий";
		for (int i = 0; i < n; i++) {
			dataGridView1->Rows[0]->Cells[i]->Value = origArr[i];
		}

		// Додаємо другий рядок (Відсортований масив)
		dataGridView1->Rows->Add();
		dataGridView1->Rows[1]->HeaderCell->Value = "За спаданням";
		for (int i = 0; i < n; i++) {
			dataGridView1->Rows[1]->Cells[i]->Value = arr[i];
		}
	}
};
}
