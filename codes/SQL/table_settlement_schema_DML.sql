-- Povoamento das tabelas do schema
ALTER SESSION SET NLS_DATE_FORMAT = 'DD.MM.YYYY';
-- Inserções em tb_editora
insert into tb_editora values (sq_editora.nextval,'Campus', 'Rua do Timbó');
insert into tb_editora values (sq_editora.nextval,'Abril', null);
insert into tb_editora values (sq_editora.nextval,'Editora Teste',null);

-- Inserções em tb_autor
insert into tb_autor values (sq_autor.nextval,'João','M','01.01.1970');
insert into tb_autor values (sq_autor.nextval,'Maria','F','17.05.1974');
insert into tb_autor values (sq_autor.nextval,'José','M','20.10.1976');

-- Inserções em tb_livro
insert into tb_livro values (sq_livro.nextval,'1234567890','Banco de Dados',2, 120.00,1);
insert into tb_livro values (sq_livro.nextval,'2345678901','Redes de Computadores',1, 110.00,2);
insert into tb_livro values (sq_livro.nextval,'3456789012','Interface Homem-Máquina',3, 90.00,1);


-- Inserções em tb_Livro_Autor
insert into tb_Livro_Autor values (sq_livro_autor.nextval,1,1); 
insert into tb_Livro_Autor values (sq_livro_autor.nextval,1,2);
insert into tb_Livro_Autor values (sq_livro_autor.nextval,2,3);
insert into tb_Livro_Autor values (sq_livro_autor.nextval,3,2);
insert into tb_Livro_Autor values (sq_livro_autor.nextval,3,3);

-- Inserções em tb_Funcionario
insert into tb_Funcionario values (sq_funcionario.nextval,'João','M');
insert into tb_Funcionario values (sq_funcionario.nextval,'Carla','F');
insert into tb_Funcionario values (sq_funcionario.nextval,'Osvaldo','M');


-- Inserções em tb_Lotacao
insert into tb_Lotacao values (1,'PRODEB',null); 
insert into tb_Lotacao values (2,'DSS', 1);
insert into tb_Lotacao values (3,'DRA',1);
insert into tb_Lotacao values (4,'GSD', 2);
insert into tb_Lotacao values (5,'GSE', 3);
insert into tb_Lotacao values (6,'COADA',4);
insert into tb_Lotacao values (7,'COEX1',5);
  
commit;