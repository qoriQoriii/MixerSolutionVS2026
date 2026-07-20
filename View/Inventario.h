#pragma once
#include "AgregarBebida.h"
//#include "InventarioController.h"



namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace ControllerMixer;
	using namespace ModelMixer;
	using namespace System::Data::SqlClient;


	

	/// <summary>
	/// Resumen de Inventario
	/// </summary>
	public ref class Inventario : public System::Windows::Forms::Form
	{
	public:
		Inventario(void)
		{
			InitializeComponent();


			RedondearBoton(btnAgregar, 25);
			RedondearBoton(btnModificar, 25);
			RedondearBoton(btnEliminar, 25);
			RedondearBoton(btnVolver, 25);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Inventario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnVolver;
	protected:

	private: System::Windows::Forms::DataGridView^ dgvInventario;

	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::Button^ btnModificar;
	private: System::Windows::Forms::Button^ btnEliminar;
		   


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Inventario::typeid));
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->dgvInventario = (gcnew System::Windows::Forms::DataGridView());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInventario))->BeginInit();
			this->SuspendLayout();
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(575, 370);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(104, 53);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Inventario::button1_Click);
			// 
			// dgvInventario
			// 
			this->dgvInventario->BackgroundColor = System::Drawing::Color::Black;
			this->dgvInventario->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvInventario->GridColor = System::Drawing::Color::Black;
			this->dgvInventario->Location = System::Drawing::Point(120, 120);
			this->dgvInventario->Name = L"dgvInventario";
			this->dgvInventario->RowHeadersWidth = 51;
			this->dgvInventario->RowTemplate->Height = 24;
			this->dgvInventario->Size = System::Drawing::Size(600, 220);
			this->dgvInventario->TabIndex = 1;
			this->dgvInventario->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Inventario::dgvInventario_CellContentClick);
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(171, 369);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(104, 53);
			this->btnAgregar->TabIndex = 3;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &Inventario::btnAgregar_Click);
			// 
			// btnModificar
			// 
			this->btnModificar->Location = System::Drawing::Point(307, 369);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(104, 52);
			this->btnModificar->TabIndex = 4;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = true;
			this->btnModificar->Click += gcnew System::EventHandler(this, &Inventario::btnModificar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(446, 370);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(104, 52);
			this->btnEliminar->TabIndex = 5;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &Inventario::btnEliminar_Click);
			// 
			// Inventario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(846, 499);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnModificar);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->dgvInventario);
			this->Controls->Add(this->btnVolver);
			this->Name = L"Inventario";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Inventario";
			this->Activated += gcnew System::EventHandler(this, &Inventario::Inventario_Activated);
			this->Load += gcnew System::EventHandler(this, &Inventario::Inventario_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInventario))->EndInit();
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

		private: void cargarData()
		{
			dgvInventario->Columns->Clear();

			dgvInventario->Columns->Add("ID", "ID");
			dgvInventario->Columns->Add("Nombre", "Bebida");
			dgvInventario->Columns->Add("Precio", "Precio");
			dgvInventario->Columns->Add("Estado", "Estado");
			dgvInventario->Columns->Add("Proporcion", "Proporción");

			dgvInventario->ReadOnly = true;

			dgvInventario->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

			dgvInventario->MultiSelect = false;

			List<Bebida^>^ listaBebidas = InventarioController::GetAllBebidas();
			for each(Bebida ^ b in listaBebidas)
			{
				dgvInventario->Rows->Add(
					b->id.ToString(),
					b->nombre,
					b->precio.ToString(),
					String::IsNullOrEmpty(b->estado) ? "Disponible" : b->estado,
					String::IsNullOrEmpty(b->proporcion) ? "-" : b->proporcion
				);
			}


			dgvInventario->AllowUserToAddRows = false;
			dgvInventario->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;


		}
	private: System::Void Inventario_Load(System::Object^ sender, System::EventArgs^ e) {
		


		cargarData();
/*
		
		dgvInventario->Rows->Add("1", "Mojito", "18", "Disponible");
		dgvInventario->Rows->Add("2", "Margarita", "20", "Disponible");
		dgvInventario->Rows->Add("3", "Piña Colada", "22", "Agotada");
		
		String^ cadena =
			"Server=200.16.7.140;"
			"Database=a20201150;"
			"User Id=a20201150;"
			"Password=f0wHl52n;"
			"TrustServerCertificate=True;";

		SqlConnection^ conexion = gcnew SqlConnection(cadena);
		conexion->Open();


		SqlCommand^ cmd =
			gcnew SqlCommand(
				"SELECT Id, Nombre, Precio, Estado, Proporcion FROM Bebidas",
				conexion);

		SqlDataReader^ reader = cmd->ExecuteReader();

*/



		// Fondo general
		dgvInventario->BackgroundColor = Color::FromArgb(30, 30, 30);
		dgvInventario->BorderStyle = BorderStyle::None;

		// Encabezados
		dgvInventario->EnableHeadersVisualStyles = false;
		dgvInventario->ColumnHeadersDefaultCellStyle->BackColor = Color::DarkOrange;
		dgvInventario->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
		dgvInventario->ColumnHeadersDefaultCellStyle->Font =
			gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);

		// Celdas
		dgvInventario->DefaultCellStyle->BackColor = Color::FromArgb(45, 45, 45);
		dgvInventario->DefaultCellStyle->ForeColor = Color::White;
		dgvInventario->DefaultCellStyle->SelectionBackColor = Color::Orange;
		dgvInventario->DefaultCellStyle->SelectionForeColor = Color::Black;

		// Filas
		dgvInventario->RowHeadersVisible = false;
		dgvInventario->GridColor = Color::Gray;

		// Fuente
		dgvInventario->DefaultCellStyle->Font =
			gcnew System::Drawing::Font("Segoe UI", 10);

		dgvInventario->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
		dgvInventario->AllowUserToResizeRows = false;

		dgvInventario->ScrollBars = ScrollBars::Vertical;
		//ultima modificacion:
		btnAgregar->FlatStyle = FlatStyle::Flat;
		btnModificar->FlatStyle = FlatStyle::Flat;
		btnEliminar->FlatStyle = FlatStyle::Flat;
		btnVolver->FlatStyle = FlatStyle::Flat;

		btnAgregar->BackColor = Color::FromArgb(20, 20, 20);
		btnModificar->BackColor = Color::FromArgb(20, 20, 20);
		btnEliminar->BackColor = Color::FromArgb(20, 20, 20);
		btnVolver->BackColor = Color::FromArgb(20, 20, 20);

		btnAgregar->ForeColor = Color::White;
		btnModificar->ForeColor = Color::White;
		btnEliminar->ForeColor = Color::White;
		btnVolver->ForeColor = Color::White;

		btnAgregar->FlatAppearance->BorderColor = Color::DarkOrange;
		btnModificar->FlatAppearance->BorderColor = Color::DarkOrange;
		btnVolver->FlatAppearance->BorderColor = Color::DarkOrange;

		btnEliminar->FlatAppearance->BorderColor = Color::Red;

		btnAgregar->FlatAppearance->BorderSize = 2;
		btnModificar->FlatAppearance->BorderSize = 2;
		btnEliminar->FlatAppearance->BorderSize = 2;
		btnVolver->FlatAppearance->BorderSize = 2;

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
		AgregarBebida^ form = gcnew AgregarBebida();

		
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				int id = dgvInventario->Rows->Count + 1;

			
				

				/*
								String^ cadena =
					"Server=200.16.7.140;"
					"Database=a20201150;"
					"User Id=a20201150;"
					"Password=f0wHl52n;"
					"TrustServerCertificate=True;";

				SqlConnection^ conexion = gcnew SqlConnection(cadena);
				conexion->Open();

				SqlCommand^ verificar = gcnew SqlCommand(
					"SELECT COUNT(*) FROM Bebidas WHERE Nombre = @nombre",
					conexion);

				verificar->Parameters->AddWithValue("@nombre", form->nombre);
				*/

				
				List<Bebida^>^ listabebida = InventarioController::GetAllBebidas();

				int existe;
				for each (Bebida ^ b in listabebida) {

					if (form->nombre == b->nombre) {
						int existe  = 1;
						break;
					}
				}

				//int existe = Convert::ToInt32(verificar->ExecuteScalar());

				if (existe == 1)
				{
					MessageBox::Show("Ya existe una bebida con ese nombre");
					//conexion->Close();
					return;
				}

