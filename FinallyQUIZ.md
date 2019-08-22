1. Опишите какого типа будут объявлены ниже переменные

```
auto value1 = 10;
auto value2 = 10.3;
auto value3 = 10.3f;

auto value4;

decltype(value1) value5;
```




2. Чему будет выведено на экране

```
#include <iostream>

int main(int argc, char const *argv[]) {
  int a = 40;
  const int const_value = a;

  constexpr int const_value_expr = const_value;
  std::cout << const_value << const_value_expr << std::endl;
  return 0;
}

```

a) 4040;

b) ошибка компиляции;

с) скомпилируеться нормально, но на экран ничего не выведет;


3. Что будет выведено на экран

```
#include <stdio.h>
int a = 90;

int main(int argc, char const *argv[]) {
  int a = 10; 
  {
    int a = 50;
	printf("%d", a);
  }
}
```

a) 90;

b) 10;

с) 50;


4. Что будет выведенно на экране
```
#include <iostream>

struct A {
  A() {
   std::cout << "A";
  }
};

struct B {
  B() {
   std::cout << "B";
  }
};

class C {
  public:
   C(): b(), a() {}
  private:
   A a;
   B b;
};

int main(int argc, char const *argv[]) {
  C();
}
```

5. Чему будет выведенно на экран
```
uint32_t value = 0;

if ((++value > 0) && (value++ == 2)) {
  std::cout << "Equal to 2";
} else if (value > 2) {
  std::cout << "value more than 2";
}

```

a) Ошибка компиляции;

b) Equal to 2;

c) value more than 2;

d) ничего не будет выведенно на экран;


6. Что будет выведенно на экран
```
#include <iostream>

int main(int argc, char const *argv[]) {
  int value = 41;

  switch(value) {
    case 1:
      std::cout << "1" << std::endl;
      break;
    case 2:
      std::cout << "2" << std::endl;
      break;
    case 41:
      std::cout << "41" << std::endl;
    case 3:
      std::cout << "3" << std::endl;
      break;
    default:
      break;
  }

 return 0;
}
```

7. Что будет выведенно на экране при следующей компиялции
g++ -std=c++14 -Werror -pedantic main.cpp
```
#include <iostream>

void print_array(size_t size) {
  int array[size] {1, 2};
  for (auto value: array) {
	std::cout << value;
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
 print_array(2);
 return 0;
}

```

8. Что будет выведенно на экране
```
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[]) {
 char array2[] = {'H', 'e', 'l', 'l', 'o'};
 char array3[] = {"Hello"};
 std::cout << strlen(array2) << " " << strlen(array3) << std::endl;
 return 0;
}
```

a) 5 5;

b) ошибка компиляции;

с) 6 5;

d) 6 6;

f) неопределенное поведение;


9. Что будет выведенно на экране
```
#include <iostream>

void print_array(int* array) {
  size_t cout = sizeof(array) / sizeof(array[0]);
  for(size_t i = 0; i < cout; ++i) {
	std::cout << array[i];
  }
}

int main(int argc, char const *argv[]) {
 int array[] {1, 2, 3};
 print_array(array);
 return 0;
}
```

a) 123;

b) 1;

c) ничего не будет выведенно на экран;

d) ошибка компиляции;

d) неопределенное поведение;


10. Откомпилируеться ли данный код
```
int main() 
{ 
    int h = int(); 
    const int* i = int(); // 1 
    int const* j = int(); // 2
    int* const k = &h;  
 
    ++i;  // 3 
    ++j;  // 4  
    ++k;  // 5 
    ++*k; // 6 
}
```

Если нет то в какой из строччек ошибка

a) 1;

b) 2;

c) 3;

d) 4;

e) 5;

f) 6;

11. Что будет выведенно на экране
```
#include <iostream>

void print(int a = 90, int b, int c = 200) {
  std::cout << a << b << c << std::endl;
}

int main(int argc, char const *argv[]) {
 print(90);
 return 0;
}
```

a) 90 90 200;

b) 90 200;

c) неопределенное поведение;

d) ошибка компиляции;


12. Чему будет выведенно на экран
```
#include <iostream>

int main(int argc, char const *argv[]) {
  int* ptr = nullptr; // 1
  int& value = *ptr;  // 2
  value = 90;  // 3
  std::cout << *ptr << std::endl; // 4
  return 0;
}
```
a) 90;

b) неопределенное поведение;

с) ошибка компиялции в строке 1 и 2;

d) ошибка компиялции в строке 3;

e) ошибка компиялции в строке 4;

f) ошибка времени выполнения в строке 2;

g) ошибка времени выполнения в строке 3;

h) ошибка времени выполнения в строке 4;

13. Что будет выведенно на экране
```
#include <iostream>

void print(int a) {
  ++a;
  std::cout << a << std::endl;
}

void print(const int* a) {
  std::cout << *a << std::endl;
}

int main(int argc, char const *argv[]) {
  print(NULL);
  print(0);
  return 0;
}
```

a) 11;

b) ошибка времени выпонения;

с) неопределенное поведение;

d) ошибка времени выполнения;

e) ошибка компиляции;

14. Что будет выведенно на экран
```
#include <iostream>

struct Test{
  int a;
  int b;
};

int main(int argc, char const *argv[]) {
  Test value1;
  Test value2{};
  std::cout << value1.a << value1.b;
  std::cout << value2.a << value2.b << std::endl;
  return 0;
}
```

a) 0000;

b) 1100;

c) ошибка компиляции;

d) неопределенное поведение;


