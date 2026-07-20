
-- 1. RECREAR TABLA BEBIDAS CON IDENTITY EN EL ID
IF OBJECT_ID('dbo.Bebidas', 'U') IS NOT NULL DROP TABLE dbo.Bebidas;
GO

CREATE TABLE dbo.Bebidas (
    Id INT IDENTITY(1,1) PRIMARY KEY,
    Nombre VARCHAR(100) NOT NULL,
    Precio INT NOT NULL,
    Estado VARCHAR(50) NULL,
    Proporcion VARCHAR(10) NULL
);
GO

-- 2. RECREAR TABLA INSUMOS CON IDENTITY EN EL ID
IF OBJECT_ID('dbo.Insumos', 'U') IS NOT NULL DROP TABLE dbo.Insumos;
GO

CREATE TABLE dbo.Insumos (
    Id INT IDENTITY(1,1) PRIMARY KEY,
    Nombre VARCHAR(100) NOT NULL,
    StockActual INT NOT NULL,
    StockMinimoAlerta INT NOT NULL
);
GO




IF OBJECT_ID('dbo.Ventas', 'U') IS NOT NULL DROP TABLE dbo.Ventas;
GO

CREATE TABLE dbo.Ventas (
    Id INT IDENTITY(1,1) PRIMARY KEY, -- IDENTITY autogenera el ID (1, 2, 3...)
    NombreBebida VARCHAR(100) NOT NULL,
    Cantidad INT NOT NULL,
    Coste DECIMAL(10,2) NOT NULL,
    Fecha DATETIME NOT NULL DEFAULT GETDATE()
);
GO


