/* Insere uma quantidade X de registros na tabela historico para os
    funcionarios já cadastrados. Do ano de 2010*/

CREATE OR REPLACE PROCEDURE SP_INSERIR_HISTORICO
AS

 VANO INTEGER;
 VMES INTEGER;
 vCARGO INTEGER;
 VSETOR INTEGER;
 vSALARIO INTEGER;
 VHORAS INTEGER;

BEGIN

      VANO := 2010;
      vMES := 1;
      VCARGO := 1;
      VSETOR := 1;
      VSALARIO := 3500;
	    vHORAS := 120;


      WHILE (vANO <= 2010) LOOP

           WHILE (vMES < 13) LOOP

              INSERT INTO TB_HISTORICO
                  SELECT
	              		VANO,
			              vMES,
			              MATRICULA,
			              vCARGO,
			              VSETOR,
			              vHORAS,
			              VSALARIO
                  FROM TB_FUNCIONARIO;

		          VMES := VMES +1;
              vSALARIO := vSALARIO +50;

           END LOOP;

           VANO := VANO +1;
           VCARGO := VCARGO +1;
           VSETOR :=  VSETOR +1;
           vMES := 1;


    	     IF (VHORAS = 120) THEN
	            VHORAS := 180;
	         ELSE
            IF (VHORAS = 180) THEN
	              vHORAS := 220;
	          ELSE
	              vHORAS := 120;
            END IF;
           END IF;

     END LOOP;

END;
