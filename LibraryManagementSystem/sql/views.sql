/*
 * 创建视图：
 * base_view 供用户访问的图书信息
 * in_view 供用户访问的可供借阅(state='in')的图书信息
 * out_view 供用户访问的在借(state='out')图书信息
 */
 
/* base_view */
CREATE VIEW base_view
AS
SELECT * FROM book;

/* in_view */
CREATE VIEW in_view
AS
SELECT id,name,author,catagory FROM book WHERE state='in';

/* out_view */
CREATE VIEW out_view
AS
SELECT id,name,author,catagory FROM book WHERE state='out';