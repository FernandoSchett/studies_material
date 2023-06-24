-- Made by: https://github.com/FernandoSchett

create table TB_editora(
id_editora int not null,
descricao varchar(50) not null,
endereco varchar(50)
);

create table TB_livro(
id_livro int not null,
titulo varchar(50) not null,
preco numeric(9,2) not null,
id_editora int not null
);

create table TB_autor(
id_autor int not null,
nome varchar(50) not null,
sexo char(01) not null,
dt_nascimento date not null
);

create table TB_autoria (
id_autoria int not null,
id_livro int not null,
id_autor int not null
);

create table TB_funcionario(
id_funcionario int not null,
nome varchar(50) not null,
sexo char(01) not null
);

--primary keys pk's

alter table TB_editora add constraint pk_editora primary key (id_editora);
alter table TB_livro add constraint pk_livro primary key (id_livro);
alter table TB_autor add constraint pk_autor primary key (id_autor);
alter table TB_autoria add constraint pk_autoria primary key (id_autoria);
alter table TB_funcionario add constraint pk_funcionario primary key (id_funcionario);


-- foreign keys fk's

alter table TB_livro add constraint fk_livro_editora foreign key (id_editora)
references TB_editora (id_editora);

alter table TB_autoria add constraint fk_autoria_livro foreign key (id_livro)
references TB_livro (id_livro);

alter table TB_autoria add constraint fk_autoria_autor foreign key (id_autor)
references TB_autor (id_autor);

-- restricao de dominio 
-- ck vem de check

alter table TB_autor add constraint ck_sexo_autor check (sexo in ('M','F'));

alter table TB_funcionario add constraint ck_sexo_func check (sexo in ('M','F'));

-- autoincremento (cada sgbd tem o seu padrao)

CREATE SEQUENCE SQ_EDITORA;
CREATE SEQUENCE SQ_LIVRO;
CREATE SEQUENCE SQ_AUTOR;
CREATE SEQUENCE SQ_AUTORIA;
CREATE SEQUENCE SQ_FUNCIONARIO;

/*
comandos de manipulacao de dados (dml) (povoar o banco)
insert / delet / update

Modelo:
insert into NOME_TABELA (NOME_ATR1,...) VALUES (VAL_ATRI1,...);
se for sequencia no id -> SQ_NOME.nextVAL
*/

insert into TB_editora (id_editora, descricao, endereco) values (SQ_EDITORA.nextVAL, 'Campus', 'Rua do TimbÃ³');
insert into TB_editora (id_editora, descricao, endereco) values (SQ_EDITORA.nextVAL, 'Abril', NULL);
insert into TB_editora (id_editora, descricao) values (SQ_EDITORA.nextVAL, 'Globo');
insert into TB_editora (id_editora, descricao) values (SQ_EDITORA.nextVAL, 'TESTE');

select * from TB_editora; 

insert into TB_livro (id_livro, titulo, preco, id_editora) values (SQ_LIVRO.nextVAL, 'Banco de Dados', 39.90,(select id_editora  
   from tb_editora  
   where descricao = 'Campus'));

insert into TB_livro (id_livro, titulo, preco, id_editora) values (SQ_LIVRO.nextVAL, 'Rede de Computadores', 105.90,2);

insert into TB_livro (id_livro, titulo, preco, id_editora) values (SQ_LIVRO.nextVAL, 'SGBD', 90.50,3);

select * from TB_livro;

-- delete from tabela where id_tabela = (id da tupla que vc quer apagar)

--dia: 27/05/22
-- alterar o formato de dada aceito
alter session set nls_date_format = 'DD/MM/YYYY';
insert into tb_autor (id_autor, nome, sexo, dt_nascimento) values (SQ_AUTOR.nextVAL, 'JoÃ£o', 'M', '01/01/1970');
insert into tb_autor (id_autor, nome, sexo, dt_nascimento) values (SQ_AUTOR.nextVAL, 'Maria', 'F', '17/05/1974');
insert into tb_autor (id_autor, nome, sexo, dt_nascimento) values (SQ_AUTOR.nextVAL, 'JosÃ©', 'M', '10/10/1977');
insert into tb_autor (id_autor, nome, sexo, dt_nascimento) values (SQ_AUTOR.nextVAL, 'Carla', 'F', '10/10/1964');

select * from tb_autor;
select * from tb_livro;

