/*==============================================================*/
/* DBMS name:      Oracle 11g                                   */
/* Created on:     27/9/2022 11:17:12                           */
/*==============================================================*/


/*==============================================================*/
/* Table: ALUNO                                                 */
/*==============================================================*/
create table ALUNO
(
    ID_ALUNO             int                            not null,
    NOME                 varchar(50)                    not null,
    SEXO                 Char(01)                       not null,
    constraint PK_ALUNO primary key (ID_ALUNO)
);

/*==============================================================*/
/* Table: MATRICULA                                             */
/*==============================================================*/
create table MATRICULA
(
    ID_MATRICULA         int                            not null,
    ANO		             int                            not null,
    SEMESTRE	         int							not null,
    ID_ALUNO	         int							not null,
    constraint PK_MATRICULA primary key (ID_MATRICULA)
);

alter table MATRICULA
   add constraint FK_MATRICUL_REFERENCE_ALUNO foreign key (ID_ALUNO)
      references ALUNO (ID_ALUNO);

/*==============================================================*/
/* Table: MENSALIDADE                                           */
/*==============================================================*/
create table MENSALIDADE
(
    ID_MENSALIDADE       int                            not null,
    ID_MATRICULA         int                            not null,
    MES			         int							not null,
    DATA_VENCIMENTO      date							not null,
	DATA_PAGAMENTO		 date,
    constraint PK_MENSALIDADE primary key (ID_MENSALIDADE)
);

alter table MENSALIDADE
   add constraint FK_MENSAL_REFERENCE_MAT foreign key (ID_MATRICULA)
      references MATRICULA (ID_MATRICULA);

CREATE SEQUENCE sq_matricula;
CREATE sequence sq_aluno;
CREATE SEQUENCE sq_mensalidade;