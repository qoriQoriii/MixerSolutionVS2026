#pragma once
#include "Admin.h"
#include "Client.h"


namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ControllerMixer;
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->BackgroundImage = Image::FromFile(Application::StartupPath + "..\\..\\..\\imagenes\\bar.png");
			this->BackgroundImageLayout = ImageLayout::Stretch;

			ControllerMixer::UsuarioController::Cargar();
			ControllerMixer::InventarioController::Cargar();
			ControllerMixer::PedidoController::Cargar();
			ControllerMixer::MixerController::Cargar();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()

		{

			ControllerMixer::UsuarioController::Guardar();
			ControllerMixer::InventarioController::Guardar();
			ControllerMixer::PedidoController::Guardar();
			ControllerMixer::MixerController::Guardar();




			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::TextBox^ txtContra;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;




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
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->txtContra = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtUsuario
			// 
			this->txtUsuario->Location = System::Drawing::Point(252, 213);
			this->txtUsuario->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(148, 30);
			this->txtUsuario->TabIndex = 0;
			this->txtUsuario->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// txtContra
			// 
			this->txtContra->Location = System::Drawing::Point(252, 285);
			this->txtContra->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtContra->Name = L"txtContra";
			this->txtContra->Size = System::Drawing::Size(148, 30);
			this->txtContra->TabIndex = 1;
			this->txtContra->UseSystemPasswordChar = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(130, 213);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"User";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(108, 285);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(200, 374);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 35);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Ingresar";
			this->button1->UseCompatibleTextRendering = true;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(865, 579);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtContra);
			this->Controls->Add(this->txtUsuario);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			String^ cadena =
				"Server=200.16.7.140;"
				"Database=a20201150;"
				"User Id=a20201150;"
				"Password=f0wHl52n;"
				"TrustServerCertificate=True;";

			SqlConnection^ conexion = gcnew SqlConnection(cadena);
			conexion->Open();
			String^ user = this->txtUsuario->Text;
			String^ password = this->txtContra->Text;

			SqlCommand^ cmd = gcnew SqlCommand(
				"SELECT TipoUsuario FROM Usuarios WHERE DNI = @dni AND Contrasena = @contra",
				conexion);

			cmd->Parameters->AddWithValue("@dni", user);
			cmd->Parameters->AddWithValue("@contra", password);

			Object^ resultado = cmd->ExecuteScalar();

			if (resultado != nullptr)
			{
				String^ tipoUsuario = resultado->ToString();

				this->Hide();

				if (tipoUsuario == "Administrador")
				{
					Admin^ admin_menu = gcnew Admin();
					admin_menu->ShowDialog();
				}
				else
				{
					Client^ client_menu = gcnew Client();
					client_menu->ShowDialog();
				}

				this->Close();
			}
			else
			{
				MessageBox::Show("Usuario o contraseña incorrectos");
			}

			//MessageBox::Show("Conexión exitosa");

			conexion->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
		/*
		String^ user = this->txtUsuario->Text;
		String^ password = this->txtContra->Text;

		String^ user_admin_correcto = "admin1";
		String^ password_admin_correcto = "1234";

		String^ user_client_correcto = "cliente1";
		String^ password_client_correcto = "1234";

		if (user->Equals(user_admin_correcto) && password->Equals(password_admin_correcto)) {
			this->Hide();
			Admin^ admin_menu = gcnew Admin();
			admin_menu->ShowDialog();
			this->Close();
		}
		else if (user->Equals(user_client_correcto) && password->Equals(password_client_correcto)) {
			this->Hide();
			Client^ client_menu = gcnew Client();
			client_menu->ShowDialog();
			this->Close();
		}
		else {
			MessageBox::Show("Usuario o contraseña incorrectos");

			txtContra->Clear();
			txtUsuario->Clear();
			txtUsuario->Focus();
		}
		*/
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}