insert into tb_autoria (id_autoria, id_livro, id_autor) values (SQ_AUTORIA.nextVal, 1, 1);
insert into tb_autoria (id_autoria, id_livro, id_autor) values (SQ_AUTORIA.nextVal, 1, 2);
insert into tb_autoria (id_autoria, id_livro, id_autor) values (SQ_AUTORIA.nextVal, 2, 2);
insert into tb_autoria (id_autoria, id_livro, id_autor) values (SQ_AUTORIA.nextVal, 2, 4);
insert into tb_autoria (id_autoria, id_livro, id_autor) values (SQ_AUTORIA.nextVal, 3, 3);

select * from tb_autoria;

insert into tb_funcionario (id_funcionario, nome, sexo) values (SQ_FUNCIONARIO.nextVAL, 'JoÃ£o', 'M');
insert into tb_funcionario (id_funcionario, nome, sexo) values (SQ_FUNCIONARIO.nextVAL, 'Carla', 'F');
insert into tb_funcionario (id_funcionario, nome, sexo) values (SQ_FUNCIONARIO.nextVAL, 'Osvaldo', 'M');

select * from tb_funcionario;

/* manipulacoes dml
Esqueleto UPDATE:
(sem filtro altera todos)
UPDATE NOME_TABELA SET ATR1 = NOVO_VALOR_ATR1,
                       ATR2 = NOVO_VALOR_ATR2;
*/

-- 1. Reajustar os preÃ§os de todos os livros em 10%

select * from tb_livro;
UPDATE
    TB_livro
SET
    preco = preco * 1.10;

-- 2. Atualizar o endereÃ§o da editora Campus para 'Av. ACM'

/*
UPDATE
    TABELA
SET
    ATRIBUTO A SER ALTERADO = 'END NOVO'
WHERE
    UPPER(ATRIBUTO DO FILTRO) = 'NOME';
*/

UPDATE
    TB_editora
SET
    endereco = 'Av. ACM'
WHERE
    descricao = 'Campus';

select * from tb_editora;

-- 3. Excluir a editora TESTE

DELETE
FROM
    tb_editora
WHERE
    descricao = 'TESTE';
-- ou id_editora = 4;

select * from tb_editora;

-- dia 01/06/22

-- 4. Apresentar o nome e data de nascimento de todos os autores
/*
SELECT
    projecao de atributos
FROM
    tabelas ou visoes
WHERE
    condicao ou filtro de registro;
ORDER BY
    atributos para ordenacao
    asc/desc  (ascendente ou descendente)
*/

SELECT nome, dt_nascimento from tb_autor;

-- 5. Apresentar o nome e a data de nascimento dos autores por ordem de nome.

SELECT nome, dt_nascimento from tb_autor order by nome;

-- 6. Apresentar o nome e data de nascimento dos autores, ordenados pelo nome, apenas do sexo feminino

SELECT nome, dt_nascimento from tb_autor where sexo = 'F' order by nome desc;

-- 7. Apresentar o nome das editoras que nao tem o endereco cadastrado 

SELECT descricao from tb_editora where endereco IS NULL;

-- 7.1 Apresentar o nome das editoras que tem o endereco cadastrado 

SELECT descricao from tb_editora where endereco IS NOT NULL;

-- 7.2 Apresentar os autores cujos ID's variam entre 2 e 3
-- 3 formas diferentes:

SELECT * from tb_autor where id_autor >=2 and id_autor <=3;
SELECT * from tb_autor where id_autor BETWEEN 2 AND 3;
SELECT * from tb_autor where id_autor IN (2,3); -- so pega os ids que foram passados como parametro

-- 7.3 Apresentar o iD dos livros em autoria sem repetiÃ§Ã£o (distinct) 
SELECT DISTINCT id_livro from tb_autoria;

-- 8. Apresentar o titulo do livro e o nome da sua editora 
-- 3 formas: 
SELECT tb_livro.titulo, tb_editora.descricao FROM tb_livro, tb_editora WHERE tb_livro.id_editora = tb_editora.id_editora;
SELECT L.titulo, E.descricao FROM tb_livro L, tb_editora E WHERE L.id_editora = E.id_editora; -- apelido local, durante a consulta 'tabela [as] apelido'
/*
INNER JOIN  (padrao - so pega tupla que tem correlaÃ§Ã£o)
OUTER JOIN -> LEFT, RIGHT , FULL 
*/
SELECT L.titulo, E.descricao FROM tb_livro L JOIN tb_editora E ON (L.id_editora = E.id_editora);  -- INNER JOIN

-- 9. Apresentar o titulo do livro e o nome da sua editora. Caso haja alguma editora sem livro publicado, informar os dados da editora com valores nulos para os livros.

SELECT 
    L.titulo, 
    E.descricao 
FROM 
    tb_livro L RIGHT JOIN tb_editora E ON (L.id_editora = E.id_editora);

-- 10. Apresentar o titulo do livro e o nome de tds os seus autores

