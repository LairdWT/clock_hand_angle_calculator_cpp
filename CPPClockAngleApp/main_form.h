/// Laird Shingleton - 2022
/// Written in Visual Studio 2022 as an exercise

#pragma once
#include <string>

namespace CPPClockAngleApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for main_form
	/// </summary>
	public ref class main_form : public System::Windows::Forms::Form
	{
	public:
		main_form(void)
		{
			InitializeComponent();
		}

	private:
		
		/// <summary>
		/// These are the input validation members
		/// </summary>
		
		bool validate_is_number(String^ input)
		{
			int result;
			if (!Int32::TryParse(input, result))
			{
				return 0;
			};
			return 1;
		}

		Int32 extract_integer_from_input(String^ input)
		{
			Int32 result;
			if (Int32::TryParse(input, result))
			{
				return result;
			};
			printf("Error: integer extraction failed! \n");
			return 0;
		}

		bool is_int32_in_range(Int32 input, Int32 low, Int32 high)
		{
			return ((input - high) * (input - low) <= 0);
		}

		double min_double(double x, double y)
		{
			return (x < y) ? x : y;

		}

		double compute_angle(Int32 hour, Int32 minute)
		{
			const double h = (double)hour;
			const double m = (double)minute;
			// hour angle is (hour * 60 + minute))
			// min angle is (6 * minute)
			// Get the absolute value of the hour and min, then return the smaller of 360 - Angle or Angle
			return min_double(360 - abs((0.5 * (h * 60 + m)) - (6 * m)), abs((0.5 * (h * 60 + m)) - (6 * m)));
		}

		/// <summary>
		/// UI member functions
		/// </summary>

		void clear_textboxes()
		{
			this->hour_textbox->Text = "12";
			this->minute_textbox->Text = "59";
			this->output_box->Text = "0";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ hour_label;
	protected:
	private: System::Windows::Forms::TextBox^ hour_textbox;
	private: System::Windows::Forms::Label^ minute_label;
	private: System::Windows::Forms::TextBox^ minute_textbox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ start_button;
	private: System::Windows::Forms::Button^ reset_button;
	private: System::Windows::Forms::Label^ output_label;
	private: System::Windows::Forms::Label^ output_box;
	private: System::Windows::Forms::Button^ quit_button;

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
			this->hour_label = (gcnew System::Windows::Forms::Label());
			this->hour_textbox = (gcnew System::Windows::Forms::TextBox());
			this->minute_label = (gcnew System::Windows::Forms::Label());
			this->minute_textbox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->start_button = (gcnew System::Windows::Forms::Button());
			this->reset_button = (gcnew System::Windows::Forms::Button());
			this->output_label = (gcnew System::Windows::Forms::Label());
			this->output_box = (gcnew System::Windows::Forms::Label());
			this->quit_button = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// hour_label
			// 
			this->hour_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->hour_label->AutoSize = true;
			this->hour_label->BackColor = System::Drawing::Color::DarkSlateGray;
			this->hour_label->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hour_label->ForeColor = System::Drawing::Color::DarkGray;
			this->hour_label->Location = System::Drawing::Point(13, 13);
			this->hour_label->Name = L"hour_label";
			this->hour_label->Size = System::Drawing::Size(140, 33);
			this->hour_label->TabIndex = 0;
			this->hour_label->Text = L"Input Hour";
			// 
			// hour_textbox
			// 
			this->hour_textbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->hour_textbox->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hour_textbox->Location = System::Drawing::Point(12, 49);
			this->hour_textbox->MinimumSize = System::Drawing::Size(200, 4);
			this->hour_textbox->Name = L"hour_textbox";
			this->hour_textbox->Size = System::Drawing::Size(300, 40);
			this->hour_textbox->TabIndex = 1;
			// 
			// minute_label
			// 
			this->minute_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->minute_label->AutoSize = true;
			this->minute_label->BackColor = System::Drawing::Color::DarkSlateGray;
			this->minute_label->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->minute_label->ForeColor = System::Drawing::Color::DarkGray;
			this->minute_label->Location = System::Drawing::Point(12, 92);
			this->minute_label->Name = L"minute_label";
			this->minute_label->Size = System::Drawing::Size(164, 33);
			this->minute_label->TabIndex = 2;
			this->minute_label->Text = L"Input Minute";
			// 
			// minute_textbox
			// 
			this->minute_textbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->minute_textbox->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->minute_textbox->Location = System::Drawing::Point(12, 128);
			this->minute_textbox->MinimumSize = System::Drawing::Size(200, 4);
			this->minute_textbox->Name = L"minute_textbox";
			this->minute_textbox->Size = System::Drawing::Size(300, 40);
			this->minute_textbox->TabIndex = 3;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->start_button, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->reset_button, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(18, 282);
			this->tableLayoutPanel1->MinimumSize = System::Drawing::Size(200, 50);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(748, 100);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// start_button
			// 
			this->start_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->start_button->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->start_button->Location = System::Drawing::Point(3, 3);
			this->start_button->Name = L"start_button";
			this->start_button->Size = System::Drawing::Size(368, 94);
			this->start_button->TabIndex = 0;
			this->start_button->Text = L"Start";
			this->start_button->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->start_button->UseVisualStyleBackColor = true;
			this->start_button->Click += gcnew System::EventHandler(this, &main_form::start_button_Click);
			// 
			// reset_button
			// 
			this->reset_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->reset_button->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reset_button->Location = System::Drawing::Point(377, 3);
			this->reset_button->Name = L"reset_button";
			this->reset_button->Size = System::Drawing::Size(368, 94);
			this->reset_button->TabIndex = 1;
			this->reset_button->Text = L"Reset";
			this->reset_button->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->reset_button->UseVisualStyleBackColor = true;
			this->reset_button->Click += gcnew System::EventHandler(this, &main_form::reset_button_Click);
			// 
			// output_label
			// 
			this->output_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->output_label->AutoSize = true;
			this->output_label->BackColor = System::Drawing::Color::DarkSlateGray;
			this->output_label->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output_label->ForeColor = System::Drawing::Color::DarkGray;
			this->output_label->Location = System::Drawing::Point(12, 171);
			this->output_label->Name = L"output_label";
			this->output_label->Size = System::Drawing::Size(401, 33);
			this->output_label->TabIndex = 5;
			this->output_label->Text = L"The angle between the hands is...";
			// 
			// output_box
			// 
			this->output_box->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->output_box->AutoSize = true;
			this->output_box->BackColor = System::Drawing::Color::DarkSlateGray;
			this->output_box->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output_box->ForeColor = System::Drawing::Color::DarkGray;
			this->output_box->Location = System::Drawing::Point(12, 215);
			this->output_box->Name = L"output_box";
			this->output_box->Size = System::Drawing::Size(127, 33);
			this->output_box->TabIndex = 6;
			this->output_box->Text = L"0 degrees";
			// 
			// quit_button
			// 
			this->quit_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->quit_button->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->quit_button->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->quit_button->Location = System::Drawing::Point(618, 13);
			this->quit_button->Name = L"quit_button";
			this->quit_button->Size = System::Drawing::Size(148, 76);
			this->quit_button->TabIndex = 2;
			this->quit_button->Text = L"Quit";
			this->quit_button->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->quit_button->UseVisualStyleBackColor = true;
			this->quit_button->Click += gcnew System::EventHandler(this, &main_form::quit_button_Click);
			// 
			// main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateGray;
			this->ClientSize = System::Drawing::Size(778, 394);
			this->Controls->Add(this->quit_button);
			this->Controls->Add(this->output_box);
			this->Controls->Add(this->output_label);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->minute_textbox);
			this->Controls->Add(this->minute_label);
			this->Controls->Add(this->hour_textbox);
			this->Controls->Add(this->hour_label);
			this->MaximumSize = System::Drawing::Size(1600, 900);
			this->MinimumSize = System::Drawing::Size(400, 400);
			this->Name = L"main_form";
			this->Text = L"Clock Hand Angle Calculator";
			this->Load += gcnew System::EventHandler(this, &main_form::main_form_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		
		System::Void start_button_Click(System::Object^ sender, System::EventArgs^ e)
		{

			// Validate hour input and create internal const
			String^ hour_text = this->hour_textbox->Text;
			if (!validate_is_number(hour_text))
			{
				clear_textboxes();
				MessageBox::Show("Error: Input a valid Hour. (1 to 12)");
				printf("%s is not a valid Int32 input \n", hour_text);
				return;
			};

			const Int32 hour = extract_integer_from_input(hour_text);

			if (!is_int32_in_range(hour, 0, 12))
			{
				clear_textboxes();
				MessageBox::Show("Error: Input a valid Hour. (1 to 12)");
				printf("%i is outside of range [1...12] \n", hour);
				return;
			}
		

			// Validate Minute input and create internal const
			String^ minute_text = this->minute_textbox->Text;
			if (!validate_is_number(minute_text))
			{
				clear_textboxes();
				MessageBox::Show("Error: Input a valid Minute. (0 to 59)");
				printf("%s is not a valid Int32 input \n", minute_text);
				return;
			};

			const Int32 minute = extract_integer_from_input(minute_text);

			if (!is_int32_in_range(minute, 0, 59))
			{
				clear_textboxes();
				MessageBox::Show("Error: Input a valid Minute. (0 to 59)");
				printf("%i is outside of range [1...12] \n", minute);
				return;
			}

			// Calc the angle
			this->output_box->Text = "The angle is " + compute_angle(hour, minute);
		}

		System::Void reset_button_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			clear_textboxes();
		}
		
		System::Void main_form_Load(System::Object^ sender, System::EventArgs^ e) 
		{
			clear_textboxes();
		}
		
		System::Void quit_button_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			exit(0);
		}
	
	};
}