/*				SqlCommand^ cmd = gcnew SqlCommand(
					"INSERT INTO Bebidas (Id, Nombre, Precio, Estado, Proporcion) VALUES (@id, @nombre, @precio, @estado, @proporcion)",
					conexion);

				cmd->Parameters->AddWithValue("@id", id);
				cmd->Parameters->AddWithValue("@nombre", form->nombre);
				cmd->Parameters->AddWithValue("@precio", Int32::Parse(form->precio));
				cmd->Parameters->AddWithValue("@estado", form->estado);
				cmd->Parameters->AddWithValue("@proporcion", form->proporcion);

				cmd->ExecuteNonQuery();

				conexion->Close();
				
				*/

				int resultado = InventarioController::CreateBebida(id, form->nombre, Int32::Parse(form->precio), form->estado, form->proporcion);

				dgvInventario->Rows->Add(
					id.ToString(),
					form->nombre,
					form->precio,
					form->estado,
					form->proporcion
				);

				if(resultado) MessageBox::Show("Bebida agregada correctamente");
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}

		


	}
private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {

	if (dgvInventario->SelectedRows->Count > 0) {

		if (MessageBox::Show(
			"¿Desea eliminar la bebida?",
			"Confirmar",
			MessageBoxButtons::YesNo
		) == System::Windows::Forms::DialogResult::Yes) {

			try
			{
				int fila = dgvInventario->SelectedRows[0]->Index;

				int id = Int32::Parse(
					dgvInventario->Rows[fila]->Cells[0]->Value->ToString()


				);

/*
				String^ cadena =
					"Server=200.16.7.140;"
					"Database=a20201150;"
					"User Id=a20201150;"
					"Password=f0wHl52n;"
					"TrustServerCertificate=True;";

				SqlConnection^ conexion = gcnew SqlConnection(cadena);
				conexion->Open();

				SqlCommand^ cmd = gcnew SqlCommand(
					"DELETE FROM Bebidas WHERE Id = @id",
					conexion);

				cmd->Parameters->AddWithValue("@id", id);

				cmd->ExecuteNonQuery();

				conexion->Close();
*/


				if (InventarioController::DeleteBebida(id)) {
					dgvInventario->Rows->RemoveAt(fila);

					MessageBox::Show("Bebida eliminada correctamente");

				}
				else {
					MessageBox::Show("La bebida no fue eliminada correctamente");

				}


			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
	}
}
private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (dgvInventario->SelectedRows->Count > 0)
	{
		try
		{
			int fila = dgvInventario->SelectedRows[0]->Index;

			int id = Int32::Parse(
				dgvInventario->Rows[fila]->Cells[0]->Value->ToString()
			);

			String^ nombre = dgvInventario->Rows[fila]->Cells[1]->Value->ToString();
			String^ precio = dgvInventario->Rows[fila]->Cells[2]->Value->ToString();
			String^ estado = dgvInventario->Rows[fila]->Cells[3]->Value->ToString();
			String^ proporcion = dgvInventario->Rows[fila]->Cells[4]->Value->ToString();

			AgregarBebida^ form =
				gcnew AgregarBebida(nombre, precio, estado, proporcion);

			if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
	/*
				String^ cadena =
					"Server=200.16.7.140;"
					"Database=a20201150;"
					"User Id=a20201150;"
					"Password=f0wHl52n;"
					"TrustServerCertificate=True;";

				SqlConnection^ conexion =
					gcnew SqlConnection(cadena);

				conexion->Open();

				SqlCommand^ cmd = gcnew SqlCommand(
					"UPDATE Bebidas "
					"SET Nombre = @nombre, Precio = @precio, Estado = @estado, Proporcion = @proporcion "
					"WHERE Id = @id",
					conexion);

				cmd->Parameters->AddWithValue("@id", id);
				cmd->Parameters->AddWithValue("@nombre", form->nombre);
				cmd->Parameters->AddWithValue("@precio",
					Int32::Parse(form->precio));
				cmd->Parameters->AddWithValue("@estado", form->estado);
				cmd->Parameters->AddWithValue("@proporcion", form->proporcion);

				cmd->ExecuteNonQuery();


				conexion->Close();
	
	*/
				int resultado = InventarioController::UpdateBebida(id, form->nombre, Int32::Parse(form->precio), form->estado, form->proporcion);

				if (resultado) {

					dgvInventario->Rows[fila]->Cells[1]->Value = form->nombre;
					dgvInventario->Rows[fila]->Cells[2]->Value = form->precio;
					dgvInventario->Rows[fila]->Cells[3]->Value = form->estado;
					dgvInventario->Rows[fila]->Cells[4]->Value = form->proporcion;

					MessageBox::Show("Bebida modificada correctamente");
				}

			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

}
private: System::Void dgvInventario_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void Inventario_Activated(System::Object^ sender, System::EventArgs^ e) {

	cargarData();

	/////////////////////////7
}
};
}
