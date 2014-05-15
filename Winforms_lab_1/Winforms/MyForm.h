#pragma once
#include "StrtoDigit.hpp"


namespace Winforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button5;
	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(27, 113);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(172, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(184, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(170, 136);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(186, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(169, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Operand1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(169, 118);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Operand2";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(168, 199);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(171, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(169, 183);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Answer";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(28, 182);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(93, 36);
			this->button2->TabIndex = 7;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(375, 113);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 42);
			this->button3->TabIndex = 8;
			this->button3->Text = L"*";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(376, 182);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 36);
			this->button4->TabIndex = 9;
			this->button4->Text = L"/";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(39, 245);
			this->textBox4->MaximumSize = System::Drawing::Size(300, 100);
			this->textBox4->MinimumSize = System::Drawing::Size(300, 150);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(300, 150);
			this->textBox4->TabIndex = 10;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(371, 282);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(78, 50);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Clear";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 411);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Application";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				this->textBox4->SetBounds( 60,250, 300, 150);
				 double oper1, oper2;
				char  stringop[30];
				try
				{
				
				oper1 = StrtoDigit( textBox1->Text, textBox1->TextLength) ;
				oper2 = StrtoDigit( textBox2->Text, textBox2->TextLength) ;

					textBox3->Text = (oper1+ oper2) + "";
					textBox4->Text += oper1.ToString() + " + " + oper2.ToString() + " = " + (oper1+ oper2) + " \n ";
				}
				catch (mException ex)
				{
					textBox3->Text = ex.ShowStr() ;
				}
			
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
			 {
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->textBox4->SetBounds( 60,250, 300, 150);
				 double oper1, oper2;
				 try
				 {
				 oper1 = StrtoDigit( textBox1->Text, textBox1->TextLength) ;
				 oper2 = StrtoDigit( textBox2->Text, textBox2->TextLength) ;

			
					 textBox3->Text = (oper1 - oper2) + "";
					 textBox4->Text += oper1.ToString() + " - " + oper2.ToString() + " = " + (oper1 - oper2) + " \n ";
				 }
				 catch (mException ex)
				 {
					 textBox3->Text = ex.ShowStr() ;
				 }
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->textBox4->SetBounds( 60,250, 300, 150);
			 double oper1, oper2;
			 try
			 {
				 oper1 = StrtoDigit( textBox1->Text, textBox1->TextLength) ;
				 oper2 = StrtoDigit( textBox2->Text, textBox2->TextLength) ;


				 textBox3->Text = (oper1 * oper2) + "";
				 textBox4->Text += oper1.ToString() + " * " + oper2.ToString() + " = " + (oper1 * oper2) + " \n ";
			 }
			 catch (mException ex)
			 {
				 textBox3->Text = ex.ShowStr() ;
			 }
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->textBox4->SetBounds( 60,250, 300, 150);
			 double oper1, oper2;
			 try
			 {
				 oper1 = StrtoDigit( textBox1->Text, textBox1->TextLength) ;
				 oper2 = StrtoDigit( textBox2->Text, textBox2->TextLength) ;

				 if( !oper2 ) throw(mException("Error. Divizion by zero"));
				 textBox3->Text = (oper1 / oper2) + "";
				 textBox4->Text += oper1.ToString() + " / " + oper2.ToString() + " = " + (oper1 / oper2) + " \n ";
			 }
			 catch (mException ex)
			 {
				 textBox3->Text = ex.ShowStr() ;
			 }
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 textBox4->Text = "";
		 }
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
