#pragma once

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Disfrute
	/// </summary>
	public ref class Disfrute : public System::Windows::Forms::Form
	{
	public:
		Disfrute(void)
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
		~Disfrute()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ btnAceptar;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Disfrute::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(155, 213);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(363, 60);
			this->label1->TabIndex = 0;
			this->label1->Text = L"¡Su bebida está lista!";
			this->label1->Click += gcnew System::EventHandler(this, &Disfrute::label1_Click);
			// 
			// btnAceptar
			// 
			this->btnAceptar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAceptar->Location = System::Drawing::Point(249, 336);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(140, 45);
			this->btnAceptar->TabIndex = 1;
			this->btnAceptar->Text = L"Aceptar";
			this->btnAceptar->UseVisualStyleBackColor = true;
			this->btnAceptar->Click += gcnew System::EventHandler(this, &Disfrute::btnAceptar_Click);
			// 
			// Disfrute
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(630, 561);
			this->Controls->Add(this->btnAceptar);
			this->Controls->Add(this->label1);
			this->Name = L"Disfrute";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mixer - Disfrute";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnAceptar_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
