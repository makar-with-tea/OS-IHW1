# Макаревич Мария, БПИ228
Индивидуальное домашнее задание 1 по дисциплине "Операционные системы".
**Работа выполнена на 9 баллов.**
## Вариант 20. Условие
ASCII–строка — строка, содержащая символы таблицы кодировки [ASCII](https://ru.wikipedia.org/wiki/ASCII). Размер строки может быть достаточно большим, чтобы вмещать многостраничные тексты, например, главы из книг, если задача связана с использованием файлов или строк, порождаемых генератором случайных чисел. Тексты при этом могут не нести смыслового содержания. Строка может
содержать символы перевода строки ('\n'). Конец строки в памяти компьютера задается символом '\0'. Концом строки, читаемой из файла, является признак конца файла.
Для упрощения обработки в программе предлагается использовать данные, содержащие символы только из первой половины таблицы (коды в диапазоне 0–12710). Символы, содержащие коды выше 12710, должны отсутствовать во входных данных.

Разработать программы, состоящую из нескольких параллельных процессов, взаимодействующих между собой через каналы. Количество программ в задании из их характеристики определяются в соответствии с требованиями выполнения на соответствующую оценку.

**Индивидуальное условие варианта:** Разработать программу, вычисляющую число вхождений различных цифр в заданной ASCII–строке. В выходном тексте для каждой цифры вывести, сколько раз она встретилась в обработанном тексте.
## 4 балла
Разработка программы, осуществляющей взаимодействие между тремя родственными процессами одной программы с использованием неименованных каналов. 

**Требования**
1. В отчете привести фамилию, имя, отчество исполнителя, группу. 
2. Привести вариант и условие задачи. 
3. Представить общую схема решаемой задачи. При этом достаточно показать процессы и связи между ними через каналы, а также связи процессов с входным и выходным файлами. 
4. Разработать консольное приложение, использующее неименованные каналы, обеспечивающее взаимодействие по следующей схеме: • первый процесс читает текстовые данные из заданного файла и через неименованный канал передает их второму процессу; • второй процесс осуществляет обработку данных в соответствии с вариантом задания и передает результат обработки через неименованный канал третьему процессу; • третий процесс осуществляет вывод данных в заданный файл. 
5. Для задания имен входного и выходного файлов, а также дополнительных параметров, необходимых по условию задачи, использовать аргументы командной строки. В отчете необходимо описать формат командной строки и обеспечить его при вывод при запуске программы с некорректными параметрами.
6. Ввод и вывод данных при работе с файлами осуществлять через системные вызовы операционной системы read и write.
7. Размеры буферов для хранения вводимых данных и результатов обработки должны быть равны 5000 байт.
8. Программа должна работать с тестовыми данными, размер которых не должен превышать размера буфера. То есть, предполагается что весь обрабатываемый текст передается по каналу за один раз.
9. Представить набор (не менее пяти) текстовых файлов, на которых проводилось тестирование программы.
10. Для каждого из входных тестовых файлов в отчете должен быть представлен выходной файл, полученный в результате работы программы.
11. Результаты работы должны быть представлены в виде выходных данных.

Схема решаемой задачи:

![image](https://github.com/makar-with-tea/OS-IHW1/assets/79705001/29182cb9-afae-424b-8a02-035c773f9f6b)

Консольное приложение, соответствующее требованиям 4-7, [разработано](4/4.c). Тесты предоставлены в папке [4/tests](4/tests). В этой программе, как и в программах на другие оценки, пользователь должен ввести аргументы командной строки в формате "inputFileName outputFileName". При некорректной подаче аргументов через командную строку сообщение о данном формате выводится в консоль.

## 5 баллов 
В дополнение к требованиям и программе на предыдущую оценку необходимо разработать еще одну программу, в которой взаимодействие между тремя родственными процессами одной программы осуществляется через именованные каналы. То есть, используется схема, аналогичная предшествующему решению. Отличие только в использовании каналов другого типа. 

**Требования**
1. Представить общую схему решаемой задачи для именованных каналов. Достаточно показать процессы и связи между ними, а также связи процессов с входным и выходным файлами. Необходимо также указать имена каналов и способ их создания, используемый в работе. 
2. Разработать консольное приложение, использующее именованные каналы, обеспечивающее взаимодействие по следующей схеме: 
• первый процесс читает текстовые данные из заданного файла и через именованный канал передает их второму процессу; 
• второй процесс осуществляет обработку данных в соответствии с заданием и передает результат обработки через именованный канал третьему процессу; 
• третий процесс осуществляет вывод данных в заданный файл.
3. Для задания имен входного и выходного файлов, а также дополнительных параметров, необходимых по условию задачи, использовать аргументы командной строки. В отчете необходимо описать формат командной строки и обеспечить его при вывод при запуске программы с некорректными параметрами.
4. Ввод и вывод данных при работе с файлами осуществляется через системные вызовы операционной системы read и write. 
5. Размеры буферов для хранения вводимых данных и результатов обработки должны быть равны 5000 байт. 
6. Программа должна работать с тестовыми данными, размер которых не должен превышать размера буфера. То есть, предполагается что весь обрабатываемый текст передается по каналу за один раз. 
7. Представлен набор (не менее пяти) текстовых файлов, на которых проводилось тестирование программы. 
8. Для каждого из входных тестовых файлов в отчете должен быть представлен выходной файл, полученный в результате работы программы. 
9. Результаты работы должны быть представлены приведены в виде выходных данных.

Схема решаемой задачи:

![image](https://github.com/makar-with-tea/OS-IHW1/assets/79705001/122b42d1-555e-455e-82db-e9f63457e6dd)

Консольное приложение, соответствующее требованиям 2-6, [разработано](5/5.c). Тесты предоставлены в папке [5/tests](5/tests). В программе используются каналы с названиями fd1.fifo и fd2.fifo, расположенные в той же папке, что и сама запускаемая программа. Каналы создаются с помощью команды mknod.

## 6 баллов 
В дополнение к требованиям на предыдущую оценку разработать новую программу, которая осуществляет взаимодействие между двумя родственными процессами одной программы с использованием неименованных каналов 

**Требования**
1. Представить общую схему решаемой задачи. Достаточно показать процессы и связи между ними, а также связи процессов с входным и выходным файлами. Необходимо также указать имена каналов и способ их создания, используемый в работе.
2. Разработать консольное приложение, использующее неименованные каналы, обеспечивающее взаимодействие по следующей схеме: 
• первый процесс читает текстовые данные из заданного файла и через неименованный канал передает их второму процессу; 
• второй процесс осуществляет обработку данных в соответствии с заданием и передает результат обработки через неименованный канал обратно первому процессу; 
• первый процесс осуществляет вывод данных в заданный файл. 
3. Для задания имен входного и выходного файлов, а также дополнительных параметров, необходимых по условию задачи, использовать аргументы командной строки. В отчете необходимо описать формат командной строки и обеспечить его при вывод при запуске программы с некорректными параметрами. 
4. Ввод и вывод данных при работе с файлами осуществляется через системные вызовы операционной системы read и write. 
5. Размеры буферов для хранения вводимых данных и результатов обработки должны быть равны 5000 байт. 
6. Программа должна работать с тестовыми данными, размер которых не должен превышать размера буфера. То есть, предполагается что весь обрабатываемый текст передается по каналу за один раз. 
7. Представлен набор (не менее пяти) текстовых файлов, на которых проводилось тестирование программы. 
8. Для каждого из входных тестовых файлов в отчете должен быть представлен выходной файл, полученный в результате работы программы. 
9. Результаты работы должны быть представлены приведены в виде выходных данных.

Схема решаемой задачи:

![image](https://github.com/makar-with-tea/OS-IHW1/assets/79705001/63fb2c01-f5b2-425f-b501-1ea5f573ce32)

Консольное приложение, соответствующее требованиям 2-6, [разработано](6/6.c). Тесты предоставлены в папке [6/tests](6/tests). В данном приложении используются неименованные каналы (pipe).

## 7 баллов 
В дополнение к требованиям на предыдущую оценку разработать программу, которая осуществляет взаимодействие между двумя родственными процессами одной программы с использованием именованных каналов 

**Требования**
1. Представить общую схему решаемой задачи. Достаточно показать процессы и связи между ними, а также связи процессов с входным и выходным файлами. Необходимо также указать имена каналов и способ их создания, используемый в работе. 
2. Разработать консольное приложение, использующее именованные каналы, обеспечивающее взаимодействие по следующей схеме: 
• первый процесс читает текстовые данные из заданного файла и через именованный канал передает их второму процессу; 
• второй процесс осуществляет обработку данных в соответствии с заданием и передает результат обработки через именованный канал обратно первому процессу; 
• первый процесс осуществляет вывод данных в заданный файл. 
3. Для задания имен входного и выходного файлов, а также дополнительных параметров, необходимых по условию задачи, использовать аргументы командной строки. В отчете необходимо описать формат командной строки и обеспечить его при вывод при запуске программы с некорректными параметрами. 
4. Ввод и вывод данных при работе с файлами осуществлять через системные вызовы операционной системы read и write. 
5. Размеры буферов для хранения вводимых данных и результатов обработки должны быть равны 5000 байт. 
6. Программа должна работать с тестовыми данными, размер которых не должен превышать размера буфера. То есть, предполагается что весь обрабатываемый текст передается по каналу за один раз.
7. Представлен набор (не менее пяти) текстовых файлов, на которых проводилось тестирование программы. 
8. Для каждого из входных тестовых файлов в отчете должен быть представлен выходной файл, полученный в результате работы программы. 
9. Результаты работы должны быть представлены приведены в виде выходных данных.

Схема решаемой задачи:

![image](https://github.com/makar-with-tea/OS-IHW1/assets/79705001/8fa05cb3-dd13-4f46-bea7-0287851505ad)

Консольное приложение, соответствующее требованиям 2-6, [разработано](7/7.c). Тесты предоставлены в папке [7/tests](7/tests).  В программе используются каналы с названиями fd1.fifo и fd2.fifo, расположенные в той же папке, что и сама запускаемая программа. Каналы создаются с помощью команды mknod.

## 8 баллов 
В дополнение к требованиям на предыдущую оценку разработать программный продукт, в котором осуществляется взаимодействие между двумя независимыми процессами разных программ с использованием именованных каналов 

**Требования**
1. Представить общую схему решаемой задачи. Достаточно показать процессы и связи между ними, а также связи процессов с входным и выходным файлами. 
2. Разработать консольное приложение, использующее именованные каналы, обеспечивающее взаимодействие по следующей схеме: 
• первый процесс читает текстовые данные из заданного файла и через именованный канал передает их второму процессу; 
• второй процесс осуществляет обработку данных в соответствии с заданием и передает результат обработки через именованный канал обратно первому процессу; 
• первый процесс осуществляет вывод данных в заданный файл. 
3. Для задания имен входного и выходного файлов, а также дополнительных параметров, необходимых по условию задачи, использовать аргументы командной строки. В отчете необходимо описать формат командной строки и обеспечить его при вывод при запуске программы с некорректными параметрами. 
4. Ввод и вывод данных при работе с файлами осуществлять через системные вызовы read и write. 
5. Размеры буферов для хранения вводимых данных и результатов обработки должны быть равны 5000 байт. 
6. Программа должна работать с тестовыми данными, размер которых не должен превышать размера буфера. То есть, предполагается что весь обрабатываемый текст передается по каналу за один раз. 
7. Представлен набор (не менее пяти) текстовых файлов, на которых проводилось тестирование программы. 
8. Для каждого из входных тестовых файлов в отчете должен быть представлен выходной файл, полученный в результате работы программы. 
9. Результаты работы должны быть представлены приведены в виде выходных данных.

Схема решаемой задачи:

![image](https://github.com/makar-with-tea/OS-IHW1/assets/79705001/b9cf5052-bc1e-486f-bd19-5663ed7e19de)

Программный продукт, соответствующий требованиям 2-6, разработан. Он состоит из двух программ: [8.1.c](8/8.1.c) и [8.2.c](8/8.2.c). Пользователь работает с программой 8.1.c, она же взаимодействует со второй программой самостоятельно. Тесты предоставлены в папке [8/tests](8/tests).  В программе используются каналы с названиями fd1.fifo и fd2.fifo, расположенные в той же папке, что и сама запускаемая программа. Каналы создаются с помощью команды mknod.

## 9 баллов 
В дополнение к требованиям на предыдущую оценку разработать программный продукт, в котором осуществляется взаимодействие между двумя независимыми процессами разных программ с использованием именованных каналов. Обмен данными ведется за счет многократной передачи текста через ограниченные по размеру буферы. 

**Требования**
1. Представить общую схему решаемой задачи. Достаточно показать процессы и связи между ними, а также связи процессов с входным и выходным файлами. 
2. Разработать консольное приложение, использующее именованные каналы, обеспечивающее взаимодействие по следующей схеме: 
• первый процесс читает ограниченную порцию текстовых данных из заданного файла и через именованный канал передает их второму процессу; 
• второй процесс осуществляет обработку части данных в соответствии с заданием и при необходимости передает результат обработки (если он при этом сформировался) через именованный канал обратно первому процессу или получает от него следующую порцию; 
• первый процесс осуществляет вывод результата в заданный файл или сразу, или по частям в зависимости от условия задачи и размера буфера, используемого для пересылки данных. 
3. Для задания имен входного и выходного файлов, а также дополнительных параметров, необходимых по условию задачи, использовать аргументы командной строки. В отчете необходимо описать формат командной строки и обеспечить его при вывод при запуске программы с некорректными параметрами. 
4. Ввод и вывод данных при работе с файлами осуществлять через системные вызовы операционной системы read и write. 
5. Размеры буферов для хранения вводимых данных и результатов обработки должны быть не более 128 байт. 
6. Допускается работа только с файлам произвольного размера. То есть необходимы циклическое считывание файла, передача его фрагментов по каналам и (если возможно) обработка. Обосновать увеличение размера буфера для обработки файла во втором процессе, если обработка данных по частям невозможна. 
7. Представить набор (не менее пяти) текстовых файлов, на которых проводилось тестирование программы. 
8. Для каждого из тестовых файлов представить файл, полученный в результате работы программы. 
9. Результаты работы привести в отчете.

Схема решаемой задачи:

![image](https://github.com/makar-with-tea/OS-IHW1/assets/79705001/ad589e89-b220-434b-beb8-4dd58311e29f)

Программный продукт, соответствующий требованиям 2-6, разработан. Он состоит из двух программ: [9.1.c](9/9.1.c) и [9.2.c](9/9.2.c). Пользователь работает с программой 9.1.c, она же взаимодействует со второй программой самостоятельно. Тесты предоставлены в папке [9/tests](9/tests).  В программе используются каналы с названиями fd1.fifo и fd2.fifo, расположенные в той же папке, что и сама запускаемая программа. Каналы создаются с помощью команды mknod.
## Котик и жабка
![image](https://github.com/makar-with-tea/OS-IHW1/assets/79705001/619bf372-fc0a-43dc-88d3-380883ff4d58)
