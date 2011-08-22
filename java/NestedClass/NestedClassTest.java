/**
 * 1. Static member class can access ONLY static
 *    members of the enclosing class (including private and inherited)
 * 2. Local and anonymous inner classes can access all members
 *    (including instance and static, even if private, of the enclosing class,
 *    including inherited members - provided the local and anonymous inner
 *    classes are declared within an instance method or an instance initializer
 *    block
 */


class OuterMost {
  String s = "OuterMost";
}

class Outer extends OuterMost{
  //private static String s = "Outer";

  Outer() {
    System.out.println("Outer Constructor");
  }

  void print() {
    System.out.println("I am Outer's method: " + s);
  }

  class Inner {
    private static final String s = "Inner";
    {
      class LocalInner {
        void print() {
          System.out.println("I am Local Inner's method: " + s);
        }
      }

      LocalInner localInnerObject = new LocalInner();
      localInnerObject.print();
    }

    Inner() {
      System.out.println("Inner Constructor");
    }

    void print() {
      System.out.println("I am Inner's method: " + s);
      Inner anonInnerObject = new Inner() {
          void print() {
            System.out.println("I am Anonymous Inner's method: " + s);
          }
        };
      anonInnerObject.print();
    }
  }

  static class StaticInner {
    String s = "StaticInner";

    StaticInner() {
      System.out.println("StaticInner Constructor");
    }

    void print() {
      System.out.println("I am Static Inner's method: " + s);
    }
  }

}

class InnerExtended extends Outer.Inner {

  String s = "InnerExtended";

  InnerExtended(Outer outerObject) {
    outerObject.super();
    System.out.println("InnerExtended Constructor");
  }

  void print() {
    System.out.println("I am InnerExtended's method: " + s);
  }

}

public class NestedClassTest {

  public static void main (String[] args) {
    Outer outerObject = new Outer();
    Outer.Inner innerObject = outerObject.new Inner();
    Outer.StaticInner staticInnerObject = new Outer.StaticInner();
    Outer.Inner innerExtendedObject = new InnerExtended(outerObject);
    outerObject.print();
    innerObject.print();
    staticInnerObject.print();
    innerExtendedObject.print();
  }

}