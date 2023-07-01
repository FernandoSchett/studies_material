
ALTER TABLE TB_FUNCIONARIO ADD  CONSTRAINT PK_FUNCIONARIO PRIMARY KEY (MATRICULA);

ALTER TABLE TB_FUNCIONARIO ADD   CONSTRAINT FK_EMPREGADOCIDADE FOREIGN KEY(CIDADE)
                 REFERENCES TB_CIDADE(CODIGO);

ALTER TABLE TB_HISTORICO   ADD   CONSTRAINT PK_HISTORICO PRIMARY KEY (ANO, MES, MATRICULA);

ALTER TABLE TB_HISTORICO   ADD   CONSTRAINT FK_HISTORICO_FUNCIONARIO FOREIGN KEY(MATRICULA)
			                 REFERENCES TB_FUNCIONARIO(MATRICULA);

ALTER TABLE TB_HISTORICO   ADD   CONSTRAINT FK_HISTORICO_CARGO FOREIGN KEY(CARGO)
			                 REFERENCES TB_CARGO(CODIGO);

ALTER TABLE TB_HISTORICO   ADD   CONSTRAINT FK_HISTORICO_SETOR FOREIGN KEY(SETOR)
			                 REFERENCES TB_SETOR(CODIGO);