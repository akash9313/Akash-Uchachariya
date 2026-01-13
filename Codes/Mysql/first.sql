//student table creation
CREATE TABLE student (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    age INT,
    grade VARCHAR(10)
);

//insert sample data into student table
INSERT INTO student (id, name, age, grade) VALUES
(1, 'Alice', 20, 'A'),
(2, 'Bob', 22, 'B'),
(3, 'Charlie', 21, 'A'),
(4, 'David', 23, 'C'),
(5, 'Eve', 20, 'B');

//query to select all students with grade 'A'
SELECT * FROM student WHERE grade = 'A';

//update age of student with id 2
UPDATE student SET age = 23 WHERE id = 2;

//delete student with id 4
DELETE FROM student WHERE id = 4;

//select all records from student table
SELECT * FROM student;

//drop the student table
DROP TABLE student;

