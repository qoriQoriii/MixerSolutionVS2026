#pragma once

using namespace System::IO;

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Client
	/// </summary>
	public ref class Client : public System::Windows::Forms::Form
	{
	public:
		Client(void)
		{
			InitializeComponent();
			//pictureBoxMixer1->Image = Image::FromFile(Application::StartupPath + "\\fondo_cliente.png");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Client()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::ComboBox^ comboBoxBebida;
	private: System::Windows::Forms::ComboBox^ comboBoxTamano;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::CheckBox^ checkBoxHielo;
	private: System::Windows::Forms::Button^ btnPreparar;
	private: System::Windows::Forms::Label^ lblEstado;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::PictureBox^ pictureBox9;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Client::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBoxBebida = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxTamano = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->checkBoxHielo = (gcnew System::Windows::Forms::CheckBox());
			this->btnPreparar = (gcnew System::Windows::Forms::Button());
			this->lblEstado = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(39, 119);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(217, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nuestras opciones son:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(96, 186);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"- Mojito";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(217, 186);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(120, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"- Cuba Libre";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(361, 186);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"- Daikiri";
			// 
			// comboBoxBebida
			// 
			this->comboBoxBebida->FormattingEnabled = true;
			this->comboBoxBebida->Location = System::Drawing::Point(311, 263);
			this->comboBoxBebida->Name = L"comboBoxBebida";
			this->comboBoxBebida->Size = System::Drawing::Size(121, 24);
			this->comboBoxBebida->TabIndex = 6;
			// 
			// comboBoxTamano
			// 
			this->comboBoxTamano->FormattingEnabled = true;
			this->comboBoxTamano->Location = System::Drawing::Point(311, 346);
			this->comboBoxTamano->Name = L"comboBoxTamano";
			this->comboBoxTamano->Size = System::Drawing::Size(121, 24);
			this->comboBoxTamano->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Transparent;
			this->label6->Location = System::Drawing::Point(83, 262);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(179, 25);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Seleccione bebida:";
			this->label6->Click += gcnew System::EventHandler(this, &Client::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Transparent;
			this->label7->Location = System::Drawing::Point(83, 346);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(91, 25);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Tamaño:";
			// 
			// checkBoxHielo
			// 
			this->checkBoxHielo->AutoSize = true;
			this->checkBoxHielo->BackColor = System::Drawing::Color::Transparent;
			this->checkBoxHielo->ForeColor = System::Drawing::Color::Transparent;
			this->checkBoxHielo->Location = System::Drawing::Point(90, 414);
			this->checkBoxHielo->Name = L"checkBoxHielo";
			this->checkBoxHielo->Size = System::Drawing::Size(110, 20);
			this->checkBoxHielo->TabIndex = 10;
			this->checkBoxHielo->Text = L"Agregar hielo";
			this->checkBoxHielo->UseVisualStyleBackColor = false;
			// 
			// btnPreparar
			// 
			this->btnPreparar->Location = System::Drawing::Point(280, 404);
			this->btnPreparar->Name = L"btnPreparar";
			this->btnPreparar->Size = System::Drawing::Size(178, 39);
			this->btnPreparar->TabIndex = 11;
			this->btnPreparar->Text = L"PREPARAR BEBIDA";
			this->btnPreparar->UseVisualStyleBackColor = true;
			this->btnPreparar->Click += gcnew System::EventHandler(this, &Client::btnPreparar_Click);
			// 
			// lblEstado
			// 
			this->lblEstado->AutoSize = true;
			this->lblEstado->BackColor = System::Drawing::Color::Transparent;
			this->lblEstado->ForeColor = System::Drawing::Color::Transparent;
			this->lblEstado->Location = System::Drawing::Point(219, 479);
			this->lblEstado->Name = L"lblEstado";
			this->lblEstado->Size = System::Drawing::Size(84, 16);
			this->lblEstado->TabIndex = 12;
			this->lblEstado->Text = L"Estado: Listo";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(151, 511);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(216, 23);
			this->progressBar1->TabIndex = 13;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox9->Location = System::Drawing::Point(464, 206);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(417, 237);
			this->pictureBox9->TabIndex = 14;
			this->pictureBox9->TabStop = false;
			// 
			// Client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(893, 546);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->lblEstado);
			this->Controls->Add(this->btnPreparar);
			this->Controls->Add(this->checkBoxHielo);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBoxTamano);
			this->Controls->Add(this->comboBoxBebida);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Client";
			this->Text = L"Client";
			this->Load += gcnew System::EventHandler(this, &Client::Client_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Client_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ ruta = Path::Combine(Application::StartupPath, "..\\..\\..\\imagenes\\bar.png");

		if (File::Exists(ruta)) {
			//pictureBox1->Image = Image::FromFile(ruta);
			//pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
		}

		// Bebidas disponibles
		comboBoxBebida->Items->Add("Mojito");
		comboBoxBebida->Items->Add("Cuba Libre");
		comboBoxBebida->Items->Add("Daikiri");

		// Tamaños
		comboBoxTamano->Items->Add("Pequeño");
		comboBoxTamano->Items->Add("Mediano");
		comboBoxTamano->Items->Add("Grande");

		lblEstado->Text = "Estado: Listo";
		progressBar1->Value = 0;
	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnPreparar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBoxBebida->SelectedIndex == -1) {
			MessageBox::Show("Seleccione una bebida");
			return;
		}

		if (comboBoxTamano->SelectedIndex == -1) {
			MessageBox::Show("Seleccione un tamaño");
			return;
		}

		lblEstado->Text = "Estado: Preparando bebida...";
		progressBar1->Value = 100;

		String^ bebida = comboBoxBebida->Text;
		String^ tamano = comboBoxTamano->Text;

		String^ hielo;

		if (checkBoxHielo->Checked)
			hielo = "Con hielo";
		else
			hielo = "Sin hielo";

		MessageBox::Show(
			"Bebida: " + bebida +
			"\nTamaño: " + tamano +
			"\n" + hielo,
			"Pedido realizado"
		);

		lblEstado->Text = "Estado: Bebida lista";
	}
	};
}