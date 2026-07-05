#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;

namespace mixer {

    public ref class VentanaReporte : public System::Windows::Forms::Form
    {
    public:
        VentanaReporte(void)
        {
            InitializeComponent();
            ProcesarTodoElReporte();
        }

    protected:
        ~VentanaReporte()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::DataVisualization::Charting::Chart^ chartTanques;
        System::Windows::Forms::Button^ btnCerrar;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->chartTanques = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->btnCerrar = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTanques))->BeginInit();
            this->SuspendLayout();

            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::Color::Black;
            this->label1->Location = System::Drawing::Point(53, 31);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(320, 55);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Bebidas: Cargando...";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
            this->label2->ForeColor = System::Drawing::Color::Black;
            this->label2->Location = System::Drawing::Point(413, 31);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(333, 55);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Ingresos: Cargando...";
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

            chartArea2->Name = L"ChartArea1";
            this->chartTanques->ChartAreas->Add(chartArea2);
            this->chartTanques->Location = System::Drawing::Point(53, 123);
            this->chartTanques->Name = L"chartTanques";
            series2->ChartArea = L"ChartArea1";
            series2->Name = L"Series1";
            this->chartTanques->Series->Add(series2);
            this->chartTanques->Size = System::Drawing::Size(693, 320);
            this->chartTanques->TabIndex = 0;
            this->chartTanques->Text = L"chart1";

            this->btnCerrar->Location = System::Drawing::Point(320, 480);
            this->btnCerrar->Name = L"btnCerrar";
            this->btnCerrar->Size = System::Drawing::Size(173, 43);
            this->btnCerrar->TabIndex = 1;
            this->btnCerrar->Text = L"Cerrar Ventana";
            this->btnCerrar->UseVisualStyleBackColor = true;
            this->btnCerrar->Click += gcnew System::EventHandler(this, &VentanaReporte::btnCerrar_Click);

            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 566);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->btnCerrar);
            this->Controls->Add(this->chartTanques);
            this->Name = L"VentanaReporte";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Reporte de Administración";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTanques))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

        void ProcesarTodoElReporte()
        {
            try {
                String^ cadena =
                    "Server=200.16.7.140;"
                    "Database=a20201150;"
                    "User Id=a20201150;"
                    "Password=f0wHl52n;"
                    "TrustServerCertificate=True;";

                SqlConnection^ conexion = gcnew SqlConnection(cadena);
                conexion->Open();

                // 1. Mantenemos la creación de la tabla Ventas para cuando empieces a registrar compras
                String^ queryCrearVentas =
                    "IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Ventas' and xtype='U') "
                    "CREATE TABLE Ventas ("
                    "Id INT IDENTITY(1,1) PRIMARY KEY, "
                    "NombreBebida VARCHAR(100), "
                    "Cantidad INT, "
                    "Coste DECIMAL(10,2), "
                    "Fecha DATETIME DEFAULT GETDATE())";
                SqlCommand^ cmdCrearV = gcnew SqlCommand(queryCrearVentas, conexion);
                cmdCrearV->ExecuteNonQuery();

                // 2. Leer totales de Ventas 
                SqlCommand^ cmdVentas = gcnew SqlCommand(
                    "SELECT ISNULL(SUM(Cantidad), 0) AS TotalBebidas, ISNULL(SUM(Coste), 0) AS TotalIngresos FROM Ventas",
                    conexion);

                SqlDataReader^ readerVentas = cmdVentas->ExecuteReader();
                int totalBebidasVendidas = 0;
                double totalDineroRegistrado = 0.0;

                if (readerVentas->Read()) {
                    totalBebidasVendidas = Convert::ToInt32(readerVentas["TotalBebidas"]);
                    totalDineroRegistrado = Convert::ToDouble(readerVentas["TotalIngresos"]);
                }
                readerVentas->Close();

                this->label1->Text = L"Bebidas: " + totalBebidasVendidas.ToString();
                this->label2->Text = L"Ingresos: S/. " + totalDineroRegistrado.ToString(L"F2");

              
                this->chartTanques->Series[0]->Points->Clear();

           
                SqlCommand^ cmdBebidas = gcnew SqlCommand("SELECT Nombre, Precio FROM Bebidas", conexion);
                SqlDataReader^ readerBebidas = cmdBebidas->ExecuteReader();

                while (readerBebidas->Read()) {
                    this->chartTanques->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;

                    this->chartTanques->Series[0]->Points->Clear();

                    this->chartTanques->Series[0]->Points->AddXY("Viernes", 15);
                    this->chartTanques->Series[0]->Points->AddXY("Sábado", 28);
                    this->chartTanques->Series[0]->Points->AddXY("Domingo", 22);
                }
                readerBebidas->Close();

                conexion->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show(L"Error de conexión con la BD: " + ex->Message, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };
}