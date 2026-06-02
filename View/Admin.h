#pragma once

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Admin
	/// </summary>
	public ref class Admin : public System::Windows::Forms::Form
	{
	public:
		Admin(void)
		{
			InitializeComponent();
			this->BackgroundImage = Image::FromFile(Application::StartupPath + "..\\..\\..\\imagenes\\admin_bg.png");
			this->BackgroundImageLayout = ImageLayout::Stretch;

			pictureBoxMixer1->Image = Image::FromFile(Application::StartupPath + "..\\..\\..\\imagenes\\mixer_activo.png");
			pictureBoxMixer2->Image = Image::FromFile(Application::StartupPath + "..\\..\\..\\imagenes\\mixer_activo.png");
			pictureBoxMixer3->Image = Image::FromFile(Application::StartupPath + "..\\..\\..\\imagenes\\mixer_desactivado.png");
			pictureBoxMixer4->Image = Image::FromFile(Application::StartupPath + "..\\..\\..\\imagenes\\mixer_desactivado.png");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::PictureBox^ pictureBoxMixer1;
	private: System::Windows::Forms::PictureBox^ pictureBoxMixer2;


	private: System::Windows::Forms::PictureBox^ pictureBoxMixer3;
	private: System::Windows::Forms::PictureBox^ pictureBoxMixer4;



	private: System::Windows::Forms::Button^ btnPedidos;


	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ btnInventario;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
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
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pictureBoxMixer1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxMixer2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxMixer3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxMixer4 = (gcnew System::Windows::Forms::PictureBox());
			this->btnPedidos = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btnInventario = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMixer1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMixer2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMixer3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMixer4))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(133, 71);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(393, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Bienvenido administrador!";
			this->label1->Click += gcnew System::EventHandler(this, &Admin::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(186, 201);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Mixer 1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(442, 201);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 29);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Mixer 2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(186, 385);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Mixer 3";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(442, 385);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 29);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Mixer 4";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::LimeGreen;
			this->label6->Location = System::Drawing::Point(429, 246);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Estado: Activo";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(392, 437);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(179, 20);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Estado: Desconectado";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::LimeGreen;
			this->label8->Location = System::Drawing::Point(178, 246);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(117, 20);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Estado: Activo";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(136, 437);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(179, 20);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Estado: Desconectado";
			// 
			// pictureBoxMixer1
			// 
			this->pictureBoxMixer1->Location = System::Drawing::Point(174, 154);
			this->pictureBoxMixer1->Name = L"pictureBoxMixer1";
			this->pictureBoxMixer1->Size = System::Drawing::Size(121, 33);
			this->pictureBoxMixer1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMixer1->TabIndex = 9;
			this->pictureBoxMixer1->TabStop = false;
			this->pictureBoxMixer1->Click += gcnew System::EventHandler(this, &Admin::pictureBox1_Click);
			// 
			// pictureBoxMixer2
			// 
			this->pictureBoxMixer2->Location = System::Drawing::Point(428, 145);
			this->pictureBoxMixer2->Name = L"pictureBoxMixer2";
			this->pictureBoxMixer2->Size = System::Drawing::Size(117, 42);
			this->pictureBoxMixer2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMixer2->TabIndex = 10;
			this->pictureBoxMixer2->TabStop = false;
			// 
			// pictureBoxMixer3
			// 
			this->pictureBoxMixer3->Location = System::Drawing::Point(174, 304);
			this->pictureBoxMixer3->Name = L"pictureBoxMixer3";
			this->pictureBoxMixer3->Size = System::Drawing::Size(121, 33);
			this->pictureBoxMixer3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMixer3->TabIndex = 11;
			this->pictureBoxMixer3->TabStop = false;
			// 
			// pictureBoxMixer4
			// 
			this->pictureBoxMixer4->Location = System::Drawing::Point(424, 304);
			this->pictureBoxMixer4->Name = L"pictureBoxMixer4";
			this->pictureBoxMixer4->Size = System::Drawing::Size(121, 33);
			this->pictureBoxMixer4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMixer4->TabIndex = 12;
			this->pictureBoxMixer4->TabStop = false;
			// 
			// btnPedidos
			// 
			this->btnPedidos->BackColor = System::Drawing::Color::Black;
			this->btnPedidos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPedidos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPedidos->ForeColor = System::Drawing::Color::White;
			this->btnPedidos->Location = System::Drawing::Point(290, 522);
			this->btnPedidos->Name = L"btnPedidos";
			this->btnPedidos->Size = System::Drawing::Size(119, 33);
			this->btnPedidos->TabIndex = 14;
			this->btnPedidos->Text = L"Pedidos";
			this->btnPedidos->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkRed;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(474, 523);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(173, 33);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Cerrar sesion";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Admin::button3_Click);
			// 
			// btnInventario
			// 
			this->btnInventario->BackColor = System::Drawing::Color::Black;
			this->btnInventario->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnInventario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInventario->ForeColor = System::Drawing::Color::White;
			this->btnInventario->Location = System::Drawing::Point(80, 523);
			this->btnInventario->Name = L"btnInventario";
			this->btnInventario->Size = System::Drawing::Size(138, 33);
			this->btnInventario->TabIndex = 16;
			this->btnInventario->Text = L"Inventario";
			this->btnInventario->UseVisualStyleBackColor = false;
			// 
			// Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(753, 587);
			this->Controls->Add(this->btnInventario);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnPedidos);
			this->Controls->Add(this->pictureBoxMixer4);
			this->Controls->Add(this->pictureBoxMixer3);
			this->Controls->Add(this->pictureBoxMixer2);
			this->Controls->Add(this->pictureBoxMixer1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Admin";
			this->Text = L"Admin";
			this->Load += gcnew System::EventHandler(this, &Admin::Admin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMixer1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMixer2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMixer3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMixer4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Admin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		//Application::Exit();
	}
	};
}