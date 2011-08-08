class Parent {

  public static int nonFinalInt = 30;
  public static final int finalInt  = 31;

  static {System.out.println("Parent-STATIC_INITIALIZER_START");}
  {System.out.println("Parent-INSTANCE_INITIALIZER_START");}

  public Parent() {
    System.out.println("Parent-CONSTRUCTOR");
  }

  static {System.out.println("Parent-STATIC_INITIALIZER_END");}
  {System.out.println("Parent-INSTANCE_INITIALIZER_END");}
}

public class ClassInitTest {
  
  public static int nonFinalInt = 40;
  public static final int finalInt  = 41;
  
  static {System.out.println("ClassInitTest-STATIC_INITIALIZER_START");}
  {System.out.println("ClassInitTest-INSTANCE_INITIALIZER_START");}

  public ClassInitTest() {
    System.out.println("ClassInitTest-CONSTRUCTOR");
  }

  public static void main (String[] args) {
    System.out.println("main_START");

    //No instance creation
    //Shouldn't trigger Parent class initialization
    //Parent p = null;

    //Assigning value to static non-final field
    //Should trigger Parent class initialization
    //Parent.nonFinalInt = 35;

    //Accessing static non-final
    //Should trigger Parent class initialization?
    //System.out.println(Parent.nonFinalInt);  

    //Accessing static final
    //Should trigger Parent class initialization?
    System.out.println(Parent.finalInt);  

    System.out.println("main_END");
    return;
  }

  static {System.out.println("ClassInitTest-STATIC_INITIALIZER_END");}
  {System.out.println("ClassInitTest-INSTANCE_INITIALIZER_END");}

}