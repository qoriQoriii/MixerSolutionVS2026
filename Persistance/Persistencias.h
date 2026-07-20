#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Xml::Serialization;


//correccion de diego
using namespace System::Data;
using namespace System::Data::SqlClient;

using namespace ModelMixer;

namespace PersistenciaMixer {

	public ref class PersistenciaManager{

	private:
		static	String^ cadena =
			"Server=200.16.7.140;"
			"Database=a20201150;"
			"User Id=a20201150;"
			"Password=f0wHl52n;"
			"TrustServerCertificate=True;";

	public:


		//Base de datos 
		static SqlConnection^ GetConnection();

		// ============================================================
		// PERSISTENCIA USUARIOS DATABASE
		// ============================================================
		static bool addUsuario(Usuario^ u);
		static Usuario^ getUsuarioByDNI(String^ dni);
		static bool updateUsuario(Usuario^ u);
		static bool deleteUsuarioByDNI(String^ dni);
		static List<Usuario^>^ getAllUsuarios();

		// ============================================================
		// PERSISTENCIA BEBIDAS DATABASE
		// ============================================================
		static bool addBebida(Bebida^ b);
		static Bebida^ getBebidaById(int id);
		static bool updateBebida(Bebida^ b);
		static bool deleteBebidaById(int id);
		static List<Bebida^>^ getAllBebidas();

		// ============================================================
		// PERSISTENCIA VENTAS DATABASE
		// ============================================================
		static bool addVenta(Venta^ v);
		static Venta^ getVentaById(int id);
		static bool updateVenta(Venta^ v);
		static bool deleteVentaById(int id);
		static List<Venta^>^ getAllVentas();

		// ============================================================
		// PERSISTENCIA INSUMOS DATABASE
		// ============================================================
		static bool addInsumo(Insumo^ i);
		static Insumo^ getInsumoById(int id);
		static bool updateInsumo(Insumo^ i);
		static bool deleteInsumoById(int id);
		static List<Insumo^>^ getAllInsumos();


		// Métodos para Mixer
		static bool AddMixer(Mixer^ m);
		static List<Mixer^>^ GetAllMixers();
		static Mixer^ ReadMixer(int id);
		static bool UpdateMixer(Mixer^ m);
		static bool DeleteMixer(int id);


		static List<String^>^ ObtenerNombresBebidasSQL()
		{
			List<String^>^ bebidas = gcnew List<String^>();


			SqlConnection^ conexion = GetConnection();

			try
			{
				conexion->Open();

				SqlCommand^ cmd = gcnew SqlCommand(
					"SELECT Nombre FROM Bebidas",
					conexion);

				SqlDataReader^ reader = cmd->ExecuteReader();

				while (reader->Read())
				{
					bebidas->Add(reader->GetString(0));
				}

				reader->Close();
			}
			finally
			{
				if (conexion->State == ConnectionState::Open)
					conexion->Close();
			}

			return bebidas;
		}






















	public:
		//Archivos del usuario
		static String^ fileUsuariosBin = "..\\..\\..\Datos\\UsuariosData.bin";
		static String^ fileUsuariosTxt = "..\\..\\..\Datos\\UsuariosData.txt";
		static String^ fileUsuariosXml = "..\\..\\..\Datos\\UsuariosData.xml";

		//Archivos de insumos
		static String^ fileInsumosBin = "..\\..\\..\Datos\\InsumosData.bin";
		static String^ fileInsumosTxt = "..\\..\\..\Datos\\InsumosData.txt";
		static String^ fileInsumosXml = "..\\..\\..\Datos\\InsumosData.xml";

		//Archivos de Bebidas
		static String^ fileBebidasBin = "..\\..\\..\Datos\\BebidasData.bin";
		static String^ fileBebidasTxt = "..\\..\\..\Datos\\BebidasData.txt";
		static String^ fileBebidasXml = "..\\..\\..\Datos\\BebidasData.xml";

		//Archivos de Pedidos
		static String^ filePedidosBin = "..\\..\\..\Datos\\PedidosData.bin";
		static String^ filePedidosTxt = "..\\..\\..\Datos\\PedidosData.txt";
		static String^ filePedidosXml = "..\\..\\..\Datos\\PedidosData.xml";

		//Archivos de Mixers
		static String^ fileMixersBin = "..\\..\\..\Datos\\MixersData.bin";
		static String^ fileMixersTxt = "..\\..\\..\Datos\\MixersData.txt";
		static String^ fileMixersXml = "..\\..\\..\Datos\\MixersData.xml";

		//Archivos de Ventas unificadas
		static String^ fileVentasBin = "..\\..\\..\\Datos\\VentasData.bin";
		static String^ fileVentasTxt = "..\\..\\..\\Datos\\VentasData.txt";
		static String^ fileVentasXml = "..\\..\\..\\Datos\\VentasData.xml";


	public:

		// ── CARGAR ────────────────────────────────────────────────────────────
		static List<Usuario^>^ CargarUsuarios() {
			if (File::Exists(fileUsuariosBin)) {
				try {
					FileStream^ fs = gcnew FileStream(fileUsuariosBin, FileMode::Open);
					BinaryFormatter^ bf = gcnew BinaryFormatter();
					List<Usuario^>^ lista = (List<Usuario^>^)bf->Deserialize(fs);
					fs->Close();
					return lista;
				}
				catch (Exception^) { return gcnew List<Usuario^>(); }
			}
			return gcnew List<Usuario^>();
		}

		static List<Insumo^>^ CargarInsumos() {
			if (File::Exists(fileInsumosBin)) {
				try {
					FileStream^ fs = gcnew FileStream(fileInsumosBin, FileMode::Open);
					BinaryFormatter^ bf = gcnew BinaryFormatter();
					List<Insumo^>^ lista = (List<Insumo^>^)bf->Deserialize(fs);
					fs->Close();
					return lista;
				}
				catch (Exception^) { return gcnew List<Insumo^>(); }
			}
			return gcnew List<Insumo^>();
		}

		static List<Bebida^>^ CargarBebidas() {
			if (File::Exists(fileBebidasBin)) {
				try {
					FileStream^ fs = gcnew FileStream(fileBebidasBin, FileMode::Open);
					BinaryFormatter^ bf = gcnew BinaryFormatter();
					List<Bebida^>^ lista = (List<Bebida^>^)bf->Deserialize(fs);
					fs->Close();
					return lista;
				}
				catch (Exception^) { return gcnew List<Bebida^>(); }
			}
			return gcnew List<Bebida^>();
		}

		static List<Pedido^>^ CargarPedidos() {
			if (File::Exists(filePedidosBin)) {
				try {
					FileStream^ fs = gcnew FileStream(filePedidosBin, FileMode::Open);
					BinaryFormatter^ bf = gcnew BinaryFormatter();
					List<Pedido^>^ lista = (List<Pedido^>^)bf->Deserialize(fs);
					fs->Close();
					return lista;
				}
				catch (Exception^) { return gcnew List<Pedido^>(); }
			}
			return gcnew List<Pedido^>();
		}

		static List<Mixer^>^ CargarMixers() {
			if (File::Exists(fileMixersBin)) {
				try {
					FileStream^ fs = gcnew FileStream(fileMixersBin, FileMode::Open);
					BinaryFormatter^ bf = gcnew BinaryFormatter();
					List<Mixer^>^ lista = (List<Mixer^>^)bf->Deserialize(fs);
					fs->Close();
					return lista;
				}
				catch (Exception^) { return gcnew List<Mixer^>(); }
			}
			return gcnew List<Mixer^>();
		}


		// binario y texto
		static void GuardarUsuarios(List<Usuario^>^ lista) {
			try {
				// Binario
				FileStream^ fs = gcnew FileStream(fileUsuariosBin, FileMode::Create);
				BinaryFormatter^ bf = gcnew BinaryFormatter();
				bf->Serialize(fs, lista);
				fs->Close();

				// XML
				XmlSerializer^ xml = gcnew XmlSerializer(List<Usuario^>::typeid);
				StreamWriter^ swXml = gcnew StreamWriter(fileUsuariosXml);
				xml->Serialize(swXml, lista);
				swXml->Close();

				// Textoo
				StreamWriter^ swTxt = gcnew StreamWriter(fileUsuariosTxt);
				for each (Usuario^ u in lista)

					swTxt->WriteLine(u->idUsuario + "|" + u->Nombre + "|" + u->DNI);
				swTxt->Close();
			}
			catch (Exception^) {}
		}

		static List<Venta^>^ CargarVentas() {
			if (File::Exists(fileVentasBin)) {
				try {
					FileStream^ fs = gcnew FileStream(fileVentasBin, FileMode::Open);
					BinaryFormatter^ bf = gcnew BinaryFormatter();
					List<Venta^>^ lista = (List<Venta^>^)bf->Deserialize(fs);
					fs->Close();
					return lista;
				}
				catch (Exception^) { return gcnew List<Venta^>(); }
			}
			return gcnew List<Venta^>();
		}

		/// <summary>
		/// ///
		/// </summary>
		/// <param name="lista"></param>

		static void GuardarInsumos(List<Insumo^>^ lista) {
			try {
				FileStream^ fs = gcnew FileStream(fileInsumosBin, FileMode::Create);
				BinaryFormatter^ bf = gcnew BinaryFormatter();
				bf->Serialize(fs, lista);
				fs->Close();

				XmlSerializer^ xml = gcnew XmlSerializer(List<Insumo^>::typeid);
				StreamWriter^ swXml = gcnew StreamWriter(fileInsumosXml);
				xml->Serialize(swXml, lista);
				swXml->Close();

				StreamWriter^ swTxt = gcnew StreamWriter(fileInsumosTxt);
				for each (Insumo^ i in lista)
					swTxt->WriteLine(i->id + "|" + i->nombre);
				swTxt->Close();
			}
			catch (Exception^) {}
		}

		static void GuardarBebidas(List<Bebida^>^ lista) {
			try {
				FileStream^ fs = gcnew FileStream(fileBebidasBin, FileMode::Create);
				BinaryFormatter^ bf = gcnew BinaryFormatter();
				bf->Serialize(fs, lista);
				fs->Close();

				XmlSerializer^ xml = gcnew XmlSerializer(List<Bebida^>::typeid);
				StreamWriter^ swXml = gcnew StreamWriter(fileBebidasXml);
				xml->Serialize(swXml, lista);
				swXml->Close();

				StreamWriter^ swTxt = gcnew StreamWriter(fileBebidasTxt);
				for each (Bebida ^ b in lista)
					swTxt->WriteLine(b->id + "|" + b->nombre + "|" + b->precio);
				swTxt->Close();
			}
			catch (Exception^) {}
		}

		static void GuardarPedidos(List<Pedido^>^ lista) {
			try {
				FileStream^ fs = gcnew FileStream(filePedidosBin, FileMode::Create);
				BinaryFormatter^ bf = gcnew BinaryFormatter();
				bf->Serialize(fs, lista);
				fs->Close();

				XmlSerializer^ xml = gcnew XmlSerializer(List<Pedido^>::typeid);
				StreamWriter^ swXml = gcnew StreamWriter(filePedidosXml);
				xml->Serialize(swXml, lista);
				swXml->Close();

				StreamWriter^ swTxt = gcnew StreamWriter(filePedidosTxt);
				for each (Pedido ^ p in lista)
					swTxt->WriteLine(p->datosDelCliente + "|" + p->precio);
				swTxt->Close();
			}
			catch (Exception^) {}
		}

		static void GuardarMixers(List<Mixer^>^ lista) {
			try {
				FileStream^ fs = gcnew FileStream(fileMixersBin, FileMode::Create);
				BinaryFormatter^ bf = gcnew BinaryFormatter();
				bf->Serialize(fs, lista);
				fs->Close();

				XmlSerializer^ xml = gcnew XmlSerializer(List<Mixer^>::typeid);
				StreamWriter^ swXml = gcnew StreamWriter(fileMixersXml);
				xml->Serialize(swXml, lista);
				swXml->Close();

				StreamWriter^ swTxt = gcnew StreamWriter(fileMixersTxt);
				for each (Mixer ^ m in lista)
					swTxt->WriteLine(m->id + "|" + m->ubicacion + "|" + m->estado);
				swTxt->Close();
			}
			catch (Exception^) {}
		}

		static void GuardarVentas(List<Venta^>^ lista) {
			try {
				FileStream^ fs = gcnew FileStream(fileVentasBin, FileMode::Create);
				BinaryFormatter^ bf = gcnew BinaryFormatter();
				bf->Serialize(fs, lista);
				fs->Close();

				XmlSerializer^ xml = gcnew XmlSerializer(List<Venta^>::typeid);
				StreamWriter^ swXml = gcnew StreamWriter(fileVentasXml);
				xml->Serialize(swXml, lista);
				swXml->Close();

				StreamWriter^ swTxt = gcnew StreamWriter(fileVentasTxt);
				for each (Venta ^ v in lista)
					swTxt->WriteLine(v->id + "|" + v->nombreBebida + "|" + v->cantidad + "|" + v->coste + "|" + v->fecha);
				swTxt->Close();
			}
			catch (Exception^) {}
		}


	};
}