SELECT
    L.titulo,
    AT.nome
FROM
    tb_autoria A 
JOIN
    tb_livro L ON (A.id_livro  = L.id_livro)
JOIN
    tb_autor AT ON (A.id_autor = AT.id_autor)
ORDER BY
    L.titulo asc;

-- 11. Apresentar o nome da editora e o nome dos autores que jÃ¡ publicaram algum livro na editora

SELECT
    E.descricao,
    AT.nome
FROM
    tb_livro L
JOIN
    tb_editora E ON (L.id_editora = E.id_editora)
JOIN
    tb_autoria A ON (L.id_livro = A.id_livro)
JOIN
    tb_autor AT ON (A.id_autor = AT.id_autor)
ORDER BY
    E.descricao asc;
/*
 % no inicio busca td que termina com a substring
 % no final busca td que comeca com a substring
 %substring% busca td que tenha a substring
 _ representa um caracter coringa ex: B__CO
*/
--12. Apresentar o tÃ­tulo dos livros que comeÃ§am a string â€˜Bancoâ€™

SELECT L.titulo FROM tb_livro L WHERE lower(titulo) LIKE 'banco%';

--13. Apresentar o tÃ­tulo dos livros que tem a string â€˜doâ€™.

SELECT L.titulo FROM tb_livro L WHERE lower(titulo) LIKE '%do%';

--14. Apresentar o nome de cada livro e seu preÃ§o reajustado em 5%

SELECT
    L.titulo,
    L.preco * 1.05 AS PRECO_REAJUSTADO
FROM tb_livro L;

--14.1 Apresentar o nome de cada livro, seu preÃ§o antigo e seu preÃ§o reajustado em 5%

SELECT
    L.titulo,
    L.preco,
    L.preco * 1.05 AS "PRECO REAJUSTADO"
FROM tb_livro L;

-- 15 COM POG *NAO FAÃ‡A*. Apresentar o nome dos autores que nasceram no mÃªs de outubro
/*
SELECT 
    AT.nome
FROM
    tb_autor AT
WHERE
    dt_nascimento
LIKE
    '%/10/%';
*/

-- 15 CERTA. Apresentar o nome dos autores e sua data de nascimento, que nasceram no mÃªs de outubro

SELECT 
    AT.nome,
    AT.dt_nascimento
FROM
    tb_autor AT
WHERE
    EXTRACT( MONTH FROM dt_nascimento) = 10;

-- 16. Apresentar o nÃºmero de livros do acervo

SELECT
    count(id_livro) as Numeros_De_Livros
FROM
    tb_livro;

-- 17. Apresentar o nÃºmero de autores do livro â€˜Banco de Dadosâ€™

SELECT
    count(*) as Numeros_De_Autores
FROM
    tb_autoria A
JOIN
    tb_livro L ON (A.id_livro = L.id_livro)
WHERE
    lower(L.titulo) = 'banco de dados';

-- 18. Apresentar o somatÃ³rio dos preÃ§os dos livros do acervo

SELECT
    SUM(L.preco) as SOMATORIO_DOS_PRECOS
FROM
    tb_livro L;

-- 19. Apresentar a mÃ©dia de preÃ§os dos livros da editora Campus

SELECT
    CAST(AVG(L.preco) AS DECIMAL(4,2)) as MEDIA_PRECOS_DOS_LIVROS
FROM
    tb_livro L
JOIN
    tb_editora E ON (L.id_livro = E.id_editora)
WHERE
    lower(E.descricao) = 'campus';

-- 20. Apresentar o maior preÃ§o dentre todos os livros do acervo.

SELECT
    MAX(L.preco) AS MAIOR_VALOR_DOS_LIVROS
FROM
    tb_livro L;

-- 21. Apresentar a data de nascimento do autor mais velho

SELECT
    MIN(dt_nascimento) AS AUTOR_MAIS_VELHO
FROM
    tb_autor;

-- 22. Apresentar o nÃºmero de livros por editora

SELECT 
    E.descricao,
    COUNT(*) AS QNT_LIVROS
FROM 
    TB_editora E JOIN tb_livro L USING (id_editora) -- juncao natural, join que tenha o msm nome como pk e fk
GROUP BY
    E.descricao
ORDER BY
    descricao asc, QNT_LIVROS asc;

-- 23. Apresentar o somatÃ³rio e mÃ©dia de preÃ§o dos livros por editora

SELECT
    E.descricao,
    SUM(preco) AS SOMATORIO,
    AVG(PRECO) AS MEDIA
FROM
    tb_editora E join tb_livro L USING (id_editora)
GROUP BY
    E.descricao
