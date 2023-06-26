CREATE TABLE ESPECTADOR (
       ID_ESPECTADOR        int NOT NULL,
       NOME                 varchar(50) NOT NULL,
       BAIRRO               varchar(30) NOT NULL,
       SEXO                 char(1) NOT NULL
);

CREATE TABLE FILME (
       ID_FILME             int NOT NULL,
       TITULO               varchar(30) NOT NULL,
       DURACAO              int NOT NULL
);

CREATE TABLE SALA (
       ID_SALA              int NOT NULL,
       NUMERO               int NOT NULL,
       CAPACIDADE           int NOT NULL,
       SITUACAO             char(1) NOT NULL
);


CREATE TABLE SESSAO (
       ID_SESSAO            int NOT NULL,
       ID_SALA              int NOT NULL,
       ID_FILME             int NOT NULL,
       DATA_HORA            TIMESTAMP NOT NULL
);

CREATE TABLE INGRESSO (
       ID_INGRESSO          int NOT NULL,
       ID_ESPECTADOR        int NOT NULL,
       ID_SESSAO            int NOT NULL,
       VALOR_PAGO           real NOT NULL
);


ALTER TABLE ESPECTADOR ADD PRIMARY KEY (ID_ESPECTADOR);

ALTER TABLE FILME ADD PRIMARY KEY (ID_FILME);

ALTER TABLE SALA ADD PRIMARY KEY (ID_SALA);

ALTER TABLE SESSAO ADD PRIMARY KEY (ID_SESSAO);

ALTER TABLE INGRESSO ADD PRIMARY KEY (ID_INGRESSO);


ALTER TABLE INGRESSO ADD FOREIGN KEY (ID_SESSAO) REFERENCES SESSAO;

ALTER TABLE INGRESSO ADD FOREIGN KEY (ID_ESPECTADOR) REFERENCES ESPECTADOR;

ALTER TABLE SESSAO ADD FOREIGN KEY (ID_FILME) REFERENCES FILME;

ALTER TABLE SESSAO ADD FOREIGN KEY (ID_SALA) REFERENCES SALA;

CREATE SEQUENCE SQ_ESPECTADOR;
CREATE SEQUENCE SQ_FILME;
CREATE SEQUENCE SQ_SALA;
CREATE SEQUENCE SQ_SESSAO;
CREATE SEQUENCE SQ_INGRESSO;