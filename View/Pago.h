#pragma once
#include "Confirmacion.h"

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Pago
	/// </summary>
	public ref class Pago : public System::Windows::Forms::Form
	{
	public:
		Pago(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Pago()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTitulo;
	protected:

	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnConfirmarPago;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Pago::typeid));
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnConfirmarPago = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->Location = System::Drawing::Point(233, 53);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(97, 22);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"YAPE QR";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(147, 105);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(281, 260);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// btnConfirmarPago
			// 
			this->btnConfirmarPago->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F));
			this->btnConfirmarPago->Location = System::Drawing::Point(237, 392);
			this->btnConfirmarPago->Name = L"btnConfirmarPago";
			this->btnConfirmarPago->Size = System::Drawing::Size(113, 63);
			this->btnConfirmarPago->TabIndex = 2;
			this->btnConfirmarPago->Text = L"Confirmar pago";
			this->btnConfirmarPago->UseVisualStyleBackColor = true;
			this->btnConfirmarPago->Click += gcnew System::EventHandler(this, &Pago::button1_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F));
			this->btnCancelar->Location = System::Drawing::Point(237, 478);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(113, 45);
			this->btnCancelar->TabIndex = 3;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &Pago::btnCancelar_Click);
			// 
			// Pago
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 555);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnConfirmarPago);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblTitulo);
			this->Name = L"Pago";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pago";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();

		Confirmacion^ form = gcnew Confirmacion();
		form->ShowDialog();

		this->Show();
	}
private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
