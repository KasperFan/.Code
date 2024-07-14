CREATE DATABASE IF NOT EXISTS webstore;

USE webstore;

CREATE TABLE books (
    id INT primary key,
    name VARCHAR(20),
    author VARCHAR(20),
    price FLOAT(7,2),
    press VARCHAR(30)
);

INSERT INTO books VALUES (
                             103, '数据库系统概论', '王珊', 36.80, '高等教育出版社');
INSERT INTO books VALUES (
                             104, '人类简史', '尤瓦尔·赫拉利', 67.30, '中国出版集团');
INSERT INTO books VALUES (
                             101, '西游记', '吴承恩', 46.70, '人民文学出版社');
INSERT INTO books VALUES (
                             102, '英语词汇的奥秘', '蒋争', 38.00, '中国国际广播出版社');
INSERT INTO books VALUES (
                             105, 'Java Web编程技术', '沈泽刚', 79.80, '清华大学出版社');
