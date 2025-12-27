// scope

#include <iostream>

struct Persona {
  /* data */
  std::string name;
  std::string surname;
  std::string address;

  int phoneNumbers[3];
  int age;
  float height;
};

void counter() {
  static int i = 0; // static mantiene il valore tra le chiamate
  i++;
  int j = 0; // j viene re-inizializzato ad ogni chiamata
  j++;
  std::cout << "il contatore ha valore: " << i << ", " << j << std::endl;
}

void increment(int &value) {
  value++;
  std::cout << "increment (by value) vale: " << value << std::endl;
}

void printPersona(const Persona *p) {
  std::cout << "Nome: " << p->name << " " << p->surname << std::endl;
  std::cout << "Indirizzo: " << p->address << std::endl;
  std::cout << "Età: " << p->age << std::endl;
  std::cout << "Altezza: " << p->height << " m" << std::endl;
}

void olderPerson(Persona &p, Persona &q) {
  if (p.age > q.age) {
    std::cout << p.name << " è più vecchio di " << q.name << std::endl;
  } else if (p.age < q.age) {
    std::cout << q.name << " è più vecchio di " << p.name << std::endl;
  } else {
    std::cout << p.name << " e " << q.name << " hanno la stessa età"
              << std::endl;
  }
}

int main() {

  int arr[] = {1, 2, 3, 4, 5};

  int i_main = 0;
  counter(); // 1
  counter(); // 2
  counter(); // 3

  increment(i_main);
  increment(i_main);
  std::cout << "i_main vale: " << i_main << std::endl;

  Persona p1;
  p1.name = "Mario";
  p1.surname = "Rossi";
  p1.address = "Via Roma 1";
  p1.age = 30;
  p1.height = 1.75f;

  Persona p2 = {
      "Luigi", "Verdi", "Via Milano 2", {123456789, 987654321, 555555555},
      28,      1.80f};
  printPersona(&p1);
  printPersona(&p2);
  olderPerson(p1, p2);

  return 0;
}
