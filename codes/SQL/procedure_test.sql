-- Criando ou substituindo a PROCEDURE SP_TESTE
CREATE OR REPLACE PROCEDURE SP_TESTE(
  pParam1 IN NUMBER,
  pParam2 IN OUT NUMBER,
  pParam3 OUT NUMBER
)
AS
BEGIN
  DBMS_OUTPUT.PUT_LINE('valores dentro da procedure (1): ' || pParam1 || ' ' || pParam2 || ' ' || pParam3);
  
  -- Não é possível modificar parâmetros IN
  pParam2 := pParam1 * 2;
  pParam3 := pParam1 * 3;

  DBMS_OUTPUT.PUT_LINE('valores dentro da procedure: (2)' || pParam1 || ' ' || pParam2 || ' ' || pParam3);
END;
/


-- Chamando a procedure recém-criada de um bloco anônimo
DECLARE
  vParam1 NUMBER := 100;
  vParam2 NUMBER := 100;
  vParam3 NUMBER := 100;
BEGIN
  SP_TESTE(vParam1, vParam2, vParam3);
  DBMS_OUTPUT.PUT_LINE('valores fora da procedure: ' || vParam1 || ' ' || vParam2 || ' ' || vParam3);
END;
/


-- Verificando o código da procedure através de uma visão do Metadados.
SELECT * FROM USER_SOURCE;


-- Chamando uma procedure através de outra procedure.
CREATE OR REPLACE PROCEDURE SP_CALCULA_AREA_RETANGULO(
  pBase NUMBER,
  pAltura NUMBER,
  pArea OUT NUMBER
)
AS
BEGIN
  pArea := pBase * pAltura;
END;
/


CREATE OR REPLACE PROCEDURE SP_CALCULA_AREA
AS
  vArea NUMBER;
BEGIN
  SP_CALCULA_AREA_RETANGULO(2, 4, vArea);
  DBMS_OUTPUT.PUT_LINE('A área da figura é: ' || vArea);
END;
/


-- Chamando a procedure recém-criada de um bloco anônimo
EXEC SP_CALCULA_AREA;


-- Criando uma função que calcula a área de um retângulo
CREATE OR REPLACE FUNCTION FC_CALCULA_AREA_RETANGULO(
  pBase NUMBER,
  pAltura NUMBER DEFAULT 4
) RETURN NUMBER
AS
  vArea NUMBER;
BEGIN
  vArea := pBase * pAltura;
  RETURN vArea;
END;
/


-- Chamando a função do console
SELECT FC_CALCULA_AREA_RETANGULO(2, 5) FROM DUAL;
SELECT FC_CALCULA_AREA_RETANGULO(2) FROM DUAL;


-- Chamando uma função através de uma procedure
CREATE OR REPLACE PROCEDURE SP_CALCULA_AREA2
AS
  vArea NUMBER;
BEGIN
  vArea := FC_CALCULA_AREA_RETANGULO(2, 3);
  DBMS_OUTPUT.PUT_LINE('A área da figura é: ' || vArea);
END;
/


-- Chamando a procedure do console
EXEC SP_CALCULA_AREA2;


-- Criando uma função para elevar o preço do livro ao quadrado
CREATE OR REPLACE FUNCTION FC_PRECO_AO_QUADRADO(
  pPreco NUMBER
) RETURN NUMBER
AS
BEGIN
  RETURN POWER(pPreco, 2);
END;
/


-- Chamando uma função através de um SELECT
SELECT titulo, preco, FC_PRECO_AO_QUADRADO(preco) FROM TB_LIVRO;


-- Retornando dinamicamente a quantidade de registros de uma tabela
CREATE OR REPLACE FUNCTION FC_CONTADOR_REGISTROS(
  pTabela VARCHAR2
) RETURN INTEGER
IS
  vRetorno INTEGER;
BEGIN
  EXECUTE IMMEDIATE 'SELECT COUNT(*) FROM ' || pTabela INTO vRetorno;
  RETURN vRetorno;
END;
/

-- Chamando a função que conta registros de tabelas
SELECT FC_CONTADOR_REGISTROS('TB_LIVRO') FROM DUAL;
