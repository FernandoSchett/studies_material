/*==============================================================*/
/* DBMS name:      Oracle 11g                                   */
/* Created on:     27/9/2022 11:17:12                           */
/*==============================================================*/
  --set serveroutput on;
  --alter session set nls_date_format='dd/mm/yyyy';

/*==============================================================*/
/* Table: ALUNO                                                 */
/*==============================================================*/
INSERT INTO ALUNO (ID_ALUNO,NOME,SEXO)
            VALUES (sq_aluno.nextval,'João','M');
INSERT INTO ALUNO (ID_ALUNO,NOME,SEXO)
            VALUES (sq_aluno.nextval,'Maria','F');
INSERT INTO ALUNO (ID_ALUNO,NOME,SEXO)
            VALUES (sq_aluno.nextval,'Carlos','M');
INSERT INTO ALUNO (ID_ALUNO,NOME,SEXO)
            VALUES (sq_aluno.nextval,'Daniela','F');

