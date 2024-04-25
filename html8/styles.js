// Создаем конструктор для объекта "автомобиль"
function Car(make, model, year, color) {
    this.make = make;
    this.model = model;
    this.year = year;
    this.color = color;
}

// Метод для объекта "автомобиль", выводящий информацию о машине
Car.prototype.getInfo = function() {
    return this.year + ' ' + this.make + ' ' + this.model + ', Color: ' + this.color;
};

// Создаем конструктор для объекта "компьютер"
function Computer(brand, model, processor, ram) {
    this.brand = brand;
    this.model = model;
    this.processor = processor;
    this.ram = ram;
}

// Метод для объекта "компьютер", выводящий информацию о компьютере
Computer.prototype.getInfo = function() {
    return this.brand + ' ' + this.model + ', Processor: ' + this.processor + ', RAM: ' + this.ram + 'GB';
};

// Создаем конструктор для объекта "фильм"
function Movie(title, director, year, genre) {
    this.title = title;
    this.director = director;
    this.year = year;
    this.genre = genre;
}

// Метод для объекта "фильм", выводящий информацию о фильме
Movie.prototype.getInfo = function() {
    return this.title + ' (' + this.year + '), Directed by: ' + this.director + ', Genre: ' + this.genre;
};

// Функция для добавления нового объекта на веб-страницу
function addObjectToPage(obj) {
    var info = obj.getInfo();
    var newItem = document.createElement('li');
    newItem.textContent = info;
    document.getElementById('object-list').appendChild(newItem);
}

// Функция для очистки списка объектов на веб-странице
function clearObjectList() {
    var objectList = document.getElementById('object-list');
    objectList.innerHTML = '';
}

// Создаем объекты
var car1 = new Car('Toyota', 'Corolla', 2020, 'Black');
var computer1 = new Computer('Dell', 'Inspiron', 'Intel Core i5', 8);
var movie1 = new Movie('Inception', 'Christopher Nolan', 2010, 'Sci-Fi');

// Добавляем объекты на веб-страницу
addObjectToPage(car1);
addObjectToPage(computer1);
addObjectToPage(movie1);

// Обработчик события для кнопки очистки списка
document.getElementById('clear-list').addEventListener('click', clearObjectList);
