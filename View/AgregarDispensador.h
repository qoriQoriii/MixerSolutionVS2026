#pragma once

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AgregarDispensador
	/// </summary>
	public ref class AgregarDispensador : public System::Windows::Forms::Form
	{
	public:
		// Modo "Agregar": no hay id todavia (se asigna en la BD).
		AgregarDispensador(void)
		{
			InitializeComponent();
			this->id = 0;
		}

		// Modo "Modificar": se recibe el id real del mixer a editar.
		AgregarDispensador(int id, String^ nom, String^ est)
		{
			InitializeComponent();

			this->id = id;
			txtNombre->Text = nom;
			txtEstado->Text = est;
		}

		int id;
		String^ nombre;
		String^ estado;

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AgregarDispensador()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtEstado;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtEstado = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(221, 171);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(221, 261);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Estado:";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(416, 171);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(116, 22);
			this->txtNombre->TabIndex = 2;
			// 
			// txtEstado
			// 
			this->txtEstado->Location = System::Drawing::Point(416, 265);
			this->txtEstado->Name = L"txtEstado";
			this->txtEstado->Size = System::Drawing::Size(116, 22);
			this->txtEstado->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(226, 388);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 58);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AgregarDispensador::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->Location = System::Drawing::Point(416, 388);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 58);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AgregarDispensador::button2_Click);
			// 
			// AgregarDispensador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(759, 574);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtEstado);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AgregarDispensador";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AgregarDispensador";
			this->Load += gcnew System::EventHandler(this, &AgregarDispensador::AgregarDispensador_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		if (String::IsNullOrWhiteSpace(txtNombre->Text) || String::IsNullOrWhiteSpace(txtEstado->Text)) {
			MessageBox::Show("Nombre y estado son obligatorios.", "Datos incompletos",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		nombre = txtNombre->Text;
		estado = txtEstado->Text;

		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void AgregarDispensador_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}