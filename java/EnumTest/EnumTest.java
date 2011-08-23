import java.util.EnumMap;
import java.util.EnumSet;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.ArrayList;

enum Operation {

  PLUS("+") {double apply (double x, double y) {return x + y;} },
  MINUS("-") {double apply (double x, double y) {return x - y;} },
  TIMES("*") {double apply (double x, double y) {return x * y;} },
  DIVIDE("/") {double apply (double x, double y) {return x / y;} };

  //constructors
  private Operation(String symbol) {
    this.symbol = symbol;
  }
  
  //static fields, blocks(initializers run only after all constants constructed)
  private static final Map<String, Operation> stringToEnum 
    = new HashMap<String, Operation>();

  static {
    for (Operation op: values())
      stringToEnum.put(op.toString(), op);
  }

  //Use fromString instead of valueOf because toString is overridden
  static Operation fromString(String symbol) {
    return stringToEnum.get(symbol);
  }

  //instance fields, blocks and methods
  private final String symbol;
  
  @Override public String toString() {return this.symbol;}

  abstract double apply (double x, double y);
}

public class EnumTest {

  public static void main (String[] args) {

    List<String> opNames = new ArrayList<String>();

    if (args.length < 2) {
      System.out.println("Usage: java EnumTest <double1> <double2>");
      System.exit(0);
    }

    double x = Double.parseDouble(args[0]);
    double y = Double.parseDouble(args[1]);

    for (Operation op: Operation.values()) {
      opNames.add(op.toString());
      System.out.printf("%f %s %f = %f%n", x, op, y, op.apply(x, y));
    }
   
    for (String s: opNames)
      System.out.println(s);
 
    for (String s: opNames) {
      Operation op = Operation.fromString(s);
      System.out.printf("%f %s %f = %f%n", x, op, y, op.apply(x, y));
    }
  }

}
