ALTER SESSION SET NLS_DATE_FORMAT = 'DD.MM.YYYY';

-- Criando tabela de pedido
create table tb_pedido
(
 id_pedido       int         not null,
 data_pedido     date	     not null,
 data_entrega    date	     not null
 );

alter table tb_pedido add constraint pk_pedido primary key (id_pedido);


-- Criando tabela de itens pedidos
create table tb_itens_pedido
(
 id_itens_pedido int         not null,
 id_livro        int         not null,
 id_pedido       int         not null,
 quantidade      int	     not null,
 preco           numeric (9,2) not null
 );

alter table tb_itens_pedido add constraint pk_itens_pedido primary key (id_itens_pedido);

alter table tb_itens_pedido add constraint fk_itens_pedido_pedido foreign key (id_pedido) references tb_pedido(id_pedido);

alter table tb_itens_pedido add constraint fk_itens_pedido_livro foreign key (id_livro) references tb_livro(id_livro);

-- Criando tabela de log
create table tb_log
(
 id_log  int         not null,
 usuario VARCHAR(50) NOT NULL,
 DATA    DATE        NOT NULL,
 operacao VARCHAR(50) NOT NULL
 );



ALTER TABLE tb_log ADD CONSTRAINT pk_log PRIMARY KEY (id_log);

-- Incluindo um campo qtde_estoque na tabela tb_livro
alter table tb_livro add qtde_estoque int;
update tb_livro set qtde_estoque = 10;


CREATE SEQUENCE sq_pedido;
CREATE SEQUENCE sq_itens_pedido;
CREATE SEQUENCE sq_Log;


--Povoando o banco de dados
INSERT INTO TB_PEDIDO VALUES (SQ_PEDIDO.NEXTVAL,'01.01.2010','10.01.2010');
INSERT INTO TB_PEDIDO VALUES (sq_pedido.nextval,'05.01.2010','15.01.2010');

DELETE FROM TB_ITENS_PEDIDO;
INSERT INTO TB_ITENS_PEDIDO VALUES (SQ_ITENS_PEDIDO.NEXTVAL,1,1,1,100.00);