ORDER BY
    E.descricao asc;

-- 24. Apresentar o nÃºmero de autores por livro, mas apenas dos livros que possuem mais de 1 autor

SELECT 
    L.titulo,
    COUNT(*) AS QNT_AUTOR
FROM 
    TB_livro L JOIN tb_autoria AL USING (id_livro)
GROUP BY
    L.titulo
HAVING 
    COUNT(*) > 1
ORDER BY
    L.titulo asc, QNT_AUTOR asc;

-- 25 Apresentar a mÃ©dia de preÃ§os geral por editora, mas apenas as editoras que possuem mÃ©dia maior que R$ 100,00 

SELECT
    E.descricao,
    AVG(preco) AS MEDIA_LIVROS
FROM 
    TB_livro L JOIN tb_editora E USING (id_editora)
GROUP BY
    E.descricao
HAVING 
    AVG(preco) > 100.00
ORDER BY
    E.descricao asc, MEDIA_LIVROS asc;

--26. Apresentar o nome e sexo dos autores e funcionÃ¡rios da editora

SELECT
    nome, sexo, 'A' as TIPO
FROM
    tb_autor
UNION
    SELECT nome, sexo, 'F'
FROM
    tb_funcionario
ORDER BY
    nome desc;

--27. Apresentar o nome dos autores que sÃ£o funcionÃ¡rios  da editora

SELECT
    nome
FROM
    tb_autor
INTERSECT
    SELECT nome
FROM
    tb_funcionario
ORDER BY
    nome desc;
    
--27. UTILIZANDO IN/NOT IN

SELECT
    nome
FROM
    tb_autor
WHERE
    nome
IN (SELECT NOME FROM tb_funcionario);

--27. UTILIZANDO O EXISTS/NOT EXISTS

SELECT
    nome
FROM
    tb_autor A
WHERE
EXISTS
(SELECT * FROM tb_funcionario F WHERE A.nome = F.nome);
    
--28. Apresentar o nome dos autores que NÃƒO sÃ£o funcionÃ¡rios da editora

SELECT
    nome
FROM
    tb_autor
MINUS
    SELECT nome
FROM
    tb_funcionario
ORDER BY
    nome desc;
    
--28. UTILIZANDO O NOT IN

SELECT
    nome
FROM
    tb_autor
WHERE
    nome
NOT IN (SELECT nome FROM tb_funcionario);

--29. Apresentar o nome dos autores que nÃ£o sÃ£o autores do livro Banco de Dados

--29. Apresentar o nome dos autores que nÃ£o sÃ£o autores do livro Banco de Dados

SELECT
    AT.nome
FROM
    tb_autor AT
MINUS
SELECT
    AT.nome
FROM
    tb_autoria A
JOIN
    tb_autor AT ON (A.id_autor = AT.id_autor)
JOIN
    tb_livro L ON (A.id_livro = L.id_livro)
WHERE
    lower(L.titulo) = 'banco de dados'
ORDER BY
    nome;
    
--29. OUTRA FORMA:

SELECT
    AT.nome
FROM
    tb_autor AT
WHERE
    AT.nome NOT IN
(SELECT AT.nome FROM tb_livro L JOIN tb_autoria A USING (id_livro)
                                JOIN tb_autor AT USING (id_autor)
    WHERE UPPER(L.titulo) = 'BANCO DE DADOS')
ORDER BY
    AT.nome;

-- 30. Apresentar  a quantidade de livros da editora Campus e Abril em colunas diferentes. (consulta derivada)

SELECT Abril, Campus  FROM 
    (SELECT COUNT(*) AS Abril FROM tb_editora E JOIN tb_livro L USING (id_editora)
    WHERE lower(E.descricao) = 'abril'),
    (SELECT COUNT(*) AS Campus FROM tb_editora E JOIN tb_livro L USING (id_editora)
    WHERE lower(E.descricao) = 'campus');

/*
EXTRACT - ExtraÃ§Ã£o de uma parte da data
COUNT - Qntd de itens na coluna
SUM - Soma dos itens na coluna
AVG - MÃ©dia dos itens na coluna
MAX - Maior valor da coluna
MIN - Menor valor da coluna
GROUP BY - Agrupa colunas com o mesmo valor em colunas sumÃ¡rio
UNION - Combina o resultado de 2 ou mais declaraÃ§Ãµes SELECT (se tiver all vai receber valores duplicados)
INTERSECT - Apresenta os valores que coincidem de 2 ou mais declaraÃ§Ãµes SELECT
MINUS - Apresenta os valores que nÃ£o coincidem de 2 ou mais declaraÃ§Ãµes SELECT
*/