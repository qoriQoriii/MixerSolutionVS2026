#pragma once

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ModelMixer;
	using namespace ControllerMixer;

	/// <summary>
	/// Resumen de AgregarBebida
	/// </summary>
	public ref class AgregarBebida : public System::Windows::Forms::Form{
	public:
		AgregarBebida(void){
			InitializeComponent();
			
		}
	public:
		AgregarBebida(String^ nom, String^ pre, String^ est, String^ prop) {
			InitializeComponent();

			txtNombre->Text = nom;
			txtPrecio->Text = pre;
			cmbEstado->Text = est;
			txtProporcion->Text = prop;
		}


		String^ nombre;
		String^ precio;
		String^ estado;
		String^ proporcion;
		int filaSeleccionada;

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AgregarBebida()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::TextBox^ txtNombre;
	private:

	protected:

	private: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::TextBox^ txtPrecio;
	private:


	private: System::Windows::Forms::Label^ label3;
	//public: System::Windows::Forms::TextBox^ txtEstado;
	public: System::Windows::Forms::ComboBox^ cmbEstado;
	public: System::Windows::Forms::TextBox^ txtProporcion;
	private: System::Windows::Forms::Label^ label4;
	private:

	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnCancelar;




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtProporcion = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label1->Location = System::Drawing::Point(173, 189);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(301, 191);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(100, 22);
			this->txtNombre->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label2->Location = System::Drawing::Point(173, 257);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Precio";
			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(301, 259);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(100, 22);
			this->txtPrecio->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label3->Location = System::Drawing::Point(173, 349);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 24);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Estado";
			// 
			// cmbEstado
			// 
			this->cmbEstado->FormattingEnabled = true;
			this->cmbEstado->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Disponible", L"Agotado" });
			this->cmbEstado->Location = System::Drawing::Point(301, 351);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(120, 24);
			this->cmbEstado->TabIndex = 5;
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(136, 480);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(140, 43);
			this->btnGuardar->TabIndex = 8;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &AgregarBebida::btnGuardar_Click_1);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(354, 480);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(102, 43);
			this->btnCancelar->TabIndex = 7;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &AgregarBebida::btnCancelar_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label4->Location = System::Drawing::Point(173, 420);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 24);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Proporción";
			// 
			// txtProporcion
			// 
			this->txtProporcion->Location = System::Drawing::Point(301, 422);
			this->txtProporcion->Name = L"txtProporcion";
			this->txtProporcion->Size = System::Drawing::Size(100, 22);
			this->txtProporcion->TabIndex = 7;
			// 
			// AgregarBebida
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(672, 635);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->txtProporcion);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->cmbEstado);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label1);
			this->Name = L"AgregarBebida";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AgregarBebida";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
	nombre = txtNombre->Text;
	precio = txtPrecio->Text;
	estado = cmbEstado->Text;
	proporcion = txtProporcion->Text;

	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
private: System::Void btnGuardar_Click_1(System::Object^ sender, System::EventArgs^ e) {
	nombre = txtNombre->Text;
	precio = txtPrecio->Text;
	estado = cmbEstado->Text;
	proporcion = txtProporcion->Text;

	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();




}
};
}
