#pragma once
#include "AgregarDispensador.h"


namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Resumen de Pedidos
	/// </summary>
	public ref class Pedidos : public System::Windows::Forms::Form
	{
	public:
		Pedidos(void)
		{
			InitializeComponent();


			RedondearBoton(btnAgregar, 25);
			RedondearBoton(btnModificar, 25);
			RedondearBoton(btnEliminar, 25);
			RedondearBoton(button1, 25);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Pedidos()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::DataGridView^ dgvPedidos;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::Button^ btnModificar;
	private: System::Windows::Forms::Button^ btnEliminar;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Pedidos::typeid));
			this->dgvPedidos = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPedidos))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvPedidos
			// 
			this->dgvPedidos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPedidos->Location = System::Drawing::Point(100, 120);
			this->dgvPedidos->Name = L"dgvPedidos";
			this->dgvPedidos->RowHeadersWidth = 51;
			this->dgvPedidos->RowTemplate->Height = 24;
			this->dgvPedidos->Size = System::Drawing::Size(600, 220);
			this->dgvPedidos->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(560, 443);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 55);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Volver";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Pedidos::button1_Click);
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(156, 443);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(106, 55);
			this->btnAgregar->TabIndex = 3;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &Pedidos::btnAgregar_Click);
			// 
			// btnModificar
			// 
			this->btnModificar->Location = System::Drawing::Point(289, 443);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(106, 55);
			this->btnModificar->TabIndex = 4;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = true;
			this->btnModificar->Click += gcnew System::EventHandler(this, &Pedidos::btnModificar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(422, 443);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(106, 55);
			this->btnEliminar->TabIndex = 5;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &Pedidos::btnEliminar_Click);
			// 
			// Pedidos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(792, 550);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnModificar);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dgvPedidos);
			this->Name = L"Pedidos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pedidos";
			this->Load += gcnew System::EventHandler(this, &Pedidos::Pedidos_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPedidos))->EndInit();
			this->ResumeLayout(false);

		}
		void RedondearBoton(Button^ btn, int radio)
		{
			GraphicsPath^ path = gcnew GraphicsPath();

			path->AddArc(0, 0, radio, radio, 180, 90);
			path->AddArc(btn->Width - radio, 0, radio, radio, 270, 90);
			path->AddArc(btn->Width - radio, btn->Height - radio, radio, radio, 0, 90);
			path->AddArc(0, btn->Height - radio, radio, radio, 90, 90);

			path->CloseFigure();

			btn->Region = gcnew System::Drawing::Region(path);
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	
	private: System::Void Pedidos_Load(System::Object^ sender, System::EventArgs^ e) {
		
		dgvPedidos->Columns->Clear();

		dgvPedidos->Columns->Add("ID", "ID");
		dgvPedidos->Columns->Add("Nombre", "Nombre");
		dgvPedidos->Columns->Add("Estado", "Estado");

		dgvPedidos->Rows->Add("1", "Mixer 1", "Activo");
		dgvPedidos->Rows->Add("2", "Mixer 2", "Activo");
		dgvPedidos->Rows->Add("3", "Mixer 3", "Desconectado");
		dgvPedidos->Rows->Add("4", "Mixer 4", "Desconectado");

		dgvPedidos->ReadOnly = true;
		dgvPedidos->AllowUserToAddRows = false;
		dgvPedidos->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

		// Fondo general
		dgvPedidos->BackgroundColor = Color::FromArgb(30, 30, 30);
		dgvPedidos->BorderStyle = BorderStyle::None;

		// Encabezados
		dgvPedidos->EnableHeadersVisualStyles = false;
		dgvPedidos->ColumnHeadersDefaultCellStyle->BackColor = Color::DarkOrange;
		dgvPedidos->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
		dgvPedidos->ColumnHeadersDefaultCellStyle->Font =
			gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);

		// Celdas
		dgvPedidos->DefaultCellStyle->BackColor = Color::FromArgb(45, 45, 45);
		dgvPedidos->DefaultCellStyle->ForeColor = Color::White;
		dgvPedidos->DefaultCellStyle->SelectionBackColor = Color::Orange;
		dgvPedidos->DefaultCellStyle->SelectionForeColor = Color::Black;

		// Filas
		dgvPedidos->RowHeadersVisible = false;
		dgvPedidos->GridColor = Color::Gray;

		// Fuente
		dgvPedidos->DefaultCellStyle->Font =
			gcnew System::Drawing::Font("Segoe UI", 12);

		dgvPedidos->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
		dgvPedidos->AllowUserToResizeRows = false;
		dgvPedidos->ScrollBars = ScrollBars::Vertical;

		// BOTONES
		btnAgregar->FlatStyle = FlatStyle::Flat;
		btnModificar->FlatStyle = FlatStyle::Flat;
		btnEliminar->FlatStyle = FlatStyle::Flat;
		button1->FlatStyle = FlatStyle::Flat;

		btnAgregar->BackColor = Color::FromArgb(20, 20, 20);
		btnModificar->BackColor = Color::FromArgb(20, 20, 20);
		btnEliminar->BackColor = Color::FromArgb(20, 20, 20);
		button1->BackColor = Color::FromArgb(20, 20, 20);

		btnAgregar->ForeColor = Color::White;
		btnModificar->ForeColor = Color::White;
		btnEliminar->ForeColor = Color::White;
		button1->ForeColor = Color::White;

		btnAgregar->FlatAppearance->BorderColor = Color::DarkOrange;
		btnModificar->FlatAppearance->BorderColor = Color::DarkOrange;
		button1->FlatAppearance->BorderColor = Color::DarkOrange;

		btnEliminar->FlatAppearance->BorderColor = Color::Red;

		btnAgregar->FlatAppearance->BorderSize = 2;
		btnModificar->FlatAppearance->BorderSize = 2;
		btnEliminar->FlatAppearance->BorderSize = 2;
		button1->FlatAppearance->BorderSize = 2;
	}
	private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
		AgregarDispensador^ form = gcnew AgregarDispensador();

		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			int id = dgvPedidos->Rows->Count + 1;

			dgvPedidos->Rows->Add(
				id.ToString(),
				form->nombre,
				form->estado
			);
		}
	}
private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dgvPedidos->SelectedRows->Count > 0) {

		if (MessageBox::Show("¿Desea eliminar el dispensador?","Confirmar",MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			dgvPedidos->Rows->RemoveAt(dgvPedidos->SelectedRows[0]->Index);
		}
	}
}
private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dgvPedidos->SelectedRows->Count > 0) {

		int fila = dgvPedidos->SelectedRows[0]->Index;

		String^ nombre = dgvPedidos->Rows[fila]->Cells[1]->Value->ToString();
		String^ estado = dgvPedidos->Rows[fila]->Cells[2]->Value->ToString();

		AgregarDispensador^ form = gcnew AgregarDispensador(nombre, estado);

		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			dgvPedidos->Rows[fila]->Cells[1]->Value = form->nombre;
			dgvPedidos->Rows[fila]->Cells[2]->Value = form->estado;
		}
	}
}
};
}