-- ============================================================
-- 1. PROCEDIMIENTOS ALMACENADOS: USUARIOS
-- ============================================================
-- 1. INSERTAR USUARIO
IF OBJECT_ID('dbo.usp_InsertUsuario', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_InsertUsuario;
GO
CREATE PROCEDURE usp_InsertUsuario
    @Nombre VARCHAR(100),
    @DNI VARCHAR(20),
    @Contrasena VARCHAR(100),
    @EdadCliente INT,
    @TipoUsuario VARCHAR(50)
AS
BEGIN
    SET NOCOUNT ON;
    INSERT INTO dbo.Usuarios (Nombre, DNI, Contrasena, EdadCliente, TipoUsuario)
    VALUES (@Nombre, @DNI, @Contrasena, @EdadCliente, @TipoUsuario);
END;
GO

-- 2. CONSULTAR USUARIO POR DNI
IF OBJECT_ID('dbo.usp_QueryuUsuarioByDNI', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_QueryuUsuarioByDNI;
GO
CREATE PROCEDURE usp_QueryuUsuarioByDNI
    @DNI VARCHAR(20)
AS
BEGIN
    SET NOCOUNT ON;
    SELECT IdUsuario, Nombre, DNI, Contrasena, EdadCliente, TipoUsuario
    FROM dbo.Usuarios
    WHERE DNI = @DNI;
END;
GO

-- 3. ACTUALIZAR USUARIO POR DNI
IF OBJECT_ID('dbo.usp_UpdateUsuarioByDNI', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_UpdateUsuarioByDNI;
GO
CREATE PROCEDURE usp_UpdateUsuarioByDNI
    @DNI VARCHAR(20),
    @Nombre VARCHAR(100),
    @Contrasena VARCHAR(100),
    @EdadCliente INT,
    @TipoUsuario VARCHAR(50)
AS
BEGIN
    SET NOCOUNT ON;
    UPDATE dbo.Usuarios
    SET Nombre = @Nombre,
        Contrasena = @Contrasena,
        EdadCliente = @EdadCliente,
        TipoUsuario = @TipoUsuario
    WHERE DNI = @DNI;
END;
GO

-- 4. ELIMINAR USUARIO POR DNI
IF OBJECT_ID('dbo.usp_DeleteUsuarioByDNI', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_DeleteUsuarioByDNI;
GO
CREATE PROCEDURE usp_DeleteUsuarioByDNI
    @DNI VARCHAR(20)
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM dbo.Usuarios WHERE DNI = @DNI;
END;
GO

-- 5. OBTENER TODOS LOS USUARIOS
IF OBJECT_ID('dbo.usp_GetAllUsuarios', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_GetAllUsuarios;
GO
CREATE PROCEDURE usp_GetAllUsuarios
AS
BEGIN
    SET NOCOUNT ON;
    SELECT IdUsuario, Nombre, DNI, Contrasena, EdadCliente, TipoUsuario
    FROM dbo.Usuarios;
END;
GO

-- ============================================================
-- 2. PROCEDIMIENTOS ALMACENADOS: BEBIDAS
-- ============================================================

-- INSERTAR BEBIDA
IF OBJECT_ID('dbo.usp_InsertBebida', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_InsertBebida;
GO
CREATE PROCEDURE usp_InsertBebida
    @Nombre VARCHAR(100),
    @Precio INT,
    @Estado VARCHAR(50),
    @Proporcion VARCHAR(10)
AS
BEGIN
    SET NOCOUNT ON;
    INSERT INTO Bebidas (Nombre, Precio, Estado, Proporcion)
    VALUES (@Nombre, @Precio, @Estado, @Proporcion);
END;
GO

-- CONSULTAR BEBIDA POR ID
IF OBJECT_ID('dbo.usp_QueryBebidaById', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_QueryBebidaById;
GO
CREATE PROCEDURE usp_QueryBebidaById
    @Id INT
AS
BEGIN
    SET NOCOUNT ON;
    SELECT Id, Nombre, Precio, Estado, Proporcion
    FROM Bebidas
    WHERE Id = @Id;
END;
GO

-- ACTUALIZAR BEBIDA
IF OBJECT_ID('dbo.usp_UpdateBebida', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_UpdateBebida;
GO
CREATE PROCEDURE usp_UpdateBebida
    @Id INT,
    @Nombre VARCHAR(100),
    @Precio INT,
    @Estado VARCHAR(50),
    @Proporcion VARCHAR(10)
AS
BEGIN
    SET NOCOUNT ON;
    UPDATE Bebidas
    SET Nombre = @Nombre,
        Precio = @Precio,
        Estado = @Estado,
        Proporcion = @Proporcion
    WHERE Id = @Id;
END;
GO

-- ELIMINAR BEBIDA POR ID
IF OBJECT_ID('dbo.usp_DeleteBebida', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_DeleteBebida;
GO
CREATE PROCEDURE usp_DeleteBebida
    @Id INT
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM Bebidas WHERE Id = @Id;
END;
GO

-- OBTENER TODAS LAS BEBIDAS
IF OBJECT_ID('dbo.usp_GetAllBebidas', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_GetAllBebidas;
GO
CREATE PROCEDURE usp_GetAllBebidas
AS
BEGIN
    SET NOCOUNT ON;
    SELECT Id, Nombre, Precio, Estado, Proporcion
    FROM Bebidas;
END;
GO


-- ============================================================
-- 3. PROCEDIMIENTOS ALMACENADOS: VENTAS
-- ============================================================

-- INSERTAR VENTA (La fecha la genera SQL Server automáticamente)
IF OBJECT_ID('dbo.usp_InsertVenta', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_InsertVenta;
GO
CREATE PROCEDURE usp_InsertVenta
    @NombreBebida VARCHAR(100),
    @Cantidad INT,
    @Coste FLOAT
AS
BEGIN
    SET NOCOUNT ON;
    INSERT INTO Ventas (NombreBebida, Cantidad, Coste)
    VALUES (@NombreBebida, @Cantidad, @Coste);
END;
GO

-- CONSULTAR VENTA POR ID
IF OBJECT_ID('dbo.usp_QueryVentaById', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_QueryVentaById;
GO
CREATE PROCEDURE usp_QueryVentaById
    @Id INT
AS
BEGIN
    SET NOCOUNT ON;
    SELECT Id, NombreBebida, Cantidad, Coste, Fecha
    FROM Ventas
    WHERE Id = @Id;
END;
GO

-- ACTUALIZAR VENTA
IF OBJECT_ID('dbo.usp_UpdateVenta', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_UpdateVenta;
GO
CREATE PROCEDURE usp_UpdateVenta
    @Id INT,
    @NombreBebida VARCHAR(100),
    @Cantidad INT,
    @Coste FLOAT
AS
BEGIN
    SET NOCOUNT ON;
    UPDATE Ventas
    SET NombreBebida = @NombreBebida,
        Cantidad = @Cantidad,
        Coste = @Coste
    WHERE Id = @Id;
END;
GO

-- ELIMINAR VENTA POR ID
IF OBJECT_ID('dbo.usp_DeleteVenta', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_DeleteVenta;
GO
CREATE PROCEDURE usp_DeleteVenta
    @Id INT
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM Ventas WHERE Id = @Id;
END;
GO

-- OBTENER TODAS LAS VENTAS
IF OBJECT_ID('dbo.usp_GetAllVentas', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_GetAllVentas;
GO
CREATE PROCEDURE usp_GetAllVentas
AS
BEGIN
    SET NOCOUNT ON;
    SELECT Id, NombreBebida, Cantidad, Coste, Fecha
    FROM Ventas;
END;
GO


-- ============================================================
-- 4. PROCEDIMIENTOS ALMACENADOS: INSUMOS
-- ============================================================

-- INSERTAR INSUMO
IF OBJECT_ID('dbo.usp_InsertInsumo', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_InsertInsumo;
GO
CREATE PROCEDURE usp_InsertInsumo
    @Nombre VARCHAR(100),
    @StockActual INT,
    @StockMinimoAlerta INT
AS
BEGIN
    SET NOCOUNT ON;
    INSERT INTO Insumos (Nombre, StockActual, StockMinimoAlerta)
    VALUES (@Nombre, @StockActual, @StockMinimoAlerta);
END;
GO

-- CONSULTAR INSUMO POR ID
IF OBJECT_ID('dbo.usp_QueryInsumoById', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_QueryInsumoById;
GO
CREATE PROCEDURE usp_QueryInsumoById
    @Id INT
AS
BEGIN
    SET NOCOUNT ON;
    SELECT Id, Nombre, StockActual, StockMinimoAlerta
    FROM Insumos
    WHERE Id = @Id;
END;
GO

-- ACTUALIZAR INSUMO
IF OBJECT_ID('dbo.usp_UpdateInsumo', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_UpdateInsumo;
GO
CREATE PROCEDURE usp_UpdateInsumo
    @Id INT,
    @Nombre VARCHAR(100),
    @StockActual INT,
    @StockMinimoAlerta INT
AS
BEGIN
    SET NOCOUNT ON;
    UPDATE Insumos
    SET Nombre = @Nombre,
        StockActual = @StockActual,
        StockMinimoAlerta = @StockMinimoAlerta
    WHERE Id = @Id;
END;
GO

-- ELIMINAR INSUMO POR ID
IF OBJECT_ID('dbo.usp_DeleteInsumo', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_DeleteInsumo;
GO
CREATE PROCEDURE usp_DeleteInsumo
    @Id INT
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM Insumos WHERE Id = @Id;
END;
GO

-- OBTENER TODOS LOS INSUMOS
IF OBJECT_ID('dbo.usp_GetAllInsumos', 'P') IS NOT NULL DROP PROCEDURE dbo.usp_GetAllInsumos;
GO
CREATE PROCEDURE usp_GetAllInsumos
AS
BEGIN
    SET NOCOUNT ON;
    SELECT Id, Nombre, StockActual, StockMinimoAlerta
    FROM Insumos;
END;
GO



select * from dbo.Bebidas
select * from dbo.Ventas
select * from dbo.Insumos
select * from dbo.Usuarios


-- ============================================================
-- 1. INSERCIÓN DE PRUEBA: BEBIDAS
-- ============================================================
INSERT INTO dbo.Bebidas (Nombre, Precio, Estado, Proporcion)
VALUES 
    ('Mojito', 20, 'Disponible', '1011'),
    ('Cuba Libre', 22, 'Disponible', '1100'),
    ('Daikiri', 25, 'Disponible', '0110'),
    ('Baileys Shake', 20, 'Agotado', '0001');

-- ============================================================
-- 2. INSERCIÓN DE PRUEBA: INSUMOS
-- ============================================================
INSERT INTO dbo.Insumos (Nombre, StockActual, StockMinimoAlerta)
VALUES 
    ('Ron Blanco (ml)', 5000, 1000),
    ('Gaseosa Cola (ml)', 10000, 2000),
    ('Jugo de Limón (ml)', 3000, 500)


INSERT INTO dbo.Ventas (NombreBebida, Cantidad, Coste, Fecha)
VALUES 
    ('Mojito', 2, 40.00, GETDATE()),
    ('Cuba Libre', 1, 22.00, GETDATE()),
    ('Daikiri', 3, 75.00, GETDATE()),
    ('Baileys Shake', 1, 20.00, GETDATE());
GO

GO

SELECT * FROM dbo.Bebidas;
SELECT * FROM dbo.Insumos;
SELECT * FROM dbo.Ventas;
SELECT * FROM dbo.Usuarios;

ALTER TABLE dbo.Ventas 
ALTER COLUMN Coste FLOAT NOT NULL;
GO