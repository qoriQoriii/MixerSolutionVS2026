#include "pch.h"

#include "Persistencias.h" 



//Base de datos:
SqlConnection^ PersistenciaMixer::PersistenciaManager::GetConnection() {

	
	SqlConnection^ conn = gcnew SqlConnection();
	conn->ConnectionString = String::Format(cadena);
	try {
		conn->Open();
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error connecting to: " + conn->ConnectionString);
		Console::WriteLine("Error connecting to SQL: " + ex->Message);
	}
	return conn;
	

}





namespace PersistenciaMixer {

    // ============================================================
    // 1. CRUD USUARIOS 
    // ============================================================

    bool PersistenciaManager::addUsuario(Usuario^ u) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_InsertUsuario", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Nombre", u->Nombre);
            cmd->Parameters->AddWithValue("@DNI", u->DNI);
            cmd->Parameters->AddWithValue("@Contrasena", u->Contrasena);
            cmd->Parameters->AddWithValue("@EdadCliente", u->EdadCliente);
            cmd->Parameters->AddWithValue("@TipoUsuario", u->TipoUsuario);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al agregar usuario: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    Usuario^ PersistenciaManager::getUsuarioByDNI(String^ dni) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        SqlDataReader^ reader = nullptr;
        Usuario^ u = nullptr;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_QueryuUsuarioByDNI", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@DNI", dni);

            reader = cmd->ExecuteReader();

            if (reader->Read()) {
                int usuarioId = reader->GetInt32(0);       // Corresponde a IdUsuario
                String^ nombre = reader->GetString(1);
                String^ dniUsuario = reader->GetString(2);      // Corresponde a DNI
                String^ contrasena = reader->GetString(3);

                // Manejo de NULL para EdadCliente
                int edadCliente = reader->IsDBNull(4) ? 0 : reader->GetInt32(4);

                String^ tipoUsuario = reader->GetString(5);

                if (tipoUsuario == "Administrador") {
                    u = gcnew Usuario(usuarioId, nombre, dniUsuario, contrasena, tipoUsuario);
                }
                else {
                    u = gcnew Usuario(usuarioId, nombre, dniUsuario, contrasena, edadCliente, tipoUsuario);
                }
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar usuario por DNI: " + ex->Message);
        }
        finally {
            if (reader != nullptr) { reader->Close(); delete reader; }
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return u;
    }

    bool PersistenciaManager::updateUsuario(Usuario^ u) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_UpdateUsuarioByDNI", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@DNI", u->DNI);
            cmd->Parameters->AddWithValue("@Nombre", u->Nombre);
            cmd->Parameters->AddWithValue("@Contrasena", u->Contrasena);
            cmd->Parameters->AddWithValue("@EdadCliente", u->EdadCliente);
            cmd->Parameters->AddWithValue("@TipoUsuario", u->TipoUsuario);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al actualizar usuario: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    bool PersistenciaManager::deleteUsuarioByDNI(String^ dni) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_DeleteUsuarioByDNI", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@DNI", dni);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al eliminar usuario por DNI: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    List<Usuario^>^ PersistenciaManager::getAllUsuarios() {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        SqlDataReader^ reader = nullptr;
        List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_GetAllUsuarios", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int usuarioId = reader->GetInt32(0);       // Corresponde a IdUsuario
                String^ nombre = reader->GetString(1);
                String^ dni = reader->GetString(2);             // Corresponde a DNI
                String^ contrasena = reader->GetString(3);

                // Manejo de NULL para EdadCliente
                int edadCliente = reader->IsDBNull(4) ? 0 : reader->GetInt32(4);

                String^ tipoUsuario = reader->GetString(5);

                Usuario^ u = nullptr;
                if (tipoUsuario == "Administrador") {
                    u = gcnew Usuario(usuarioId, nombre, dni, contrasena, tipoUsuario);
                }
                else {
                    u = gcnew Usuario(usuarioId, nombre, dni, contrasena, edadCliente, tipoUsuario);
                }

                listaUsuarios->Add(u);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al obtener lista de usuarios: " + ex->Message);
        }
        finally {
            if (reader != nullptr) { reader->Close(); delete reader; }
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return listaUsuarios;
    }


    // ============================================================
    // 2. CRUD BEBIDAS
    // ============================================================

    bool PersistenciaManager::addBebida(Bebida^ b) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_InsertBebida", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Nombre", b->nombre);
            cmd->Parameters->AddWithValue("@Precio", b->precio);
            cmd->Parameters->AddWithValue("@Estado", b->estado);
            cmd->Parameters->AddWithValue("@Proporcion", b->proporcion);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al agregar bebida: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    Bebida^ PersistenciaManager::getBebidaById(int id) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        SqlDataReader^ reader = nullptr;
        Bebida^ b = nullptr;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_QueryBebidaById", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            reader = cmd->ExecuteReader();

            if (reader->Read()) {
                int bebidaId = reader->GetInt32(0);
                String^ nombre = reader->GetString(1);
                int precio = reader->GetInt32(2);
                String^ estado = reader->GetString(3);
                String^ proporcion = reader->GetString(4);

                b = gcnew Bebida(bebidaId, nombre, precio, estado, proporcion);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar bebida por ID: " + ex->Message);
        }
        finally {
            if (reader != nullptr) { reader->Close(); delete reader; }
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return b;
    }

    bool PersistenciaManager::updateBebida(Bebida^ b) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_UpdateBebida", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", b->id);
            cmd->Parameters->AddWithValue("@Nombre", b->nombre);
            cmd->Parameters->AddWithValue("@Precio", b->precio);
            cmd->Parameters->AddWithValue("@Estado", b->estado);
            cmd->Parameters->AddWithValue("@Proporcion", b->proporcion);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al actualizar bebida: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    bool PersistenciaManager::deleteBebidaById(int id) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_DeleteBebida", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al eliminar bebida por ID: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    List<Bebida^>^ PersistenciaManager::getAllBebidas() {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        SqlDataReader^ reader = nullptr;
        List<Bebida^>^ listaBebidas = gcnew List<Bebida^>();

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_GetAllBebidas", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int id = reader->GetInt32(0);
                String^ nombre = reader->GetString(1);
                int precio = reader->GetInt32(2);
                String^ estado = reader->GetString(3);
                String^ proporcion = reader->GetString(4);

                Bebida^ b = gcnew Bebida(id, nombre, precio, estado, proporcion);
                listaBebidas->Add(b);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al obtener lista de bebidas: " + ex->Message);
        }
        finally {
            if (reader != nullptr) { reader->Close(); delete reader; }
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return listaBebidas;
    }


    // ============================================================
    // 3. CRUD VENTAS
    // ============================================================

    bool PersistenciaManager::addVenta(Venta^ v) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_InsertVenta", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@NombreBebida", v->nombreBebida);
            cmd->Parameters->AddWithValue("@Cantidad", v->cantidad);
            cmd->Parameters->AddWithValue("@Coste", v->coste);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al agregar venta: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    Venta^ PersistenciaManager::getVentaById(int id) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        SqlDataReader^ reader = nullptr;
        Venta^ v = nullptr;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_QueryVentaById", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            reader = cmd->ExecuteReader();

            if (reader->Read()) {
                int ventaId = reader->GetInt32(0);
                String^ nombreBebida = reader->GetString(1);
                int cantidad = reader->GetInt32(2);
                double coste = reader->GetDouble(3);
                DateTime^ fechaBD = reader->GetDateTime(4);

                v = gcnew Venta(ventaId, nombreBebida, cantidad, coste, fechaBD);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar venta por ID: " + ex->Message);
        }
        finally {
            if (reader != nullptr) { reader->Close(); delete reader; }
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return v;
    }

    bool PersistenciaManager::updateVenta(Venta^ v) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_UpdateVenta", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", v->id);
            cmd->Parameters->AddWithValue("@NombreBebida", v->nombreBebida);
            cmd->Parameters->AddWithValue("@Cantidad", v->cantidad);
            cmd->Parameters->AddWithValue("@Coste", v->coste);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al actualizar venta: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    bool PersistenciaManager::deleteVentaById(int id) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_DeleteVenta", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al eliminar venta por ID: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    List<Venta^>^ PersistenciaManager::getAllVentas() {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        SqlDataReader^ reader = nullptr;
        List<Venta^>^ listaVentas = gcnew List<Venta^>();

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_GetAllVentas", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int id = reader->GetInt32(0);
                String^ nombreBebida = reader->GetString(1);
                int cantidad = reader->GetInt32(2);
                double coste = reader->GetDouble(3);
                DateTime^ fechaBD = reader->GetDateTime(4);

                Venta^ v = gcnew Venta(id, nombreBebida, cantidad, coste, fechaBD);
                listaVentas->Add(v);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al obtener lista de ventas: " + ex->Message);
        }
        finally {
            if (reader != nullptr) { reader->Close(); delete reader; }
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return listaVentas;
    }


    // ============================================================
    // 4. CRUD INSUMOS
    // ============================================================

    bool PersistenciaManager::addInsumo(Insumo^ i) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_InsertInsumo", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Nombre", i->nombre);
            cmd->Parameters->AddWithValue("@StockActual", i->stockActual);
            cmd->Parameters->AddWithValue("@StockMinimoAlerta", i->stockMinimoAlerta);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al agregar insumo: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    Insumo^ PersistenciaManager::getInsumoById(int id) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        SqlDataReader^ reader = nullptr;
        Insumo^ i = nullptr;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_QueryInsumoById", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            reader = cmd->ExecuteReader();

            if (reader->Read()) {
                int insumoId = reader->GetInt32(0);
                String^ nombre = reader->GetString(1);
                int stockActual = reader->GetInt32(2);
                int stockMinimo = reader->GetInt32(3);

                i = gcnew Insumo(insumoId, nombre, stockActual, stockMinimo);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar insumo por ID: " + ex->Message);
        }
        finally {
            if (reader != nullptr) { reader->Close(); delete reader; }
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return i;
    }

    bool PersistenciaManager::updateInsumo(Insumo^ i) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_UpdateInsumo", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", i->id);
            cmd->Parameters->AddWithValue("@Nombre", i->nombre);
            cmd->Parameters->AddWithValue("@StockActual", i->stockActual);
            cmd->Parameters->AddWithValue("@StockMinimoAlerta", i->stockMinimoAlerta);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al actualizar insumo: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    bool PersistenciaManager::deleteInsumoById(int id) {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        bool exito = false;

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_DeleteInsumo", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            exito = (cmd->ExecuteNonQuery() > 0);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al eliminar insumo por ID: " + ex->Message);
        }
        finally {
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return exito;
    }

    List<Insumo^>^ PersistenciaManager::getAllInsumos() {
        SqlConnection^ conn = nullptr;
        SqlCommand^ cmd = nullptr;
        SqlDataReader^ reader = nullptr;
        List<Insumo^>^ listaInsumos = gcnew List<Insumo^>();

        try {
            conn = GetConnection();
            cmd = gcnew SqlCommand("dbo.usp_GetAllInsumos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int id = reader->GetInt32(0);
                String^ nombre = reader->GetString(1);
                int stockActual = reader->GetInt32(2);
                int stockMinimo = reader->GetInt32(3);

                Insumo^ i = gcnew Insumo(id, nombre, stockActual, stockMinimo);
                listaInsumos->Add(i);
            }
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al obtener lista de insumos: " + ex->Message);
        }
        finally {
            if (reader != nullptr) { reader->Close(); delete reader; }
            if (cmd != nullptr) delete cmd;
            if (conn != nullptr) { conn->Close(); delete conn; }
        }
        return listaInsumos;
    }

}

