
CREATE TABLE TB_CARGO
(
   CODIGO         SMALLINT 	 	     NOT NULL,
   DESCRICAO      VARCHAR(30)            NOT NULL,
   CONSTRAINT     PK_CARGO PRIMARY KEY (CODIGO)
);


CREATE TABLE TB_SETOR
(
   CODIGO             SMALLINT            NOT NULL,
   DESCRICAO          VARCHAR(30)         NOT NULL,
   CONSTRAINT PK_SETOR PRIMARY KEY (CODIGO)
);


CREATE TABLE TB_CIDADE
(
   CODIGO             SMALLINT            NOT NULL,
   DESCRICAO          VARCHAR(30)         NOT NULL,
   CONSTRAINT PK_CIDADE PRIMARY KEY (CODIGO)
);


CREATE TABLE TB_FUNCIONARIO
(
   MATRICULA            INT               NOT NULL,
   NOME                 VARCHAR(50)       NOT NULL,
   LOGRADOURO           VARCHAR(50)       NOT NULL,
   NUMEROENDERECO       INT               ,
   COMPLENDERECO        VARCHAR(20)       ,
   BAIRRO               VARCHAR(30)       ,
   CIDADE               SMALLINT          NOT NULL,
   CEP                  CHAR(08)          NOT NULL,
   PONTOREFERENCIA      VARCHAR(60)      ,
   TELEFONE             VARCHAR(10)       DEFAULT '0000000000',
   E_MAIL               VARCHAR(60)      ,
   SEXO                 CHAR(01)          NOT NULL,
   ESTADOCIVIL          CHAR(01)          NOT NULL,
   DATANASCIMENTO       DATE              NOT NULL,
   CPF                  CHAR(11)          NOT NULL,
   DATAADMISSAO         DATE              NOT NULL,
   DATADEMISSAO         DATE             
);


CREATE TABLE TB_HISTORICO
(
   ANO        		SMALLINT          NOT NULL,
   MES		      SMALLINT          NOT NULL,
   MATRICULA            INT               NOT NULL,
   CARGO                SMALLINT          NOT NULL,
   SETOR                SMALLINT          NOT NULL,
   HORASMENSAIS         SMALLINT          NOT NULL,
   SALARIOBASE          NUMERIC(11,2)     NOT NULL
);

