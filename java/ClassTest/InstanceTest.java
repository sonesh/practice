import java.util.List;
import java.util.ArrayList;

class Animal {
  public void talk() {
    System.out.println("I am an animal");
  }
}

class Dog extends Animal {
  public void talk() {
    System.out.println("I am a Dog");
  }
}

class Cat extends Animal {
  public void talk() {
    System.out.println("I am a Cat");
  }
}

public class InstanceTest {

  public static void main (String[] args) {

    ArrayList<Animal> animals = new ArrayList<Animal>();
    Animal x = new Animal();
    Animal y = new Dog();
    Animal z = new Cat();

    animals.add(x);
    animals.add(y);
    animals.add(z);
    
    for (Animal a: animals) {
      System.out.println(a);
      System.out.println(a.getClass());
      if (a instanceof Animal)
        System.out.println("Animal instance");
      if (a instanceof Dog)
        System.out.println("Dog instance");
      if (a instanceof Cat)
        System.out.println("Cat instance");
    }
  }

}
