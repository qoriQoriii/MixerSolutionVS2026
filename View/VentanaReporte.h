#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
//using namespace View;

using namespace ModelMixer;
using namespace ControllerMixer;
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
            System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->chartTanques = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->btnCerrar = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTanques))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::Color::Black;
            this->label1->Location = System::Drawing::Point(40, 25);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(240, 45);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Bebidas: Cargando...";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label2
            // 
            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
            this->label2->ForeColor = System::Drawing::Color::Black;
            this->label2->Location = System::Drawing::Point(310, 25);
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(250, 45);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Ingresos: Cargando...";
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // chartTanques
            // 
            chartArea1->Name = L"ChartArea1";
            this->chartTanques->ChartAreas->Add(chartArea1);
            this->chartTanques->Location = System::Drawing::Point(40, 100);
            this->chartTanques->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->chartTanques->Name = L"chartTanques";
            series1->ChartArea = L"ChartArea1";
            series1->Name = L"Series1";
            this->chartTanques->Series->Add(series1);
            this->chartTanques->Size = System::Drawing::Size(520, 260);
            this->chartTanques->TabIndex = 0;
            this->chartTanques->Text = L"chart1";
            // 
            // btnCerrar
            // 
            this->btnCerrar->Location = System::Drawing::Point(240, 390);
            this->btnCerrar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->btnCerrar->Name = L"btnCerrar";
            this->btnCerrar->Size = System::Drawing::Size(130, 35);
            this->btnCerrar->TabIndex = 1;
            this->btnCerrar->Text = L"Cerrar Ventana";
            this->btnCerrar->UseVisualStyleBackColor = true;
            this->btnCerrar->Click += gcnew System::EventHandler(this, &VentanaReporte::btnCerrar_Click);
            // 
            // VentanaReporte
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(600, 460);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->btnCerrar);
            this->Controls->Add(this->chartTanques);
            this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->Name = L"VentanaReporte";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Reporte de Administración";
            this->Load += gcnew System::EventHandler(this, &VentanaReporte::VentanaReporte_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTanques))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

        void ProcesarTodoElReporte()
        {
            try {
                /*
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

                                SqlCommand^ cmdVentas = gcnew SqlCommand(
                    "SELECT ISNULL(SUM(Cantidad), 0) AS TotalBebidas, ISNULL(SUM(Coste), 0) AS TotalIngresos FROM Ventas",
                    conexion);

                SqlDataReader^ readerVentas = cmdVentas->ExecuteReader();
                */

  

                /*
                              // 2. Leer totales de Ventas 

                List<Venta^>^ listaVenta = VentaController::GetAllVentas();

                int totalBebidasVendidas = 0;
                double totalDineroRegistrado = 0.0;

                for each (Venta^ v in listaVenta) {

                    totalBebidasVendidas += totalBebidasVendidas;
                    totalDineroRegistrado += totalDineroRegistrado;

                }


                this->label1->Text = L"Bebidas: " + totalBebidasVendidas.ToString();
                this->label2->Text = L"Ingresos: S/. " + totalDineroRegistrado.ToString(L"F2");

              
                this->chartTanques->Series[0]->Points->Clear();

                List<Bebida^>^ listaBebida = InventarioController::GetAllBebidas();

           


                for each (Bebida^ b in listaBebida) {
                    this->chartTanques->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;

                    this->chartTanques->Series[0]->Points->Clear();

                    this->chartTanques->Series[0]->Points->AddXY("Viernes", 15);
                    this->chartTanques->Series[0]->Points->AddXY("Sábado", 28);
                    this->chartTanques->Series[0]->Points->AddXY("Domingo", 22);
                }

                
                */


                /*

SqlCommand^ cmdBebidas = gcnew SqlCommand("SELECT Nombre, Precio FROM Bebidas", conexion);
SqlDataReader^ readerBebidas = cmdBebidas->ExecuteReader();
*/
                /*
                
                SqlCommand^ cmdBebidas = gcnew SqlCommand("SELECT Nombre, Precio FROM Bebidas", conexion);
                SqlDataReader^ readerBebidas = cmdBebidas->ExecuteReader();
                */

                // 1. Obtener lista de ventas
                List<Venta^>^ listaVenta = VentaController::GetAllVentas();

                int totalBebidasVendidas = 0;
                double totalDineroRegistrado = 0.0;

                // Diccionario para acumular las unidades vendidas de cada bebida
                Dictionary<String^, int>^ ventasPorBebida = gcnew Dictionary<String^, int>();

                for each(Venta ^ v in listaVenta) {
                    // Sumar las cantidades y costes reales de la venta
                    totalBebidasVendidas += v->cantidad;
                    totalDineroRegistrado += v->coste;

                    // Agrupar cantidad por nombre de bebida
                    if (ventasPorBebida->ContainsKey(v->nombreBebida)) {
                        ventasPorBebida[v->nombreBebida] += v->cantidad;
                    }
                    else {
                        ventasPorBebida->Add(v->nombreBebida, v->cantidad);
                    }
                }

                // 2. Actualizar Labels
                this->label1->Text = L"Bebidas: " + totalBebidasVendidas.ToString();
                this->label2->Text = L"Ingresos: S/. " + totalDineroRegistrado.ToString(L"F2");

                // 3. Configurar el gráfico UNA sola vez (fuera del bucle)
                this->chartTanques->Series[0]->Points->Clear();
                this->chartTanques->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;

                // 4. Agregar cada bebida y su total de ventas al gráfico
                for each(KeyValuePair<String^, int> ^ par in ventasPorBebida) {
                    // par->Key es el nombre de la bebida, par->Value es la cantidad total vendida
                    this->chartTanques->Series[0]->Points->AddXY(par->Key, par->Value);
                }


            }
            catch (Exception^ ex) {
                MessageBox::Show(L"Error de conexión con la BD: " + ex->Message, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    private: System::Void VentanaReporte_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}