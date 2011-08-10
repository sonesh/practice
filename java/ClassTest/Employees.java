// Test problem to understand class & object initialization

import java.lang.String;

class Employee {

  private String name;        //instance variable
  private double salary;      //instance variable
  static int count;           //class variable
  static double bonus;        //class variable

  Employee(String name, double salary) {
    this.name = name;
    this.salary = salary;
    if (this instanceof Accountant)
      this.salary += bonus;
  }

  static {
    bonus = 500.0;
  }

  {
    if (count > 5)
      bonus = 0.0;
    count++;
  }

  String getName() {
    return name;
  }

  double getSalary() {
    return salary;
  }

}

class Accountant extends Employee {

  Accountant (String name, double salary) {
    super(name, salary);
  }

}

class Employees {

  public static void main (String[] args) {
    
    String[] names = { "John Doe",
                       "Jane Smith",
                       "Jack Jones",
                       "Bob Smyth",
                       "Alice Doe",
                       "Janet Jones" };

    double[] salaries = { 40000.0,
                          50000.0,
                          30000.0,
                          37500.0,
                          52000.0,
                          47000.0 };

    for (int i = 0; i < names.length; i++) {
      if (i < 3) {
        Employee e = new Employee (names[i], salaries[i]);
        System.out.println("Name = " + e.getName());
        System.out.println("Salary = " + e.getSalary());
      } else {
        Accountant a = new Accountant (names[i], salaries[i]);
        System.out.println("Name = " + a.getName());
        System.out.println("Salary = " + a.getSalary());
      }
    }
  }

}
