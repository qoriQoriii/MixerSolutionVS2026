#pragma once
#include "Disfrute.h"

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	public ref class Preparacion : public System::Windows::Forms::Form
	{
	private:
		int angulo = 0;
		int contador = 0;

	public:
		Preparacion(void)
		{
			InitializeComponent();
			pbGif->Image = Image::FromFile("..\\imagenes\\preparacion.gif");
		}

	protected:
		~Preparacion()
		{
			if (components)
			{
				delete components;
			}
		}

		virtual void OnPaint(PaintEventArgs^ e) override
		{
			Form::OnPaint(e);
			Graphics^ g = e->Graphics;
			g->SmoothingMode = SmoothingMode::AntiAlias;

			float size = 80.0f;
			float grosor = 10.0f;
			float x = (this->ClientSize.Width - size) / 2.0f - 10.0f;
			float y = (this->ClientSize.Height - size - 100.0f);

			Pen^ pista = gcnew Pen(Color::FromArgb(60, 255, 255, 255), grosor);
			pista->StartCap = LineCap::Round;
			pista->EndCap = LineCap::Round;
			g->DrawEllipse(pista, x, y, size, size);

			Pen^ arco = gcnew Pen(Color::White, grosor);
			arco->StartCap = LineCap::Round;
			arco->EndCap = LineCap::Round;
			g->DrawArc(arco, x, y, size, size, (float)angulo, 270.0f);

			delete pista;
			delete arco;
		}

	private:
		System::Windows::Forms::Timer^ timerLoading;
		System::Windows::Forms::Label^ lblEstado;
		System::Windows::Forms::Timer^ timer1;
		System::Windows::Forms::PictureBox^ pbGif;
		System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Preparacion::typeid));
			this->lblEstado = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pbGif = (gcnew System::Windows::Forms::PictureBox());
			this->timerLoading = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGif))->BeginInit();
			this->SuspendLayout();
			// 
			// lblEstado
			// 
			this->lblEstado->AutoSize = true;
			this->lblEstado->BackColor = System::Drawing::Color::Transparent;
			this->lblEstado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lblEstado->ForeColor = System::Drawing::Color::Black;
			this->lblEstado->Location = System::Drawing::Point(202, 439);
			this->lblEstado->Name = L"lblEstado";
			this->lblEstado->Size = System::Drawing::Size(193, 25);
			this->lblEstado->TabIndex = 0;
			this->lblEstado->Text = L"Preparando bebida...";
			this->lblEstado->Click += gcnew System::EventHandler(this, &Preparacion::lblEstado_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Preparacion::timer1_Tick);
			// 
			// pbGif
			// 
			this->pbGif->BackColor = System::Drawing::Color::Black;
			this->pbGif->Location = System::Drawing::Point(216, 23);
			this->pbGif->Name = L"pbGif";
			this->pbGif->Size = System::Drawing::Size(154, 248);
			this->pbGif->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbGif->TabIndex = 1;
			this->pbGif->TabStop = false;
			// 
			// timerLoading
			// 
			this->timerLoading->Enabled = true;
			this->timerLoading->Tick += gcnew System::EventHandler(this, &Preparacion::timerLoading_Tick);
			// 
			// Preparacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(606, 526);
			this->Controls->Add(this->pbGif);
			this->Controls->Add(this->lblEstado);
			this->DoubleBuffered = true;
			this->Name = L"Preparacion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mixer - Preparacion";
			this->Load += gcnew System::EventHandler(this, &Preparacion::Preparacion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGif))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Preparacion_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		contador++;

		if (contador >= 100)
		{
			timer1->Stop();
			timerLoading->Stop();

			this->Hide();

			Disfrute^ f = gcnew Disfrute();
			f->ShowDialog();

			

			this->Close();
		}
	}
	private: System::Void lblEstado_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void timerLoading_Tick(System::Object^ sender, System::EventArgs^ e) {
	angulo += 6;
	if (angulo >= 360) angulo = 0;
	this->Invalidate();
	
}

};
}
