CREATE OR REPLACE PROCEDURE SP_TESTE

(

 pParam1 IN number,

 pParam2 in out number,

 pParam3 out number

)

AS

BEGIN

 

  DBMS_OUTPUT.PUT_LINE('valores dentro da procedure (1): ' ||  pParam1 ||  ' ' || pParam2 || ' ' || pParam3);

 

  -- pParam1 := pParam1 * 1.5; Não é possível modificar parâmetros IN

  pParam2 := pParam1 * 2;

  pParam3 := pParam1 * 3;

 

 

  DBMS_OUTPUT.PUT_LINE('valores dentro da procedure : (2)' ||  pParam1 ||  ' ' || pParam2 || ' ' || pParam3);

 

END;

 

 

               --Chamando a procedure recém-criada de um bloco anônimo

 

DECLARE

 vParam1 number := 100;

 vParam2 number := 100;

 vParam3 number := 100;

BEGIN

  sp_teste(vParam1,vParam2,vparam3);

  DBMS_OUTPUT.PUT_LINE('valores fora da procedure : ' ||  vParam1 ||  ' ' || vParam2 || ' ' || vParam3);

END;

 

          --Verificando o código da procedure através de uma visão do Metadados.

                   

                    SELECT * FROM USER_SOURCE;

 

 

 

 

Chamando uma procedure através de outra procedure.
 

CREATE OR REPLACE PROCEDURE SP_CALCULA_AREA_RETANGULO

(

 pBase number,

 pAltura number,

 pArea out number

)

AS

BEGIN

  pArea := pBase * pAltura;

END;

 

 

CREATE OR REPLACE PROCEDURE SP_CALCULA_AREA

AS

 vArea number;

BEGIN

 

  sp_calcula_area_retangulo(2,4,vArea);

  DBMS_OUTPUT.PUT_LINE('A área da figura é : ' ||  vArea);

 

END;

 

 

          --Chamando a procedure recém-criada de um bloco anônimo

 

            Exec SP_calcula_Area;

 

 

Criando uma função que calcula área de um retângulo
 

 

CREATE OR REPLACE FUNCTION FC_CALCULA_AREA_RETANGULO

(

 pBase number,

 pAltura number default 4

)

RETURN number

AS

 vArea number;

BEGIN

  vArea := pBase * pAltura;

  Return vArea;

END;

 

                -- chamando a função do console     

                SELECT fc_calcula_area_retangulo(2,5) FROM DUAL;

                SELECT fc_calcula_area_retangulo(2) FROM DUAL;

    

         

Chamando uma função através de uma procedure
 

 

CREATE OR REPLACE PROCEDURE SP_CALCULA_AREA2

AS

 vArea number;

BEGIN

 

  vArea := fc_calcula_area_retangulo(2,3);

  DBMS_OUTPUT.PUT_LINE('A área da figura é : ' ||  vArea);

 

END;

 

               -- Chamando a procedure do console

               EXEC SP_CALCULA_AREA2;

Criando uma função para elevar o preço do livro ao cubo.
 

CREATE OR REPLACE FUNCTION FC_PRECO_AO_QUADRADO

(

 pPreco number

)

RETURN number

AS

BEGIN

 

  Return pPreco**2;

 

END;

 

               --Chamando uma função através de um SELECT

               SELECT titulo, preco, fc_preco_ao_quadrado(preco) FROM TB_LIVRO;    

 

 

  return vNome;

END;

 

 

    25-b) Retornando dinamicamente a quantidade e registros de uma tabela.

 

CREATE OR REPLACE FUNCTION FC_CONTADOR_REGISTROS

(

   PTABELA VARCHAR2

)

   RETURN INTEGER

IS

   vRetorno INTEGER;

BEGIN

 

   EXECUTE IMMEDIATE

      'SELECT COUNT(*)

         FROM ' || pTabela

      INTO vRETORNO;

     

   RETURN vRetorno;

END;

 

-- Chamando a função que conta registros de tabelas

select fc_contador_registros('TB_LIVRO') from dual