15. Что будет выведенно на экране
```
#include <iostream>

class A {
  public:
   A() {
	 std::cout << "A" << std::endl;
   }
   ~A() {
	 std::cout << "~A" << std::endl;
   }
};

int main(int argc, char const *argv[]) {
  A* array = new A[2];
  delete A;
  return 0;
}

```

a) AA~A~A;

b) AA~A;

c) AA;

d) ошибка компиляции;

e) ошибка времени выполнения;

f) неопределенное поведение;

16. Что будет выведенно на экране
```
#include <iostream>

class A {
  public:
   static void print() {
	 std::cout << a << b << std::endl; // 1
   }
  private:
   static const int a = 90; // 2
   static const float b = 100.f; // 3 
};

int main(int argc, char const *argv[]) {
  A::print(); // 4
  return 0;
}
```

a) 90 100;

b) ошибка компиляции в строке 1;

c) ошибка компиляции в строке 2;

d) ошибка компиляции в строке 3;

e) ошибка компиляции в строке 4;

17. В каких строчках будет ошибка компиляции, и ниже опишите почему
```
#include <iostream>

class Test {
  public:
   Test(int a) {
     a = a;
   }
  private:
  int a = 90;
};

int main(int argc, char const *argv[]) {
  Test t; // 1
  Test t2{40}; // 2
  Test t3 = t2; // 3
  return 0;
}
```

a) 1;

b) 2;

c) 3;

18. Что будет выведенно на экран
```
#include <iostream>

template <class T>
class Test;

template <class T>
class Test<T*> {
  public:
   Test() : value(new T{20}) {}
   void print() {std::cout << *value << std::endl;}
  private:
   T* value;
};

template <>
class Test<float> {
  public:
   void print() {std::cout << value << std::endl;}
  private:
   float value = 10.f;
};

int main(int argc, char const *argv[]) {
  Test<float> t;
  t.print();
  Test<int*> t2;
  t2.print();
  return 0;
}
```

a) ошибка компиляции;

b) ошибка времени выполнения;

c) 10 10;

d) 10 20;

e) 20 20

19. Что будет выведенно на экран
```
#include <iostream>

template <class T>
void func(T value) {
  static int a = 0;
  ++a;
  std::cout << a << std::endl;
}

int main(int argc, char const *argv[]) {
  func(1);
  func(10u);
  func(3);
  return 0;
}
```

a) 1 1 1;

b) 1 2 3;

с) ошибка компиляции;

d) 1 10 3;

d) 1 1 2;


20 Какие строчки нужно закомментировать, что бы скомпилировался следующий фрагмент кода:
```
class A 
{ 
public: 
    int l; 
 
protected: 
    int m; 
 
private: 
    int n; 
}; 
 
 
class B : public A 
{ 
public: 
    int l; 
 
protected: 
    int m; 
     
    void func2() 
    { 
        l = A::l;   // 1 
        m = A::m;   // 2 
        n = A::n;   // 3 
    } 
 
private: 
    int n; 
}; 
```

a) 1;

b) 2;

c) 3;

21 Что будет выведено на экране

```
#include <iostream>

class Test {
  public:
   Test(int a): a(a) {

   }
   void print() {std::cout << a << std::endl;}
  private:
   int a = 90;
};


int main(int argc, char const *argv[]) {

  const unsigned SIZE = 4;
  Test test[SIZE];
  for (unsigned i = 0; i < SIZE; ++i) {
    test[i].print();
  }
  return 0;
}
```

a) 90 90 90 90 90;

b) 0 0 0 0 0;

c) неопределенное поведение;

c) ошибка компиляции;

22. Что будет выведено на экран
```
#include <iostream>

class A {
 public:
  void print() {
    std::cout << "1" << std::endl;   
  }
};

class B {
 public:
  void print() {
    std::cout << "2" << std::endl;
  }
};

class C : public A, public B {};

int main(int argc, char const *argv[]) {
  C c;
  c.print();
  return 0;
}
```

a) 1;

b) 2;

c) 1 2;

d) ошибка компиляции;

23. Что будет выведено на экран

```
class C {
public:
  C(int i) : i(i) { std::cout << i; }
  ~C() { std::cout << i + 5; }

private:
  int i;
};

int main() {
  const C &c = C(1);
  C(2);
  C(3);
```

24. Что будет выведенно на экране
```
#include <iostream>

class Base {
  public:
   virtual void print() { std::cout << res << std::endl;}
   virtual void calc(int a_, int b_) { res = a_ * b_;}
  private:
   long res = 0;
};

class Derived: public Base {
  public:
   void print() { std::cout << res << std::endl;}
   void calc(double a_, double b_) { res = a_ + b_;}
  private:
   long double res = 0;
};

void print(Base& base) {
  base.calc(2, 4);
  base.print();
}


int main(int argc, char const *argv[]) {
  Derived d;
  print(d);
  return 0;
}
```

25. Можем ли мы вызывать виртуальные функции в конструкторе
a) Да, никаких проблем;

b) Да, но он может не делать то, что мы ожидаем. В конструкторе механизм виртуального вызова отключен, потому что переопределение из производных классов еще не произошло;

c) Нет, это запрещено стандартом С++;

d) Нет, мы не можем в конструкторе, так как механизм вызова виртуальных функций отключен;

26. В чем разница между X x; и X x();

a) X x(); выдает ошибку если класс не имеет конструктора по умолчанию, а X x; не выдает;

b) Вариант X x(); не объявляет экземпляр класса, а объявляет прототип функции;

c) Нет никакой разницы, вызывается конструктор по умолчанию;

d) В X x; не произойдет вызов конструктора, в X x(); - произойдет;
