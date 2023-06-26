/* Insere uma quantidade X de registros na tabela funcionario*/
CREATE OR REPLACE PROCEDURE SP_INSERIR_FUNCIONARIOS 
(
	PQTDE_REG INTEGER
)
	AS

	vCONT INTEGER;
	VSEXO CHAR;
  VESTADOCIVIL CHAR;
  
	BEGIN

      VCONT := 1;
	    VSEXO := 'M';
      vEstadoCivil := 'S';

      WHILE (VCONT < PQTDE_REG) LOOP

         INSERT INTO TB_FUNCIONARIO VALUES
              (	VCONT,
			          'EMPREGADO' || vCONT,
			          'AVENIDA DAS AMERICAS',
          			0,
			          'S/N',
			          'MUSSURUNGA',
			          1,
          			'40000000',
			          'EM FRENTE AO ESPORTE CLUBE MUSSURUNGA',
			          '7134560969',
			          'ESPORTECLUBEMUSURUNGA@MUSSURUNGA.COM.BR',
			          VSEXO,
			          vEstadoCivil,
			          to_date('01/01/1980', 'dd/mm/yyyy'),
			          '12345678901',
			          to_date('01/01/2000', 'dd/mm/yyyy'),
			          NULL
               );

	        IF (vEstadoCivil = 'S') THEN
		        vEstadoCivil := 'C';
	        ELSE
		        vEstadoCivil := 'S';
          END IF;

	        IF (vCont in (10, 100, 300, 500, 700, 1000, 1500, 2000, 4000, 6500)) THEN
		        vSEXO := 'M';
	        ELSE
		        vSEXO := 'F';
          END IF;

	        VCONT := VCONT +1;

        END LOOP;
	END;

