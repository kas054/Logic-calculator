# Logic-calculator
Вариант 13

 

1.Разработать класс "логический элемент" в соответствии со следующим заданием:

Состояние класса -

Логический элемент определяется последовательностью описателей клемм. Описатель клеммы содержит информацию о типе клеммы (входная или выходная), количестве соединений (входная клемма может иметь не больше 1 соединения, а выходная клемма – не больше 3 соединений) и состоянии сигнала - значение уровня 0, 1 или Х (неопределенное состояние). Для описания клеммы целесообразно использовать структуру. Память под массив структур выделяется статически, во время компиляции, и задается массивом фиксированного размера.

Протокол класса -

Определяет  возможности создания и инициализации экземпляров класса и правила их использования (методы класса).

Предусмотреть следующие возможности:

·          пустой конструктор для инициализации экземпляров и массивов экземпляров класса по умолчанию (“инвертор”);

·          создание экземпляров класса с инициализацией количеством входных и выходных клемм логического элемента;

·          создание экземпляров класса с инициализацией массивом описателей клемм заданной длины;

·          переопределение состояний всех входных и выходных клемм посредством ввода их новых значений из входного потока;

·          вывод в выходной поток информации обо всех клеммах логического элемента;

·          установить новое состояние клеммы с заданным номером;

·          определить текущее состояние клеммы с заданным номером;

·          соединение клеммы – увеличение в допустимых пределах количества соединений клеммы, заданной её номером;

·          уменьшение числа соединений клеммы, заданной её номером (свободная клемма в состоянии Х);

·          добавить входную или выходную клемму.

2. Проектирование класса рекомендуется начать с представления состояния класса, учитывающего заданные операции, а затем реализации конструкторов и метода вывода. Для отладки и исчерпывающего тестирования других методов разработанного класса реализовать диалоговую программу, которая позволяет вводить параметры отлаживаемых методов. Для обработки ошибочных ситуаций использовать механизм исключительных ситуаций.

3. Повторить разработку класса, реализовав отдельные методы (там, где это оправданно), перегруженными операторами. Состав перегруженных операторов целесообразно согласовать с преподавателем.

4. Еще раз повторить разработку класса при условии, что память под массив необходимой длины выделяется динамически, во время выполнения программы (с помощью оператора new; память задается указателем на char в состоянии класса). Для хранения данных в экземпляре класса не должна использоваться лишняя память.

Дополнить интерфейс класса следующими возможностями:

·          создание экземпляра класса с его инициализацией другим экземпляром класса (копирующий конструктор);

·          переопределение экземпляра класса (с помощью перегруженного оператора присваивания).

Разработать и реализовать прикладную программу, использующую класс, разработанный другим студентом. Задание для прикладной программы разработать самостоятельно и согласовать с преподавателем.