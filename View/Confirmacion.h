#pragma once
#include "Preparacion.h"


namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Confirmacion
	/// </summary>
	public ref class Confirmacion : public System::Windows::Forms::Form
	{
	public:
		Confirmacion(void)
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
		~Confirmacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnAceptar;
	protected:
	private: System::Windows::Forms::Label^ label1;






	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Confirmacion::typeid));
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnAceptar
			// 
			this->btnAceptar->Location = System::Drawing::Point(211, 279);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(103, 47);
			this->btnAceptar->TabIndex = 1;
			this->btnAceptar->Text = L"Aceptar";
			this->btnAceptar->UseVisualStyleBackColor = true;
			this->btnAceptar->Click += gcnew System::EventHandler(this, &Confirmacion::btnAceptar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(108, 206);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(302, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Pago realizado correctamente";
			// 
			// Confirmacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(533, 459);
			this->Controls->Add(this->btnAceptar);
			this->Controls->Add(this->label1);
			this->Name = L"Confirmacion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Confirmacion";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAceptar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();

		Preparacion^ form = gcnew Preparacion();
		form->ShowDialog();

		this->Show();
	}
	};
}
